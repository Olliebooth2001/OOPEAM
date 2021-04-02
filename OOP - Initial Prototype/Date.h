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


	void GetCurrentDate();
	std::string GetDate();

private:
	int day;
	int month;
	int year;

};