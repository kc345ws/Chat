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
	ID = string(temp);
	/*ID = rand()*rand();*/
	cout << "你的QQ号为:" << ID <<endl;
	cout << "请输入你的密码" << endl;
	cin >> PassWord;
	ApplyDate.ShowDate();
	Age = 0;
	cout << "请输入你的QQ名字:" << endl;
	cin >> Name;
	cout << "请输入你所在的省份" << endl;
	cin >> Area;
	cout << "输入你的个性签名" << endl;
	cin >> Autograph;
	cout << "QQ号申请成功" << endl;
	cout << "你的QQ号为:" << ID << endl;
	cout << "你的QQ密码为:" << PassWord << endl;
	cout << "请妥善保存帐号和密码" << endl;

	string QQ = "QQ\\" + ID;
	CreateDirectory(QQ.c_str(), NULL);//每个QQ创建一个文件夹

}

QQ_CHC::QQ_CHC(string qqid, int qage, string qqpw, string qqname, string qqpv, string ag)
{
	ID = qqid;
	Age = qage;
	PassWord = qqpw;
	Name = qqname;
	Area = qqpv;
	Autograph = ag;
	FriendNumber = 0;
	PartyNumber = 0;
}

QQ_CHC::~QQ_CHC()
{
	for (int i = 0; i < size(FriendList); i++)
	{
		delete FriendList[i];
	}

	for (int i = 0; i < size(PartyList); i++)
	{
		delete PartyList[i];
	}
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