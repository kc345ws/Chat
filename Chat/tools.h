#pragma once
#ifndef QQTOOLS_H
#define QQTOOLS_H
#include<iostream>
#include"GreedySnake.h"
#include"chat.h"
#include<vector>
#include<string>
using namespace std;
//class WeiBo_CHC;
class QQTools_CHC;
class WeiBoTools_CHC;
class WeiChatTools_CHC;

extern QQTools_CHC QQTools;
extern WeiBoTools_CHC WeiBoTools;
extern WeiChatTools_CHC WeiChatTools;

class ToolsBase_CHC
{
public:

	virtual void Apply() = 0;

	virtual void Login() = 0;

	virtual void Menu() = 0;

	virtual void AddFriend() = 0;

	virtual void SaveFriends() = 0;

	virtual void GetFriends() = 0;

	virtual void ShowFriends() = 0; 

	virtual void DeleteFriend() = 0;

	virtual void AgreeFriend() = 0;

	virtual void ShowFriendInformation() = 0;

	virtual void ChangeFriendRemarks() = 0;

	virtual void SaveChange() = 0;

protected:


private:

	virtual void isFatherBase() = 0;
};


class QQToolsBase_CHC : public ToolsBase_CHC
{

public:
	virtual void Menu();

	virtual void Apply();

	virtual void Login();

	virtual void Client();

	virtual void QQMenu();

	virtual void SaveQQ();

	virtual void GetQQ();

	virtual void ShowQQ();

	virtual void AddFriend();

	virtual void DeleteFriend();

	virtual void ShowFriends();

	virtual void GetFriends();

	virtual void CreatQQparty();

	virtual void SaveQQParty();

	virtual void ShowQQParty();

	virtual void GetQQParty();

	virtual void PlayGame();

	virtual void AddPartyMember();

	virtual void AgreeMember();

	virtual void AgreeFriend();

	virtual void DeletePartyMember();

	virtual void AddPartyAdmin();

	virtual void SaveFriends();

	virtual void QuitParty();

	virtual void ShowMyInformation();

	virtual void ChangePassWord();

	virtual void SaveChange();

	virtual void ChangeName();

	virtual void ChangeAutoGraph();

	virtual void ChangeArea();

	virtual void ShowFriendInformation();

	virtual void ShowFriendNoReturn();

	virtual void ChangeFriendRemarks();

	virtual void ShowPartyInformation();

	virtual void ShowQQPartyNoReturn();

	virtual void ShowPartyMemberS();

	virtual void CreateWeiBo();

	virtual string &ReturnQQid() { return QQid; }

	virtual vector<QQ_CHC*> &ReturnQQ() { return QQ; }

protected:

	vector<QQ_CHC*>QQ;

	string QQid; //��½��QQ��

	string QQparty;//������Ⱥ��;

	string PartyMember; //�����Ⱥ��QQ��

private:

	void ToolsBase_CHC::isFatherBase() {}

};


class WeiBoToolsBase_CHC : public ToolsBase_CHC
{

public:

	virtual vector<WeiBo_CHC*> &ReturnWeiBolist() { return WeiBoList; }

	virtual void SaveWeiBo();

	virtual void GetWeiBo();

	virtual void WeiBoMenu();

	virtual void Menu();

	virtual void Login();

	virtual void Apply() { cout << "���¼QQ��ͨ΢��" << endl; }

	virtual void AddFriend() { cout << "δ����"; }

	virtual void SaveFriends() { cout<<"δ����"; }

	virtual void GetFriends() { cout << "δ����"; }

	virtual void ShowFriends() { cout << "δ����"; }

	virtual void DeleteFriend() {}

	virtual void AgreeFriend() {}

	virtual void ShowFriendInformation() {}

	virtual void ChangeFriendRemarks() {}

	virtual void SaveChange() {}

protected:

	vector<WeiBo_CHC*> WeiBoList;

	string LoginedWeiBoID;

private:
	void ToolsBase_CHC::isFatherBase() {}

};


class WeiChatToolsBase_CHC:public ToolsBase_CHC
{
public:

	virtual void Apply();

	virtual void Menu();

	virtual void WeiChatMenu();

	virtual void Login();

	virtual void SaveWeiChat();

	virtual void GetWeiChat();

	virtual void ShowWeiChat();

	virtual void AddFriend();

	virtual void SaveFriends();

	virtual void GetFriends();

	virtual void ShowFriends();

	virtual void CreatParty();

	virtual void SaveParty();

	virtual void GetParty();

	virtual void DeleteFriend();

	virtual void AgreeFriend();

	virtual void ShowFriendInformation();

	virtual void ShowFriendNoReturn();

	virtual void ChangeFriendRemarks();

	virtual void SaveChange();

	virtual void ShowParty();

	virtual vector<WeiChat_CHC*> &ReturnWeiChatList() { return WeiChatList; }

protected:

	vector<WeiChat_CHC*>WeiChatList;

	string LoginedWeiChat;

	string WeiChatparty;//������Ⱥ��;

	string WeiChatPartyMember; //�����Ⱥ��QQ��




private:

	void ToolsBase_CHC::isFatherBase(){}

};












class QQTools_CHC : public QQToolsBase_CHC
{

};


class WeiBoTools_CHC : public WeiBoToolsBase_CHC
{


};


class WeiChatTools_CHC:public WeiChatToolsBase_CHC
{

};


#endif