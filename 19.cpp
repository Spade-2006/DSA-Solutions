
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prevSum;
        int count = 0;
        int currSum = 0;

        // Base case: a prefix sum of 0 has occurred once 
        // (handles subarrays starting from index 0)
        prevSum[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            // If (currSum - k) exists in our map, it means 
            // there are subarrays ending here that sum to k
            if (prevSum.find(currSum - k) != prevSum.end()) {
                count += prevSum[currSum - k];
            }

            // Update the frequency of the current prefix sum in the map
            prevSum[currSum]++;
        }

        return count;
    }
};