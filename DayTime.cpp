#include "DayTime.h"


DayTime::DayTime(int hours,int minutes)
{
    this->minutes=minutes%60;
    this->hours=(hours+minutes/60)%24;
}

DayTime::DayTime()
{
    time_t currTime;
    time(&currTime); // Get current time
	struct tm* currTimeStruct = localtime(&currTime); // Get time as structure
    this->hours=currTimeStruct->tm_hour;
    this->minutes=currTimeStruct->tm_min;
}

void DayTime::show() const
{
    // Show time in format HH:MM
    cout << (this->hours<10 ? "0":"") << this->hours << ":" <<  (this->minutes<10 ? "0":"") <<this->minutes;
}

int DayTime::getHours() const
{
    return this->hours;
}

int DayTime::getMinutes() const
{
    return this->minutes;
}

int DayTime::compareDayTime(const DayTime dtime) const
{
    // This function return -1 if the operating object is "bigger" (after) dtime parameter,
    // returns 1 if dtime is after the operating object, 0 if they are equal.
    if (this->hours > dtime.getHours())
        return -1;
    else if (this->hours < dtime.getHours())
        return 1;
    else{
        if (this->minutes > dtime.getMinutes())
            return -1;
        else if (this->minutes < dtime.getMinutes())
            return 1;
        else
            return 0;
    }
}

