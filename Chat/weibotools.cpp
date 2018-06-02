#include<iostream>
#include"tools.h"
#include<fstream>
#include<conio.h>

extern QQTools_CHC QQTools;
extern WeiBoTools_CHC WeiBoTools;

void WeiBoToolsBase_CHC::SaveWeiBo()//保存开通的微博
{
	fstream WeiBoListFile;
	string WeiBoListFileName = "WeiBoList.txt";
	WeiBoListFile.open(WeiBoListFileName, ios::app);
	string m = QQTools.ReturnQQid();
	WeiBoListFile << QQTools.ReturnQQid() << endl;
	WeiBoListFile.close();
}

void WeiBoToolsBase_CHC::GetWeiBo()
{
	ofstream WeiBoListFileCheck;
	fstream WeiBoListFile;
	string WeiBoListFileName = "WeiBoList.txt";
	string WeiBoListTemp;

	WeiBoListFileCheck.open(WeiBoListFileName, ios::out | ios::app);
	/*if (!WeiBoListFileCheck)
	{
	WeiBoListFileCheck.close();
	cout << "没有已注册微博号" << endl;
	cout << "按任意键返回QQ主菜单" << endl;
	_getch();
	_getch();
	QQTools.Menu();
	}*/
	WeiBoListFileCheck.close();


	WeiBoListFile.open(WeiBoListFileName);
	while (!WeiBoListFile.eof())
	{
		getline(WeiBoListFile, WeiBoListTemp);

		WeiBoTools.ReturnWeiBolist().emplace_back(new WeiBo_CHC(WeiBoListTemp));
	}
	WeiBoTools.ReturnWeiBolist().pop_back();

	WeiBoListFile.close();


}

void WeiBoToolsBase_CHC::Login()
{
	system("CLS");
	string WeiBoID;
	string WeiBoPW;
	int ThisWeiBo;
	bool isCheckFlag = false;
	bool PWCheckFlag = false;
	cout << "请输入你的微博(QQ)号" << endl;
	cin >> WeiBoID;
	

	//判断微博账号是否存在
	while (1)
	{
		for (int i = 0; i < size(QQTools.ReturnQQ()); i++)
		{
			if (QQTools.ReturnQQ()[i]->ReturnID() == WeiBoID)
			{
				isCheckFlag = true;
				ThisWeiBo = i;
				WeiBoTools.LoginedWeiBoID = WeiBoID;
				break;
			}
		}

		if (isCheckFlag == false)
		{
			cout << "你输入的账号不存在，请重新输入或输入#返回微博主菜单" << endl;
			cin >> WeiBoID;
			if (WeiBoID == "#")
			{
				Menu();
			}
			continue;
		}
		else
		{
			break;
		}
	}


	cout << "请输入你的微博(QQ)号密码" << endl;
	cin >> WeiBoPW;
	while (1)
	{
		if (QQTools.ReturnQQ()[ThisWeiBo]->ReturnPassWord() == WeiBoPW)
		{
			cout << "登陆成功,按任意键进入微博主页" << endl;
			_getch();
			_getch();
			WeiBoMenu();
			break;
		}
		else
		{
			cout << "密码输入错误,请重新输入或输入#返回微博主菜单" << endl;
			cin >> WeiBoPW;
			if (WeiBoPW == "#")
			{
				Menu();
			}
			continue;
		}
	}


}

void WeiBoToolsBase_CHC::Menu()
{
	system("CLS");
	int select;
	cout << "请选择你所需的功能" << endl;
	cout << "1.登陆微博" << endl;
	cin >> select;

	switch (select)
	{
	case 1:
		Login();
		break;
	default:
		cout << "输入错误,按任意键返回微博主菜单" << endl;
		_getch();
		_getch();
		WeiBoMenu();
		break;
	}
}

void WeiBoToolsBase_CHC::WeiBoMenu()
{
	system("CLS");
	int select;
	cout << "欢迎来到微博" << endl;
	cout << "你的微博号为" << WeiBoTools.LoginedWeiBoID;
	cout << "请选择所需的功能" << endl;
	cout << "0.返回主菜单" << endl;
	cin >> select;
	switch (select)
	{

	default:
		QQTools.Menu();
		break;
	}
}
