class Solution {
    public int minimumDifference(int[] nums, int k)
    {
        if (k <= 1) return 0;
        
        Arrays.sort(nums);
        int minDiff = (int) 1e7;
        
        for (int i = 0; i <= nums.length - k; i++)
        {
            minDiff = Math.min(minDiff, nums[i + k - 1] - nums[i]);
        }
        
        return minDiff;
    }
}