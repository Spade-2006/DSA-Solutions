class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st1;
        stack<char> st2;


        for(char c : s)
        {
            if(!st1.empty() and c == '#')
                st1.pop();

            else
            {
                if(c=='#')
                    continue;
                st1.push(c);
            }
        }
        for(char c : t)
        {
            if(!st2.empty() and c == '#')
                st2.pop();

            else
            {
                if(c=='#')
                    continue;
                st2.push(c);
            }
        }

        while(!st1.empty() and !st2.empty())
        {
            if(st1.top() != st2.top())
            {
                return false;
            }
            st1.pop();
            st2.pop();
        }

        if(!st1.empty() or !st2.empty())
            return false;

        return true;
    }
};