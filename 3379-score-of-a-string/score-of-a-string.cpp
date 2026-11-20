class Solution {
public:
    int scoreOfString(string s)
    {

        int ans = 0;

        for(int i = 0 ; i < s.length()-1 ; i++)
        {
            int curr = s[i];
            int next = s[i+1];

            ans += abs(curr-next);
        }

        return ans;

        
    }
};