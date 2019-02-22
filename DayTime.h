#pragma warning (disable:4996)
// Disable warnings: localtime unsafe, strcpy unsafe
#ifndef _DAYTIME_H
#define _DAYTIME_H
#include <iostream>
#include <ctime>
using namespace std;

class DayTime
{
private:
	int hours;
	int minutes;
public:
	DayTime(int,int);
    DayTime();
	void show() const;
	int getHours() const;
	int getMinutes() const;
	int compareDayTime(const DayTime) const;
};

#endif
