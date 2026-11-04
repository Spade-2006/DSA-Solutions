class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<int,vector<char>> mp;
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};

        vector<string> ans;
        string curr = "";
        solve(digits , mp , ans , curr,0,0);
        return ans;
        
    }

    void solve(string digits , unordered_map<int,vector<char>> &mp,vector<string> &ans , string &curr , int i ,  int vi)
    {
        if (i == digits.length()) {
            ans.push_back(curr);
            return;
        }

        int digit = digits[i] - '0';

        if (vi >= mp[digit].size()) {
            return;
        }

        
        curr.push_back(mp[digit][vi]);
        solve(digits , mp , ans , curr , i+1 , 0);
        curr.pop_back();
        solve(digits , mp , ans , curr , i , vi+1);

    }
};