class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes)
    {

        int window = 0 ;
        int max_window = 0;

        int satisfied = 0;

        int l = 0;

        for(int r = 0;r<grumpy.length ; r++)
        {
            if(grumpy[r] == 1)
            {
                window += customers[r];
            }
            else
            {
                satisfied += customers[r];
            }

            if((r-l+1) > minutes)
            {
                
                if(grumpy[l] == 1)
                {
                    window -= customers[l];
                }
                l++;
                
            }
            max_window = Math.max(window,max_window);

        }

        return satisfied + max_window;
        
    }
}