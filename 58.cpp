#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        
        int n = arr.size();
        // Maps prefix sum to its frequency of occurrence
        unordered_map<int, int> prevSum;
    
        int count = 0;
        int curr_sum = 0;
    
        for (int i = 0; i < n; i++) {
            curr_sum += arr[i];
    
            // If prefix sum is 0, we found one subarray starting from index 0
            if (curr_sum == 0) {
                count++;
            }
    
            // If curr_sum has been seen before, it means there are subarrays
            // with 0 sum between the previous occurrences and current index
            if (prevSum.find(curr_sum) != prevSum.end()) {
                count += prevSum[curr_sum];
            }
    
            // Increment frequency of the current prefix sum
            prevSum[curr_sum]++;
        }

        return count;
        
        // code here.
    }
};