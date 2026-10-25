class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.length(), m = b.length();
        vector<int> nextRow(m + 1, 0);
        vector<int> currRow(m + 1, 0);

        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int ni = nextRow[j];
                int nj = currRow[j + 1];
                int nij = nextRow[j + 1];

                int ans = 0;

                if (a[i] == b[j]) {
                    ans = 1 + nij;
                } else {
                    ans = max(ni, nj);
                }
                currRow[j] = ans;
            }
            nextRow = currRow; 
        }

        return nextRow[0];
    }
};