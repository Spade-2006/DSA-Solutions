class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int key) {
        int n = arr.size();
        int first = -1, last = -1;

        // First Occurrence
        int s = 0, e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == key) {
                first = mid;
                e = mid - 1;
            }
            else if (arr[mid] < key) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        // Last Occurrence
        s = 0, e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == key) {
                last = mid;
                s = mid + 1;
            }
            else if (arr[mid] < key) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return {first, last};
    }
};
