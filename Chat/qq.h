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
class Tencent_CHC;

class Tencent_CHC //帐号基类
{

public:

	virtual int ReturnAge(){return Age;}

	virtual int ReturnFriendNumber(){return FriendNumber;}

	virtual int ReturnPartyNumber() { return PartyNumber; }

	virtual string ReturnID() { return ID; }

	virtual string  ReturnPassWord(){return PassWord;}

	virtual string  ReturnName(){return Name;}

	virtual string  ReturnArea(){return Area;}

	virtual string  ReturnAutograph(){return Autograph;}

	virtual void ChangePartyNumbers(int num){PartyNumber = num;}

	virtual void ChangeFriendsNumber(int num){FriendNumber = num;}

	virtual void ChangePassWord(string pw) { PassWord = pw; }

	virtual void ChangeName(string newname) { Name = newname; }

	virtual void ChangeAutoGraph(string newautograph) { Autograph = newautograph; }

	virtual void ChangeArea(string newarea) { Area = newarea; }

protected:

	int Age; //注册天数

	int FriendNumber; //好友数量

	int PartyNumber; //群数量

	string ID;  //帐号
	
	string Name;  //用户姓名

	string PassWord; //用户密码

	string Area;//用户所在地区

	string Autograph;//用户个性签名

	Date ApplyDate;//用户注册日期

private:

};


class QQ_CHC : public Tencent_CHC
{

public:

	QQ_CHC();

	QQ_CHC(string qqid, int qage, string qqpw, string qqname,string qqpv, string ag);

	~QQ_CHC();

	vector<QQFriends_CHC*>& ReturnFriendList(){return FriendList;}

	vector<QQParties_CHC*>& ReturnPartyList(){return PartyList;}


	//string ReturnID()
	//{
	//	return ID;
	//}

	//int ReturnAge()
	//{
	//	return Age;
	//}

	//int ReturnFriendNumber()
	//{
	//	return FriendNumber;
	//}

	//string  ReturnPassWord()
	//{
	//	return PassWord;
	//}

	//string  ReturnName()
	//{
	//	return Name;
	//}

	//string  ReturnArea()
	//{
	//	return Area;
	//}

	//string  ReturnAutograph()
	//{
	//	return Autograph;
	//}

	/*int ReturnPartyNumber()
	{
		return PartyNumber;
	}

	void ChangePartyNumbers(int num)
	{
		PartyNumber = num;
	}

	void ChangeFriendsNumber(int num)
	{
		FriendNumber = num;
	}*/

private:

	//int Age;

	//int FriendNumber;

	//int PartyNumber;

	//string ID;

	//string PassWord;//

	//string Name;

	//string Area;

	//string Autograph;

	//Date ApplyDate;

	vector<QQFriends_CHC*> FriendList;

	vector<QQParties_CHC*> PartyList;

};

class QQFriends_CHC
{

public:

	friend class QQ_CHC;

	QQFriends_CHC(string name, string id, string newremarks);

	QQFriends_CHC(string name, string id);

	string ReturnFriendName(){return FriendName;}

	string ReturnID(){return ID;}

	string ReturnRemarks() {return Remarks;}

	void ChangeRemarks(string newremarks) { Remarks = newremarks; }

private:
	
	string FriendName;

	string ID;

	string Remarks;

};


class QQParties_CHC
{

public:

	friend class QQ_CHC;

	string ReturnPartyID(){return PartyID;}

	string ReturnPartyName(){return PartyName;}

	string ReturnCreatUserID(){return CreatUserID;}

	QQParties_CHC(string id , string name ,string userid);

	vector<string> &ReturnPartyMembers() { return PartyMembrs; }

	vector<string> &ReturnAdminsID() { return AdminsList; }

private:
	
	string PartyID;//群号

	string PartyName;//群名称

	string CreatUserID;//群主

	vector<string> PartyMembrs;//群成员列表

	vector<string> AdminsList;//管理员列表

};

#endif