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

protected:

	int year, month, day;

};

#endif