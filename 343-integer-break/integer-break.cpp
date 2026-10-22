class Solution {
public:
    int integerBreak(int n)
    {
        if (n == 2) return 1;
        if (n == 3) return 2;
        vector<int> dp(n+1 , 1);

        int prev3 = 1;
        int prev2 = 2;
        int prev1 = 3;
        
        int ans = 0;
        for(int i = 4 ; i<=n ; i++)
        {
            long long case1 = prev2 * 2 ;
        
            long long case2 = prev3 * 3 ;

            ans =  max(case2 , case1);

            prev3 = prev2;
            prev2 = prev1;
            prev1 = ans;

        }

        return prev1;
    }

    


};