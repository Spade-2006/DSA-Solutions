class Solution {
public:
    int minSideJumps(vector<int>& o) {
        int n = o.size();
        vector<vector<int>> dp(n, vector<int>(4, 1e9));

        
        dp[n - 1][1] = 0;
        dp[n - 1][2] = 0;
        dp[n - 1][3] = 0;

        for (int i = n - 2; i >= 0; i--) {
            
            for (int lane = 1; lane <= 3; lane++) {
                if (o[i + 1] != lane) {
                    dp[i][lane] = dp[i + 1][lane];
                }
            }

            
            for (int lane = 1; lane <= 3; lane++) {
                if (o[i] == lane) continue;

                int lane1 = (lane % 3) + 1;
                int lane2 = ((lane + 1) % 3) + 1;

                int jumpl = (o[i] != lane1) ? 1 + dp[i][lane1] : 1e9;
                int jumpr = (o[i] != lane2) ? 1 + dp[i][lane2] : 1e9;

                dp[i][lane] = min(dp[i][lane], min(jumpl, jumpr));
            }
        }

        return dp[0][2];
    }
};