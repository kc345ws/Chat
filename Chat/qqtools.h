#pragma once
#ifndef QQTOOLS_H
#define QQTOOLS_H
#include<iostream>
#include"GreedySnake.h"
#include"qq.h"
#include<vector>
#include<string>
using namespace std;
//class QQTools_CHC;

class QQTools_CHC
{
public:

	void Menu();

	void ApplyQQ();

	void LoginQQ();

	void Client();

	void QQMenu();

	void SaveQQ();

	void GetQQ();

	void ShowQQ();

	void AddFriend();

	void DeleteFriend();

	void ShowFriends();

	void GetFriends();

	//void AddQQParty();

	void CreatQQparty();

	void SaveQQParty();

	void ShowQQParty();

	void GetQQParty();

	void PlayGame();

	void AddPartyMember();

	void AgreeMember();

	void AgreeFriend();

	void DeletePartyMember();

	/*void ShowCommonFriends();*/

	/*void QQSelectMenu();*/

	void AddPartyAdmin();

	void SaveFriends();

	void QuitParty();

	void ShowMyInformation();

	void ChangePassWord();

	void SaveChange();

	void ChangeName();

	void ChangeAutoGraph();

	void ChangeArea();

	void ShowFriendInformation();

	void ShowFriendNoReturn();

	void ChangeFriendRemarks();

	void ShowPartyInformation();

	void ShowQQPartyNoReturn();

	void ShowPartyMemberS();

private:

	vector<QQ_CHC*>QQ;

	string QQid; //登陆的QQ号

	string QQparty;//创建的群号;

	string PartyMember; //申请加群的QQ号

};

extern QQTools_CHC QQtools;

#endif