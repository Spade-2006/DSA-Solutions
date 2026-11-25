class Solution {
    public int minMovesToSeat(int[] seats, int[] students)
    {
        Arrays.sort(seats);
        Arrays.sort(students);


        int ans = 0;

        for(int i = 0;i< seats.length ; i++)
        {
            int temp = Math.abs(seats[i] - students[i]);
            ans += temp;
        }

        return ans;
        
    }
}