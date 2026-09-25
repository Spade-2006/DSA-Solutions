class Solution {
public:

    int solve(int n , vector<int> &dp)
    {
        if(n==1 or n==0)
            return n;
        //step 3
        if(dp[n] != -1)
            return dp[n];
        //step 2
        dp[n] =  solve(n-1,dp) + solve(n-2,dp);
        return dp[n];  

    }
    int fib(int n)
    {
        // step1 
        
        
        int prev1  = 0;
        
        int prev2  = 1;

        if(n == 0 or n ==1 )
            return n;

        int curr;

        for(int i = 1 ; i<=n ; i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
      
        }

        return curr;
               
    }
};