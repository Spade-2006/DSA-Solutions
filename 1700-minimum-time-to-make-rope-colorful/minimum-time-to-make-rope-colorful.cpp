class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int ans = 0;

        int i = 0 , j = 1;

        while(i<colors.length() and j < colors.length())
        {
            if(colors[i] == colors[j])
            {
                ans+=min(neededTime[i],neededTime[j]);

                if(neededTime[i] > neededTime[j])
                {
                    j++;
                }
                else
                {
                    i=j;
                    j++;
                }   
            }

            else
            {
                i=j;
                j++;
            }
        }

        return ans;
        
    }
};