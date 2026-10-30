class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {

        vector<vector<int>> dp(target+1 , vector<int>(nums.size()+1 , -1));

        return solve(nums , target , 0 ,dp);
        
    }
    

    int solve(vector<int>& nums , int target , int i ,vector<vector<int>> &dp)
    {
        if(target == 0)
            return 1;

        if(target<0)
            return 0;

        if(i >= nums.size())

            return 0;

        if(dp[target][i] != -1)
            return dp[target][i];

        int inc = solve(nums , target-nums[i] , 0 ,dp);
        int exc = solve(nums , target , i+1 , dp);


        return dp[target][i] = inc+exc;
    }
};