#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void findCommonElements(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m == 0) return;
    int n = matrix[0].size();

    unordered_map<int, int> mp;

    // 1. Initialize map with elements from the first row
    // We set the count to 1 for all distinct elements in row 0
    for (int j = 0; j < n; j++) {
        mp[matrix[0][j]] = 1;
    }

    // 2. Traverse the rest of the matrix
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int currentVal = matrix[i][j];

            // If element is present in the map and its count 
            // is equal to the current row index 'i'
            if (mp.find(currentVal) != mp.end() && mp[currentVal] == i) {
                // Increment count to indicate it's found in this row too
                mp[currentVal] = i + 1;

                // If we are at the last row, this element is common to all
                if (i == m - 1) {
                    cout << currentVal << " ";
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9}
    };

    cout << "Common elements are: ";
    findCommonElements(matrix);
    cout << endl;

    return 0;
}