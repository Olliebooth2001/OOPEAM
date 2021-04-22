#pragma once


#include <string>
#include <ctime>
#include <chrono>
#include <time.h>
#include <cmath>



class Date
{
public:
	Date(int, int, int);
	Date();


	Date GetCurrentDate();
	std::string GetDate() const;

private:
	int day;
	int month;
	int year;

};