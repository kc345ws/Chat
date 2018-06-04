#include<iostream>
#include"tools.h"
#include<conio.h>
#include<fstream>


void WeiChatToolsBase_CHC::Menu()
{
	system("CLS");
	int select;
	cout << "请选择你所需的功能" << endl;
	cout << "1.登陆微信" << endl;
	cout << "2.注册微信" << endl;
	cout << "3.已注册微信绑定QQ" << endl;


	cin >> select;

	switch (select)
	{
	case 1:
		Login();
		break;
	case 2:
		Apply();
		break;
	case 3:
		ShowWeiChat();
		break;
	default:
		Menu();
		break;
	}
}

void WeiChatToolsBase_CHC::Apply()
{
	system("CLS");
	WeiChatList.emplace_back(new WeiChat_CHC());
	SaveWeiChat();

	cout << "按任意键返回" << endl;
	_getch();
	_getch();
	Menu();
}

void WeiChatToolsBase_CHC::SaveWeiChat()
{
	ofstream file;
	file.open("WeiChat.txt", ios::app);
	/*auto iter = WeiChatList.begin();*/
	int i = 0;
	for (i = 0; i < size(WeiChatList); i++)
	{

	}
	file << WeiChatList[i - 1]->ReturnID() << endl;
	file << WeiChatList[i - 1]->ReturnAge() << endl;
	/*file << WeiChatList[i - 1]->ReturnApplyDate().ReturnDate() << endl;*/
	file << WeiChatList[i - 1]->ReturnPassWord() << endl;
	file << WeiChatList[i - 1]->ReturnName() << endl;
	file << WeiChatList[i - 1]->ReturnArea() << endl;
	file << WeiChatList[i - 1]->ReturnAutograph() << endl;
	file << " " << endl;
	file.close();
}

void WeiChatToolsBase_CHC::GetWeiChat()
{
	int qage;
	string qqid;
	string qqpw, qqname, qqpv, qqag;
	ifstream file;
	int line = 0;
	char c;
	file.open("WeiChat.txt");
	while (file.get(c))
	{
		if (c == ' ')
		{
			line++;
		}
	}
	file.close();
	file.open("WeiChat.txt");
	for (int i = 0; i < line; i++)
	{
		file >> qqid;
		file >> qage;
		file >> qqpw;
		file >> qqname;
		file >> qqpv;
		file >> qqag;
		//QQ_CHC qq(qqid, qage, qqpw, qqname, qqpv,qqag);
		WeiChatList.emplace_back(new WeiChat_CHC(qqid, qage, qqpw, qqname, qqpv, qqag));
	}
}

void WeiChatToolsBase_CHC::Login()
{
	system("CLS");
	string ID;
	bool flag = false;
	string PassWord;
	bool flag1 = true;
	//vector<QQ_CHC*>::iterator iter = QQ.begin();
	cout << "输入你要登陆的微信:" << endl;
	cin >> ID;
	LoginedWeiChat = ID;

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == ID)
		{
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		while (1)
		{
			cout << "没有该微信号，请重新输入或按#返回主菜单" << endl;
			cin >> ID;
			if (ID == "#")
			{
				Menu();
			}
			else
			{
				for (int i = 0; i < size(WeiChatList); i++)
				{
					if (WeiChatList[i]->ReturnID() == ID)
					{
						flag = true;
						break;
					}
				}
			}
			if (flag == true)
			{
				break;
			}
			/*cout << "按任意键返回" << endl;
			_getch();
			_getch();
			Menu();*/
		}
	}
	//if (flag != true)
	//{
	//	cout << "没有该QQ号，请先申请" << endl;
	//	cout << "按任意键返回" << endl;
	//	_getch();
	//	Menu();
	//}
	cout << "请输入该微信的密码" << endl;
	cin >> PassWord;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == ID && WeiChatList[i]->ReturnPassWord() == PassWord)
		{
			GetFriends();//获取好友
			//GetQQParty();//获取群
			cout << "登陆成功" << endl;
			cout << "按任意键开始使用微信" << endl;
			_getch();
			WeiChatMenu();
			break;
		}
		else if (WeiChatList[i]->ReturnID() == ID && WeiChatList[i]->ReturnPassWord() != PassWord)
		{
			cout << "密码输入错误" << endl;
			cout << "请重新输入密码,或输入#返回主菜单" << endl;
			cin >> PassWord;
			if (PassWord == "#")
			{
				Menu();
			}
			while (1)
			{
				if (WeiChatList[i]->ReturnPassWord() == PassWord)
				{
					cout << "登陆成功" << endl;
					cout << "按任意键开始使用QQ" << endl;
					_getch();
					_getch();
					WeiChatMenu();
				}
				else
				{
					cout << "密码输入错误" << endl;
					cout << "请重新输入密码,或输入#返回主菜单" << endl;
					cin >> PassWord;
					if (PassWord == "#")
					{
						Menu();
					}
					continue;
				}
			}
			/*	if (QQ[i]->ReturnPassWord() == PassWord)
			{
			cout << "登陆成功" << endl;
			cout << "按任意键开始使用QQ" << endl;
			_getch();
			_getch();
			QQMenu();
			break;
			}
			else
			{
			cout << "密码输入错误" << endl;
			cout << "请重新输入密码" << endl;
			cin >> PassWord;
			}
			break;*/
		}


	}
}

void WeiChatToolsBase_CHC::ShowWeiChat()
{
	system("CLS");
	vector<WeiChat_CHC*>WeiChat;
	int  qage;
	string qqid;
	string qqpw, qqname, qqpv, qqag;
	ifstream file;
	int line = 0;
	char c;

	file.open("WeiChat.txt");
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
		WeiChat.emplace_back(new WeiChat_CHC(qqid, qage, qqpw, qqname, qqpv, qqag));
	}
	for (int i = 0; i < line; i++)
	{
		cout << "微信号:" << WeiChat[i]->ReturnID() << endl;
		cout << "微龄:" << WeiChat[i]->ReturnAge() << endl;
		cout << "微信密码:" << WeiChat[i]->ReturnPassWord() << endl;
		cout << "微信名称:" << WeiChat[i]->ReturnName() << endl;
		cout << "所在地区:" << WeiChat[i]->ReturnArea() << endl;
		cout << "个性签名:" << WeiChat[i]->ReturnAutograph() << endl;
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

void WeiChatToolsBase_CHC::WeiChatMenu()
{
	system("CLS");
	/*SetColor(6);*/
	int select;
	//vector<QQFriends_CHC*> FL;
	//vector<QQParties_CHC*> PL;
	int Myqq;
	cout << "欢迎使用微信" << endl;
	cout << "你的微信号为:" << LoginedWeiChat << endl;
	cout << "请选择使用的功能" << endl;
	cout << "1.好友功能" << endl;
	cout << "2.群功能" << endl;
	cout << "3.游戏功能" << endl;
	cout << "4.聊天功能" << endl;
	cout << "5.个人资料" << endl;
	cout << "6.开通服务" << endl;
	cout << "0.返回主菜单" << endl;
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
		cout << "5.查看好友资料" << endl;
		cout << "6.修改好友备注" << endl;
		cout << "0.返回QQ主菜单" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			/*AddFriend();*/
			break;
		case 2:
			/*ShowFriends();*/
			break;
		case 3:
			/*DeleteFriend();*/
			break;
		case 4:
			/*AgreeFriend();*/
			break;
		case 5:
			/*ShowFriendInformation();*/
			break;
		case 6:
			/*ChangeFriendRemarks();*/
			break;
		default:
			WeiChatMenu();
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
		cout << "7.踢出群成员" << endl;
		cout << "8.查看群成员信息" << endl;
		cout << "0.返回主菜单" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			/*AddPartyMember();*/
			break;
		case 2:
			/*QuitParty();*/
			break;
		case 3:
			/*CreatQQparty();*/
			break;
		case 4:
			/*ShowQQParty();*/
			break;
		case 5:
			/*AgreeMember();*/
			break;
		case 6:
		/*	AddPartyAdmin();*/
			break;
		case 7:
			/*DeletePartyMember();*/
			break;
		case 8:
			/*ShowPartyInformation();*/
			break;
		default:
			WeiChatMenu();
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
			/*PlayGame();*/
			break;
		default:
			WeiChatMenu();
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
			/*Client();*/
			break;
		default:
			WeiChatMenu();
			break;
		}

	case 5:
		cout << "请选择所需的资料功能" << endl;
		cout << "1.查看个人资料" << endl;
		cout << "2.修改密码" << endl;
		cout << "3.修改名称" << endl;
		cout << "4.修改签名" << endl;
		cout << "5.修改所在地" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			/*ShowMyInformation();*/
			break;
		case 2:
			/*ChangePassWord();*/
			break;
		case 3:
			/*ChangeName();*/
			break;
		case 4:
			/*ChangeAutoGraph();*/
			break;
		case 5:
			/*ChangeArea();*/
			break;
		default:
			WeiChatMenu();
			break;
		}
		break;
	case 6:
		cout << "请选择所需功能:" << endl;
		cout << "1.开通微博" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			/*CreateWeiBo();*/
			break;
		default:
			cout << "选择错误，按任意键返回QQ主菜单" << endl;
			_getch();
			_getch();
			WeiChatMenu();
			break;
		}
		break;
	case 0:

		for (int i = 0; i < size(WeiChatList); i++)
		{
			if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
			{
				Myqq = i;
			}
		}

		/*for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
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
		QQ[Myqq]->ReturnPartyList().shrink_to_fit();*/
		/*delete QQ[Myqq];*/
		Menu();
		break;

	default:
		WeiChatMenu();
		break;

	}
	_getch();
}

void WeiChatToolsBase_CHC::AddFriend()
{
	system("CLS");
	int Myqq;
	string id;
	string name;
	bool flag = false;
	cout << "请输入添加好友的QQ号" << endl;
	cin >> id;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == id)
		{
			flag = true;
			name = WeiChatList[i]->ReturnName();
			cout << "好友申请成功，请等待对方确认" << endl;
		}
	}

	if (flag == false)
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
			WeiChatMenu();
			break;

		default:
			cout << "输入错误,按任意键返回QQ主页" << endl;
			_getch();
			WeiChatMenu();
			break;
		}

	}

	string mark = "&";
	string ID = mark + id;
	if (flag)
	{
		for (int i = 0; i < size(WeiChatList); i++)
		{
			if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
			{
				Myqq = i;
			}
		}
		WeiChatList[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name, ID));
		WeiChatList[Myqq]->ChangeFriendsNumber(WeiChatList[Myqq]->ReturnFriendNumber() + 1);
	}
	SaveFriends();


	//向好友QQ文件中添加本QQ
	fstream file;
	string friendfilename = "QQ\\" + id + "\\" + id + "Friendlist.txt";
	string remarks = "未备注";
	file.open(friendfilename, ios::app);
	file << "^" << WeiChatList[Myqq]->ReturnID() << endl;
	file << WeiChatList[Myqq]->ReturnName() << endl;
	file << remarks << endl;
	file << " " << endl;
	file.close();

	cout << "按任意键返回QQ主页" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::SaveFriends()
{
	int i = 0, Myqq, n;
	ofstream file;
	string qq = LoginedWeiChat;
	string txt = ".txt";
	string filename = "WeiChat\\" + qq + "\\" + qq + "Friendlist.txt";
	file.open(filename, ios::app);
	for (i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	for (n = 0; n < size(WeiChatList[Myqq]->ReturnFriendList()); n++)
	{
	}

	if (n > 0)
	{
		file << WeiChatList[Myqq]->ReturnFriendList()[n - 1]->ReturnID() << endl;
		file << WeiChatList[Myqq]->ReturnFriendList()[n - 1]->ReturnFriendName() << endl;
		file << WeiChatList[Myqq]->ReturnFriendList()[n - 1]->ReturnRemarks() << endl;
		file << " " << endl;
		file.close();
	}
	else
	{
		file.close();
		file.open(filename, ios::trunc | ios::out);//清空文件内容
		file.close();
	}
}

void WeiChatToolsBase_CHC::GetFriends()
{
	ifstream file;
	string qq = LoginedWeiChat;
	string txt = ".txt";
	string filename = "WeiChat\\" + qq + "\\" + qq + "Friendlist.txt";
	string id;
	string name;
	string remarks;
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
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	WeiChatList[Myqq]->ChangeFriendsNumber(line);
	file.open(filename, ios::app);
	for (int i = 0; i < line; i++)
	{
		file >> id;
		file >> name;
		file >> remarks;
		WeiChatList[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name, id, remarks));
	}

	file.close();
}

void WeiChatToolsBase_CHC::ShowFriends()
{
	system("CLS");
	//GetFriends();

	int friendsnum;
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	friendsnum = size(WeiChatList[Myqq]->ReturnFriendList());
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')//判断添加好友标记
		{
			friendsnum--;
		}
	}

	cout << "你有" << friendsnum << "个好友" << endl;
	int friends = 0;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')
		{
			continue;
		}
		cout << "第" << friends + 1 << "位好友" << endl;
		cout << "姓名:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "QQ:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
		friends++;
	}

	cout << "按任意键返回QQ主页" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}