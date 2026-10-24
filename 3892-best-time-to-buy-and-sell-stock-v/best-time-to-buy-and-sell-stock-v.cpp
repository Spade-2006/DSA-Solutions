class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k)
    {
        if (prices.empty() || k == 0) return 0;
        vector<vector<vector<long long>>> dp(
            prices.size(), vector<vector<long long>>(k + 1, vector<long long>(3, -1e18))
        );
        return solve(prices , 0 , k , 0 , dp);
    }

    long long solve(vector<int> &prices , int index , int limit , int state , vector<vector<vector<long long>>> &dp)
    {
    
        if (index == prices.size()) {
            return (state == 0) ? 0 : -1e14;
        }

        
        if (limit == 0 && state == 0) {
            return 0;
        }

        if(dp[index][limit][state]  != -1e18)
        {
            return dp[index][limit][state] ;
        }
        long long profit = 0;

        if(state == 0)
        {

            long long bought = (-(prices[index]) + solve(prices , index+1 , limit , 1 ,dp));

            long long sell =  (+(prices[index]) + solve(prices , index+1 , limit , 2 ,dp));

            long long skip = (0+ solve(prices , index+1 , limit , 0 ,dp));
            profit = max({bought , sell , skip});

        }

        else if(state == 1)
        {
            long long sellNow = (+(prices[index]) + solve(prices , index+1 , limit-1 , 0 ,dp));
            long long skipNow = ( 0 + solve(prices , index+1 , limit , 1 ,dp));
            profit = max(sellNow , skipNow);
        }
        else
        {
            long long BuyNow = (-(prices[index]) + solve(prices , index+1 , limit-1 , 0 ,dp));
            long long skipNow = ( 0 + solve(prices , index+1 , limit , 2 ,dp));
            profit = max(BuyNow , skipNow);

        }

        return dp[index][limit][state] = profit;
    }
};