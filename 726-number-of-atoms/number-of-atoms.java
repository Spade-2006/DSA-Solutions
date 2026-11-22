class Solution
{
    public String countOfAtoms(String formula)
    {
        Map<String, Integer> mp = new TreeMap<>();

        Stack<String> st = new Stack<>();

        StringBuilder sb = new StringBuilder();

        int i = 0;

        int nonu = formula.length();

        while (i < nonu)
        {
            if (formula.charAt(i) == '(')
            {
                st.push("(");
                i++;
            }
            else if (formula.charAt(i) == ')')
            {
                i++;
                int n = 0;
                while (i < nonu && Character.isDigit(formula.charAt(i)))
                {
                    n = n * 10 + (formula.charAt(i) - '0');
                    i++;
                }
                if (n == 0)
                    n = 1;

                Stack<String> tempSt = new Stack<>();
                while (!st.isEmpty() && !st.peek().equals("("))
                {
                    String ch = st.peek();
                    st.pop();
                    String[] parts = ch.split(":");
                    int newCount = Integer.parseInt(parts[1]) * n;
                    tempSt.push(parts[0] + ":" + newCount);
                }
                if (!st.isEmpty())
                {
                    st.pop();
                }
                while (!tempSt.isEmpty())
                {
                    st.push(tempSt.peek());
                    tempSt.pop();
                }
            }
            else
            {
                int start = i;
                i++;
                while (i < nonu && Character.isLowerCase(formula.charAt(i)))
                {
                    i++;
                }
                String temp = formula.substring(start, i);

                int n = 0;
                while (i < nonu && Character.isDigit(formula.charAt(i)))
                {
                    n = n * 10 + (formula.charAt(i) - '0');
                    i++;
                }
                if (n == 0)
                    n = 1;

                if (st.isEmpty())
                {
                    if (mp.containsKey(temp))
                    {
                        mp.put(temp, mp.get(temp) + n);
                    }
                    else
                    {
                        mp.put(temp, n);
                    }
                }
                else
                {
                    st.push(temp + ":" + n);
                }
            }
        }

        while (!st.isEmpty())
        {
            String ch = st.peek();
            st.pop();
            String[] parts = ch.split(":");
            String atom = parts[0];
            int cnt = Integer.parseInt(parts[1]);

            if (mp.containsKey(atom))
            {
                mp.put(atom, mp.get(atom) + cnt);
            }
            else
            {
                mp.put(atom, cnt);
            }
        }

        for (Map.Entry<String, Integer> entry : mp.entrySet())
        {
            String key = entry.getKey();
            int val = entry.getValue();

            sb.append(key);
            if (val > 1)
            {
                sb.append(val);
            }
        }

        return sb.toString();
    }
}