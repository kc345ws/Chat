#pragma once
#ifndef CHAT_H
#define CHAT_H
#include<string>
#include<vector>
#include<iostream>
#include"Date.h"
using namespace std;
class Date;
class QQFriends_CHC;

class QQ_CHC
{

public:

	QQ_CHC();

	QQ_CHC(int qqid, int qage, string qqpw, string qqname,string qqpv, string ag);

	friend void LoginQQ();

	friend void GetQQ();

	friend void SaveQQ();

	friend void ShowQQ();

	friend void AddFriend();

	friend void ShowFriends();

private:

	int QQID;

	int Qage;

	int FriendsNumber;

	string QQPassWord;//

	string QQName;

	string QQProvince;

	string QQAutograph;

	Date ApplyDate;

	vector<QQFriends_CHC*> FriendList;

};

class QQFriends_CHC
{

public:

	friend class QQ_CHC;

	QQFriends_CHC(string name ,int id);

	friend void ShowFriends();

private:
	
	string FriendName;

	int ID;

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