#pragma once
#ifndef CHAT_H
#define CHAT_H
#include<string>
#include<vector>
#include<iostream>
#include"Date.h"
using namespace std;
class Date;

class QQ_CHC
{

public:

	QQ_CHC();

	QQ_CHC(int qqid, int qage, string qqpw, string qqname,string qqpv, string ag);

	friend void LoginQQ();

	friend void GetQQ();

	friend void SaveQQ();

	friend void ShowQQ();

private:

	int QQID;

	int Qage;

	string QQPassWord;//

	string QQName;

	string QQProvince;

	string QQAutograph;

	Date ApplyDate;

};
//ofstream &operator << (ofstream & out, const vector<QQ_CHC*>&QQ)
//{
//	auto iter = QQ.begin();
//	for (iter; iter != QQ.end(); iter++)
//	{
//		(*iter)->QQID;
//	}
//}

class QQFriends_CHC
{

public:

	friend class QQ_CHC;

	class  Friend
	{

		string FriendName;

		int ID;
	};

	QQFriends_CHC();

private:
	
	int FriendsNumber;

	vector<Friend> FriendList;


protected:

};

class QQParties_CHC
{

public:

	friend class QQ_CHC;

	struct Party
	{
		string PartyNmae;//ÈºÃû³Æ

		int PartyID;//ÈººÅ
	};

	QQParties_CHC();

private:

	int PartyNumbers;

	vector<Party> PartyList;

};
#endif