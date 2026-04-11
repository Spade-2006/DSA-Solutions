#include<unordered_map>
using namespace std;

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        
        unordered_map<int,int> m;
        
        for(int i : a)
        {
            m[i]++;
        }
        
        
        for(auto i : b)
        {
            if(m[i]>0)
                m[i]--;
            else
                return false;
        }
        
        return true;
        
        
        
    }
};