class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int left = 0, right = 0, sum = nums[0];
        // Start mini at n+1 so we can tell if it was never updated
        int mini = n + 1; 
        int window = 1;

        do {
            if (sum >= target) {
                // Record mini only when the condition is actually met
                mini = min(mini, window);
                
                // Shrink window
                sum -= nums[left];
                left++;
                window--;
            } 
            else if (right < n - 1) {
                // Expand window
                right++;
                sum += nums[right];
                window++;
            } 
            else {
                // We reached the end and sum is too small
                break;
            }
        // Loop as long as left hasn't passed right, or we haven't exhausted the array
        } while (left < n);

        return (mini > n) ? 0 : mini;
    }
};