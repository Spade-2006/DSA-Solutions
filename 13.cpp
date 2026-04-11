class Solution {
public:
    int findpivot(vector<int>& nums) {
        // Look for the first DIP from the right
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) // Changed > to <
                return i;
        }
        return -1;
    }

    // Pass by reference (&) to modify the original vector
    void rev(vector<int>& nums, int start, int end) {
        while(start < end) {
            swap(nums[start++], nums[end--]);
        }
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        int pivot = findpivot(nums);

        if(pivot == -1) {
            rev(nums, 0, n);
            return;
        }

        // Instead of upper_bound (which needs sorted), scan from right
        // Find the smallest number in suffix larger than nums[pivot]
        int nextGreater = -1;
        for (int i = n; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                nextGreater = i;
                break;
            }
        }

        swap(nums[pivot], nums[nextGreater]);
        rev(nums, pivot + 1, n);
    }
};