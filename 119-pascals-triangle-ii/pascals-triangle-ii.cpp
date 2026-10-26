class Solution {
public:
    vector<int> getRow(int num) {
        vector<vector<int>> ans;

        for (int n = 1; n <= num + 1; n++) {
            vector<int> curr;
            for (int i = 0; i < n; i++) {
                if (i == 0 || i == n - 1) {
                    curr.push_back(1);
                } else {
                    curr.push_back(ans[n - 2][i - 1] + ans[n - 2][i]);
                }
            }
            ans.push_back(curr);
        }

        return ans[num];
    }
};