#pragma once
#ifndef TOOLS_H
#define TOOLS_H
#include<iostream>
#include"GreedySnake.h"
#include"chat.h"
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

	/*void ShowCommonFriends();*/

	/*void QQSelectMenu();*/

	void AddPartyAdmin();

	void SaveFriends();

	void QuitParty();

private:

	vector<QQ_CHC*>QQ;

	string QQid; //登陆的QQ号

	string QQparty;//创建的群号;

	string PartyMember; //申请加群的QQ号

};

extern QQTools_CHC QQtools;

#endif