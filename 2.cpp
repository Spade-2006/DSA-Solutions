
class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        
        int n = arr.size();
        int max,mini;
        max = mini = arr[0];
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>max)
                max = arr[i];
            if(arr[i]<mini)
                mini = arr[i];
        }
        
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(max);
        
        return ans;
        
    }
};