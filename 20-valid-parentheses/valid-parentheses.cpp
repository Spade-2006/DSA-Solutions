class Solution {
public:
    bool isValid(string s) {

        if(s.length()<2)
            return false;

        stack<char> st;
        for(char i : s)
        {
            if(i=='(' or i=='{' or i=='[')
            {
                st.push(i);
            }

            else
            {
                if(st.size()==0)
                    return false;
                char top = st.top();
                st.pop();

                if(i == ')')
                {
                    if(top!='(')
                        return false;

                }
                else if(i=='}')
                {

                    if(top!='{')
                        return false;

                }
                else
                {

                    if(top!='[')
                        return false;

                }
            }
        }

        return st.empty();;
        
    }
};