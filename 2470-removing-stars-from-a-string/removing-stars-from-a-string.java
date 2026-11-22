class Solution {
    public String removeStars(String s)
    {
        StringBuilder sb = new StringBuilder();

        Stack<Character> st = new Stack<>();

        for(char c : s.toCharArray())
        {
            if(!st.isEmpty() && c == '*')
                st.pop();
            else
                st.push(c);
        }

        while(!st.empty())
        {
            char c = st.peek();
            st.pop();
            sb.append(c);
        }

        sb.reverse();

        return sb.toString();
        
    }
}