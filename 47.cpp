
class Solution {
    private:

    int search(vector<int>& arr, int target,int start , int end) {

        int mid = start + (end-start)/2;
        while(start <= end)
        {
            if(arr[mid]==target)
                return mid;
            if(arr[mid]>target)
                end = mid-1;
            else
                start = mid+1;
            mid = start + (end-start)/2;
        }
        return -1;
    }
    
    int findMin(vector<int>& arr) {
        int s = 0 , e = arr.size()-1;
        while(s<e)
        {
            int mid = s + (e-s)/2;
            if(arr[mid] > arr[e])
            s = mid+1;
            else
            e = mid;      
        }   
        return e;        
    }


public:

    int search(vector<int>& nums, int target) {
    int pivot = findMin(nums);
    int ans;

    if(target >= nums[pivot] && target <= nums[nums.size()-1])
    {
        ans = search(nums,target,pivot,nums.size()-1);
    }
    else
    {
        ans = search(nums,target,0,pivot-1);
    }

    return ans;

        
    }
};