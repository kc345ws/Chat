#include "stdafx.h"
#include<iostream>
#include"chat.h"
#include"GreedySnake.h"
#include<Windows.h>
#include<string>
#include<conio.h>
#include<fstream>
using namespace std;
void MainMenu();

extern QQTools_CHC QQTools;
extern WeiBoTools_CHC WeiBoTools;
extern WeiChatTools_CHC WeiChatTools;

int main()
{
	SetConsoleTitle("Chat-2017�����ִ�ѧ�������9��º賬����");
	/*SetWindowSize(41, 32);*/
	string QQ = "QQ";
	string WeiChat = "WeiChat";
	string WeiBo = "WeiBo";
	string Parties = "QQ\\Parties";
	CreateDirectory(QQ.c_str(), NULL);//�����ļ���
	CreateDirectory(WeiChat.c_str(), NULL);
	CreateDirectory(WeiBo.c_str(), NULL);
	CreateDirectory(Parties.c_str(), NULL);
	/*Menu();*/
	WeiBoTools.GetWeiBo();
	QQTools.GetQQ();
	QQTools.Menu();
	return 0;
}


void MainMenu()
{
	system("CLS");
	int select;

	cout << "��ѡ��ʹ�õ�������:" << endl;
	cout << "1.QQ" << endl;
	cout << "2.΢��" << endl;
	cout << "3.΢��" << endl;

	cin >> select;

	switch (select)
	{
	case 1:
		QQTools.Menu();
		break;
	case 2:
		WeiBoTools.Menu();
		break;
	case 3:
		cout << "δ����" << endl;
		break;
	default:
		cout << "ѡ�����������ѡ��" << endl;
		cout << "��������������˵�" << endl;
		_getch();
		_getch();
		MainMenu();
	}
}