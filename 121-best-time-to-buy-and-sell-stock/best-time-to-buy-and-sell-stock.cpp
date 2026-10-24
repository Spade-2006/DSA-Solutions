class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        int mini = prices[0];

        for(int p : prices)
        {
            int diff = p-mini;
            profit = max(profit , diff);
            mini = min(mini,p);
        }

        return profit;
        
    }
};