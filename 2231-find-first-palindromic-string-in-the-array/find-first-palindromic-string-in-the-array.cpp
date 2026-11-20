class Solution {
public:

    bool ispalindromic(string s)
    {
        int i = 0;
        int j = s.length()-1;

        while(i<j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words)
    {

        for(string s : words)
        {
            if(ispalindromic(s))
                return s;

        }


        return "";
        
    }
};