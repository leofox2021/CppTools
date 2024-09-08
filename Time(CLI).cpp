#include <filesystem>
#include <windows.h>
#include "Tools.h"
#include "Time.h"

using namespace std;

LeosTools::Time::Time(bool utc = false)
{
    SYSTEMTIME time;

    if (utc)
        GetSystemTime(&time);
    else
        GetLocalTime(&time);

    // Convert from WORD to string
    this->Milliseconds = to_string(time.wMilliseconds);
    this->Seconds = to_string(time.wSecond);
    this->Minutes = to_string(time.wMinute);
    this->Hours = to_string(time.wHour);
    this->Day = to_string(time.wDay);
    this->Month = to_string(time.wMonth);
    this->Year = to_string(time.wYear);
    this->DayOfWeek = to_string(time.wDayOfWeek);

    // Create ints
    this->MillisecondsInt = stoi(this->Milliseconds);
    this->SecondsInt = stoi(this->Seconds);
    this->MinutesInt = stoi(this->Minutes);
    this->HoursInt = stoi(this->Hours);
    this->DayInt = stoi(this->Day);
    this->MonthInt = stoi(this->Month);
    this->YearInt = stoi(this->Year);
    this->DayOfWeekInt = stoi(this->DayOfWeek);

    // Fix digit formatting
    if (this->Milliseconds.size() == 1)
        Tools::FixDigitFormat(2, this->Milliseconds);
    if (this->Milliseconds.size() == 2)
        Tools::FixDigitFormat(1, this->Milliseconds);

    if (this->Seconds.size() == 1)
        Tools::FixDigitFormat(1, this->Seconds);

    if (this->Minutes.size() == 1)
        Tools::FixDigitFormat(1, this->Minutes);

    if (this->Hours.size() == 1)
        Tools::FixDigitFormat(1, this->Hours);

    if (this->Day.size() == 1)
        Tools::FixDigitFormat(1, this->Day);

    // Fix string month names
    switch (this->MonthInt)
    {
    case 1:
        this->Month = "January";
        break;
        
    case 2:
        this->Month = "February";
        break;

    case 3:
        this->Month = "March";
        break;

    case 4:
        this->Month = "April";
        break;

    case 5:
        this->Month = "May";
        break;

    case 6:
        this->Month = "June";
        break;

    case 7:
        this->Month = "July";
        break;

    case 8:
        this->Month = "August";
        break;

    case 9:
        this->Month = "September";
        break;

    case 10:
        this->Month = "October";
        break;

    case 11:
        this->Month = "November";
        break;

    case 12:
        this->Month = "December";
        break;
        
    default:
        this->Month = "None";
        break;
    }

    // Fix string day of week names
    switch (this->DayOfWeekInt)
    {
    case 1:
        this->DayOfWeek = "Monday";
        break;

    case 2:
        this->DayOfWeek = "Tuesday";
        break;
        
    case 3:
        this->DayOfWeek = "Wednesday";
        break;

    case 4:
        this->DayOfWeek = "Thursday";
        break;

    case 5:
        this->DayOfWeek = "Friday";
        break;

    case 6:
        this->DayOfWeek = "Saturday";
        break;

    case 7:
        this->DayOfWeek = "Sunday";
        break;

    default:
        this->DayOfWeek = "None";
        break;
    }
}

LeosTools::Time::~Time() = default;