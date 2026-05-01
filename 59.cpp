class Solution {
public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int i = 0, j = 0, c = 0;
        int n = a.size();
        int m = b.size();
        
        while (i < n || j < m) {
            c++;
            int res;

            if (i < n && (j >= m || a[i] <= b[j])) {
                res = a[i];
                i++;
            } else {
                res = b[j];
                j++;
            }

            if (c == k) {
                return res;
            }
        }
        
        return 0;
    }
};