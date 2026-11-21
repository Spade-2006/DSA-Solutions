class Solution {
    public int minimumRecolors(String blocks, int k)
    {
        int n = blocks.length();

        int ans = (int) 1e7;

        int i = 0 , j = 0;

        int c = 0;
        while(j<n)
        {
            if(blocks.charAt(j) == 'W')
                c++;

            j++;
            

            if((j-i) == k)
            {
                ans = Math.min(ans,c);
                
                if(blocks.charAt(i) == 'W')
                {
                    c--;
                    i++;
                }
                else
                {
                    i++;
                }

            }
        }

        return ans;
        
    }
}