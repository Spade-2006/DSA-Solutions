class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int q = strs.size();
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        
        
        for(int i = q-1 ; i>=0 ; i--)
        {
            for(int j = 0 ; j<=m ;j++)
            {
                for(int k = 0 ; k<=n ; k++)
                {
                    int zs = 0 , os = 0;

                    for(char c : strs[i])
                    {
                        if(c=='0')
                        {
                            zs++;
                        }
                        else
                            os++;
                    }

                    int exc = dp[i+1][j][k];

                    int inc =0;
                    if((j-zs) >= 0 and (k-os) >=0 )
                        inc = 1 + dp[i+1][j-zs][k-os];


                    dp[i][j][k] =  max(inc,exc);

                }
            }
        }

        return dp[0][m][n];
    }

    
};