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
	SetConsoleTitle("Chat-2017级吉林大学软件工程9班陈鸿超制作");
	/*SetWindowSize(41, 32);*/
	string QQ = "QQ";
	string WeiChat = "WeiChat";
	string WeiBo = "WeiBo";
	string Parties = "QQ\\Parties";
	CreateDirectory(QQ.c_str(), NULL);//创建文件夹
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

	cout << "请选择使用的软件编号:" << endl;
	cout << "1.QQ" << endl;
	cout << "2.微博" << endl;
	cout << "3.微信" << endl;

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
		cout << "未开发" << endl;
		break;
	default:
		cout << "选择错误请重新选择" << endl;
		cout << "按任意键返回主菜单" << endl;
		_getch();
		_getch();
		MainMenu();
	}
}