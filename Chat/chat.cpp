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
	for (int i = 0; i<1000000; i++) //��ǿQQ�����������
	{
		srand(time(0));
	}
	int p = rand()*rand();
	char temp[128];
	itoa(p , temp , 10);
	ID = string(temp);
	/*ID = rand()*rand();*/
	cout << "���QQ��Ϊ:" << ID <<endl;
	cout << "�������������" << endl;
	cin >> PassWord;
	ApplyDate.ShowDate();
	Age = 0;
	cout << "���������QQ����:" << endl;
	cin >> Name;
	cout << "�����������ڵ�ʡ��" << endl;
	cin >> Area;
	cout << "������ĸ���ǩ��" << endl;
	cin >> Autograph;
	cout << "QQ������ɹ�" << endl;
	cout << "���QQ��Ϊ:" << ID << endl;
	cout << "���QQ����Ϊ:" << PassWord << endl;
	cout << "�����Ʊ����ʺź�����" << endl;

	string QQ = "QQ\\" + ID;
	CreateDirectory(QQ.c_str(), NULL);//ÿ��QQ����һ���ļ���

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

QQFriends_CHC::QQFriends_CHC(string name, string id , string newremarks)
{
	FriendName = name;
	ID = id;
	Remarks = newremarks;
}

QQFriends_CHC::QQFriends_CHC(string name, string id)
{
	FriendName = name;
	ID = id;
	Remarks = "δ��ע";
}

QQParties_CHC::QQParties_CHC(string id, string name, string userid)
{
	PartyID = id;
	PartyName = name;
	CreatUserID = userid;
}