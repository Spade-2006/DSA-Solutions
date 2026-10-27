class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for(int s : nums) sum+=s;
        vector<vector<int>> dp(nums.size()+1,(vector<int>(sum+1,-1)));
        return solve(nums , 0 , 0,dp);
    }

    bool solve(vector<int>& nums , int diff, int i, vector<vector<int>> &dp)
    {
        if(i==nums.size())
        {
            return diff==0;
        }

        if(dp[i][diff] != -1)
            return dp[i][diff];

        
        bool case1 = solve(nums , diff +  nums[i], i+1,dp);

        bool case2;
        if(diff-nums[i] > 0)
            case2 = solve(nums , diff - nums[i] , i+1,dp);
        else
            case2 = solve(nums , nums[i] - diff  , i+1,dp);
            


        return dp[i][diff] = case1 or  case2;
    }
};