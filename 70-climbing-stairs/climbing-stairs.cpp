class Solution {
public:
    int climbStairs(int stairs)
    {
        //step 1 
        vector<int> dp(stairs+1 , -1);
        //int ans = solve(stairs , 1 , dp) + solve(stairs , 2 , dp);

        //step 2 tab
        dp[stairs] = 1;

        for(int i = stairs-1 ; i>=0 ; i--)
        {
            if(i == stairs-1)
                dp[i] = dp[i+1];
            else
                dp[i] = dp[i+1] + dp[i+2];
        }
        return dp[0];
    }

    int solve(int &stairs , int i , vector<int> &dp)
    {
        //Base case
        if(i == stairs)
            return 1;
        if(i>stairs)
            return 0;

        //step 3 
        if(dp[i] != -1)
            return dp[i];

        //step 2 
        dp[i] =  solve(stairs , i+1 , dp) + solve(stairs , i+2 , dp);   
        return dp[i];     
    }
};