class Solution {

public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int currsum = nums[0];
        for(int i=0; i<nums.size(); i++){
            currsum = 0; 
            
        for(int j = i; j<nums.size(); j++){
                currsum =  currsum+nums[j];
                result = max(result,currsum);
        }
        }
        return result;
    }
       
};

        
 