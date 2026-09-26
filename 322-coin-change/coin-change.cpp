class Solution {
public:
    int coinChange(vector<int>& coins, int A) {
    
    //step 1 
    vector<int> dp(A+1 , -1);
    int ans = solve(coins , A,dp);

    return ans==INT_MAX ? -1 :  ans;
        
    }

    int solve(vector<int> &coins , int B , vector<int> &dp)
    {
        if(B == 0)
            return 0;

        if(B < 0)
            return INT_MAX;

        //step 3
        if(dp[B] !=-1)
            return dp[B];

        int mini = INT_MAX;

        for(int i : coins)
        {
            int res =solve(coins,B-i,dp);
            if(res!=INT_MAX)
                mini = min(mini, 1+res);
        }

        //step 2
        dp[B] = mini;
        return dp[B];
    }
};