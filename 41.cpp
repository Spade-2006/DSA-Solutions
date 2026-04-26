#include <bits/stdc++.h>
class Solution {
  public:
    vector<string> findPermutation(string &s) {
        
        vector<string> result;
        
        sort(s.begin(), s.end()); // Must be sorted first
        do {
            result.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
        
        return result;
                // Code here there
    }
};
