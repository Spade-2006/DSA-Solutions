class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        
        solve(1, n, curr, k, ans);
        
        return ans;
    }

    public void solve(int i, int n, List<Integer> curr, int k, List<List<Integer>> ans)
    {
        if (k <= 0) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        
        if (i > n) {
            return;
        }

        curr.add(i);
        solve(i + 1, n, curr, k - 1, ans);

        curr.remove(curr.size() - 1);
        solve(i + 1, n, curr, k, ans);
    }
}