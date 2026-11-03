class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int dp[4] = {0, 1, 0, 1};

        for (int obs : obstacles) {
            if (obs > 0) {
                dp[obs] = 1e9;
            }

            for (int lane = 1; lane <= 3; ++lane) {
                if (lane != obs) {
                    dp[lane] = min(dp[lane], min(dp[(lane % 3) + 1], dp[((lane + 1) % 3) + 1]) + 1);
                }
            }
        }

        return min(dp[1], min(dp[2], dp[3]));
    }
};