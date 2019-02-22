#pragma warning (disable:4996)
// Disable warnings: localtime unsafe, strcpy unsafe
#ifndef _DATE_H
#define _DATE_H
#include <iostream>
#include <ctime>
using namespace std;

const int MIN_YEAR=1000;
bool isLeapYear(int year);
int calculateDaysInMonth(int month,int year);

class Date
{
private:
	int year;
	int month;
	int day;
    const int UNKNOWN=0;
public:
    friend bool isLeapYear(int year);
    friend int calculateDaysInMonth(int month,int year);
	Date(int,int,int);
    Date();
    bool isValidDate() const;
    bool isValidYear() const {return year!=UNKNOWN;}
    bool isValidMonth() const {return month!=UNKNOWN;}
    bool isValidDay() const {return day!=UNKNOWN;}
	void show() const;
    bool setYear(int year);
    bool setMonth(int month);
    bool setDay(int day);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int compareDate(const Date) const;
};

#endif
			
