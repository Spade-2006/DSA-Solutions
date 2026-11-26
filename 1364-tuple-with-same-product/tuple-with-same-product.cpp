class Solution {
public:
    int tupleSameProduct(vector<int>& nums)
    {

        int count = 0;
        unordered_map<int , vector<pair<int,int>>> mp;

        for(int i = 0;i<nums.size();i++)
        {
            for(int j = i+1;j<nums.size();j++)
            {
                int prod = nums[i]*nums[j];
                mp[prod].push_back({nums[i],nums[j]});
            }
        }

        for(auto i : mp)
        {
            int p = i.first;
            vector<pair<int,int>> v = i.second;

            if(v.size() > 1)
            {
                count += ((v.size() * (v.size()-1))/2) * 8;
            }
        }

        return count;

        
    }
};