#pragma once

using namespace std;

namespace LeosTools
{
    struct Time
    {
    public:
        string Milliseconds;
        string Seconds;
        string Minutes;
        string Hours;
        string Day;
        string Month;
        string Year;
        string DayOfWeek;

        int MillisecondsInt;
        int SecondsInt;
        int MinutesInt;
        int HoursInt;
        int DayInt;
        int MonthInt;
        int YearInt;
        int DayOfWeekInt;

        Time(bool utc);

        ~Time();
    };
}