class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        int count = 0;
        int n = nums.size();
        int l = 0;
        int zeros = 0;

        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (l < r && (nums[l] == 0 || sum > goal)) {
                if (nums[l] == 0) {
                    zeros++;
                } else {
                    zeros = 0;
                }
                sum -= nums[l];
                l++;
            }

            if (sum == goal) {
                count += 1 + zeros;
            }
        }

        return count;
    }
};