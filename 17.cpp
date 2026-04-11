#include<unordered_map>

class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        
        unordered_map<int,int> m;
        
        
        for(int i=0;i<arr1.size();i++)
        {
            if(i!=0 && arr1[i] == arr1[i-1])
                continue;
                
            if(m.count(arr1[i]))
                m[arr1[i]]++;
            
            else
            m[arr1[i]] = 1;
        }
        
        for(int i=0;i<arr2.size();i++)
        {
            if(i!=0 && arr2[i] == arr2[i-1])
                continue;
                
            if(m.count(arr2[i]))
                m[arr2[i]]++;
            
            else
            m[arr2[i]] = 1;
        }
        
        
        for(int i=0;i<arr3.size();i++)
        {
            if(i!=0 && arr3[i] == arr3[i-1])
                continue;
                
            if(m.count(arr3[i]))
                m[arr3[i]]++;
            
            else
            m[arr3[i]] = 1;
        }
        
        
        vector<int> ans;
        
        for (auto const& [number, frequency] : m) {
            if (frequency == 3) {
                ans.push_back(number);
            }
        }
        
        sort(ans.begin(),ans.end());
        if(ans.empty())
        {
            return {-1};
        }
        else
            return ans;
        
        
        
    }
};