class Solution {
public:
    int longestPalindrome(string s)
    {
        vector<int> mp(52,0);

        for(char ch : s)
        {
            if(ch >= 'A' and ch<= 'Z')
            {
                mp[ch - 'A']++;
            }
            else
            {
                mp[ch - 'a' + 26]++;
            }
        }

        int ans = 0;


        for(int i = 0 ; i <52 ; i++)
        {
            if(mp[i] %2 ==0)
            {
                ans += mp[i];
            }
            else
            {
                int element = (mp[i]-1);
                ans += element;
            }
        }

        for(int i = 0 ; i<52 ;i++)
        {
            if(mp[i] %2 != 0)
            {
                ans++;
                break;
            }
        }

        return ans;
   
    }
};