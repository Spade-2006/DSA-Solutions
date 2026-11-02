class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;

        vector<vector<int>> dp1(n, vector<int>(k + 1, -1));
        vector<vector<int>> dp2(n, vector<int>(k + 1, -1));

        int first = solve(slices, 0, n - 2, k, dp1);
        int last = solve(slices, 1, n - 1, k, dp2);

        return max(first, last);
    }

    int solve(vector<int>& slice, int i, int end,int k, vector<vector<int>>& dp) {

        if (k == 0) return 0;

        if (i > end) return INT_MIN;

        if (dp[i][k] != -1) return dp[i][k];

        int eat = slice[i] + solve(slice, i + 2, end, k - 1, dp);

        int notEat = solve(slice, i + 1, end, k, dp);

        return dp[i][k] = max(eat, notEat);
    }
};