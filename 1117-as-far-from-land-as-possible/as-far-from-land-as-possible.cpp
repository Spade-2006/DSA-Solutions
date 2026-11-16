class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        const int INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }

        int ans = -1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    if (i < n - 1) dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    if (j < n - 1) dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);

                    if (dp[i][j] < INF) {
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
        }

        return ans;
    }
};