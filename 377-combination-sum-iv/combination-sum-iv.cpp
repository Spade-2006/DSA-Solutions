class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {

        vector<vector<unsigned int>> dp(target+1 , vector<unsigned int>(nums.size()+1 , 0));

        for(int i = 0; i<=nums.size();i++)
        {
            dp[0][i] = 1;
        }

        for(int t = 1 ; t <= target ; t++)
        {
            for(int i = nums.size()-1 ; i>=0 ; i--)
            {
                unsigned int inc = 0;

                if(t-nums[i] >= 0)
                    inc = dp[t-nums[i]][0];
                
                unsigned int exc = dp[t][i+1];


                dp[t][i] = inc+exc;

            }
        }

        return dp[target][0];
        
    }
    

  
};