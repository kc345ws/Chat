#include<iostream>
#include"tools.h"
#include<conio.h>
#include<fstream>


void WeiChatToolsBase_CHC::Menu()
{
	system("CLS");
	int select;
	cout << "��ѡ��������Ĺ���" << endl;
	cout << "1.��½΢��" << endl;
	cout << "2.ע��΢��" << endl;
	cout << "3.��ע��΢�Ű�QQ" << endl;


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

	cout << "�����������" << endl;
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
	cout << "������Ҫ��½��΢��:" << endl;
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
			cout << "û�и�΢�źţ������������#�������˵�" << endl;
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
			/*cout << "�����������" << endl;
			_getch();
			_getch();
			Menu();*/
		}
	}
	//if (flag != true)
	//{
	//	cout << "û�и�QQ�ţ���������" << endl;
	//	cout << "�����������" << endl;
	//	_getch();
	//	Menu();
	//}
	cout << "�������΢�ŵ�����" << endl;
	cin >> PassWord;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == ID && WeiChatList[i]->ReturnPassWord() == PassWord)
		{
			GetFriends();//��ȡ����
			//GetQQParty();//��ȡȺ
			cout << "��½�ɹ�" << endl;
			cout << "���������ʼʹ��΢��" << endl;
			_getch();
			WeiChatMenu();
			break;
		}
		else if (WeiChatList[i]->ReturnID() == ID && WeiChatList[i]->ReturnPassWord() != PassWord)
		{
			cout << "�����������" << endl;
			cout << "��������������,������#�������˵�" << endl;
			cin >> PassWord;
			if (PassWord == "#")
			{
				Menu();
			}
			while (1)
			{
				if (WeiChatList[i]->ReturnPassWord() == PassWord)
				{
					cout << "��½�ɹ�" << endl;
					cout << "���������ʼʹ��QQ" << endl;
					_getch();
					_getch();
					WeiChatMenu();
				}
				else
				{
					cout << "�����������" << endl;
					cout << "��������������,������#�������˵�" << endl;
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
			cout << "��½�ɹ�" << endl;
			cout << "���������ʼʹ��QQ" << endl;
			_getch();
			_getch();
			QQMenu();
			break;
			}
			else
			{
			cout << "�����������" << endl;
			cout << "��������������" << endl;
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
		cout << "΢�ź�:" << WeiChat[i]->ReturnID() << endl;
		cout << "΢��:" << WeiChat[i]->ReturnAge() << endl;
		cout << "΢������:" << WeiChat[i]->ReturnPassWord() << endl;
		cout << "΢������:" << WeiChat[i]->ReturnName() << endl;
		cout << "���ڵ���:" << WeiChat[i]->ReturnArea() << endl;
		cout << "����ǩ��:" << WeiChat[i]->ReturnAutograph() << endl;
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

	cout << "�����������" << endl;
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
	cout << "��ӭʹ��΢��" << endl;
	cout << "���΢�ź�Ϊ:" << LoginedWeiChat << endl;
	cout << "��ѡ��ʹ�õĹ���" << endl;
	cout << "1.���ѹ���" << endl;
	cout << "2.Ⱥ����" << endl;
	cout << "3.��Ϸ����" << endl;
	cout << "4.���칦��" << endl;
	cout << "5.��������" << endl;
	cout << "6.��ͨ����" << endl;
	cout << "0.�������˵�" << endl;
	//cout << "1.��������������" << endl;
	//cout << "2.���QQ����" << endl;
	//cout << "3,�鿴QQ����" << endl;
	//cout << "4.����QQȺ" << endl;
	//cout << "5.����QQȺ" << endl;
	//cout << "6.�鿴�Լ�����QQȺ" << endl;
	//cout << "7.����QQȺ" << endl;
	//cout << "8.ɾ��QQ����" << endl;
	//cout << "9.С��Ϸ" << endl;
	//cout << "10.�鿴��������" << endl;
	//cout << "11.���Ⱥ����Ա" << endl;
	//cout << "0.�������˵�" << endl;
	cin >> select;
	switch (select)
	{
	case 1:

		/*Client();*/
		cout << "��ѡ��ʹ�õĺ��ѹ���" << endl;
		cout << "1.��Ӻ���" << endl;
		cout << "2.��ʾ���к���" << endl;
		cout << "3.ɾ������" << endl;
		cout << "4.�鿴��������" << endl;
		cout << "5.�鿴��������" << endl;
		cout << "6.�޸ĺ��ѱ�ע" << endl;
		cout << "0.����QQ���˵�" << endl;
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

		cout << "��ѡ��ʹ�õ�Ⱥ����" << endl;
		cout << "1.����QQȺ" << endl;
		cout << "2.�˳�QQȺ" << endl;
		cout << "3.����QQȺ" << endl;
		cout << "4.�鿴�Ѽ����QQȺ" << endl;
		cout << "5.�鿴��Ⱥ����" << endl;
		cout << "6.���QQȺ����Ա" << endl;
		cout << "7.�߳�Ⱥ��Ա" << endl;
		cout << "8.�鿴Ⱥ��Ա��Ϣ" << endl;
		cout << "0.�������˵�" << endl;
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
		cout << "��ѡ�������Ϸ" << endl;
		cout << "1.̰����" << endl;
		cout << "0.����QQ���˵�" << endl;
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
		cout << "��ѡ��ʹ�õ����칦��" << endl;
		cout << "1.����������" << endl;
		cout << "0.����QQ���˵�" << endl;
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
		cout << "��ѡ����������Ϲ���" << endl;
		cout << "1.�鿴��������" << endl;
		cout << "2.�޸�����" << endl;
		cout << "3.�޸�����" << endl;
		cout << "4.�޸�ǩ��" << endl;
		cout << "5.�޸����ڵ�" << endl;
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
		cout << "��ѡ�����蹦��:" << endl;
		cout << "1.��ͨ΢��" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			/*CreateWeiBo();*/
			break;
		default:
			cout << "ѡ����󣬰����������QQ���˵�" << endl;
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
	cout << "��������Ӻ��ѵ�QQ��" << endl;
	cin >> id;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == id)
		{
			flag = true;
			name = WeiChatList[i]->ReturnName();
			cout << "��������ɹ�����ȴ��Է�ȷ��" << endl;
		}
	}

	if (flag == false)
	{
		cout << "��QQ��û��ע�ᣬ���������������QQ��" << endl;
		cout << "1.��������QQ����Ӻ���" << endl;
		cout << "2.����QQ��ҳ" << endl;
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
			cout << "�������,�����������QQ��ҳ" << endl;
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


	//�����QQ�ļ�����ӱ�QQ
	fstream file;
	string friendfilename = "QQ\\" + id + "\\" + id + "Friendlist.txt";
	string remarks = "δ��ע";
	file.open(friendfilename, ios::app);
	file << "^" << WeiChatList[Myqq]->ReturnID() << endl;
	file << WeiChatList[Myqq]->ReturnName() << endl;
	file << remarks << endl;
	file << " " << endl;
	file.close();

	cout << "�����������QQ��ҳ" << endl;
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
		file.open(filename, ios::trunc | ios::out);//����ļ�����
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
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')//�ж���Ӻ��ѱ��
		{
			friendsnum--;
		}
	}

	cout << "����" << friendsnum << "������" << endl;
	int friends = 0;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')
		{
			continue;
		}
		cout << "��" << friends + 1 << "λ����" << endl;
		cout << "����:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "QQ:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
		friends++;
	}

	cout << "�����������QQ��ҳ" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}