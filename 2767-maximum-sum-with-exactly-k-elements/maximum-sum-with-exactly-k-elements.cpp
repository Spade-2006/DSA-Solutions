class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxval = *max_element(nums.begin(), nums.end());
        int ans = (maxval * k);
        k--;
        ans += (k * (k + 1) ) / 2;
        return ans;
    }
};