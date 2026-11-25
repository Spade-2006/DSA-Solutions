class Solution {
    public int buyChoco(int[] arr, int money)
    {
        Arrays.sort(arr);

        if((arr[0] + arr[1]) <= money)
        {
            int sum = arr[0] + arr[1];
            return money-sum;
        }

        return money;
        
    }
}