#ifndef _TIME_H
#define _TIME_H
#include "Date.h"
#include "DayTime.h"


class Time
{
private:
	DayTime dTime;
	Date date;
public:
	Time(DayTime,Date);
    Time();
	void show() const;
	Date getDate() const;
    DayTime getDaytime() const;
    int compareTime(const Time) const;
};

#endif
