class Solution {
public:
    int solve(vector<int>& p, int i, int time, vector<vector<int>>& dp) {
        if (i == p.size()) return 0;
        if (dp[i][time] != -1) return dp[i][time];

        int inc = p[i] * (time + 1) + solve(p, i + 1, time + 1, dp);
        int exc = solve(p, i + 1, time, dp);

        return dp[i][time] = max(inc, exc);
    }

    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(s, 0, 0, dp);
    }
};