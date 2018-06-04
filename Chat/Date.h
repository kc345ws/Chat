#pragma once
#ifndef DATE_H
#define DATE_H
using namespace std;

class Date
{
public:

	Date();

	void ShowDate();

	bool ChechBirthday();

	string &ReturnDate() 
	{
		YearMonthDay = year + '.' + month + '.' + day;
		return YearMonthDay;
	}

	int &ReturnYear() { return year; }

	int &ReturnMonth() { return month; }

	int &ReturnDay() { return day; }

	

protected:

	int year, month, day;

private:

	string YearMonthDay;

};

#endif