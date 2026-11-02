class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;

        vector<vector<int>> dp1(n + 2, vector<int>(k + 1, 0));
        vector<vector<int>> dp2(n + 2, vector<int>(k + 1, 0));

        // Case 1: Exclude last element
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {

                int eat = slices[i] + dp1[i + 2][j - 1];

                int notEat = dp1[i + 1][j];

                dp1[i][j] = max(eat, notEat);
            }
        }

        // Case 2: Exclude first element
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= k; j++) {

                int eat = slices[i] + dp2[i + 2][j - 1];

                int notEat = dp2[i + 1][j];

                dp2[i][j] = max(eat, notEat);
            }
        }

        return max(dp1[0][k], dp2[1][k]);
    }
};