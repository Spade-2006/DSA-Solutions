class Solution {
public:
    bool valid(string& s) {
        int cur = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                cur++;
            } else if (s[i] == ')') {
                cur--;
            }
            if (cur < 0) {
                return false;
            }
        }
        return (cur == 0);
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        if (valid(s)) {
            ans.push_back(s);
            return ans;
        }
        queue<string> q;
        q.push(s);
        bool done = false;
        unordered_set<string> mp;
        while (!q.empty() && !done) {
            int sz = q.size();
            while (sz--) {
                string temp = q.front();
                q.pop();
                for (int j = 0; j < temp.length(); j++) {
                    if (temp[j] != '(' && temp[j] != ')' ||
                        (j > 0 && temp[j] == temp[j - 1])) {
                        continue;
                    }
                    string temp2 = temp;
                    temp2.erase(j, 1);
                    if (!mp.insert(temp2).second) {
                        continue;
                    }
                    if (valid(temp2)) {
                        done = true;
                        ans.push_back(temp2);
                    }
                    if (!done) {
                        q.push(temp2);
                    }
                }
            }
        }
        return ans;
    }
};