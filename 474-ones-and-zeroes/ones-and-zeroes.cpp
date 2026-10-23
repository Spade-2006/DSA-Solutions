class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {

        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        
        return solve(strs , m , n , 0 , dp);
    }

    int solve(vector<string>& strs , int m, int n , int index ,vector<vector<vector<int>>> &dp)
    {
       

        if (index == strs.size())
            return 0;

        if(dp[index][m][n] != -1)
            return dp[index][m][n];


        int zs = 0 , os = 0;

        for(char c : strs[index])
        {
            if(c=='0')
            {
                zs++;
            }
            else
                os++;
        }

        int exc = solve(strs , m , n , index+1,dp);

        int inc =0;
        if((m-zs) >= 0 and (n-os) >=0 )
            inc = 1 + solve(strs , m-zs , n-os , index+1,dp)  ;


        dp[index][m][n] =  max(inc,exc);

        return dp[index][m][n];


        

    }
};