#include<iostream>
#include"Date.h"
#include<time.h>
#include "stdafx.h"
using namespace std;


Date::Date()
{
	time_t timer;
	time(&timer);
	tm* t_tm = localtime(&timer);
	year = t_tm->tm_year+1900;
	month = t_tm->tm_mon + 1;
	day = t_tm->tm_mday;
}

void Date::ShowDate()
{
	cout << "你的QQ的注册日期:" << endl;
	cout << year << "." << month << "." << day << endl;
}

bool Date::ChechBirthday()
{
	time_t timer;
	time(&timer);
	tm* t_tm = localtime(&timer);
	if (t_tm->tm_mon + 1 == month)
		return true;
	else
		return false;
}
