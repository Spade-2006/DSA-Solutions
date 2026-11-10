static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() < n - 1) return -1;

        vector<int> trustScore(n + 1, 0);

        for (const auto& t : trust) {
            trustScore[t[0]]--;
            trustScore[t[1]]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (trustScore[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};