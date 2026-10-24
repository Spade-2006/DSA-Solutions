class Solution {
    const int INF = 1e7;
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = 0;
        for (int r : rods) sum += r;

        vector<vector<int>> dp(rods.size(), vector<int>(sum + 1, -1));
        int ans = solve(rods, 0, 0, dp);
        return max(0, ans);
    }

    int solve(vector<int>& rods, int index, int diff, vector<vector<int>>& dp) {
        if (index >= rods.size()) {
            return (diff == 0) ? 0 : -INF;
        }

        if (dp[index][diff] != -1) return dp[index][diff];

        
        int res = solve(rods, index + 1, diff, dp);

        res = max(res, solve(rods, index + 1, diff + rods[index], dp));

        
        if (rods[index] <= diff) {
            // Shorter billboard stays shorter or becomes equal
            res = max(res, rods[index] + solve(rods, index + 1, diff - rods[index], dp));
        } else {
            // Shorter billboard becomes the new taller one
            res = max(res, diff + solve(rods, index + 1, rods[index] - diff, dp));
        }

        return dp[index][diff] = res;
    }
};