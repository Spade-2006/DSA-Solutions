class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if (n <= 1) return n;

        vector<int> next(n, 0);
        vector<int> curr(n, 0);

        next[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            curr[i] = 1;

            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    curr[j] = 2 + next[j - 1];
                } else {
                    int inc = next[j];
                    int exc = curr[j - 1];
                    curr[j] = max(inc, exc);
                }
            }

            next = curr;
        }

        return curr[n - 1];
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
};