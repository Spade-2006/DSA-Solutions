class Solution {
public:
    bool checkString(string s) {
        
        bool B = false;

        for(auto ch: s) {

            if(ch == 'a' && B) return false;

            if(ch == 'b') B = true;
        }

        return true;
    }
};