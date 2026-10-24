class Solution {
public:
    int maxProfit(vector<int>& prices , int fee)
    {
        vector<vector<int>> dp(prices.size() , vector<int>(2 , -1));
        return solve(0 , true , prices , dp , fee);
        
    }

    int solve(int index , bool buy , vector<int> &prices , vector<vector<int>> &dp , int fee)
    {
        if(index>=prices.size())
            return 0;

        if(dp[index][buy] != -1)
        {
            return dp[index][buy];
        }

        int profit = 0;

        if(buy)
        {
            profit = max((-(prices[index]) + solve(index+1 , false , prices,dp , fee )),(0+solve(index+1 , true , prices,dp , fee)));
        }
        else
        {

            profit = max((prices[index] -  fee  + solve(index+1 , true , prices ,dp , fee)),(0+solve(index+1 , false , prices,dp , fee)));

        }
        return dp[index][buy] = profit;
    }
};