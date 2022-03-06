#pragma once
#ifndef CALENDAR_HEADER_H
#define CALENDAR_HEADER_H

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
enum class Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
class DateInterval
{
public:
	DateInterval(int y, int mo, int d, int h, int mi, int s);
	DateInterval(const DateInterval &dateint);
	int DateInt_year() const { return iyear; }
	int DateInt_month() const { return imonth; }
	int DateInt_day() const { return iday; }
	int DateInt_hour() const { return ihour; }
	int DateInt_min() const { return iminute; }
	int DateInt_sec() const { return isec; }
	DateInterval& operator = (const DateInterval &date)
	{
		if (this != &date)
		{
			iyear = date.iyear;
			imonth = date.imonth;
			iday = date.iday;
			ihour = date.ihour;
			iminute = date.iminute;
			isec = date.isec;
		}
		return *this;
	}
	bool operator ==(DateInterval &a2)
	{
		if (
			(iyear == a2.DateInt_year()) &&
			(imonth == a2.DateInt_month()) &&
			(iday == a2.DateInt_day()) &&
			(ihour == a2.DateInt_hour()) &&
			(iminute == a2.DateInt_min()) &&
			(isec == a2.DateInt_sec())
			)
			return true;
		return false;
	}
private:
	int iyear;
	int imonth;
	int iday;
	int ihour;
	int iminute;
	int isec;
};
class Date
{
public:
	Date();
	Date(const Date &date);
	int Date_year() const { return year; }
	Month Date_month() const { return month; }
	int Date_day() const { return day; }
	int Date_hour() const { return hour; }
	int Date_min() const { return minute; }
	int Date_sec() const { return sec; }
	Date(int y, Month m, int d, int h, int min, int s);
	Date(unsigned int y, Month m, unsigned int d);
	Date(unsigned int h, unsigned int m, unsigned int s);
	Date addYears(int add)const;
	Date addMonth(int add)const;
	Date addDays(int add)const;
	Date addHours(int add)const;
	Date addMinutes(int add)const;
	Date addSeconds(int add)const;
	Date& operator = (const Date &date)
	{
		if (this != &date)
		{
			year = date.year;
			month = date.month;
			day = date.day;
			hour = date.hour;
			minute = date.minute;
			sec = date.sec;
		}
		return *this;
	}
	DateInterval getInterval(const Date &another)const;
	Date addInterval(const DateInterval &interv)const;
	Date operator +(const DateInterval &d)const
	{
		Date n_d(year + d.DateInt_year(), static_cast<Month>(static_cast<int>(month) + d.DateInt_month()), 
			day + d.DateInt_day(), hour + d.DateInt_hour(), minute + d.DateInt_min(), sec + d.DateInt_sec());
		return n_d;
	}
	Date operator -(const DateInterval &d)const
	{
		Date n_d(year - d.DateInt_year(), static_cast<Month>(static_cast<int>(month) - d.DateInt_month()),
			day - d.DateInt_day(), hour - d.DateInt_hour(), minute - d.DateInt_min(), sec - d.DateInt_sec());
		return n_d;
	}
	Date operator +=(const DateInterval &d)
	{
		year += d.DateInt_year();
		month = static_cast<Month>(static_cast<int>(month) + d.DateInt_month());
		day += d.DateInt_day();
		hour += d.DateInt_hour();
		minute += d.DateInt_min();
		sec += d.DateInt_sec();
		normalize();
		return (*this);
	}
	Date operator -=(const DateInterval &d)
	{
		year -= d.DateInt_year();
		month = static_cast<Month>(static_cast<int>(month) - d.DateInt_month());
		day -= d.DateInt_day();
		hour -= d.DateInt_hour();
		minute -= d.DateInt_min();
		sec -= d.DateInt_sec();
		normalize();
		return (*this);
	}
	Date& operator ++()
	{
		day += 1;
		normalize();
		return (*this);
	}
	Date& operator --()
	{
		day -= 1;
		normalize();
		return (*this);
	}
	Date operator ++(int)
	{
		Date n(*this);
		day += 1;
		normalize();
		return n;
	}
	Date operator --(int)
	{
		Date n(*this);
		day -= 1;
		normalize();
		return n;
	}
	bool operator ==(Date &a2)
	{
		if (
			(year == a2.Date_year()) &&
			(month == a2.Date_month()) &&
			(day == a2.Date_day()) &&
			(hour == a2.Date_hour()) &&
			(minute == a2.Date_min()) &&
			(sec == a2.Date_sec())
			)
			return true;
		return false;
	}
	std::string DateFormat(std::string format);
private:
	int year;
	Month month;
	int day;
	int hour;
	int minute;
	int sec;
	Date normalize();
};
std::ostream& operator<<(std::ostream &os, const Date &d);
std::ostream& operator<<(std::ostream &ost, const DateInterval &d_i);
int isleap(int year);
#endif