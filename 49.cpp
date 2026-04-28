#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // Use long long to avoid integer overflow, matching the Java (long) cast
                    long long acquiredNum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (acquiredNum < target) {
                        left++;
                    } else if (acquiredNum > target) {
                        right--;
                    } else {
                        answer.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for the third number
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for the fourth number
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                }
            }
        }
        return answer;
    }
};