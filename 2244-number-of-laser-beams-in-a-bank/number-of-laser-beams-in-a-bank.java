class Solution {
    public int numberOfBeams(String[] bank)
    {
        int ans = 0;

        int prev = 0;
        int curr = 0;

        for(String s : bank)
        {
            for(char c : s.toCharArray())
            {
                if(c == '1')
                {
                    curr++;
                }
            }
            if(curr == 0)
                continue;
            int temp = curr*prev;
            prev = curr;
            curr = 0;

            ans += temp;
            
        }

        return ans;
        
    }
}