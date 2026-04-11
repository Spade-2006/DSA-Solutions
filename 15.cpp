class Solution {
  public:
    int mergeAndCount(vector<int> &arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        
        vector<int> left(n1), right(n2);
        for (int i = 0; i < n1; i++) left[i] = arr[l + i];
        for (int i = 0; i < n2; i++) right[i] = arr[m + 1 + i];

        int count = 0;
        int i = 0, j = 0, k = l;
        
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                count += (n1 - i); 
            }
        }
        
        while (i < n1) arr[k++] = left[i++];
        while (j < n2) arr[k++] = right[j++];
        
        return count;
    }

    int solve(vector<int> &arr, int l, int r) {
        int count = 0;
        if (l < r) {
            int m = l + (r - l) / 2;
            count += solve(arr, l, m);
            count += solve(arr, m + 1, r);
            count += mergeAndCount(arr, l, m, r);
        }
        return count;
    }

    int inversionCount(vector<int> &arr) {
        return solve(arr, 0, arr.size() - 1);
    }
};