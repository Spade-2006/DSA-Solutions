class Solution {
public:
    int climbStairs(int stairs)
    {
        int next1 = 1;
        int next2 = 1; 
        int curr;
        for(int i = stairs-1 ; i>=0 ; i--)
        {
            if(i == stairs-1)
            {
                curr = next1;
                next2 = next1;
                next1 = curr;
            }
            else
            {
                curr = next1 + next2;
                next2 = next1;
                next1 = curr;
            }
        }
        return curr;
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