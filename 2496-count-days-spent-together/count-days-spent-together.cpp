class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int count = 0;
        for (int m = 1; m <= 12; m++) {
            for (int d = 1; d <= days[m - 1]; d++) {
                string today = (m < 10 ? "0" : "") + to_string(m) + "-" + (d < 10 ? "0" : "") + to_string(d);
                bool alice = arriveAlice <= today && today <= leaveAlice;
                bool bob = arriveBob <= today && today <= leaveBob;
                if (alice && bob) count++;
            }
        }
        return count;
    }
};