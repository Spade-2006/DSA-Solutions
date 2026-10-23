class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {   
        int c=0;
        solve(nums , target , 0 , c );
        return c;
    }

    void solve(vector<int> &nums ,  int target ,int i , int &c)
    {
        if(i == nums.size() and target==0)
        {
            c=c+1;
            return;
        }
        if(i>=nums.size())
            return ;

        
        solve(nums , target-nums[i] , i+1 , c);
        solve(nums , target+nums[i] , i+1 , c);

        

    }
};