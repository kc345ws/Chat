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
class QQParties_CHC;

class QQ_CHC
{

public:

	QQ_CHC();

	QQ_CHC(string qqid, int qage, string qqpw, string qqname,string qqpv, string ag);

	//friend void LoginQQ();

	//friend void GetQQ();

	//friend void SaveQQ();

	//friend void ShowQQ();

	//friend void ShowFriends();

	//friend void SaveFriends();

	friend void AddFriend();

	friend void GetFriends();

	friend void CreatQQparty();

	string ReturnQQID()
	{
		return QQID;
	}

	int ReturnQage()
	{
		return Qage;
	}

	int ReturnFriendsNumber()
	{
		return FriendsNumber;
	}

	string  ReturnQQPassWord()
	{
		return QQPassWord;
	}

	string  ReturnQQName()
	{
		return QQName;
	}

	string  ReturnQQProvince()
	{
		return QQProvince;
	}

	string  ReturnQQAutograph()
	{
		return QQAutograph;
	}

	vector<QQFriends_CHC*>& ReturnFriendList()
	{
		return FriendList;
	}

	vector<QQParties_CHC*>& ReturnPartyList()
	{
		return PartyList;
	}

	int ReturnPartyNumbers()
	{
		return PartyNumbers;
	}

	void ChangePartyNumbers(int num)
	{
		PartyNumbers = num;
	}

private:

	int Qage;

	int FriendsNumber;

	int PartyNumbers;

	string QQID;

	string QQPassWord;//

	string QQName;

	string QQProvince;

	string QQAutograph;

	Date ApplyDate;

	vector<QQFriends_CHC*> FriendList;

	vector<QQParties_CHC*> PartyList;

};

class QQFriends_CHC
{

public:

	friend class QQ_CHC;

	QQFriends_CHC(string name ,string id);

	//friend void ShowFriends();

	//friend void SaveQQ();

	//friend void SaveFriends();

	string ReturnFriendName()
	{
		return FriendName;
	}

	string ReturnID()
	{
		return ID;
	}


private:
	
	string FriendName;

	string ID;

protected:

};

class QQParties_CHC
{

public:

	friend class QQ_CHC;

	/*friend void ShowQQParty();*/
	//struct Party
	//{
	//	string PartyNmae;//ÈºÃû³Æ

	//	int PartyID;//ÈººÅ
	//};
	string ReturnPartyID()
	{
		return PartyID;
	}

	string ReturnPartyName()
	{
		return PartyName;
	}

	string ReturnCreatUserID()
	{
		return CreatUserID;
	}

	QQParties_CHC(string id , string name ,string userid);

private:
	
	string PartyID;

	string PartyName;

	string CreatUserID;

};
#endif