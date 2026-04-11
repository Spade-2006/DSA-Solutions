class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {

        int n = nums.size();

        sort(nums.begin(),nums.end());

    

        int diff = nums[n-1] - nums[0];

        int smol = nums[0]+k;
        int large = nums[n-1]-k;

        for(int i = 0;i<n-1;i++)
        {
            int maxi = max(nums[i]+k,large) , mini = min(nums[i+1]-k,smol);
            diff = min(diff,maxi-mini);      
        }

        return diff;

        
    }
};