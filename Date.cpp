#include "Date.h"

Date::Date(int day,int month,int year)
{
    // Year: full year - 1991 and not 91 for example
    if (year>=MIN_YEAR)
        this->year=year;
    else
        this->year=UNKNOWN;
    
    if (month>=1 && month<=12)
        this->month=month;
    else
        this->month=UNKNOWN;
    
    if (day>=1 && day<=calculateDaysInMonth(this->month,this->year))
        this->day=day;
    else
        this->day=UNKNOWN;

}

Date::Date()
{
    time_t currTime;
    time(&currTime); // Get current time
	struct tm* currTimeStruct = localtime(&currTime); // Get time as structure
    this->month=currTimeStruct->tm_mon+1;
    this->day=currTimeStruct->tm_mday;
    this->year=currTimeStruct->tm_year+1900;
}

bool isLeapYear(int year)
{
    // This function returns true if year is a leap year.
    if (year%4==0){
        if (year%100==0){
            if (year%400==0)
                return true;
            else
                return false;
        }
        return true;
    }
    return false;
}

int calculateDaysInMonth(int month,int year)
{
    // This function returns the number of days in a month.
    if (month<1 || month>12)
        return 0;   // UNKNONWN=0
    if (month<7){
        if (month==2)
            return (isLeapYear(year)? 29:28);
        else if (month%2==0)
            return 30;
        else
            return 31;
    }
    else{
        if (month%2==0)
            return 31;
        else
            return 30;
    }
}

void Date::show() const
{
    // This function prints the date in format dd/mm/yyyy.
    if (this->day!=UNKNOWN && this->month!=UNKNOWN)
        cout << this->day << "/" << this->month << "/";
    cout << this->year;
}

int Date::getYear() const
{
    return this->year;
}

int Date::getMonth() const
{
    return this->month;
}

int Date::getDay() const
{
    return this->day;
}

int Date::compareDate(const Date dte) const
{
    // This function return -1 if the operating object is "bigger" (after) dte parameter,
    // returns 1 if dte is after the operating object, 0 if they are equal.
    if (this->year > dte.getYear()){
        return 1;
    }
    else if(this->year < dte.getYear())
        return -1;
    else{
        if (this->month > dte.getMonth())
            return 1;
        else if (this->month < dte.getMonth())
            return -1;
        else {
            if (this->day > dte.getDay())
                return 1;
            else if (this->day < dte.getDay())
                return -1;
            else
                return 0;
        }
    }
}

bool Date::isValidDate() const
{
    return isValidDay() && isValidMonth() && isValidYear();
}

bool Date::setYear(int year)
{
    if(!isValidYear())
    {
        if (year>=MIN_YEAR)
        {
            this->year=year;
            return true;
        }
        this->year=UNKNOWN;
        return false;
    }
    else{
        cout << "Can't change previous setted year." << endl;
        return true;
    }
}

bool Date::setMonth(int month)
{
    if(!isValidMonth())
    {
        if (month<1||month>12)
        {
            this->month=UNKNOWN;
            return false;
        }
        this->month=month;
        return true;
    }
    else{
        cout << "Can't change previous setted month." << endl;
        return true;
    }
}

bool Date::setDay(int day)
{
    if (!isValidDay())
    {
        int daysInMonth=calculateDaysInMonth(this->month, this->year);
        if (day<1 || day>daysInMonth)
        {
            this->day=UNKNOWN;
            return false;
        }
        this->day=day;
        return true;
    }
    else{
        cout << "Can't change previous setted day." << endl;
        return true;
    }
}
