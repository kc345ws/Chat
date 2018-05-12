#include<iostream>
#include"tools.h"
#include"chat.h"
#include<conio.h>
#include "stdafx.h"
#include "Initsock.h"
#include<fstream>
CInitSock initSock; // 初始化Winsock库
using namespace std;
vector<QQ_CHC*>QQ;
int QQid;

void SaveQQ()
{
	ofstream file;
	file.open("QQ.txt");
	for (int i = 0; i < size(QQ); i++)
	{
		file << QQ[i]->QQID << endl;
		file << QQ[i]->Qage << endl;
		file << QQ[i]->QQPassWord << endl;
		file << QQ[i]->QQName << endl;
		file << QQ[i]->QQProvince << endl;
		file << QQ[i]->QQAutograph << endl;
	}
	//for (int i = 0; i < size(QQ); i++)
	//{
	//	file << QQ[i]->QQID << endl;
	//}
	file.close();
}

void GetQQ()
{
	int qqid, qage;
	string qqpw, qqname, qqpv, qqag;
	ifstream file;
	int line = 0;
	char c;
	file.open("QQ.txt");
	while (file.get(c))
	{
		if (c == '\n')
		{
			line++;
		}
	}
	file.close();
	file.open("QQ.txt");
	for (int i = 0; i < line / 6; i++)
	{
		file >> qqid;
		file >> qage;
		file >> qqpw;
		file >> qqname;
		file >> qqpv;
		file >> qqag;
		//QQ_CHC qq(qqid, qage, qqpw, qqname, qqpv,qqag);
		QQ.emplace_back(new QQ_CHC(qqid, qage, qqpw, qqname, qqpv, qqag));
	}
}

void ShowQQ()
{
	int qqid, qage;
	string qqpw, qqname, qqpv, qqag;
	ifstream file;
	int line = 0;
	char c;
	file.open("QQ.txt");
	while (file.get(c))
	{
		if (c == '\n')
		{
			line++;
		}
	}
	file.close();
	file.open("QQ.txt");
	for (int i = 0; i < line / 6; i++)
	{
		file >> qqid;
		file >> qage;
		file >> qqpw;
		file >> qqname;
		file >> qqpv;
		file >> qqag;
		//QQ_CHC qq(qqid, qage, qqpw, qqname, qqpv,qqag);
		QQ.emplace_back(new QQ_CHC(qqid, qage, qqpw, qqname, qqpv, qqag));
	}
	for (int i = 0; i < line / 6; i++)
	{
		cout << "QQ号:"<<QQ[i]->QQID << endl;
		cout << "Q龄:"<<QQ[i]->Qage << endl;
		cout << "QQ密码:"<<QQ[i]->QQPassWord << endl;
		cout << "QQ名称:"<<QQ[i]->QQName << endl;
		cout << "所在地区:"<<QQ[i]->QQProvince << endl;
		cout << "个性签名:"<<QQ[i]->QQAutograph << endl;
		cout << endl;

	}
	/*vector<int>qqid;
	for (int i = 0; i < 2; i++)
	{
		int qq;
		file >> qq;
		qqid.emplace_back(qq);
	}
	file.close();
	cout << qqid[0] << endl;;
	cout << qqid[1];*/
	/*int num = file.gcount();
	int i = 0;
	for (string s; file >> s;)
	{
		QQ[i].push_back(s);
	}
	for (int i = 0; i < file.gcount(); i++)
	{
		file.read((char *)&QQ[i], sizeof(QQ_CHC));
	}*/

	//for (int i = 0; i < size(QQ); i++)
	//{
	//	cout << QQ[i]->QQID << endl;
	//}
	file.close();
}

void Menu()
{
	system("CLS");
	GetQQ();
	int select;

	cout << "请选择登陆/注册的帐号" << endl;
	cout << "1.QQ" << endl;
	cout << "2.微博" << endl;
	cout << "3.微信" << endl;

	cin >> select;

	switch (select)
	{
	case 1:
		{
		cout << "请选择所需功能" << endl;
		cout << "1.登陆QQ" << endl;
		cout << "2.注册QQ" << endl;
		cout << "3.保存QQ" << endl;
		cout << "4.查看已申请QQ号" << endl;
			int ch;
			cin >> ch;
			switch (ch)
			{
			case 1:

				LoginQQ();
				break;

			case 2:

				ApplyQQ();
				break;

			case 3:
				SaveQQ();
				break;

			case 4:
				GetQQ();
				break;

			default:
				{
				cout << "输入错误" << endl;
				cout << "按任意键返回主菜单" << endl;
				getch();
				Menu();
				}
			}
			cout << "按任意键返回主菜单" << endl;
			getch();
			Menu();
			break;
		}
	default:
		{
		cout << "输入错误" << endl;
		cout << "按任意键返回主菜单" << endl;
		_getch();
		Menu();
		break;
		}
	}
}

void ApplyQQ() 
{
	QQ.emplace_back(new QQ_CHC());

}

void LoginQQ()
{
	int ID;
	bool flag = false;
	string PassWord;
	//vector<QQ_CHC*>::iterator iter = QQ.begin();
	cout << "输入你要登陆的QQ:" << endl;
	cin >> ID;
	::QQid = ID;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->QQID == ID)
		{
			flag = true;
		}
	}
	if (flag != true)
	{
		cout << "没有该QQ号，请先申请" << endl;
		cout << "按任意键返回主菜单" << endl;
		_getch();
		Menu();
	}
	cout << "请输入该QQ的密码" << endl;
	cin >> PassWord;
	for (int i = 0 ; i < size(QQ) ; i++)
	{
		if (QQ[i]->QQID == ID && QQ[i]->QQPassWord == PassWord)
		{
			cout << "登陆成功" << endl;
			cout << "按任意键开始使用QQ" << endl;
			getch();
			QQMenu();
			break;
		}
		else if (QQ[i]->QQID == ID && QQ[i]->QQPassWord != PassWord)
		{
			cout << "密码输入错误" << endl;
			cout << "请重新输入密码" << endl;
			cin >> PassWord;
			if (QQ[i]->QQPassWord == PassWord)
			{
				cout << "登陆成功" << endl;
				cout << "按任意键开始使用QQ" << endl;
				getch();
				QQMenu();
				break;
			}
			else
			{
				cout << "密码输入错误" << endl;
				cout << "请重新输入密码" << endl;
				cin >> PassWord;
			}
			break;
		}
		/*else
		{
			cout << "没有该QQ号，请先申请" << endl;
			cout << "按任意键返回主菜单" << endl;
			_getch();
			Menu();
			break;
		}*/
			
	}
}

void QQMenu()
{
	system("CLS");
	cout << "欢迎使用QQ" << endl;
	cout << "你的QQ号为:" << QQid << endl;
}

void Client()//聊天服务器
{
	// 创建套节字
	SOCKET s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		printf(" 创建失败 socket() \n");
		exit(0);
	}

	// 也可以在这里调用bind函数绑定一个本地地址
	// 否则系统将会自动安排

	// 填写远程地址信息
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(4567);
	// 注意，这里要填写服务器程序（TCPServer程序）所在机器的IP地址
	// 如果你的计算机没有联网，直接使用127.0.0.1即可
	servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	if (::connect(s, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
	{
		printf(" 连接失败connect() \n");
		exit(0);
	}

	char buff[256];
	char szText[256];
	cout << "登陆服务器成功" << endl;
	while (TRUE)
	{
		//从服务器端接收数据
		int nRecv = ::recv(s, buff, 256, 0);
		if (nRecv > 0)
		{
			buff[nRecv] = '\0';
			printf("接收到数据：%s\n", buff);
		}

		// 向服务器端发送数据
		cout << "请发送消息:" << endl;
		cin >> szText;
		szText[255] = '\0';
		::send(s, szText, strlen(szText), 0);

		cout << "请等待对方回复" << endl;
	}

	// 关闭套节字
	::closesocket(s);
}