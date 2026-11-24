class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        solve(0, nums, ans, new ArrayList<>());
        return ans;
    }

    void solve(int i, int[] num, List<List<Integer>> ans, List<Integer> curr) {
        if (i == num.length) {
            ans.add(new ArrayList<>(curr));
            return;
        }

       
        curr.add(num[i]);
        solve(i + 1, num, ans, curr);
        curr.remove(curr.size() - 1);

        while (i + 1 < num.length && num[i] == num[i + 1]) {
            i++;
        }
        solve(i + 1, num, ans, curr);
    }
}