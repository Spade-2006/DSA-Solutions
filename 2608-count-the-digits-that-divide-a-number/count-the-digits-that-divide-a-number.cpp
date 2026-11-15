class Solution {
public:
    int countDigits(int num)
    {
        int temp = num;
        int c = 0;
        while(temp > 0)
        {
            int digit = temp %10;
            temp /=10;
            if(num%digit == 0)
            {
                c++;
            }
        }

        return c;
        
    }
};