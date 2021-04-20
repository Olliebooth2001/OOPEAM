#include "Date.h"

#include <iostream>


Date::Date(int day, int month, int year)
    : day(day), month(month), year(year)
{

}
Date::Date() {}

Date Date::GetCurrentDate() {

    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    int Month = 1 + newtime.tm_mon;
    int Day = newtime.tm_mday;
    int Year = newtime.tm_year - 100;
    Date date = Date(Day, Month, Year);
    return date;
    //std::cout << Day << " / " << Month << " / " << Year;
}
std::string Date::GetDate() {

    std::string date = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
    return date;

}

