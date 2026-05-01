class Solution {
public:
    int countBits(int n) {
        // Built-in function to count set bits: __builtin_popcount(n)
        int cnt = 0;
        while (n > 0) {
            n &= (n - 1); // Brian Kernighan’s Algorithm: faster way to clear bits
            cnt++;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int countA = countBits(a);
            int countB = countBits(b);
            
            // If bit counts are equal, sort numerically
            if (countA == countB) return a < b;
            // Otherwise, sort by bit count
            return countA < countB;
        });
        return arr;
    }
};