class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string>week = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

        int days = 0;

        for(int y = 1971; y < year; y++){
            if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
            days += 366;
            else
            days += 365;
        }
         int m[] = {31,28,31,30,31,30,31,31,30,31,30,31};

         if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
         m[1] = 29;

         for(int i = 0; i < month - 1; i++)
         days += m[i];

         days += day - 1;

         return week[(days + 5) % 7];
    }
};