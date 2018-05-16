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
CInitSock initSock; // 初始化Winsock库
using namespace std;
vector<QQ_CHC*>QQ;
string QQid; //登陆的QQ号
string QQparty;//创建的群号;
string PartyMember; //申请加群的QQ号

void SaveQQ()
{
	ofstream file;
	file.open("QQ.txt",ios::app);
	auto iter = QQ.begin();
	int i = 0;
	for (i = 0; i < size(QQ); i++)
	{

	}
		file << QQ[i-1]->ReturnQQID() << endl;
		file << QQ[i-1]->ReturnQage() << endl;
		file << QQ[i-1]->ReturnQQPassWord() << endl;
		file << QQ[i-1]->ReturnQQName() << endl;
		file << QQ[i-1]->ReturnQQProvince() << endl;
		file << QQ[i-1]->ReturnQQAutograph() << endl;
		file << " "<<endl;
	file.close();
}

void SaveFriends()
{
	int i = 0, Myqq, n;
	ofstream file;
	string qq = ::QQid;
	string txt = ".txt";
	string filename = qq + txt;
	file.open(filename, ios::app);
	for (i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	for (n = 0; n < size(QQ[Myqq]->ReturnFriendList()); n++)
	{
	}
	file << QQ[Myqq]->ReturnFriendList()[n - 1]->ReturnFriendName() << endl;
	file << QQ[Myqq]->ReturnFriendList()[n - 1]->ReturnID() << endl;
	file << " " << endl;
	file.close();
}

void GetQQ()
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

void ShowQQ()
{
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
		cout << "QQ号:"<<qq[i]->ReturnQQID() << endl;
		cout << "Q龄:"<<qq[i]->ReturnQage() << endl;
		cout << "QQ密码:"<<qq[i]->ReturnQQPassWord() << endl;
		cout << "QQ名称:"<<qq[i]->ReturnQQName() << endl;
		cout << "所在地区:"<<qq[i]->ReturnQQProvince() << endl;
		cout << "个性签名:"<<qq[i]->ReturnQQAutograph() << endl;
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
	SetColor(6);
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
	system("CLS");
	QQ.emplace_back(new QQ_CHC());
	SaveQQ();
}

void LoginQQ()
{
	string ID;
	bool flag = false;
	string PassWord;
	//vector<QQ_CHC*>::iterator iter = QQ.begin();
	cout << "输入你要登陆的QQ:" << endl;
	cin >> ID;
	::QQid = ID;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ID)
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
		if (QQ[i]->ReturnQQID() == ID && QQ[i]->ReturnQQPassWord() == PassWord)
		{
			cout << "登陆成功" << endl;
			cout << "按任意键开始使用QQ" << endl;
			_getch();
			QQMenu();
			break;
		}
		else if (QQ[i]->ReturnQQID() == ID && QQ[i]->ReturnQQPassWord() != PassWord)
		{
			cout << "密码输入错误" << endl;
			cout << "请重新输入密码" << endl;
			cin >> PassWord;
			if (QQ[i]->ReturnQQPassWord() == PassWord)
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
	SetColor(6);
	int select;
	cout << "欢迎使用QQ" << endl;
	cout << "你的QQ号为:" << QQid << endl;
	cout << "请选择使用的功能" << endl;
	cout << "1.进入聊天室聊天" << endl;
	cout << "2.添加QQ好友" << endl;
	cout << "3,查看QQ好友" << endl;
	cout << "4.创建QQ群" << endl;
	cout << "5.加入QQ群" << endl;
	cout << "6.查看自己所有QQ群" << endl;
	cout << "7.管理QQ群" << endl;
	cout << "9.小游戏" << endl;
	cout << "0.返回主菜单" << endl;
	cin >> select;
	switch (select)
	{
	case 1:

		Client();
		break;

	case 2:

		AddFriend();
		break;

	case 3:
		ShowFriends();
		break;

	case 4:
		CreatQQparty();
		break;

	case 5:
		AddPartyMember();
		break;

	case 6:
		ShowQQParty();
		break;

	case 7:
		AgreeMember();
		break;

	case 9:
		PlayGame();
		break;

	case 0:
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

void AddFriend()
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
		if (QQ[i]->ReturnQQID() == id)
		{
			flag = true;
			name = QQ[i]->ReturnQQName();
			cout << "添加好友成功" << endl;
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
	
	if (flag)
	{
		for (int i = 0; i < size(QQ); i++)
		{
			if (QQ[i]->ReturnQQID() == ::QQid)
			{
				Myqq = i;
			}
		}
		QQ[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name , id));
		QQ[Myqq]->FriendsNumber++;
	}
	SaveFriends();
	cout << "按任意键返回QQ主页" << endl;
	_getch();
	QQMenu();
}

void ShowFriends()
{
	system("CLS");
	GetFriends();
	int Myqq;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	cout << "你有" << QQ[Myqq]->ReturnFriendsNumber() << "个好友" << endl;
	for (int i = 0; i < QQ[Myqq]->ReturnFriendsNumber(); i++)
	{
		cout << "第" << i + 1 << "位好友" << endl;
		cout << "姓名:" << QQ[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "QQ:" << QQ[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
	}
	cout << "按任意键返回QQ主页" << endl;
	_getch();
	QQMenu();
}

void GetFriends()
{
	ifstream file;
	string qq = ::QQid;
	string txt = ".txt";
	string filename = qq + txt;
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
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	QQ[Myqq]->FriendsNumber = line;
	file.open(filename, ios::app);
	for (int i = 0; i < line; i++)
	{
		file >> id;
		file >> name;
		QQ[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name, id));
	}

	file.close();
}

void CreatQQparty()
{
	int Myqq;
	system("CLS");
	cout << "请输入你想创建的群号" << endl;
	string ID;
	cin >> ID;
	::QQparty = ID;
	cout << "请输入群名称" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	QQ[Myqq]->ReturnPartyList().emplace_back(new QQParties_CHC(ID, name, ::QQid));
	QQ[Myqq]->PartyNumbers++;
	SaveQQParty();


	//每个QQ都有自己的群列表
	fstream FILE;
	string qq;
	qq = ::QQid;
	string txt1 = "PartyList.txt";
	string FILEName = qq + txt1;
	FILE.open(FILEName, ios::app);
	FILE << ID << endl;

	cout << "按任意键返回QQ主页" << endl;
	_getch();
	QQMenu();
}

void AddQQParty()
{
	system("CLS");
	int Myqq;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	cout << "请输入你想加入的群" << endl;
	string partyid;
	::PartyMember = partyid;
	cin >> partyid;
	string txt = ".txt";
	string filename = partyid + txt;
	ofstream file;
	ifstream check;
	check.open(filename,ios::in);
	if (!check)
	{
		int select;
		cout << "该QQ群还没有创建，请重新输入或返回QQ主页" << endl;
		cout << "1.重新输入QQ群号" << endl;
		cout << "2.返回QQ主页" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			AddQQParty();
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
	check.close();
	file.open(filename, ios::app);
	file << QQ[Myqq]->ReturnQQID() << endl;
	file << QQ[Myqq]->ReturnQQName() << endl;
	file << endl;
	file.close();

	AddPartyMember();

	cout << "按任意键返回QQ主页" << endl;
	_getch();
	QQMenu();
}

void SaveQQParty() //每创建一个群便将该群保存成一个.txt文件
{
	system("CLS");
	int i = 0, Myqq, n;
	string ID;
	ID = QQparty;
	string txt = ".txt";
	string PartyID = ID + txt;
	fstream file;
	file.open(PartyID, ios::app);
	for (i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
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

void GetQQParty() //从文件读取该QQ的群，并保存到容器中
{
	int Myqq, line = 0;
	char c;
	string txt1 = "PartyList.txt";

	string txt = ".txt";

	ifstream listfile;

	ifstream partyfile;

	string qq = ::QQid;

	vector<string>party;

	string temp;

	string filename = qq + txt1;

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
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	QQ[Myqq]->ChangePartyNumbers(line);

	for (int i = 0; i < size(party); i++)
	{
		temp = party[i];
		filename = temp + txt;
		partyfile.open(filename);
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

void ShowQQParty()
{
	system("CLS");
	GetQQParty();
	int Myqq;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	cout << "你共有" << QQ[Myqq]->ReturnPartyNumbers() << "个群" << endl;
	for (int i = 0; i < QQ[Myqq]->ReturnPartyNumbers(); i++)
	{
		cout << "第" << QQ[Myqq]->ReturnPartyNumbers() << "个群" << endl;
		cout << "群号:" << QQ[Myqq]->ReturnPartyList()[i]->ReturnPartyID() << endl;
		cout << "群名称:" << QQ[Myqq]->ReturnPartyList()[i]->ReturnPartyName() << endl;
		cout << "群主:" << QQ[Myqq]->ReturnPartyList()[i]->ReturnCreatUserID() << endl;
		cout << endl;
	}
	cout << "按任意键返回QQ主页" << endl;
	_getch();
	QQMenu();
}

void AddPartyMember()
{
	system("CLS");
	cout << "请输入你想加入的群" << endl;
	string partyid;
	cin >> partyid;
	::PartyMember = partyid;
	string id;
	int Myqq;
	id = ::PartyMember;
	string txt = ".txt";
	string filename = id + txt;
	ofstream ofile;
	ofile.open(filename,ios::app);
	ofile << "^" <<::QQid  << endl;
	/*for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
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

void AgreeMember()//群主查看申请
{
	cout << "请输入要管理的群号" << endl;
	char c;
	int line = 0;
	string id;
	string txt = ".txt";
	cin >> id;
	string filename = id + txt;
	ifstream infile;
	infile.open(filename,ios::in);
	if (!infile)
	{
		cout << "没有此群,请重新输入或返回QQ主页" << endl;
		cout << "重新输入" << endl;
		cout << "返回QQ主页" << endl;
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

	if (temp != ::QQid)
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
		//}
		outfile.close();
		temp.pop_back();
		cout << "你是否同意" << temp << "入群?" << endl;
		cout << "1.同意" << endl;
		cout << "2.拒绝" << endl;
		int select;
		cin >> select;

		vector<char> content;

		auto iter = content.begin();
		auto iter1 = temp.begin();
		int m = 0;

		string msg;
		/*char ch1[1000];*/

		int n = 0;
		/*int words = 0;*/
		switch (select)
		{
		case 1:
			outfile.open(filename, ios::in | ios::out);

			char ch;
			while (!outfile.eof())
			{

				char ch[1000];

				outfile.getline(ch,1000);
				for (int i = 0; i < strlen(ch); i++)
				{
					msg.push_back(ch[i]);//读取文件内容
				}
				
				
				msg.push_back('\n');
				//cout << msg << endl;

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

			break;

		default:
			cout << "你已拒绝该请求" << endl;
			outfile.open(filename, ios::in, ios::out);

			while (outfile.get(c))
			{
				content.emplace_back(c);
			}
			outfile.close();

			for (int i = 0; i < size(content); i++)
			{
				if (content[i] == '■')
				{

					n = i;

					while (1)
					{
						content.erase(content.begin() + n); //删除申请人QQ

						n++;

						if (content[n] == '\n')
						{
							content.erase(content.begin() + n);
							break;
						}


					}

					break;
				}
			}

			outfile.open(filename, ios::out, ios::trunc);//清空原有内容

			for (int i = 0; i < size(content); i++)
			{
				outfile << content[i];//把删除申请人QQ后的文件内容重新输入文件内
			}
			outfile.close();

			cout << "按任意键返回QQ主页" << endl;
			_getch();
			QQMenu();
			break;
		}

	
}

void Client()//聊天服务器
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

void PlayGame()
{
	Controller c;//声明一个Controller类

	c.Game();//整个游戏循环

	_getch();

}

string UTF8ToGB(const char* str)
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;

	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//获得临时变量的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
