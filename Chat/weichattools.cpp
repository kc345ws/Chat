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

void WeiChatToolsBase_CHC::CreatParty()
{
	system("CLS");
	int Myqq;
	for (int i = 0; i<1000000; i++) //��ǿQQȺ�����������
	{
		srand(time(0));
	}
	int p = rand()*rand();
	char temp[128];
	itoa(p, temp, 10);
	string ID;
	/*cin >> ID;*/
	ID = string(temp);
	cout << "���Ⱥ��Ϊ:" << ID << endl;
	WeiChatparty = ID;
	cout << "������Ⱥ����" << endl;
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


	//ÿ��QQ�����Լ���Ⱥ�б�
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
	cout << "�����������΢����ҳ" << endl;
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
	file << "��" << endl;
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



	//��ȡȺ��Ա
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


		//BUG�޸�
		QQPartyMemberFileContent.clear();
		QQPartyMemberFileContent.shrink_to_fit();
		QQPartyMemberFile.close();
	}




	//��ȡȺ����ԱQQ
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

	//��ʾ���к���
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	cout << "����" << WeiChatList[Myqq]->ReturnFriendNumber() << "������" << endl;
	for (int i = 0; i < WeiChatList[Myqq]->ReturnFriendNumber(); i++)
	{
		cout << "��" << i + 1 << "λ����" << endl;
		cout << "����:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "΢�ź�:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
	}


	//ɾ����QQ�еĺ���
	string qq;
	cout << "��������ɾ�����ѵ�΢�ź�" << endl;
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
		cout << "��û�д˺���" << endl;
		cout << "1.��������΢�ź�" << endl;
		cout << "2.����΢����ҳ" << endl;
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
			WeiChatList[Myqq]->ReturnFriendList().resize(num - 1);//�������ú���������С
			WeiChatList[Myqq]->ChangeFriendsNumber(num - 1);
		}
	}

	/*SaveFriends();*/
	//ɾ����QQ�еĺ���QQ
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
	int m = content1.find(qq);//�ҵ�����QQ�ļ��б�QQ��λ��
	for (int i = m; i < (m + word); i++)
	{
		content1.erase(content1.begin() + m);//ɾ��
	}
	myqqfile.close();
	myqqfile.open(myqqfilename, ios::trunc | ios::out);
	myqqfile << content1;
	myqqfile.close();



	//ɾ������QQ�ļ��еı�QQ
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
			//if (temp[i] < 0 || temp[i] > 127)//�����ַ�ռ�����ֽ�
			//{
			//	words++;
			//}
		}
		content.push_back('\n');
		words++;
	}

	m = content.find(LoginedWeiChat);//�ҵ�����QQ�ļ��б�QQ��λ��
	for (int i = m; i < (m + words); i++)
	{
		content.erase(content.begin() + m);//ɾ��
	}
	outfile.close();

	outfile.open(friendqqfilename, ios::trunc | ios::out);
	outfile << content;
	outfile.close();

	cout << "ɾ�����ѳɹ�" << endl;
	cout << "�����������΢����ҳ" << endl;
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
	while (myqqfile.get(c))//��ȡ������WeiChat
	{
		if (c == '^')
		{
			line++;
			flag = true;
			continue;
		}

		if (line == 1) //��ȡ����Ӻ��ѵ���WeiChat��
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
		cout << "û�к�������" << endl;
		cout << "�����������WeiChat��ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}
	myqqfile.close();
	fdqq = temp;
	/*string myqqfilename = "WeiChat\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "Friendlist.txt";*/
	friendqqfilename = "WeiChat\\" + fdqq + "\\" + fdqq + "Friendlist.txt";

	//temp.pop_back();
	cout << "���Ƿ�ͬ��" << temp << "�ĺ�������?" << endl;
	cout << "1.ͬ��" << endl;
	cout << "2.�ܾ�" << endl;

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
			//	content.push_back(msg[i]);//��ȡ�ļ�����
			//}


			//content.push_back('\n');

		}
		myaceptcontent.pop_back();
		/*content.pop_back();
		content.shrink_to_fit();*/


		//for (int i = 0; i < size(content); i++)//��δ������ɾ��
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

		myqqfile.open(myqqfilename, ios::out | ios::trunc); //���ԭ���ļ�����

															/*myqqfile << content;*/
		for (int i = 0; i < size(myaceptcontent); i++)
		{
			myqqfile << myaceptcontent[i] << endl;
		}

		/*cout << "ȷ������ɹ�" << endl;*/

		myqqfile.close();





		friendqqfile.open(friendqqfilename);

		while (!friendqqfile.eof())//��ȡ�����ļ�����
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

		//for (int i = 0; i < size(contentfriend); i++)//ɾ�������ļ��еı��
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

		friendqqfile.open(friendqqfilename, ios::out | ios::trunc);//��պ����ļ�����
																   //friendqqfile << contentfriend;//����д��ɾ����Ǻ�ĺ����ļ�����
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
		cout << "ȷ������ɹ�" << endl;
		cout << "�����������WeiChat��ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();

		break;


	default:

		cout << "���Ѿܾ�������" << endl;

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
			//	content.push_back(msg[i]);//��ȡ�ļ�����
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
		//			content.erase(content.begin() + n); //ɾ��������WeiChat


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

		myqqfile.open(myqqfilename, ios::out | ios::trunc); //���ԭ���ļ�����
															/*myqqfile << content;*/

		for (int i = 0; i < size(myqqfilecontent); i++)
		{
			myqqfile << myqqfilecontent[i] << endl;
		}
		myqqfile.close();





		//ɾ�������ļ��е�WeiChat
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
			//	contentfriend.push_back(msgfriend[i]);//��ȡ�ļ�����
			//}

			//contentfriend.push_back('\n');
		}
		friendfilecontent.pop_back();
		friendqqfile.close();
		/*contentfriend.pop_back();
		contentfriend.shrink_to_fit();
		friendqqfile.close();*/

		//for (int i = 0; i < size(contentfriend); i++) //ɾ�������ļ��еı�WeiChat
		//{
		//	if (contentfriend[i] == '&')
		//	{

		//		n = i;

		//		while (1)
		//		{
		//			contentfriend.erase(contentfriend.begin() + n); //ɾ��������WeiChat

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

		friendqqfile.open(friendqqfilename, ios::out, ios::trunc);//���ԭ������
																  /*friendqqfile << contentfriend;*/

		for (int i = 0; i < size(friendfilecontent); i++)
		{
			friendqqfile << friendfilecontent[i] << endl;
		}
		friendqqfile.close();





		cout << "�����������WeiChat��ҳ" << endl;
		_getch();
		WeiChatMenu();
		break;
	}
}

void WeiChatToolsBase_CHC::ShowFriendInformation()
{
	system("CLS");
	ShowFriendNoReturn();
	cout << "�����������ѯ�ĺ���WeiChatList�ţ�������#����WeiChatList���˵�" << endl;
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
			cout << "��û�д˺��ѣ����������������#����WeiChatList���˵�" << endl;
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

	cout << "����Ϊ�˺�����Ϣ" << endl;
	cout << "�ʺ�:" << WeiChatList[friendid]->ReturnID() << endl;
	cout << "����:" << WeiChatList[friendid]->ReturnName() << endl;
	cout << "��ע:" << WeiChatList[Myqq]->ReturnFriendList()[friendremarks]->ReturnRemarks() << endl;
	cout << "����ǩ��:" << WeiChatList[friendid]->ReturnAutograph() << endl;
	cout << "���ڵ���:" << WeiChatList[friendid]->ReturnArea() << endl;

	cout << endl;

	cout << "�����������WeiChatList���˵�" << endl;
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
}

void WeiChatToolsBase_CHC::ChangeFriendRemarks()
{
	system("CLS");
	ShowFriendNoReturn();
	cout << "�����������ѯ�ĺ���WeiChatList�ţ�������#����WeiChatList���˵�" << endl;
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
			cout << "��û�д˺��ѣ����������������#����WeiChatList���˵�" << endl;
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



	cout << "�����������޸ĵı�ע" << endl;
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

	cout << "�޸ı�ע�ɹ�" << endl;
	cout << "�����������WeiChatList���˵�" << endl;
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
	cout << "�㹲��" << WeiChatList[Myqq]->ReturnPartyNumber() << "��Ⱥ" << endl;
	for (int i = 0; i < WeiChatList[Myqq]->ReturnPartyNumber(); i++)
	{
		cout << "��" << WeiChatList[Myqq]->ReturnPartyNumber() << "��Ⱥ" << endl;
		cout << "Ⱥ��:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() << endl;
		cout << "Ⱥ����:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyName() << endl;
		cout << "Ⱥ��:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnCreatUserID() << endl;
		cout << endl;
	}
	cout << "�����������WeiChatList��ҳ" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

