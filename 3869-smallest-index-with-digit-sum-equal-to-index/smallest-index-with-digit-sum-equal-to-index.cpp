class Solution {
public:
    int sum(int a)
    {
        int sum = 0;
        while(a>0)
        {
            int digit = a%10;
            sum += digit;
            a/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums)
    {
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(i == sum(nums[i]))
                return i;
        }

        return -1;
        
    }
};