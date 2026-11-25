class Solution {
    public String maximumOddBinaryNumber(String s) {
        int once = 0;

        for (char c : s.toCharArray()) {
            if (c == '1') {
                once++;
            }
        }

        int zeros = s.length() - once;
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < once - 1; i++) {
            ans.append('1');
        }

        for (int i = 0; i < zeros; i++) {
            ans.append('0');
        }

        ans.append('1');

        return ans.toString();
    }
}