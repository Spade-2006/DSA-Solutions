class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        vector<vector<int>> dp(prices.size() , vector<int>(2 , -1));
        return solve(0 , true , prices , dp);
        
    }

    int solve(int index , bool buy , vector<int> &prices , vector<vector<int>> &dp)
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
            profit = max((-(prices[index]) + solve(index+1 , false , prices,dp )),(0+solve(index+1 , true , prices,dp)));
        }
        else
        {

            profit = max((+(prices[index]) + solve(index+2 , true , prices ,dp)),(0+solve(index+1 , false , prices,dp)));

        }
        return dp[index][buy] = profit;
    }
};