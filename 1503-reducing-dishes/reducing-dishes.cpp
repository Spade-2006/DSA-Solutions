class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int time = n; time >= 0; time--) {
                int inc = s[i] * (time + 1) + dp[i + 1][time + 1];
                int exc = dp[i + 1][time];

                dp[i][time] = max(inc, exc);
            }
        }

        return dp[0][0];
    }
};