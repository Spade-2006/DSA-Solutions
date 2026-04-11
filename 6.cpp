class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(int i = 0;i<nums1.size();i++)
        {
        
        for(int j = 0;j<nums2.size();j++){
            if(nums2[j]==nums1[i])
                s.insert(nums2[j]);
        }
        }

        vector<int> sol;
        for(auto i : s)
            sol.push_back(i);

        return sol;
        
    }
};