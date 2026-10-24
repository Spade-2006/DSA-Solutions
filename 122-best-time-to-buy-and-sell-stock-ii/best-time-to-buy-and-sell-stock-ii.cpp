class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int aheadBuy = 0, aheadNotBuy = 0;
        int currBuy = 0, currNotBuy = 0;

        for(int i = prices.size()-1 ; i>=0 ; i--)
        {
            currBuy = max((-(prices[i]) + aheadNotBuy),(0+aheadBuy));
            currNotBuy  = max((+(prices[i]) + aheadBuy),(0+aheadNotBuy));
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

        return aheadBuy;
        
    }

};