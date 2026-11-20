class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2)
    {
        vector<vector<int>> ans;


        unordered_map<int,int> mp;

        for(auto k : nums1)
        {
            int id = k[0];
            int val = k[1];
            mp[id] += val;
        }
        for(auto k: nums2)
        {
            int id = k[0];
            int val = k[1];
            mp[id] += val;
        }


        for(auto [id , val] : mp)
        {
            ans.push_back({id,val});
        }

        sort(ans.begin() , ans.end());


        return ans;



        
    }
};