#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() , vector<int>(amount+1 , -1));
        return solve(0, amount, coins,dp);
    }

    int solve(int index, int amount, const vector<int>& coins , vector<vector<int>> &dp) {
        
        if (amount == 0) {
            return 1;
        }

  
        if (index >= coins.size() || amount < 0) {
            return 0;
        }

        if(dp[index][amount]!=-1)
            return dp[index][amount];

        int include = 0;
        if (coins[index] <= amount) {
            include = solve(index, amount - coins[index], coins,dp);
        }

       int exclude = solve(index + 1, amount, coins,dp);

        dp[index][amount] = include + exclude;
        return dp[index][amount];
    }
};