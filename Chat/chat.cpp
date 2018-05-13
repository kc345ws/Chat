#include<iostream>
#include"chat.h"
#include<time.h>
#include "stdafx.h"
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
using namespace std;

QQ_CHC::QQ_CHC()
{
	for (int i = 0; i<1000000; i++) //加强QQ号生成随机性
	{
		srand(time(0));
	}
	int p = rand()*rand();
	char temp[128];
	itoa(p , temp , 10);
	QQID = string(temp);
	/*QQID = rand()*rand();*/
	cout << "你的QQ号为:" << QQID <<endl;
	cout << "请输入你的密码" << endl;
	cin >> QQPassWord;
	ApplyDate.ShowDate();
	Qage = 0;
	cout << "请输入你的QQ名字:" << endl;
	cin >> QQName;
	cout << "请输入你所在的省份" << endl;
	cin >> QQProvince;
	cout << "输入你的个性签名" << endl;
	cin >> QQAutograph;
	cout << "QQ号申请成功" << endl;
	cout << "你的QQ号为:" << QQID << endl;
	cout << "你的QQ密码为:" << QQPassWord << endl;
	cout << "请妥善保存帐号和密码" << endl;

}

QQ_CHC::QQ_CHC(string qqid, int qage, string qqpw, string qqname, string qqpv, string ag)
{
	QQID = qqid;
	Qage = qage;
	QQPassWord = qqpw;
	QQName = qqname;
	QQProvince = qqpv;
	QQAutograph = ag;
	FriendsNumber = 0;
	PartyNumbers = 0;
}

QQFriends_CHC::QQFriends_CHC(string name, string id)
{
	FriendName = name;
	ID = id;
}

QQParties_CHC::QQParties_CHC(string id, string name, string userid)
{
	PartyID = id;
	PartyName = name;
	CreatUserID = userid;
}