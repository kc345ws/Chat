#include<iostream>
#include"tools.h"
#include<conio.h>
#include<fstream>
#include<time.h>
#include<windows.h>


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
		case 5:
			ShowFriendInformation();
			break;
		case 6:
			ChangeFriendRemarks();
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
			CreatParty();
			break;
		case 4:
			ShowParty();
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

void WeiChatToolsBase_CHC::CreatParty()
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
	cout << "你的群号为:" << ID << endl;
	WeiChatparty = ID;
	cout << "请输入群名称" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	WeiChatList[Myqq]->ReturnPartyList().emplace_back(new QQParties_CHC(ID, name, LoginedWeiChat));
	WeiChatList[Myqq]->ChangePartyNumbers(WeiChatList[Myqq]->ReturnPartyNumber() + 1);
	SaveParty();


	//每个QQ都有自己的群列表
	fstream FILE;
	string qq;
	qq = LoginedWeiChat;
	string txt1 = "PartyList.txt";
	/*"QQ\\" + QQid + "\\" + QQid + ".txt";*/
	string FILEName = "WeiChat\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "PartyList.txt";
	FILE.open(FILEName, ios::app);
	FILE << ID << endl;

	fstream PartyListFile;
	string PartyListFileName = "PartyList.txt";
	PartyListFile.open(PartyListFileName, ios::app);
	PartyListFile << ID << endl;

	PartyListFile.close();
	cout << "按任意键返回微信主页" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::SaveParty()
{
	system("CLS");
	int i = 0, Myqq, n;
	string ID;
	ID = WeiChatparty;
	string txt = ".txt";
	string DirectoryName = "WeiChat\\Parties\\" + ID;
	CreateDirectory(DirectoryName.c_str(), NULL);
	string PartyID = "WeiChat\\Parties\\" + ID + "\\" + ID + ".txt";
	fstream file;
	file.open(PartyID, ios::app);
	for (i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	for (n = 0; n < size(WeiChatList[Myqq]->ReturnPartyList()); n++)
	{
	}
	file << WeiChatList[Myqq]->ReturnPartyList()[n - 1]->ReturnPartyID() << endl;
	file << WeiChatList[Myqq]->ReturnPartyList()[n - 1]->ReturnPartyName() << endl;
	file << WeiChatList[Myqq]->ReturnPartyList()[n - 1]->ReturnCreatUserID() << endl;
	file << "★" << endl;
	file.close();
}

void WeiChatToolsBase_CHC::GetParty()
{
	int Myqq, line = 0;
	char c;
	string txt1 = "PartyList.txt";

	string txt = ".txt";

	ifstream listfile;

	ifstream partyfile;

	string qq = LoginedWeiChat;

	vector<string>party;

	string temp;
	/*string myqqfilename = "QQ\\" + QQid + "\\" + QQid + "Friendlist.txt";*/
	string filename = "WeiChat\\" + qq + "\\" + qq + "PartyList.txt";
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


	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	WeiChatList[Myqq]->ChangePartyNumbers(line);

	for (int i = 0; i < size(party); i++)
	{
		temp = party[i];
		/*filename = temp + txt;*/
		partyfilename = "WeiChat\\Parties\\" + temp + "\\" + temp + ".txt";
		partyfile.open(partyfilename);
		string id;
		string name;
		string userid;
		partyfile >> id;
		partyfile >> name;
		partyfile >> userid;
		partyfile.close();
		WeiChatList[Myqq]->ReturnPartyList().emplace_back(new QQParties_CHC(id, name, userid));
	}



	//获取群成员
	fstream QQPartyMemberFile;
	string QQPartyMemberFileName;
	string QQPartyMemberFileTemp;
	string OwnerQQ;
	vector<string>QQPartyMemberFileContent;

	int ThisPartyID;
	string QQPartyID;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}

	for (int i = 0; i < size(party); i++)
	{
		QQPartyMemberFileName = "WeiChat\\Parties\\" + party[i] + "\\" + party[i] + ".txt";
		QQPartyMemberFile.open(QQPartyMemberFileName);

		while (!QQPartyMemberFile.eof())
		{
			getline(QQPartyMemberFile, QQPartyMemberFileTemp);

			QQPartyMemberFileContent.push_back(QQPartyMemberFileTemp);
		}
		QQPartyID = QQPartyMemberFileContent[0];
		OwnerQQ = QQPartyMemberFileContent[2];
		QQPartyMemberFileContent.erase(QQPartyMemberFileContent.begin());
		QQPartyMemberFileContent.erase(QQPartyMemberFileContent.begin());
		QQPartyMemberFileContent.erase(QQPartyMemberFileContent.begin());
		QQPartyMemberFileContent.erase(QQPartyMemberFileContent.begin());
		if (QQPartyMemberFileContent.size() != 0)
		{
			QQPartyMemberFileContent.pop_back();
		}

		for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()); i++)
		{
			if (WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() == QQPartyID)
			{
				ThisPartyID = i;
				break;
			}
		}

		WeiChatList[Myqq]->ReturnPartyList()[ThisPartyID]->ReturnPartyMembers().push_back(OwnerQQ);
		for (int i = 0; i < QQPartyMemberFileContent.size(); i++)
		{
			WeiChatList[Myqq]->ReturnPartyList()[ThisPartyID]->ReturnPartyMembers().push_back(QQPartyMemberFileContent[i]);
		}


		//BUG修复
		QQPartyMemberFileContent.clear();
		QQPartyMemberFileContent.shrink_to_fit();
		QQPartyMemberFile.close();
	}




	//获取群管理员QQ
	fstream adminfile;
	string adminfilename;
	string admintemp;
	string ThidPartyID;

	//int ThisAdmin;
	/*vector<string> AdminQQ;*/
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()); i++)
	{
		ThidPartyID = WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID();

		adminfilename = "WeiChat\\Parties\\" + ThidPartyID + "\\" + ThidPartyID + "admin.txt";
		adminfile.open(adminfilename);

		while (!adminfile.eof())
		{

			getline(adminfile, admintemp);

			WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnAdminsID().push_back(admintemp);

		}
		if (WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnAdminsID().size() != 0)
		{
			WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnAdminsID().pop_back();
		}

		adminfile.close();

	}
	/*adminfilename = "QQ\\Parties\\" + id + "\\" + id + "admin.txt";*/
	/*adminfile.open(adminfilename);*/
	/*while (!adminfile.eof())
	{

	getline(adminfile, temp);

	AdminQQ.push_back(temp);

	}*/
	/*AdminQQ.pop_back();*/
}

void WeiChatToolsBase_CHC::DeleteFriend()
{
	system("CLS");

	//显示所有好友
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	cout << "你有" << WeiChatList[Myqq]->ReturnFriendNumber() << "个好友" << endl;
	for (int i = 0; i < WeiChatList[Myqq]->ReturnFriendNumber(); i++)
	{
		cout << "第" << i + 1 << "位好友" << endl;
		cout << "姓名:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "微信号:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
	}


	//删除本QQ中的好友
	string qq;
	cout << "请输入想删除好友的微信号" << endl;
	cin >> qq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
			break;
		}
	}

	bool flag = false;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() == qq)
		{
			flag = true;
		}
	}
	if (flag == false)
	{
		cout << "你没有此好友" << endl;
		cout << "1.重新输入微信号" << endl;
		cout << "2.返回微信主页" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			DeleteFriend();
			break;

		default:
			WeiChatMenu();
			break;
		}

	}
	int num = WeiChatList[Myqq]->ReturnFriendNumber();
	for (int i = 0; i < (WeiChatList[Myqq]->ReturnFriendNumber()); i++)
	{
		if (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() == qq)
		{
			WeiChatList[Myqq]->ReturnFriendList().erase(WeiChatList[Myqq]->ReturnFriendList().begin() + i);
			WeiChatList[Myqq]->ReturnFriendList().resize(num - 1);//重新设置好友容器大小
			WeiChatList[Myqq]->ChangeFriendsNumber(num - 1);
		}
	}

	/*SaveFriends();*/
	//删除本QQ中的好友QQ
	fstream myqqfile;
	string temp1;
	string content1;
	int word = 0;
	string myqqfilename = "WeiChat\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "Friendlist.txt";
	string friendqqfilename = "WeiChat\\" + qq + "\\" + qq + "Friendlist.txt";
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

	m = content.find(LoginedWeiChat);//找到好友QQ文件中本QQ的位置
	for (int i = m; i < (m + words); i++)
	{
		content.erase(content.begin() + m);//删除
	}
	outfile.close();

	outfile.open(friendqqfilename, ios::trunc | ios::out);
	outfile << content;
	outfile.close();

	cout << "删除好友成功" << endl;
	cout << "按任意键返回微信主页" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::AgreeFriend()
{
	system("CLS");
	fstream myqqfile;
	string myqqfilename = "WeiChat\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "Friendlist.txt";
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
	while (myqqfile.get(c))//获取申请人WeiChat
	{
		if (c == '^')
		{
			line++;
			flag = true;
			continue;
		}

		if (line == 1) //获取申请加好友的人WeiChat号
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
		cout << "按任意键返回WeiChat主页" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}
	myqqfile.close();
	fdqq = temp;
	/*string myqqfilename = "WeiChat\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "Friendlist.txt";*/
	friendqqfilename = "WeiChat\\" + fdqq + "\\" + fdqq + "Friendlist.txt";

	//temp.pop_back();
	cout << "你是否同意" << temp << "的好友申请?" << endl;
	cout << "1.同意" << endl;
	cout << "2.拒绝" << endl;

	string FriendApplyQQ = temp;

	int select;
	cin >> select;

	string content;
	string msg;
	fstream friendqqfile;
	int n = 0;
	int linefriend = 0;
	string contentfriend;
	string msgfriend;


	string myacepttemp;
	vector<string> myaceptcontent;
	string friendacepttemp;
	vector<string> friendaceptcontent;
	switch (select)
	{
	case 1:
		myqqfile.open(myqqfilename);


		while (!myqqfile.eof())
		{

			//char ch[1000];

			/*getline(myqqfile, msg);*/
			getline(myqqfile, myacepttemp);
			myaceptcontent.push_back(myacepttemp);

			//for (int i = 0; i < size(msg); i++)
			//{
			//	content.push_back(msg[i]);//读取文件内容
			//}


			//content.push_back('\n');

		}
		myaceptcontent.pop_back();
		/*content.pop_back();
		content.shrink_to_fit();*/


		//for (int i = 0; i < size(content); i++)//将未加入标记删除
		//{
		//	if (content[i] == '^')
		//	{

		//		content.erase(content.begin() + i);
		//	}
		//}
		for (int i = 0; i < size(myaceptcontent); i++)
		{
			if (myaceptcontent[i] == ("^" + FriendApplyQQ))
			{
				myaceptcontent[i] = FriendApplyQQ;
			}
		}

		myqqfile.close();

		myqqfile.open(myqqfilename, ios::out | ios::trunc); //清空原有文件内容

															/*myqqfile << content;*/
		for (int i = 0; i < size(myaceptcontent); i++)
		{
			myqqfile << myaceptcontent[i] << endl;
		}

		/*cout << "确认申请成功" << endl;*/

		myqqfile.close();





		friendqqfile.open(friendqqfilename);

		while (!friendqqfile.eof())//获取好友文件内容
		{

			/*getline(friendqqfile, msgfriend);*/
			getline(friendqqfile, friendacepttemp);
			friendaceptcontent.push_back(friendacepttemp);

			/*for (int i = 0; i < size(msgfriend); i++)
			{
			contentfriend.push_back(msgfriend[i]);
			}
			contentfriend.push_back('\n');*/
		}
		friendaceptcontent.pop_back();
		/*contentfriend.pop_back();
		contentfriend.shrink_to_fit();*/

		//for (int i = 0; i < size(contentfriend); i++)//删除好友文件中的标记
		//{
		//	if (contentfriend[i] == '&')
		//	{
		//		contentfriend.erase(contentfriend.begin() + i);
		//	}
		//}
		for (int i = 0; i < size(friendaceptcontent); i++)
		{
			if (friendaceptcontent[i] == ("&" + LoginedWeiChat))
			{
				friendaceptcontent[i] = LoginedWeiChat;
			}
		}
		friendqqfile.close();

		friendqqfile.open(friendqqfilename, ios::out | ios::trunc);//清空好友文件内容
																   //friendqqfile << contentfriend;//重新写入删除标记后的好友文件内容
		for (int i = 0; i < size(friendaceptcontent); i++)
		{
			friendqqfile << friendaceptcontent[i] << endl;
		}
		friendqqfile.close();

		for (int i = 0; i < size(WeiChatList); i++)
		{
			if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
			{
				Myqq = i;
			}
		}
		for (int i = 0; i < size(WeiChatList); i++)
		{
			if (WeiChatList[i]->ReturnID() == fdqq)
			{
				friendqq = i;
			}
		}
		name = WeiChatList[friendqq]->ReturnName();
		id = WeiChatList[friendqq]->ReturnID();
		WeiChatList[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name, id));
		WeiChatList[Myqq]->ChangeFriendsNumber(WeiChatList[Myqq]->ReturnFriendNumber() + 1);

		friendqqfile.close();
		cout << "确认申请成功" << endl;
		cout << "按任意键返回WeiChat主页" << endl;
		_getch();
		_getch();
		WeiChatMenu();

		break;


	default:

		cout << "你已拒绝该请求" << endl;

		myqqfile.open(myqqfilename);

		string myqqfiletemp;
		vector<string> myqqfilecontent;

		while (!myqqfile.eof())
		{

			/*getline(myqqfile, msg);*/
			getline(myqqfile, myqqfiletemp);

			myqqfilecontent.push_back(myqqfiletemp);

			//for (int i = 0; i < size(msg); i++)
			//{
			//	content.push_back(msg[i]);//读取文件内容
			//}

			//content.push_back('\n');

		}
		myqqfilecontent.pop_back();

		/*content.pop_back();
		content.shrink_to_fit();*/

		//for (int i = 0; i < size(content); i++)
		//{
		//	if (content[i] == '^')
		//	{

		//		n = i;

		//		while (1)
		//		{
		//			content.erase(content.begin() + n); //删除申请人WeiChat


		//			if (content[n] == '\n')
		//			{
		//				content.erase(content.begin() + n);
		//				break;
		//			}

		//		}
		//		break;
		//	}
		//}
		for (int i = 0; i < size(myqqfilecontent); i++)
		{
			if (myqqfilecontent[i] == ("^" + FriendApplyQQ))
			{
				myqqfilecontent.erase(myqqfilecontent.begin() + i);
				myqqfilecontent.erase(myqqfilecontent.begin() + i);
				myqqfilecontent.erase(myqqfilecontent.begin() + i);
				myqqfilecontent.erase(myqqfilecontent.begin() + i);
				break;
			}
		}
		myqqfile.close();
		myqqfilecontent.shrink_to_fit();

		myqqfile.open(myqqfilename, ios::out | ios::trunc); //清空原有文件内容
															/*myqqfile << content;*/

		for (int i = 0; i < size(myqqfilecontent); i++)
		{
			myqqfile << myqqfilecontent[i] << endl;
		}
		myqqfile.close();





		//删除好友文件中的WeiChat
		friendqqfile.open(friendqqfilename);
		string friendfiletemp;
		vector<string> friendfilecontent;

		while (!friendqqfile.eof())
		{
			/*getline(friendqqfile, msgfriend);*/
			getline(friendqqfile, friendfiletemp);
			friendfilecontent.push_back(friendfiletemp);

			//for (int i = 0; i < size(msgfriend); i++)
			//{
			//	contentfriend.push_back(msgfriend[i]);//读取文件内容
			//}

			//contentfriend.push_back('\n');
		}
		friendfilecontent.pop_back();
		friendqqfile.close();
		/*contentfriend.pop_back();
		contentfriend.shrink_to_fit();
		friendqqfile.close();*/

		//for (int i = 0; i < size(contentfriend); i++) //删除好友文件中的本WeiChat
		//{
		//	if (contentfriend[i] == '&')
		//	{

		//		n = i;

		//		while (1)
		//		{
		//			contentfriend.erase(contentfriend.begin() + n); //删除申请人WeiChat

		//			if (contentfriend[n] == '\n')
		//			{
		//				contentfriend.erase(contentfriend.begin() + n);
		//				break;
		//			}

		//		}
		//		break;
		//	}
		//}

		for (int i = 0; i < size(friendfilecontent); i++)
		{
			if (friendfilecontent[i] == ("&" + LoginedWeiChat))
			{
				friendfilecontent.erase(friendfilecontent.begin() + i);
				friendfilecontent.erase(friendfilecontent.begin() + i);
				friendfilecontent.erase(friendfilecontent.begin() + i);
				friendfilecontent.erase(friendfilecontent.begin() + i);
			}
		}
		friendfilecontent.shrink_to_fit();

		friendqqfile.open(friendqqfilename, ios::out, ios::trunc);//清空原有内容
																  /*friendqqfile << contentfriend;*/

		for (int i = 0; i < size(friendfilecontent); i++)
		{
			friendqqfile << friendfilecontent[i] << endl;
		}
		friendqqfile.close();





		cout << "按任意键返回WeiChat主页" << endl;
		_getch();
		WeiChatMenu();
		break;
	}
}

void WeiChatToolsBase_CHC::ShowFriendInformation()
{
	system("CLS");
	ShowFriendNoReturn();
	cout << "请输入你想查询的好友WeiChatList号，或输入#返回WeiChatList主菜单" << endl;
	string FriendQQ;
	cin >> FriendQQ;

	int Myqq;
	if (FriendQQ == "#")
	{
		WeiChatMenu();
	}

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}

	bool FriendCheckFlag = false;
	while (1)
	{
		for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
		{
			if (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() == FriendQQ)
			{
				FriendCheckFlag = true;
			}
		}
		if (FriendCheckFlag == true)
		{
			break;
		}
		else
		{
			cout << "你没有此好友，请重新输入或输入#返回WeiChatList主菜单" << endl;
			cin >> FriendQQ;
			if (FriendQQ == "#")
			{
				WeiChatMenu();
			}
			else
			{
				continue;
			}
		}
	}

	int friendid;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == FriendQQ)
		{
			friendid = i;
		}
	}

	int friendremarks;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() == FriendQQ)
		{
			friendremarks = i;
		}
	}

	cout << "以下为此好友信息" << endl;
	cout << "帐号:" << WeiChatList[friendid]->ReturnID() << endl;
	cout << "姓名:" << WeiChatList[friendid]->ReturnName() << endl;
	cout << "备注:" << WeiChatList[Myqq]->ReturnFriendList()[friendremarks]->ReturnRemarks() << endl;
	cout << "个性签名:" << WeiChatList[friendid]->ReturnAutograph() << endl;
	cout << "所在地区:" << WeiChatList[friendid]->ReturnArea() << endl;

	cout << endl;

	cout << "按任意键返回WeiChatList主菜单" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ShowFriendNoReturn()
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
}

void WeiChatToolsBase_CHC::ChangeFriendRemarks()
{
	system("CLS");
	ShowFriendNoReturn();
	cout << "请输入你想查询的好友WeiChatList号，或输入#返回WeiChatList主菜单" << endl;
	string FriendQQ;
	cin >> FriendQQ;

	int Myqq;
	if (FriendQQ == "#")
	{
		WeiChatMenu();
	}

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}

	bool FriendCheckFlag = false;
	while (1)
	{
		for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
		{
			if (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() == FriendQQ)
			{
				FriendCheckFlag = true;
			}
		}
		if (FriendCheckFlag == true)
		{
			break;
		}
		else
		{
			cout << "你没有此好友，请重新输入或输入#返回WeiChatList主菜单" << endl;
			cin >> FriendQQ;
			if (FriendQQ == "#")
			{
				WeiChatMenu();
			}
			else
			{
				continue;
			}
		}
	}



	cout << "请输入你想修改的备注" << endl;
	string NewRemarks;
	cin >> NewRemarks;



	int friendid;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() == FriendQQ)
		{
			friendid = i;
		}
	}

	WeiChatList[Myqq]->ReturnFriendList()[friendid]->ChangeRemarks(NewRemarks);
	SaveChange();

	cout << "修改备注成功" << endl;
	cout << "按任意键返回WeiChatList主菜单" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::SaveChange()
{
	fstream qqfile;
	string qqfilename = "WeiChat.txt";
	qqfile.open(qqfilename, ios::trunc | ios::out);
	for (int i = 0; i < size(WeiChatList); i++)
	{
		qqfile << WeiChatList[i]->ReturnID() << endl;
		qqfile << WeiChatList[i]->ReturnAge() << endl;
		qqfile << WeiChatList[i]->ReturnPassWord() << endl;
		qqfile << WeiChatList[i]->ReturnName() << endl;
		qqfile << WeiChatList[i]->ReturnArea() << endl;
		qqfile << WeiChatList[i]->ReturnAutograph() << endl;
		qqfile << " " << endl;
	}
	qqfile.close();


	fstream qqfriendlistfile;
	string qqfriendlistfilename = "WeiChatList\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "Friendlist.txt";
	qqfriendlistfile.open(qqfriendlistfilename, ios::out | ios::trunc);

	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}

	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		qqfriendlistfile << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		qqfriendlistfile << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		qqfriendlistfile << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnRemarks() << endl;
		qqfriendlistfile << " " << endl;
	}
	qqfriendlistfile.close();
}

void WeiChatToolsBase_CHC::ShowParty()
{
	system("CLS");
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	cout << "你共有" << WeiChatList[Myqq]->ReturnPartyNumber() << "个群" << endl;
	for (int i = 0; i < WeiChatList[Myqq]->ReturnPartyNumber(); i++)
	{
		cout << "第" << WeiChatList[Myqq]->ReturnPartyNumber() << "个群" << endl;
		cout << "群号:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() << endl;
		cout << "群名称:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyName() << endl;
		cout << "群主:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnCreatUserID() << endl;
		cout << endl;
	}
	cout << "按任意键返回WeiChatList主页" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

