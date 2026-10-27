class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int evenIdx = 0;
        int oddIdx = 1;

        for (int x : nums) {
            if (x % 2 == 0) {
                result[evenIdx] = x;
                evenIdx += 2;
            } else {
                result[oddIdx] = x;
                oddIdx += 2;
            }
        }

        return result;
    }
};