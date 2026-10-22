class Solution {
public:
    int integerBreak(int n)
    {
        if (n == 2) return 1;
        if (n == 3) return 2;
        vector<int> dp(n+1 , 1);

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4 ; i<=n ; i++)
        {
            int case1 = dp[i-2] * 2 ;
        
            int case2 = dp[i-3] * 3 ;

            dp[i] =  max(case2 , case1);

        }

        return dp[n];
    }

    


};