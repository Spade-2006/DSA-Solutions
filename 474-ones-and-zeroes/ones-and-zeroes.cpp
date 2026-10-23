class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int q = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        
        for(int i = q-1 ; i>=0 ; i--)
        {
            for(int j = m ; j>=0  ;j--)
            {
                for(int k = n ; k>=0 ; k--)
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

                    int exc = dp[j][k];

                    int inc =0;
                    if((j-zs) >= 0 and (k-os) >=0 )
                        inc = 1 + dp[j-zs][k-os];


                    dp[j][k] =  max(inc,exc);

                }
            }
        }

        return dp[m][n];
    }

    
};