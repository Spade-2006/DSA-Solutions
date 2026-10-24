class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
       vector<vector<vector<int>>> dp(prices.size() , vector<vector<int>>(2 , vector<int>( k+1, -1)));
        return solve(prices , 0 , true , k,dp);
    }

    int solve(vector<int> &prices , int index , bool buy , int limit , vector<vector<vector<int>>> &dp)
    {
        if(index==prices.size() or limit==0)
        {
            return 0;
        }

        if(dp[index][buy][limit] != -1)
            return dp[index][buy][limit];

        int profit = 0;
        if(buy)
        {
            profit = max((-(prices[index]) + solve(prices , index+1 , false , limit , dp)),(0 + solve(prices , index+1 , true , limit , dp)));

        }
        else
        {
            profit = max((prices[index] + solve(prices , index+1 , true , limit-1  , dp)),( 0 + solve(prices , index+ 1 , false , limit , dp)));

        }
        return dp[index][buy][limit] = profit;
    }

};