class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return answer(word1, word2, n, m, dp);
    }

    int answer(string &word1, string &word2, int index1, int index2, vector<vector<int>> &dp) {
        if (index1 == 0) return index2;
        if (index2 == 0) return index1;

        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        if (word1[index1 - 1] == word2[index2 - 1]) {
            return dp[index1][index2] = answer(word1, word2, index1 - 1, index2 - 1, dp);
        }

        int del_from_word1 = 1 + answer(word1, word2, index1 - 1, index2, dp);
        int del_from_word2 = 1 + answer(word1, word2, index1, index2 - 1, dp);

        return dp[index1][index2] = min(del_from_word1, del_from_word2);
    }
};