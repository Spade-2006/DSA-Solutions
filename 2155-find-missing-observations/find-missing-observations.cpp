class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {

        int sum = 0;

        int m = rolls.size();

        for(int i = 0;i<m;i++)
        {
            sum += rolls[i];
        }

        int number = n+m;

        int avg = mean*number;

        int nsum = avg - sum;


        if((nsum) > (n*6))
            return {};


        if(nsum<n)
        {
            return {};
        }
        vector<int> ans(n,1);

        nsum-= n;

        while(nsum > 0)
        {
            if(nsum >= n)
            {
                for(int i = 0;i<n;i++)
                {
                    ans[i]+=1;
                }
                nsum-=n;
            }
            else
            {
                for(int i = 0;i<n ; i++)
                {
                    int curr = ans[i];
                    int more = 6-curr;

                    if(nsum == more)
                    {
                        ans[i]+=nsum;
                        nsum = 0;
                        break;
                    }
                    else if(nsum < more)
                    {
                        ans[i] += nsum;
                        nsum = 0;
                        break;
                    }
                    else
                    {
                        ans[i] += more;
                        nsum-=more;
                    }
                }
            }
        }


        return ans;

        
        
    }
};