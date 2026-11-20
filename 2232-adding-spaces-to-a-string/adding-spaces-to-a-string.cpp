class Solution {
public:
    string addSpaces(string s, vector<int>& spaces)
    {
        string ans = "";

        for(int i = 0 ; i < spaces.size() ; i++)
        {
            spaces[i] = spaces[i]+i;
        }
        int id = 0;
        int si =0;
        for(int i = 0 ; i < s.length()+spaces.size() ; i++)
        {
            if(id<spaces.size() and i==spaces[id])
            {
                ans+=" ";
                id++;
            }
            else
            {
                ans+=s[si++];

            }
        }

        return ans;

        
        
    }
};