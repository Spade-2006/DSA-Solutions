class Solution {
public:
    int dayOfYear(string date) {
        vector<int> days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,7));
        int d = stoi(date.substr(8,9));
        int total = 0;
        if ((y % 400 == 0 && m > 2) || (y % 4 == 0 && y % 100 != 0 && m > 2)) 
        {
            return  days[m-1] + d + 1;
        }
        return days[m-1] + d;
    }
};