class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        
        
        sort(a.begin(),a.end());
        
        int mini  =  2e7;
        
        
        for(int i = 0;i<= a.size() - m ;i++)
        {
            if(a[i+m-1] - a[i] < mini)
                mini  = a[i+m-1] - a[i];
            
        }
        
        return mini;
        // code here
        
    }
};