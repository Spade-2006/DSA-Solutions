using namespace std;

class Solution {
    vector<string> concat(vector<string>& a, vector<string>& b) {
        vector<string> res;
        for (string x : a) {
            for (string y : b) {
                res.push_back(x + y);
            }
        }
        return res;
    }

    pair<int, vector<string>> parse(string& s, int i) {
        vector<string> total;
        vector<string> cur = {""};

        while (i < s.size() && s[i] != '}') {
            if (s[i] == '{') {
                auto next = parse(s, i + 1);
                i = next.first;
                cur = concat(cur, next.second);
            } else if (s[i] == ',') {
                total.insert(total.end(), cur.begin(), cur.end());
                cur = {""};
                i++;
            } else {
                string ch(1, s[i]);
                vector<string> single = {ch};
                cur = concat(cur, single);
                i++;
            }
        }

        total.insert(total.end(), cur.begin(), cur.end());
        return {i + 1, total};
    }

public:
    vector<string> braceExpansionII(string expression) {
        auto res = parse(expression, 0).second;
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};