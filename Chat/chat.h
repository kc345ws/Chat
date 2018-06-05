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
class TencentFriends_CHC;

class Tencent_CHC //�ʺŻ���
{

public:

	virtual int ReturnAge()
	{
		//Age=ApplyDate.ReturnYear
		return Age;
	}

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

	virtual Date &ReturnApplyDate() { return ApplyDate; }

protected:

	int Age; //ע������

	int FriendNumber; //��������

	int PartyNumber; //Ⱥ����

	string ID;  //�ʺ�
	
	string Name;  //�û�����

	string PassWord; //�û�����

	string Area;//�û����ڵ���

	string Autograph;//�û�����ǩ��

	string Sex;

	Date ApplyDate;//�û�ע������

	struct SexType
	{
		string SexFlag;
	}Man{ "��" }, WoMan{ "Ů" };

private:

};

//class TencentFriends_CHC
//{
//public:
//
//	/*friend class QQ_CHC;*/
//
//	TencentFriends_CHC(string name, string id, string newremarks);
//
//	TencentFriends_CHC(string name, string id);
//
//	string ReturnFriendName() { return FriendName; }
//
//	string ReturnID() { return ID; }
//
//	string ReturnRemarks() { return Remarks; }
//
//	void ChangeRemarks(string newremarks) { Remarks = newremarks; }
//
//private:
//
//	string FriendName;
//
//	string ID;
//
//	string Remarks;
//};


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
	
	string PartyID;//Ⱥ��

	string PartyName;//Ⱥ����

	string CreatUserID;//Ⱥ��

	vector<string> PartyMembrs;//Ⱥ��Ա�б�

	vector<string> AdminsList;//����Ա�б�

};


class WeiBo_CHC: public Tencent_CHC//΢����
{
public:

	vector<string> &ReturnWeiBoContent() { return WeiBoContent; }

	WeiBo_CHC(){}

	WeiBo_CHC(string id) { ID = id; LinkedQQ = id; }

	vector<QQFriends_CHC*>& ReturnFriendList() { return FriendList; }

	vector<QQParties_CHC*>& ReturnPartyList() { return PartyList; }


private:

	string LinkedQQ;//�󶨵�QQ

	vector<string>WeiBoContent;//΢������

	vector<QQFriends_CHC*> FriendList;

	vector<QQParties_CHC*> PartyList;


};



class WeiChat_CHC : public Tencent_CHC
{
public:

	WeiChat_CHC();

	WeiChat_CHC(string qqid, int qage, string qqpw, string qqname, string qqpv, string ag);

	vector<QQFriends_CHC*>& ReturnFriendList() { return FriendList; }

	vector<QQParties_CHC*>& ReturnPartyList() { return PartyList; }


private:

	vector<QQFriends_CHC*> FriendList;

	vector<QQParties_CHC*> PartyList;

};

#endif