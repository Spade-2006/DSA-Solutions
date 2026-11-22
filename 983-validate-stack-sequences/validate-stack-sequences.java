class Solution
{
    public boolean validateStackSequences(int[] pushed, int[] popped)
    {
        Stack<Integer> st = new Stack<>();

        int i = 0; 
        int j = 0;

        int n1 = pushed.length;
        int n2 = popped.length;

        while (j < n2)
        {
            if (st.isEmpty())
            {
                if (i == n1) break;
                st.push(pushed[i]);
                i++;
            }
            else
            {
                if (st.peek() == popped[j])
                {
                    st.pop();
                    j++;
                }
                else
                {
                    if (i == n1) break;
                    st.push(pushed[i]);
                    i++;
                }
            }
        }

        return (i == n1) && (j == n2);
    }
}