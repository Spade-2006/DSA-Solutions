#include <vector>

using namespace std;

class Solution {
public:
    int modulo = 1e9 + 7;

    int numTilings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(n, 0, false, dp);
    }

    int solve(int &n, int j, bool in, vector<vector<int>> &dp) {
        if (j == n && !in)
            return 1;

        if (j >= n)
            return 0;

        if (dp[j][in] != -1)
            return dp[j][in];

        int dom1 = 0;
        int dom2 = 0;
        int trom1 = 0;
        int trom = 0;

        if (!in) {
            dom1 = solve(n, j + 1, in, dp) % modulo;
            dom2 = solve(n, j + 2, in, dp) % modulo;
            trom1 = solve(n, j + 1, !in, dp) % modulo;
            trom = solve(n, j + 1, !in, dp) % modulo;
        }

        if (in) {
            trom1 = solve(n, j + 2, !in, dp) % modulo;
            dom1 = solve(n, j + 1, in, dp) % modulo;
        }

        return dp[j][in] = (((dom1 + dom2) % modulo + trom1) % modulo + trom) % modulo;
    }
};