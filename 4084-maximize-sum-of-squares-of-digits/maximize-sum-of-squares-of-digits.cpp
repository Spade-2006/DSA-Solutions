class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        string ans = "";

        if(sum > num * 9){
            return "";
        }

        while(num > 0){
            if(sum > 9){
            ans += "9";
            sum-=9;
            }else{
                ans += '0' + sum;
                sum = 0;
            }
            num--;
        }

        return ans;
    }
};