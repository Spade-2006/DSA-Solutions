class Solution {
public:
    int rob(vector<int>& nums)
    {
        
        int n = nums.size();
        int prevRob = 0;
        int maxRob = 0;
        

        
        for (int curr : nums)
        {
            int temp = max(maxRob , prevRob + curr);
            prevRob = maxRob;
            maxRob = temp;
        }
        return maxRob;

        
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