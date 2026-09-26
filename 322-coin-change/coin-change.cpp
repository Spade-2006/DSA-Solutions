class Solution {
public:
    int coinChange(vector<int>& coins, int A) {
    
    //step 1 
    vector<int> dp(A+1 , INT_MAX);

    //step 2
    dp[0] = 0;

    for(int B = 0 ; B <=A ; B++)
    {
       

        for(int coin : coins)
        {
            if(B-coin >=0 and dp[B-coin] !=INT_MAX)
                dp[B] = min(dp[B] , 1+dp[B-coin]);
        }

    }

    return dp[A]==INT_MAX ? -1 : dp[A];
    
        
    }

  
};