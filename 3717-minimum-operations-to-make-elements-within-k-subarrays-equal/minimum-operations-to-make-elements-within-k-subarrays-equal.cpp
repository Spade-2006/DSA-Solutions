class Solution {
public:
    long long INF = 1e18;
    vector<vector<long long>> dp;

    long long count(vector<long long>& cost, int idx, int k, int x) {
        if (k == 0) return 0;

        if (idx >= cost.size()) return INF;

        if (dp[idx][k] != -1) {
            return dp[idx][k];
        }

        long long pick =
            cost[idx] + count(cost, idx + x, k - 1, x);

        long long notpick =
            count(cost, idx + 1, k, x);

        return dp[idx][k] = min(pick, notpick);
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        vector<long long> cost(nums.size() - x + 1);

        multiset<int> mx;
        multiset<int> mn;

        long long suml = 0;
        long long sumr = 0;

        int l = 0;
        int r = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (mx.empty() || *mx.rbegin() >= nums[i]) {
                mx.insert(nums[i]);
                suml += nums[i];
                l++;
            } else {
                mn.insert(nums[i]);
                sumr += nums[i];
                r++;
            }

            if (i >= x) {
                int val = nums[i - x];

                if (mx.count(val)) {
                    mx.erase(mx.find(val));
                    suml -= val; // correction
                    l--;
                } else {
                    mn.erase(mn.find(val));
                    sumr -= val;
                    r--;
                }
            }

            if (mx.size() > mn.size() + 1) {
                int val = *mx.rbegin();

                mx.erase(mx.find(val));
                suml -= val;
                l--;

                mn.insert(val);
                sumr += val;
                r++;
            }

            if (mn.size() > mx.size()) {
                int val = *mn.begin();

                mn.erase(mn.find(val));
                sumr -= val;
                r--;

                mx.insert(val);
                suml += val;
                l++;
            }

            if (i >= x - 1) {
                long long mid = *mx.rbegin();

                long long left = 1LL * l * mid - suml;
                long long right = sumr - 1LL * r * mid;

                cost[i - x + 1] = left + right;
            }
        }

        dp.assign(cost.size() + 1, vector<long long>(k + 1, -1));

        return count(cost, 0, k, x);
    }
};