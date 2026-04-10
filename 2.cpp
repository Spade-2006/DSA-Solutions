// Description :
// Given an array arr[].
//  Your task is to find the minimum and maximum elements in the array.


//Approach :


//  Approach: Linear Scan
//     Logic:
//     1.  Initialize two variables: mini and maxi with the first element of the array.
//     2.  Traverse the array from the second element to the end.
//     3.  For each element, **update** mini if the element is smaller and maxi if it is larger.
//     4.  Return the pair `(mini, maxi).

// Time Complexity ($TC$):** $O(n)$ (Single pass through the array)
// Space Complexity ($SC$):** $O(1)$ (Only two variables used)



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