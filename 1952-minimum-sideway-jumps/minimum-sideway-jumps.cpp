class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(obstacles.size(), vector<int>(4, -1));
        return solve(obstacles, 0, 2, dp);
    }

    int solve(vector<int>& o, int i, int lane, vector<vector<int>>& dp) {
        if (i >= o.size() - 1) {
            return 0;
        }

        if (dp[i][lane] != -1) {
            return dp[i][lane];
        }

        if (o[i + 1] != lane) {
            return dp[i][lane] = solve(o, i + 1, lane, dp);
        }

        int jumpl = 1e9, jumpr = 1e9;

        int lane1 = (lane % 3) + 1;
        int lane2 = ((lane + 1) % 3) + 1;

        if (o[i] != lane1) {
            jumpl = 1 + solve(o, i, lane1, dp);
        }

        if (o[i] != lane2) {
            jumpr = 1 + solve(o, i, lane2, dp);
        }

        return dp[i][lane] = min(jumpl, jumpr);
    }
};