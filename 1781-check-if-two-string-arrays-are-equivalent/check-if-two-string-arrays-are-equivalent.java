class Solution
{
    public boolean arrayStringsAreEqual(String[] word1, String[] word2)
    {
        String s1 = "" , s2 = "";


        for(String s : word1)
        {
            for(char c : s.toCharArray())
            {
                s1+=c;
            }
        }
        for(String s : word2)
        {
            for(char c : s.toCharArray())
            {
                s2+=c;
            }
        }

        return (s1.equals(s2));
        
    }
}