class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        vector<vector<int>> dp(2  , vector<int>( 2+1 , 0));
    
        for(int i = prices.size() -1 ;i>=0 ; i--)
        {
            for(int j = 0 ; j<2 ; j++)
            {
                for(int k = 1 ; k<=2 ; k++)
                {
                    int profit = 0;

                    if(j)
                    {
                        profit = max((-(prices[i]) + dp[j-1][k]),(0 + dp[j][k]));

                    }
                    else
                    {
                        profit = max((prices[i] + dp[j+1][k-1]),( 0 + dp[j][k]));

                    }
                    dp[j][k] = profit;

                }
            }
        }

        return dp[1][2];
    }

    // int solve(vector<int> &prices , int index , bool buy , int limit , vector<vector<vector<int>>> &dp)
    // {
    //     if(index==prices.size() or limit==0)
    //     {
    //         return 0;
    //     }

    //     if(dp[index][buy][limit] != -1)
    //         return dp[index][buy][limit];

    //     int profit = 0;
    //     if(buy)
    //     {
    //         profit = max((-(prices[index]) + solve(prices , index+1 , false , limit , dp)),(0 + solve(prices , index+1 , true , limit , dp)));

    //     }
    //     else
    //     {
    //         profit = max((prices[index] + solve(prices , index+1 , true , limit-1  , dp)),( 0 + solve(prices , index+ 1 , false , limit , dp)));

    //     }
    //     return dp[index][buy][limit] = profit;
    // }

};