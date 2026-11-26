import java.time.LocalTime;
import java.time.temporal.ChronoUnit;

class Solution 
{
    public int findMinDifference(List<String> timePoints) 
    {
        if (timePoints.size() > 1445) 
        {
            return 0;
        }

        List<LocalTime> times = new ArrayList<>();
        for (String tp : timePoints) 
        {
            times.add(LocalTime.parse(tp));
        }

        Collections.sort(times);

        int minDiff = Integer.MAX_VALUE;

        for (int i = 1; i < times.size(); i++) 
        {
            int diff = (int) ChronoUnit.MINUTES.between(times.get(i - 1), times.get(i));
            minDiff = Math.min(minDiff, diff);
        }

        int wrapAround = (int) (1440 - ChronoUnit.MINUTES.between(times.get(0), times.get(times.size()-1 )));
        minDiff = Math.min(minDiff, wrapAround);

        return minDiff;
    }
}