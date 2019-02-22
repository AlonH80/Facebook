#include "Time.h"

Time::Time(DayTime dTime,Date date) : dTime(dTime),date(date)
{
}

Time::Time() : dTime(DayTime()), date(Date())
{
}

void Time::show() const
{
    this->dTime.show();
    cout << " , ";
    this->date.show();
    cout << endl;
}

Date Time::getDate() const
{
    return this->date;
}

DayTime Time::getDaytime() const
{
    return this->dTime;
}

int Time::compareTime(const Time other) const
{
    // This function return -1 if the operating object is "bigger" (after) other parameter,
    // returns 1 if other is after the operating object, 0 if they are equal.
    int dateCompare=this->date.compareDate(other.getDate());
    if (dateCompare!=0)
        return dateCompare;
    else
        return this->dTime.compareDayTime(other.getDaytime());
}
