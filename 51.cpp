class Solution {
  public:
    int countTriplets(int s, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            

            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum>=s)
                {
                    
                    k--;
                }
                else
                {
                    ans+=(k-j);
                    j++;
                }
            }
        }

        return ans;
        // code here
        
    }
};