#include "Header.h"
Date::Date(const Date &date)
{
	year = date.year;
	month = date.month;
	day = date.day;
	hour = date.hour;
	minute = date.minute;
	sec = date.sec;
}
Date::Date(int y, Month m, int d, int h, int min, int s)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = min;
	sec = s;
	normalize();
	if ((year > 9999)||(year <=0))
	{
	throw std::exception();
	}
}
Date::Date(unsigned int y, Month m, unsigned int d)
{
	year = y;
	month = m;
	day = d;
	hour = 0;
	minute = 0;
	sec = 0;
	normalize();
	if ((year > 9999) || (year <= 0))
	{
		throw std::exception();
	}
}
Date::Date(unsigned int h, unsigned int m, unsigned int s) 
{
	time_t  t = time(nullptr);
	tm* atm = gmtime(&t);
	year = static_cast<unsigned int>(atm->tm_year) + 1900;
	month = static_cast<Month>(atm->tm_mon + 1);
	day = static_cast<unsigned int>(atm->tm_mday);
	hour = h;
	minute = m;
	sec = s;
	normalize();
	if ((year > 9999) || (year <= 0))
	{
		throw std::exception();
	}
}
Date::Date()
{
	time_t  t = time(nullptr);
	tm* atm = gmtime(&t);
	year = static_cast<unsigned int>(atm->tm_year) + 1900;
	month = Month(atm->tm_mon + 1);
	day = static_cast<unsigned int>(atm->tm_mday);
	hour = static_cast<unsigned int>(atm->tm_hour);
	minute = static_cast<unsigned int>(atm->tm_min);
	sec = static_cast<unsigned int>(atm->tm_sec);

}
Date Date::normalize()
{
	int mm;
	int y = year, d = day, h = hour, min = minute, s = sec;
	Month m = month;
	std::vector<int> dim2{ 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	sec = s;
	if (s >= 60)
		minute = min + sec / 60;
	else if (s < 0)
		minute = min + (sec / 60 - 1);
	else
		minute = min;
	if (minute >= 60)
		hour = h + minute / 60;
	else if (minute < 0)
		hour = h + (minute / 60 - 1);
	else
		hour = h;
	if (hour >= 24)
		day = d + hour / 24;
	else if (hour < 0)
		day = d + (hour / 60 - 1);
	else
		day = d;
	mm = static_cast<int>(m);
	if (mm > 12)
	{
		y = y + mm / 12;
		mm = mm % 12;
		if (0 == mm)
			mm = 12;
	}
	else if (mm <= 0)
	{
		y = y + (mm / 12 - 1);
		mm = 12 + mm % 12;
	}
	while (day > dim2[mm])
	{
		if (2 != mm)
			day -= dim2[mm];
		else if ((2 == mm) && (29 == day) && (isleap(y)))
			break;
		else
			day -= (dim2[mm] + isleap(y));
		if (12 == mm)
			++y;
		mm = (mm + 1) % 12;
		if (0 == mm)
			mm = 12;
	}
	while (day <= 0)
	{
		if (3 != mm)
			day += dim2[mm - 1];
		else
			day += (dim2[mm - 1] + isleap(y));
		if (1 == mm)
			--y;
		mm = (mm - 1) % 12;
		if (0 == mm)
			mm = 12;
	}
	month = static_cast<Month>(mm);
	year = y;
	sec = (sec % 60 >= 0) ? (sec % 60) : (60 + sec % 60);
	minute = (minute % 60 >= 0) ? (minute % 60) : (60 + minute % 60);
	hour = (hour % 24 >= 0) ? (hour % 24) : (24 + hour % 24);
	/*if ((year > 9999) || (year <= 0))
	{
		throw std::exception();
	}*/
	return (*this);
}
Date Date::addYears(int add)const
{
	int new_d = day;
	if (!(isleap(year + add)) && (2 == static_cast<int>(month)) && (29 == day))
		new_d = 28;
	Date n(year+add, month, new_d, hour, minute, sec);
	return n;
}
Date Date::addMonth(int add)const
{
	int m = static_cast<int>(month);
	std::vector<int> dim2{ 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int new_m = m + add;
	int new_y = year;
	int new_day = day;
	if (new_m > 12)
		new_y += (new_m / 12);
	else if (new_m <= 0)
		new_y -= (new_m / 12 + 1);
	new_m = (new_m % 12 >= 0) ? (new_m % 12) : (12 + new_m % 12);
	if (0 == new_m)
		new_m = 12;
	if (new_day > dim2[new_m])
		new_day = dim2[new_m];
	Date n(new_y, static_cast<Month>(new_m), new_day, hour, minute, sec);
	return n;
}
Date Date::addDays(int add)const
{
	Date n(year, month, day+add, hour, minute, sec);
	return n;
}
Date Date::addHours(int add)const
{
	Date n(year, month, day, hour+add, minute, sec);
	return n;
}
Date Date::addMinutes(int add)const
{
	Date n(year, month, day, hour, minute+add, sec);
	return n;
}
Date Date::addSeconds(int add)const
{
	Date n(year, month, day, hour, minute, sec+add);
	return n;
}
DateInterval::DateInterval(int y, int mo, int d, int h, int mi, int s)
{
	iyear = y;
	imonth = mo;
	iday = d;
	ihour = h;
	iminute = mi;
	isec = s;
}
DateInterval Date::getInterval(const Date& another)const
{
	int in_y, in_m, in_d, in_h, in_min, in_s;
	in_y = year - another.Date_year();
	in_m = static_cast<int>(month) - static_cast<int>(another.Date_month());
	in_d = day - another.Date_day();
	in_h = hour - another.Date_hour();
	in_min = minute - another.Date_min();
	in_s = sec - another.Date_sec();
	DateInterval intr(in_y, in_m, in_d, in_h, in_min, in_s);
	return intr;
}
Date Date::addInterval(const DateInterval& interv)const
{
	Date n(year + interv.DateInt_year(), static_cast<Month>(static_cast<int>(month) + interv.DateInt_month()), day + interv.DateInt_day(), hour + interv.DateInt_hour(), minute + interv.DateInt_min(), sec + interv.DateInt_sec());
	return n;
}
DateInterval::DateInterval(const DateInterval &date)
{
	iyear = date.iyear;
	imonth = date.imonth;
	iday = date.iday;
	ihour = date.ihour;
	iminute = date.iminute;
	isec = date.isec;
}
int isleap(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return 1;
			else
				return 0;
		}
		else
			return 1;
	}
	else
		return 0;
}
std::ostream& operator<<(std::ostream &os, const Date &d)
{
	os << d.Date_year() << "-";
	if (static_cast<int>(d.Date_month()) < 10)
		os << "0" << static_cast<int>(d.Date_month()) << "-";
	else 
		os << static_cast<int>(d.Date_month()) << "-";
	if (d.Date_day() < 10)
		os << "0" << d.Date_day();
	else 
		os << d.Date_day();
	os << " ";
	if (d.Date_hour() < 10)
		os << "0" << d.Date_hour() << "::";
	else
		os << d.Date_hour() << "::";
	if (d.Date_min() < 10)
		os << "0" << d.Date_min() << "::";
	else
		os << d.Date_min() << "::";
	if (d.Date_sec() < 10)
		os << "0" << d.Date_sec();
	else
		os << d.Date_sec();
	os << std::endl;
	return os;
}
std::ostream& operator<<(std::ostream &ost, const DateInterval &d_i)
{
	ost << d_i.DateInt_year() << " years\n" << d_i.DateInt_month() << " month\n" << d_i.DateInt_day() << " days\n";
	ost << d_i.DateInt_hour() << " hours\n" << d_i.DateInt_min() << " minutes\n" << d_i.DateInt_sec() << " seconds" << std::endl;
	return ost;
}
std::string Date::DateFormat(std::string format)
{
	size_t position;
	std::string result = format;
	position = result.find("YYYY");
	if (position != std::string::npos)
		result.replace(position, 4, std::to_string(year));
	position = result.find("MMM");
	if (position != std::string::npos)
	{
		switch (month)
		{
		case Month::Jan: {result.replace(position, 3, "Jan"); break;}
		case Month::Feb: {result.replace(position, 3, "Feb"); break;}
		case Month::Mar: {result.replace(position, 3, "Mar"); break;}
		case Month::Apr: {result.replace(position, 3, "Apr"); break;}
		case Month::May: {result.replace(position, 3, "May"); break;}
		case Month::Jun: {result.replace(position, 3, "Jun"); break;}
		case Month::Jul: {result.replace(position, 3, "Jul"); break;}
		case Month::Aug: {result.replace(position, 3, "Aug"); break;}
		case Month::Sep: {result.replace(position, 3, "Sep"); break;}
		case Month::Oct: {result.replace(position, 3, "Oct"); break;}
		case Month::Nov: {result.replace(position, 3, "Nov"); break;}
		case Month::Dec: {result.replace(position, 3, "Dec"); break;}
		}
	}	
	position = result.find("MM");
	if (position != std::string::npos)
	{
		if (static_cast<int>(month) < 10)
			result.replace(position, 2, "0" + std::to_string(static_cast<int>(month)));
		else
			result.replace(position, 2, std::to_string(static_cast<int>(month)));
	}
	position = result.find("DD");
	if (position != std::string::npos)
	{
		if (day < 10)
			result.replace(position, 2, "0" + std::to_string(day));
		else
			result.replace(position, 2, std::to_string(day));
	}
	position = result.find("hh");
	if (position != std::string::npos)
	{
		if (hour < 10)
			result.replace(position, 2, "0" + std::to_string(hour));
		else
			result.replace(position, 2, std::to_string(hour));
	}
	position = result.find("mm");
	if (position != std::string::npos)
	{
		if (minute < 10)
			result.replace(position, 2, "0" + std::to_string(minute));
		else
			result.replace(position, 2, std::to_string(minute));
	}
	position = result.find("ss");
	if (position != std::string::npos)
	{
		if (sec < 10)
			result.replace(position, 2, "0" + std::to_string(sec));
		else
			result.replace(position, 2, std::to_string(sec));
	}
	return result;
}