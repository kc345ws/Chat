#include<iostream>
#include"tools.h"
#include"chat.h"
#include<conio.h>
#include "stdafx.h"
#include "Initsock.h"
#include<fstream>
#include<io.h>
#include"GreedySnake.h"
#include<list>
#include <cstring>
#include<stdlib.h>
#include<time.h>
CInitSock initSock; // 初始化Winsock库
using namespace std;
//vector<QQ_CHC*>QQ;
//string QQid; //登陆的QQ号
//string QQparty;//创建的群号;
/*string PartyMember;*/ //申请加群的QQ号


void QQTools_CHC::SaveQQ()
{
	ofstream file;
	file.open("QQ.txt",ios::app);
	auto iter = QQ.begin();
	int i = 0;
	for (i = 0; i < size(QQ); i++)
	{

	}
		file << QQ[i-1]->ReturnID() << endl;
		file << QQ[i-1]->ReturnAge() << endl;
		file << QQ[i-1]->ReturnPassWord() << endl;
		file << QQ[i-1]->ReturnName() << endl;
		file << QQ[i-1]->ReturnArea() << endl;
		file << QQ[i-1]->ReturnAutograph() << endl;
		file << " "<<endl;
	file.close();
}

void QQTools_CHC::SaveFriends()
{
	int i = 0, Myqq, n;
	ofstream file;
	string qq = QQid;
	string txt = ".txt";
	string filename = "QQ\\" + qq + "\\" + qq + "Friendlist.txt";
	file.open(filename, ios::app);
	for (i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
		}
	}
	for (n = 0; n < size(QQ[Myqq]->ReturnFriendList()); n++)
	{
	}

	if (n > 0)
	{
		file <<QQ[Myqq]->ReturnFriendList()[n - 1]->ReturnID() << endl;
		file << QQ[Myqq]->ReturnFriendList()[n - 1]->ReturnFriendName() << endl;
		file << " " << endl;
		file.close();
	}
	else
	{
		file.close();
		file.open(filename,ios::trunc | ios::out);//清空文件内容
		file.close();
	}
	
}

void QQTools_CHC::GetQQ()
{
	int qage;
	string qqid;
	string qqpw, qqname, qqpv, qqag;
	ifstream file;
	int line = 0;
	char c;
	file.open("QQ.txt");
	while (file.get(c))
	{
		if (c == ' ')
		{
			line++;
		}
	}
	file.close();
	file.open("QQ.txt");
	for (int i = 0; i < line; i++)
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

void QQTools_CHC::ShowQQ()
{
	system("CLS");
	vector<QQ_CHC*>qq;
	int  qage;
	string qqid;
	string qqpw, qqname, qqpv, qqag;
	ifstream file;
	int line = 0;
	char c;

	file.open("QQ.txt");
	while (file.get(c))
	{
		if (c == ' ')
		{
			line++;
		}
	}
	file.close();
	file.open("QQ.txt");
	for (int i = 0; i < line; i++)
	{
		file >> qqid;
		file >> qage;
		file >> qqpw;
		file >> qqname;
		file >> qqpv;
		file >> qqag;
		//QQ_CHC qq(qqid, qage, qqpw, qqname, qqpv,qqag);
		qq.emplace_back(new QQ_CHC(qqid, qage, qqpw, qqname, qqpv, qqag));
	}
	for (int i = 0; i < line; i++)
	{
		cout << "QQ号:"<<qq[i]->ReturnID() << endl;
		cout << "Q龄:"<<qq[i]->ReturnAge() << endl;
		cout << "QQ密码:"<<qq[i]->ReturnPassWord() << endl;
		cout << "QQ名称:"<<qq[i]->ReturnName() << endl;
		cout << "所在地区:"<<qq[i]->ReturnArea() << endl;
		cout << "个性签名:"<<qq[i]->ReturnAutograph() << endl;
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
	//	cout << QQ[i]->ID << endl;
	//}
	file.close();

	cout << "按任意键返回" << endl;
	_getch();
	_getch();
	Menu();
}

void QQTools_CHC::Menu()
{
	system("CLS");
	int select , key = 1;
	bool flag = false;

	/*SetColor(3);
	SetCursorPosition(13, 10);*/
	cout << "请选择登陆/注册的帐号" << endl;
	/*SetCursorPosition(13, 11);
	SetBackColor();*/
	cout << "1.QQ" << endl;
	/*SetColor(3);
	SetCursorPosition(13, 12);*/
	cout << "2.微博" << endl;
	//SetCursorPosition(13, 13);
	cout << "3.微信" << endl;
	//SetCursorPosition(0, 31);

	cin >> select;
	switch (select)
	{
	case 1:
	{
		cout << "请选择所需功能" << endl;
		cout << "1.登陆QQ" << endl;
		cout << "2.注册QQ" << endl;
		cout << "3.查看已申请QQ号" << endl;
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
			ShowQQ();
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
		_getch();
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

//void QQTools_CHC::QQSelectMenu()
//{
//	/*getch();*/
//	system("CLS");
//	cin.clear();
//	cin.sync();
//	getch();
//	int key = 1, select;
//	bool flag = false;
//	SetColor(3);
//	SetCursorPosition(13, 10);
//	cout << "请选择所需功能" << endl;
//	SetCursorPosition(13, 11);
//	SetBackColor();
//	cout << "1.登陆QQ" << endl;
//	SetColor(3);
//	SetCursorPosition(13, 12);
//	cout << "2.注册QQ" << endl;
//	SetCursorPosition(13, 13);
//	cout << "3.查看已申请QQ号" << endl;
//	/*cin.sync();*/
//	SetCursorPosition(0, 31);
//	/*getch();*/
//	//key = 1;
//	/*cin.sync();*/
//	/*getch();
//	getch();*/
//
//	/*getch();*/
//	/*getch();*/
//	getch();
//	key = 1;
//	getch();
//	while (select = _getch())
//	{
//
//		if (select = 224)
//		{
//			select = _getch();
//		}
//		switch (select)
//		{
//			case 72:
//
//				if (key > 0)
//				{
//
//				switch (key)
//
//				{
//
//				case 2:
//				SetCursorPosition(13, 11);
//				SetBackColor();
//				cout << "1.登陆QQ" << endl;
//				SetCursorPosition(13, 12);
//				SetColor(3);
//				cout << "2.注册QQ" << endl;
//				--key;
//				SetCursorPosition(0, 31);
//				break;
//
//				case 3:
//				SetCursorPosition(13, 12);
//				SetBackColor();
//				cout << "2.注册QQ" << endl;
//				SetCursorPosition(13, 13);
//				SetColor(3);
//				cout << "3.查看已注册QQ号" << endl;
//				--key;
//				SetCursorPosition(0, 31);
//				break;
//
//				}
//
//				}
//
//			break;
//
//			case 80:
//
//			
//				if (key < 4)
//				{
//
//				switch (key)
//				{
//
//				case 1:
//
//				SetCursorPosition(13, 12);
//				SetBackColor();
//				cout << "2.注册QQ" << endl;
//				SetCursorPosition(13, 11);
//				SetColor(3);
//				cout << "1.登录QQ" << endl;
//				++key;
//				SetCursorPosition(0, 31);
//				break;
//
//				case 2:
//				SetCursorPosition(13, 13);
//				SetBackColor();
//				cout << "3.查看已注册QQ号" << endl;
//				SetCursorPosition(13, 12);
//				SetColor(3);
//				cout << "2.注册QQ" << endl;
//				++key;
//				SetCursorPosition(0, 31);
//				break;
//				}
//
//				}
//			break;
//
//			case 13:
//			flag = true;
//			break;
//
//
//			default:
//				QQSelectMenu();
//				break;
//
//			SetCursorPosition(0, 31);
//
//		}
//
//
//		if (flag)
//		{
//			if (key == 1)
//			{
//				LoginQQ();
//			}
//
//			else if (key == 2)
//			{
//				ApplyQQ();
//			}
//
//			else if (key == 3)
//			{
//				ShowQQ();
//			}
//		}
//	}
//
//	
//}

void QQTools_CHC::ApplyQQ()
{
	system("CLS");
	QQ.emplace_back(new QQ_CHC());
	SaveQQ();

	cout << "按任意键返回" << endl;
	_getch();
	_getch();
	Menu();
}

void QQTools_CHC::LoginQQ()
{
	system("CLS");
	string ID;
	bool flag = false;
	string PassWord;
	bool flag1 = true;
	//vector<QQ_CHC*>::iterator iter = QQ.begin();
	cout << "输入你要登陆的QQ:" << endl;
	cin >> ID;
	QQid = ID;

	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == ID)
		{
			flag = true;
			GetFriends();//获取好友
			GetQQParty();//获取群
		}
	}
	if (flag != true)
	{
		cout << "没有该QQ号，请先申请" << endl;
		cout << "按任意键返回" << endl;
		_getch();
		Menu();
	}
	cout << "请输入该QQ的密码" << endl;
	cin >> PassWord;
	for (int i = 0 ; i < size(QQ) ; i++)
	{
		if (QQ[i]->ReturnID() == ID && QQ[i]->ReturnPassWord() == PassWord)
		{
			cout << "登陆成功" << endl;
			cout << "按任意键开始使用QQ" << endl;
			_getch();
			QQMenu();
			break;
		}
		else if (QQ[i]->ReturnID() == ID && QQ[i]->ReturnPassWord() != PassWord)
		{
			cout << "密码输入错误" << endl;
			cout << "请重新输入密码" << endl;
			cin >> PassWord;
			if (QQ[i]->ReturnPassWord() == PassWord)
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

			
	}
}

void QQTools_CHC::QQMenu()
{
	system("CLS");
	/*SetColor(6);*/
	int select;
	vector<QQFriends_CHC*> FL;
	vector<QQParties_CHC*> PL;
	int Myqq;
	cout << "欢迎使用QQ" << endl;
	cout << "你的QQ号为:" << QQid << endl;
	cout << "请选择使用的功能" << endl;
	cout << "1.好友功能" << endl;
	cout << "2.群功能" << endl;
	cout << "3.游戏功能" << endl;
	cout << "4.聊天功能" << endl;
	cout << "5.开通服务" << endl;
	//cout << "1.进入聊天室聊天" << endl;
	//cout << "2.添加QQ好友" << endl;
	//cout << "3,查看QQ好友" << endl;
	//cout << "4.创建QQ群" << endl;
	//cout << "5.加入QQ群" << endl;
	//cout << "6.查看自己所有QQ群" << endl;
	//cout << "7.管理QQ群" << endl;
	//cout << "8.删除QQ好友" << endl;
	//cout << "9.小游戏" << endl;
	//cout << "10.查看好友申请" << endl;
	//cout << "11.添加群管理员" << endl;
	//cout << "0.返回主菜单" << endl;
	cin >> select;
	switch (select)
	{
	case 1:

		/*Client();*/
		cout << "请选择使用的好友功能" << endl;
		cout << "1.添加好友" << endl;
		cout << "2.显示所有好友" << endl;
		cout << "3.删除好友" << endl;
		cout << "4.查看好友申请" << endl;
		cout << "0.返回QQ主菜单" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			AddFriend();
			break;
		case 2:
			ShowFriends();
			break;
		case 3:
			DeleteFriend();
			break;
		case 4:
			AgreeFriend();
			break;
		default:
			QQMenu();
			break;

		}
		break;

	case 2:

		cout << "请选择使用的群功能" << endl;
		cout << "1.加入QQ群" << endl;
		cout << "2.退出QQ群" << endl;
		cout << "3.创建QQ群" << endl;
		cout << "4.查看已加入的QQ群" << endl;
		cout << "5.查看入群申请" << endl;
		cout << "6.添加QQ群管理员" << endl;
		cout << "0.返回主菜单" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			AddPartyMember();
			break;
		case 2:
			/*cout << "退出QQ群没有开发完成" << endl;
			cout << "按任意键返回QQ主菜单" << endl;
			_getch();
			_getch();
			QQMenu();*/
			QuitParty();
			break;
		case 3:
			CreatQQparty();
			break;
		case 4:
			ShowQQParty();
			break;
		case 5:
			AgreeMember();
			break;
		case 6:
			AddPartyAdmin();
			break;
		default:
			QQMenu();
			break;
		}
		break;

	case 3:
		cout << "请选择玩的游戏" << endl;
		cout << "1.贪吃蛇" << endl;
		cout << "0.返回QQ主菜单" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			PlayGame();
			break;
		default:
			QQMenu();
			break;
		}
		break;

	case 4:
		cout << "请选择使用的聊天功能" << endl;
		cout << "1.进入聊天室" << endl;
		cout << "0.返回QQ主菜单" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			Client();
			break;
		default:
			QQMenu();
			break;
		}

	case 5:
		cout << "还没有开发完成" << endl;
		cout << "按任意键返回QQ主菜单" << endl;
		_getch();
		_getch();
		QQMenu();
		break;
	case 0:
		
		for (int i = 0; i < size(QQ); i++)
		{
			if (QQ[i]->ReturnID() == QQid)
			{
				Myqq = i;
			}
		}

		for (int i = 0; i < size(QQ[Myqq]->ReturnFriendList()); i++)
		{
			delete QQ[Myqq]->ReturnFriendList()[i];
		}
		QQ[Myqq]->ReturnFriendList().resize(0);
		QQ[Myqq]->ReturnFriendList().clear();
		QQ[Myqq]->ReturnFriendList().shrink_to_fit();
		for (int i = 0; i < size(QQ[Myqq]->ReturnPartyList()); i++)
		{
			delete  QQ[Myqq]->ReturnPartyList()[i];
		}
		QQ[Myqq]->ReturnPartyList().resize(0);
		QQ[Myqq]->ReturnPartyList().clear();
		QQ[Myqq]->ReturnPartyList().shrink_to_fit();
		/*delete QQ[Myqq];*/
		Menu();
		break;

	default:
		cout << "输入错误,按任意键返回QQ主页" << endl;
		_getch();
		QQMenu();
		break;

	}
	_getch();
}

void QQTools_CHC::AddFriend()
{
	system("CLS");
	int Myqq;
	string id;
	string name;
	bool flag = false;
	cout << "请输入添加好友的QQ号" << endl;
	cin >> id;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == id)
		{
			flag = true;
			name = QQ[i]->ReturnName();
			cout << "好友申请成功，请等待对方确认" << endl;
		}
	}

	if(flag == false)
		{
			cout << "该QQ还没有注册，按任意键重新输入QQ号" << endl;
			cout << "1.重新输入QQ号添加好友" << endl;
			cout << "2.返回QQ主页" << endl;
			int select;
			cin >> select;
			switch (select)
			{
			case 1:
				AddFriend();
				break;

			case 2:
				QQMenu();
				break;

			default:
				cout << "输入错误,按任意键返回QQ主页" << endl;
				_getch();
				QQMenu();
				break;
			}
			
		}
	
	string mark = "&";
	string ID = mark + id;
	if (flag)
	{
		for (int i = 0; i < size(QQ); i++)
		{
			if (QQ[i]->ReturnID() == QQid)
			{
				Myqq = i;
			}
		}
		QQ[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name , ID));
		QQ[Myqq]->ChangeFriendsNumber(QQ[Myqq]->ReturnFriendNumber() + 1);
	}
	SaveFriends();


	//向好友QQ文件中添加本QQ
	fstream file;
	string friendfilename = "QQ\\" + id + "\\" + id + "Friendlist.txt";
	file.open(friendfilename,ios::app);
	file << "^" <<QQ[Myqq]->ReturnID() << endl;
	file << QQ[Myqq]->ReturnName() << endl;
	file << " " << endl;
	file.close();

	cout << "按任意键返回QQ主页" << endl;
	_getch();
	_getch();
	QQMenu();
}

void QQTools_CHC::DeleteFriend()
{
	system("CLS");

	//显示所有好友
	int Myqq;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
		}
	}
	cout << "你有" << QQ[Myqq]->ReturnFriendNumber() << "个好友" << endl;
	for (int i = 0; i < QQ[Myqq]->ReturnFriendNumber(); i++)
	{
		cout << "第" << i + 1 << "位好友" << endl;
		cout << "姓名:" << QQ[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "QQ:" << QQ[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
	}


	//删除本QQ中的好友
	string qq;
	cout << "请输入想删除好友的QQ号" << endl;
	cin >> qq;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
			break;
		}
	}

	bool flag = false;
	for (int i = 0; i < size(QQ[Myqq]->ReturnFriendList()); i++)
	{
		if (QQ[Myqq]->ReturnFriendList()[i]->ReturnID() == qq)
		{
			flag = true;
		}
	}
	if (flag == false)
	{
		cout << "你没有此好友" << endl;
		cout << "1.重新输入QQ号" << endl;
		cout << "2.返回QQ主页" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			DeleteFriend();
			break;

		default:
			QQMenu();
			break;
		}
		
	}
	int num = QQ[Myqq]->ReturnFriendNumber();
	for (int i = 0; i < (QQ[Myqq]->ReturnFriendNumber()); i++)
	{
		if (QQ[Myqq]->ReturnFriendList()[i]->ReturnID() == qq)
		{
			QQ[Myqq]->ReturnFriendList().erase(QQ[Myqq]->ReturnFriendList().begin() + i);
			QQ[Myqq]->ReturnFriendList().resize(num - 1);//重新设置好友容器大小
			QQ[Myqq]->ChangeFriendsNumber(num - 1);
		}
	}
	
	/*SaveFriends();*/
	//删除本QQ中的好友QQ
	fstream myqqfile;
	string temp1;
	string content1;
	int word = 0;
	string myqqfilename = "QQ\\" + QQid + "\\" + QQid + "Friendlist.txt";
	string friendqqfilename = "QQ\\" + qq + "\\" + qq + "Friendlist.txt";
	myqqfile.open(myqqfilename);
	while (!myqqfile.eof())
	{
		getline(myqqfile, temp1);
		for (int i = 0; i < size(temp1); i++)
		{
			content1.push_back(temp1[i]);
			word++;
		}
		content1.push_back('\n');
		word++;
	}
	int m = content1.find(qq);//找到好友QQ文件中本QQ的位置
	for (int i = m; i < (m + word); i++)
	{
		content1.erase(content1.begin() + m);//删除
	}
	myqqfile.close();
	myqqfile.open(myqqfilename, ios::trunc | ios::out);
	myqqfile << content1;
	myqqfile.close();



	//删除好友QQ文件中的本QQ
	fstream outfile;
	outfile.open(friendqqfilename);
	string temp;
	string content;
	int words = 0;
	while (!outfile.eof())
	{
		getline(outfile, temp);
		for (int i = 0; i < size(temp); i++)
		{
			content.push_back(temp[i]);
			words++;
			//if (temp[i] < 0 || temp[i] > 127)//中文字符占两个字节
			//{
			//	words++;
			//}
		}
		content.push_back('\n');
		words++;
	}

	m =content.find(QQid);//找到好友QQ文件中本QQ的位置
	for (int i = m; i < (m + words); i++)
	{
		content.erase(content.begin()+m);//删除
	}
	outfile.close();

	outfile.open(friendqqfilename,ios::trunc|ios::out);
	outfile << content;
	outfile.close();

	cout << "删除好友成功" << endl;
	cout << "按任意键返回QQ主页" << endl;
	_getch();
	_getch();
	QQMenu();
}

void QQTools_CHC::ShowFriends()
{
	system("CLS");
	//GetFriends();

	int friendsnum;
	int Myqq;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
		}
	}
	friendsnum = size(QQ[Myqq]->ReturnFriendList());
	for (int i = 0; i < size(QQ[Myqq]->ReturnFriendList()); i++)
	{
		if ((QQ[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (QQ[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^' )//判断添加好友标记
		{
			friendsnum--;
		}
	}

	cout << "你有" << friendsnum << "个好友" << endl;
	int friends = 0;
	for (int i = 0; i < size(QQ[Myqq]->ReturnFriendList()); i++)
	{
		if ((QQ[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' ||(QQ[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^' )
		{
			continue;
		}
		cout << "第" << friends + 1 << "位好友" << endl;
		cout << "姓名:" << QQ[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "QQ:" << QQ[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
		friends++;
	}

	cout << "按任意键返回QQ主页" << endl;
	_getch();
	QQMenu();
}

void QQTools_CHC::GetFriends()
{
	ifstream file;
	string qq = QQid;
	string txt = ".txt";
	string filename = "QQ\\" + qq + "\\" + qq + "Friendlist.txt";
	string id;
	string name;
	char c;
	int line = 0;
	int Myqq;
	file.open(filename, ios::app);
	while (file.get(c))
	{
		if (c == ' ')
		{
			line++;
		}
	}
	file.close();
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
		}
	}
	QQ[Myqq]->ChangeFriendsNumber(line);
	file.open(filename, ios::app);
	for (int i = 0; i < line; i++)
	{
		file >> id;
		file >> name;
		QQ[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name, id));
	}

	file.close();
}

void QQTools_CHC::AgreeFriend()
{
	system("CLS");
	fstream myqqfile;
	string myqqfilename = "QQ\\" + QQid + "\\" + QQid + "Friendlist.txt";
	string friendqqfilename;


	myqqfile.open(myqqfilename);
	int Myqq, friendqq;
	string qq;
	string temp;
	string fdqq;

	string name, id;

	char c;
	int line = 0;
	bool flag = false;
	while (myqqfile.get(c))//获取申请人QQ
	{
		if (c == '^')
		{
			line++;
			flag = true;
			continue;
		}
		
		if (line == 1) //获取申请加好友的人QQ号
		{
			if (c == '\n')
			{
				break;
			}
			temp.push_back(c);
		}
	}
	if (flag == false)
	{
		cout << "没有好友申请" << endl;
		cout << "按任意键返回QQ主页" << endl;
		_getch();
		QQMenu();
	}
	myqqfile.close();
	fdqq = temp;
	/*string myqqfilename = "QQ\\" + QQid + "\\" + QQid + "Friendlist.txt";*/
	friendqqfilename = "QQ\\" + fdqq + "\\" + fdqq + "Friendlist.txt";

	//temp.pop_back();
	cout << "你是否同意" << temp << "的好友申请?" << endl;
	cout << "1.同意" << endl;
	cout << "2.拒绝" << endl;
	int select;
	cin >> select;

	string content;
	string msg;
	fstream friendqqfile;
	int n = 0;
	int linefriend = 0;
	string contentfriend;
	string msgfriend;

	switch (select)
	{
	case 1:
		myqqfile.open(myqqfilename);

		while (!myqqfile.eof())
		{

			//char ch[1000];

			getline(myqqfile, msg);
			for (int i = 0; i < size(msg); i++)
			{
				content.push_back(msg[i]);//读取文件内容
			}


			content.push_back('\n');

		}
		content.pop_back();
		content.shrink_to_fit();


		for (int i = 0; i < size(content); i++)//将未加入标记删除
		{
			if (content[i] == '^')
			{

				content.erase(content.begin() + i);
			}
		}

		myqqfile.close();

		myqqfile.open(myqqfilename, ios::out | ios::trunc); //清空原有文件内容

		myqqfile << content;

		cout << "确认申请成功" << endl;

		myqqfile.close();




		friendqqfile.open(friendqqfilename);
		
		while (!friendqqfile.eof())//获取好友文件内容
		{
			getline(friendqqfile, msgfriend);
			for (int i = 0; i < size(msgfriend); i++)
			{
				contentfriend.push_back(msgfriend[i]);
			}
			contentfriend.push_back('\n');
		}
		contentfriend.pop_back();
		contentfriend.shrink_to_fit();

		for (int i = 0; i < size(contentfriend); i++)//删除好友文件中的标记
		{
			if (contentfriend[i] == '&')
			{
				contentfriend.erase(contentfriend.begin() + i);
			}
		}
		friendqqfile.close();

		friendqqfile.open(friendqqfilename, ios::out | ios::trunc);//清空好友文件内容
		friendqqfile << contentfriend;//重新写入删除标记后的好友文件内容
		friendqqfile.close();

		for (int i = 0; i < size(QQ); i++)
		{
			if (QQ[i]->ReturnID() == QQid)
			{
				Myqq = i;
			}
		}
		for (int i = 0; i < size(QQ); i++)
		{
			if (QQ[i]->ReturnID() == fdqq)
			{
				friendqq = i;
			}
		}
		name = QQ[friendqq]->ReturnName();
		id = QQ[friendqq]->ReturnID();
		QQ[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name, id));
		QQ[Myqq]->ChangeFriendsNumber(QQ[Myqq]->ReturnFriendNumber() + 1);

		friendqqfile.close();
		cout << "确认申请成功" << endl;
		cout << "按任意键返回QQ主页" << endl;
		_getch();
		QQMenu();

		break;


	default:

		cout << "你已拒绝该请求" << endl;

		myqqfile.open(myqqfilename);

		while (!myqqfile.eof())
		{

			getline(myqqfile, msg);
			for (int i = 0; i < size(msg); i++)
			{
				content.push_back(msg[i]);//读取文件内容
			}

			content.push_back('\n');

		}
		content.pop_back();
		content.shrink_to_fit();

		for (int i = 0; i < size(content); i++)
		{
			if (content[i] == '^')
			{

				n = i;

				while (1)
				{
					content.erase(content.begin() + n); //删除申请人QQ


					if (content[n] == '\n')
					{
						content.erase(content.begin() + n);
						break;
					}

				}
				break;
			}
		}
		myqqfile.close();

		myqqfile.open(myqqfilename, ios::out | ios::trunc); //清空原有文件内容
		myqqfile << content;
		myqqfile.close();





		//删除好友文件中的QQ
		friendqqfile.open(friendqqfilename);
		while (!friendqqfile.eof())
		{
			getline(friendqqfile, msgfriend);

			for (int i = 0; i < size(msgfriend); i++)
			{
				contentfriend.push_back(msgfriend[i]);//读取文件内容
			}

			contentfriend.push_back('\n');
		}
		contentfriend.pop_back();
		contentfriend.shrink_to_fit();
		friendqqfile.close();
		
		for (int i = 0; i < size(contentfriend); i++) //删除好友文件中的本QQ
		{
			if (contentfriend[i] == '&')
			{

				n = i;

				while (1)
				{
					contentfriend.erase(contentfriend.begin() + n); //删除申请人QQ

					if (contentfriend[n] == '\n')
					{
						contentfriend.erase(contentfriend.begin() + n);
						break;
					}

				}
				break;
			}
		}
		friendqqfile.open(friendqqfilename, ios::out, ios::trunc);//清空原有内容
		friendqqfile << contentfriend;
		friendqqfile.close();

		
		


		cout << "按任意键返回QQ主页" << endl;
		_getch();
		QQMenu();
		break;
	}

}



void QQTools_CHC::CreatQQparty()//创建QQ群
{
	system("CLS");
	int Myqq;
	for (int i = 0; i<1000000; i++) //加强QQ群号生成随机性
	{
		srand(time(0));
	}
	int p = rand()*rand();
	char temp[128];
	itoa(p, temp, 10);
	string ID;
	/*cin >> ID;*/
	ID = string(temp);
	cout << "你的群号为:" << ID <<endl;
	QQparty = ID;
	cout << "请输入群名称" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
		}
	}
	QQ[Myqq]->ReturnPartyList().emplace_back(new QQParties_CHC(ID, name, QQid));
	QQ[Myqq]->ChangePartyNumbers(QQ[Myqq]->ReturnPartyNumber() + 1);
	SaveQQParty();


	//每个QQ都有自己的群列表
	fstream FILE;
	string qq;
	qq = QQid;
	string txt1 = "PartyList.txt";
	/*"QQ\\" + QQid + "\\" + QQid + ".txt";*/
	string FILEName = "QQ\\" + QQid + "\\" + QQid + "PartyList.txt";
	FILE.open(FILEName, ios::app);
	FILE << ID << endl;

	fstream PartyListFile;
	string PartyListFileName = "PartyList.txt";
	PartyListFile.open(PartyListFileName, ios::app);
	PartyListFile << ID << endl;

	PartyListFile.close();
	cout << "按任意键返回QQ主页" << endl;
	_getch();
	QQMenu();
}

//void AddQQParty()
//{
//	system("CLS");
//	int Myqq;
//	for (int i = 0; i < size(QQ); i++)
//	{
//		if (QQ[i]->ReturnID() == QQid)
//		{
//			Myqq = i;
//		}
//	}
//	cout << "请输入你想加入的群" << endl;
//	string partyid;
//	::PartyMember = partyid;
//	cin >> partyid;
//	string txt = ".txt";
//	string filename = partyid + txt;
//	ofstream file;
//	ifstream check;
//	check.open(filename,ios::in);
//	if (!check)
//	{
//		int select;
//		cout << "该QQ群还没有创建，请重新输入或返回QQ主页" << endl;
//		cout << "1.重新输入QQ群号" << endl;
//		cout << "2.返回QQ主页" << endl;
//		cin >> select;
//		switch (select)
//		{
//		case 1:
//			AddQQParty();
//			break;
//		
//		case 2:
//			QQMenu();
//			break;
//
//		default:
//			cout << "输入错误,按任意键返回QQ主页" << endl;
//			_getch();
//			QQMenu();
//			break;
//
//		}
//		
//	}
//	check.close();
//	file.open(filename, ios::app);
//	file << QQ[Myqq]->ReturnID() << endl;
//	file << QQ[Myqq]->ReturnName() << endl;
//	file << endl;
//	file.close();
//
//	AddPartyMember();
//
//	cout << "按任意键返回QQ主页" << endl;
//	_getch();
//	QQMenu();
//}

void QQTools_CHC::QuitParty()
{
	/*ShowQQParty();*/

	bool flag = false;
	int Myqq, select;
	string partyid;
	cout << "请输入你想退出的QQ群" << endl;
	cin >> partyid;

	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
			break;
		}
	}

	for (int i = 0; i < size(QQ[Myqq]->ReturnPartyList()); i++)
	{
		if (QQ[Myqq]->ReturnPartyList()[i]->ReturnPartyID() == partyid)
		{
			flag = true;
		}
	}

	if (flag == false)
	{
		cout << "你没有加入此群" << endl;
		cout << "请选择重新输入或返回QQ主菜单" << endl;
		cout << "1.重新输入QQ群" << endl;
		cout << "2.返回QQ主菜单" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			QuitParty();
			break;
		default:
			QQMenu();
			break;
		}
	}


	//向本QQ群列表中删除该群
	fstream myqqpartylistfile;
	string temp;//读取文件每行内容
	string content;//保存文件所有内容
	string myqqpartylistfilename = "QQ\\" + QQid + "\\" + QQid + "PartyList.txt";
	myqqpartylistfile.open(myqqpartylistfilename);

	while (!myqqpartylistfile.eof())
	{
		getline(myqqpartylistfile, temp);

		if (temp == partyid)
		{
			continue;
		}

		for (int i = 0; i < size(temp); i++)
		{
			content.push_back(temp[i]);
		}
		content.push_back('\n');

		
	}
	content.pop_back();//删除多余\n
	myqqpartylistfile.close();

	myqqpartylistfile.open(myqqpartylistfilename, ios::out | ios::trunc);
	myqqpartylistfile << content;
	myqqpartylistfile.close();



	//从本群列表中删除此QQ
	fstream partyfile;
	string partyfilename = "QQ\\Parties\\" + partyid + "\\" + partyid + ".txt";
	partyfile.open(partyfilename);
	string partycontent;
	string partytemp;
	vector<string> partyvec;

	while (!partyfile.eof())
	{
		getline(partyfile, partytemp);
		partyvec.push_back(partytemp);
		for (int i = 0; i < size(partytemp); i++)
		{
			partycontent.push_back(partytemp[i]);
		}

		partycontent.push_back('\n');
	}
	partycontent.pop_back();//删除末尾\n
	partyvec.pop_back();
	partyvec.pop_back();
	partyfile.close();
	partyvec.shrink_to_fit();

	partyfile.open(partyfilename, ios::out | ios::trunc);

	for (int i = 0; i < size(partyvec); i++)
	{
		if (partyvec[i] == QQid)
		{
			partyvec.erase(partyvec.begin() + i);
			break;
		}
	}
	partyvec.shrink_to_fit();
	for (int i = 0; i < size(partyvec); i++)
	{
		partyfile << partyvec[i] << endl;
	}
	/*partyfile << partycontent;*/
	partyfile.close();



	fstream partyadminfile;
	string partyadminfilename;
	string admincontent;
	string admintemp;
	vector<string> AdminQQ;
	partyadminfilename = "QQ\\Parties\\" + partyid + "\\" + partyid + "admin.txt";
	partyadminfile.open(partyadminfilename);
	
	while (!partyadminfile.eof())
	{
		getline(partyadminfile, admintemp);
		/*admintemp.push_back('\n');*/
		AdminQQ.push_back(admintemp);
		for (int i = 0; i < size(admintemp); i++)
		{
			admincontent.push_back(admintemp[i]);
		}

		admincontent.push_back('\n');
	}
	admincontent.pop_back();
	AdminQQ.pop_back();
	partyadminfile.close();

	bool adminflag = false;
	for (int i = 0; i < size(AdminQQ); i++)
	{
		if (AdminQQ[i] == QQid)
		{
			adminflag = true;
			break;
		}
	}


	if (adminflag == false)
	{
		cout << "退出群" << partyid << "成功" << endl;
		cout << "按任意键返回QQ主菜单" << endl;
		_getch();
		_getch();
		QQMenu();
	}

	partyadminfile.open(partyadminfilename, ios::out | ios::trunc);

	for (int i = 0; i < size(AdminQQ); i++)
	{
		if (AdminQQ[i] == QQid)
		{
			AdminQQ.erase(AdminQQ.begin() + i);
		}
	}

	AdminQQ.clear();
	AdminQQ.shrink_to_fit();
	for (int i = 0; i < size(AdminQQ); i++)
	{
		partyadminfile << AdminQQ[i] << endl;
	}

	partyadminfile.close();


	cout << "退出群" << partyid << "成功" << endl;
	cout << "按任意键返回QQ主菜单" << endl;

	_getch();
	_getch();
	QQMenu();
	

}



void QQTools_CHC::AddPartyAdmin()//添加群管理员
{

	cout << "请输入要管理的群号" << endl;
	int Myqq;
	char c;
	int line = 0;
	bool flag = false;
	string id;
	string txt = ".txt";
	cin >> id;
	string filename = "QQ\\Parties\\" + id + "\\" + id + ".txt";
	ifstream infile;
	string temp;
	//string id;
	vector<string>PartyMember;
	line = 0;
	infile.open(filename, ios::in);
	if (!infile)
	{
		cout << "没有此群,请重新输入或返回QQ主页" << endl;
		cout << "1.重新输入" << endl;
		cout << "2.返回QQ主页" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			AddPartyAdmin();
			break;

		default:
			QQMenu();
			break;
		}
	}
	infile.close();
	fstream outfile;
	outfile.open(filename);
	temp.clear();
	while (outfile.get(c))
	{
		if (c == '\n')
		{
			line++;
			continue;
		}
		if (line == 2) //获取群主QQ号
		{
			temp.push_back(c);
		}

	}
	/*temp.pop_back(); *///删除末尾\n

	if (temp != QQid)
	{
		cout << "你不是该群的群主,无法管理该群" << endl;
		cout << "按任意键返回QQ主页" << endl;
		_getch();
		_getch();
		QQMenu();
	}
	outfile.close();

	//获取群成员
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
		}
	}

	outfile.open(filename);

	line = 0;
	temp.clear();
	while (!outfile.eof())
	{
		getline(outfile, temp);
		
		if (temp == "★")
		{
			line++;
			continue;
		}
		/*if (line == 4)
		{
			continue;
		}*/
		if (line == 1)
		{
			PartyMember.push_back(temp);
		}
	}
	PartyMember.pop_back();
	line = 0;
	outfile.close();


	if (size(PartyMember) == 0)
	{
		cout << "此群没有成员请重新输入" << endl;
		cout << "按任意键返回QQ主页" << endl;
		_getch();
		_getch();
		QQMenu();
	}


	fstream adminfile;
	string adminfilename;
	adminfilename = "QQ\\Parties\\" + id + "\\" + id + "admin.txt";
	adminfile.open(adminfilename, ios::app);
	cout << "请输入你想添加的管理员QQ" << endl;
	string adminid;
	cin >> adminid;
	int adminqq;

	flag = false;

	
	for (int i = 0; i < size(PartyMember); i++)
	{
		if (PartyMember[i] == adminid)
		{
			flag = true;
		}
	}

	if (flag == false)
	{
		cout << "本群没有此成语请重新输入" << endl;
		AddPartyAdmin();
	}


	adminfile << adminid << endl;
	adminfile.close();


	fstream adminqqfile;
	string adminqqfilename;
	adminqqfilename = "QQ\\" + adminid + "\\" + adminid + "PartyList.txt";
	adminqqfile.open(adminqqfilename, ios::app);
	adminqqfile << id << endl;
	adminqqfile.close();



	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == adminid)
		{
			adminqq = i;
		}
	}


	fstream partyfile;
	string partyfilename;
	partyfilename = "QQ\\Parties" + id + "\\" + id + ".txt";
	partyfile.open(partyfilename, ios::app);
	partyfile << QQ[adminqq]->ReturnID() << endl;
	/*partyfile << QQ[adminqq]->ReturnName() << endl;*/
	partyfile.close();

	cout << "添加成功，按任意键返回QQ主页" << endl;
	_getch();
	_getch();
	QQMenu();
}


void QQTools_CHC::SaveQQParty() //每创建一个群便将该群保存成一个.txt文件
{
	system("CLS");
	int i = 0, Myqq, n;
	string ID;
	ID = QQparty;
	string txt = ".txt";
	string DirectoryName = "QQ\\Parties\\" + ID;
	CreateDirectory(DirectoryName.c_str(), NULL);
	string PartyID = "QQ\\Parties\\" + ID + "\\" + ID + ".txt";
	fstream file;
	file.open(PartyID, ios::app);
	for (i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
		}
	}
	for (n = 0; n < size(QQ[Myqq]->ReturnPartyList()); n++)
	{
	}
	file << QQ[Myqq]->ReturnPartyList()[n - 1]->ReturnPartyID() << endl;
	file << QQ[Myqq]->ReturnPartyList()[n - 1]->ReturnPartyName() << endl;
	file << QQ[Myqq]->ReturnPartyList()[n - 1]->ReturnCreatUserID() << endl;
	file << "★" << endl;
	file.close();

}

void QQTools_CHC::GetQQParty() //从文件读取该QQ的群，并保存到容器中
{
	int Myqq, line = 0;
	char c;
	string txt1 = "PartyList.txt";

	string txt = ".txt";

	ifstream listfile;

	ifstream partyfile;

	string qq = QQid;

	vector<string>party;

	string temp;
	/*string myqqfilename = "QQ\\" + QQid + "\\" + QQid + "Friendlist.txt";*/
	string filename = "QQ\\" + qq + "\\" + qq + "PartyList.txt";
	string partyfilename;

	listfile.open(filename);

	while (listfile.get(c))
	{
		string x;
		x = c;
		temp += x;

		if (c == '\n')
		{
			line++;
			temp.pop_back();
			party.emplace_back(temp);
			temp.clear();
		}
	}
	listfile.close();


	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
		}
	}
	QQ[Myqq]->ChangePartyNumbers(line);

	for (int i = 0; i < size(party); i++)
	{
		temp = party[i];
		/*filename = temp + txt;*/
		partyfilename = "QQ\\Parties\\" + temp + "\\" + temp + ".txt";
		partyfile.open(partyfilename);
		string id;
		string name;
		string userid;
		partyfile >> id;
		partyfile >> name;
		partyfile >> userid;
		partyfile.close();
		QQ[Myqq]->ReturnPartyList().emplace_back(new QQParties_CHC(id , name , userid));
	}

}

void QQTools_CHC::ShowQQParty()
{
	system("CLS");
	int Myqq;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
		}
	}
	cout << "你共有" << QQ[Myqq]->ReturnPartyNumber() << "个群" << endl;
	for (int i = 0; i < QQ[Myqq]->ReturnPartyNumber(); i++)
	{
		cout << "第" << QQ[Myqq]->ReturnPartyNumber() << "个群" << endl;
		cout << "群号:" << QQ[Myqq]->ReturnPartyList()[i]->ReturnPartyID() << endl;
		cout << "群名称:" << QQ[Myqq]->ReturnPartyList()[i]->ReturnPartyName() << endl;
		cout << "群主:" << QQ[Myqq]->ReturnPartyList()[i]->ReturnCreatUserID() << endl;
		cout << endl;
	}
	cout << "按任意键返回QQ主页" << endl;
	_getch();
	QQMenu();
}

void QQTools_CHC::AddPartyMember()
{
	system("CLS");
	cout << "请输入你想加入的群" << endl;
	string partyid;
	cin >> partyid;
	PartyMember = partyid;
	string id;
	int Myqq;
	id = PartyMember;
	string txt = ".txt";
	
	string filename = "QQ\\Parties\\" + partyid + "\\" + partyid + ".txt";
	ofstream ofile;
	ofile.open(filename,ios::app);
	ofile << "^" <<QQid  << endl;
	/*for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
		}
	}*/
	ofile.close();
	cout << "申请入群成功,请等待群主同意" << endl;
	cout << "按任意键返回QQ主页" << endl;
	_getch();
	QQMenu();
}

void QQTools_CHC::AgreeMember()//群主查看申请
{

	cout << "请输入要管理的群号" << endl;
	char c;
	int line = 0;
	bool flag = false;
	string id;
	string txt = ".txt";
	cin >> id;
	string filename = "QQ\\Parties\\" + id + "\\" + id + ".txt";
	ifstream infile;
	infile.open(filename,ios::in);
	if (!infile)
	{
		cout << "没有此群,请重新输入或返回QQ主页" << endl;
		cout << "1.重新输入" << endl;
		cout << "2.返回QQ主页" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			AgreeMember();
			break;

		case 2:
			QQMenu();
			break;
		}
	}
	infile.close();
	fstream outfile;
	outfile.open(filename);

	string temp;
	while (outfile.get(c))
	{
		if (c == '\n')
		{
			line++;
			continue;
		}
		if (line == 2) //获取群主QQ号
		{
			temp.push_back(c);
		}
		
	}
	/*temp.pop_back(); *///删除末尾\n

	if (temp != QQid)
	{
		cout << "你不是该群的群主,无法管理该群" << endl;
		cout << "按任意键返回QQ主页" << endl;
		_getch();
		_getch();
		QQMenu();
	}

	outfile.close();
	temp.clear();

	
	line = 0;
	outfile.open(filename);
	
	
	while (outfile.get(c))
	{
		if (c == '^')
		{
			line++;
			flag = true;
			continue;
		}
		if (line == 1) //获取申请入群的人QQ号
		{
			temp.push_back(c);
			//temp.clear();//清除■
			line++;
		}
		else if (line == 2)
		{
			temp.push_back(c);
		}

	}

	if (flag == false)
	{
		cout << "没有加群申请" << endl;
		cout << "按任意键返回QQ主页" << endl;
		_getch();
		QQMenu();
	}
		//}
		outfile.close();
		temp.pop_back();
		cout << "你是否同意" << temp << "入群?" << endl;
		cout << "1.同意" << endl;
		cout << "2.拒绝" << endl;
		int select;
		cin >> select;

		string member = temp;
		string PartyList = "PartyList.txt";
		string filename1 = "QQ\\" + member + "\\" + member + "PartyList.txt";
		string msg;
		vector<char> content;
		int n = 0;

		/*auto iter = content.begin();
		auto iter1 = temp.begin();*/
		/*int m = 0;*/
		/*char ch1[1000];*/
		/*int words = 0;*/

		switch (select)
		{
		case 1:
			outfile.open(filename, ios::in | ios::out);

			while (!outfile.eof())
			{

				char ch[1000];

				outfile.getline(ch,1000);
				for (int i = 0; i < strlen(ch); i++)
				{
					msg.push_back(ch[i]);//读取文件内容
				}
				
				
				msg.push_back('\n');

			}

			

			for (int i = 0; i < size(msg); i++)//将未加入标记删除
			{
				if (msg[i] == '^')
				{
					/*			content[i];*/
								//content.erase(content.begin() + i);
					msg.erase(msg.begin() + i);
				}
			}
			/*size(temp);*/
			/*cout << msg;*/
			

			outfile.close();

			outfile.open(filename, ios::out, ios::trunc); //清空原有文件内容
			
			outfile << msg;

			cout << "确认申请成功" << endl;

			outfile.close();

			outfile.open(filename1,ios::app);

			outfile << id << endl;

			cout << "按任意键返回QQ主页" << endl;
			_getch();
			QQMenu();

			break;


		default:

			cout << "你已拒绝该请求" << endl;
			outfile.open(filename);

			while (!outfile.eof())
			{

				char ch[1000];

				outfile.getline(ch, 1000);
				for (int i = 0; i < strlen(ch); i++)
				{
					msg.push_back(ch[i]);//读取文件内容
				}

				msg.push_back('\n');

			}
			outfile.close();

			/*while (outfile.get(c))
			{
				content.emplace_back(c);
			}*/

			for (int i = 0; i < size(msg); i++)
			{
				if (msg[i] == '^')
				{

					n = i;

					while (1)
					{
						msg.erase(msg.begin() + n); //删除申请人QQ


						if (msg[n] == '\n')
						{
							msg.erase(msg.begin() + n);
							break;
						}


					}

					break;
				}
			}

			outfile.open(filename, ios::out, ios::trunc);//清空原有内容

			outfile << msg;

			outfile.close();

			cout << "按任意键返回QQ主页" << endl;
			_getch();
			QQMenu();

			break;
		}

	
}

void QQTools_CHC::Client()//聊天服务器
{
	system("CLS");
	// 创建套节字
	cout << "按#键返回QQ主页" << endl;
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
		printf(" 连接聊天服务器失败connect() \n");
		cout << "按任意键返回QQ主页" << endl;
		_getch();
		QQMenu();
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
			printf("来自对方的消息：%s\n", buff);
		}

		// 向服务器端发送数据
		cout << "请发送消息:" << endl;
		cin >> szText;
		if (szText[0] == '#')
		{
			QQMenu();
		}
		szText[255] = '\0';
		::send(s, szText, strlen(szText), 0);

		cout << "请等待对方回复" << endl;
	}

	// 关闭套节字
	::closesocket(s);
}

void QQTools_CHC::PlayGame()
{
	Controller c;//声明一个Controller类

	c.Game();//整个游戏循环

	_getch();

}



