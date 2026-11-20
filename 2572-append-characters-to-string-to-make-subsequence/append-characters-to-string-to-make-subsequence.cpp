class Solution {
public:
    int appendCharacters(string s, string t)
    {
        int len = t.length();

        int i = 0, j = 0;

        while(i<s.length() and j < t.length())
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }

        return len-j;
        
    }
};