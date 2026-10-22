class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int j = 0; j < k - 1; j++) {
            while (!dq.empty() && nums[dq.back()] <= nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
        }

        for (int i = 0; i <= (int)nums.size() - k; i++) {
            int end = i + k - 1;

            while (!dq.empty() && nums[dq.back()] <= nums[end]) {
                dq.pop_back();
            }
            dq.push_back(end);

            if (!dq.empty() && dq.front() < i) {
                dq.pop_front();
            }

            result.push_back(nums[dq.front()]);
        }

        return result;
    }
};