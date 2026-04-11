
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        int i = n-1,j=0;
        while(i>j)
        {
            swap(arr[i--],arr[j++]);
            
        }     
    }
};