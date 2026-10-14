class Solution {
public:
    int rob(vector<int>& nums)
    {
        //step1
        int n = nums.size();
        vector<int> dp(nums.size()+2,0);
        

        
        for (int i = n - 1; i >= 0; i--)
        {
            int robCurrent = nums[i] + dp[i + 2];
            int skipCurrent = dp[i + 1];
            dp[i] = max(robCurrent, skipCurrent);
    
        }
        return dp[0];

        
    }


    int solve(vector<int> &nums, int i, vector<int> &dp)
    {
        //base case
        if(i>nums.size()-1)
            return 0;

        //step3
        if(dp[i]!=-1)
            return dp[i];
        
        
        return dp[i];

    }
};