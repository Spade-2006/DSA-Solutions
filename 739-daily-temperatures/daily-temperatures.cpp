class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp)
    {
        vector<int> ans(temp.size() , 0);
        stack<int> st;
        for(int i = temp.size()-1 ; i>=0 ; i--)
        {
            while(!st.empty() and temp[i]>=temp[st.top()])
                st.pop();
            if(!st.empty())
                ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};