#include "MallUI.h"
#include "ShopUI.h"
#include "mall.h"
#include <iostream>
using namespace std;

MallUI::MallUI() {};

MallUI::MallUI(mall mall) : _mall(mall) {};

void MallUI::showCustomer()								//印出客戶名單
{
	int i = 0;
	for (vector<customer*>::iterator v = _mall.getCustomer()->begin(); v != _mall.getCustomer()->end(); v++)
	{
		cout << ++i << "." << (*v)->getName() << endl;
	}
	cout << ++i << ".離開" << endl;
	cout << "select customer : ";
}

void MallUI::showShop()									//印出商店名單
{
	int i = 0;
	for (vector<shop*>::iterator v = _mall.getShop()->begin(); v != _mall.getShop()->end(); v++)
	{
		cout << ++i << "." << (*v)->GetName() << endl;
	}
	cout << "Select Shop : ";
}

void MallUI::Execute()									//執行
{
	ShopUI shopUI;
	_mall.LoadData();
	int selectCustomer;
	string option;
	while (1)
	{
		showCustomer();
		cin >> selectCustomer;
		if (selectCustomer == 4)						//目前只有3個顧客，第四個是離開
			break;
		while (1)
		{
			showShop();
			while (cin >> option)						//使用者輸入
			{
				if (IsOptionInvalid(option) == true)	//檢查指令是否正確
				{
					cout << "請輸入正確選項：";
				}
				else
					break;								//書到正確為止
			}
			_mall.selectShop(stod(option) - 1);			//選好商店
			_mall.selectCustomer(selectCustomer - 1);	//選好顧客
			shopUI.Execute(*(*_mall.getShop())[stoi(option) - 1], *(*_mall.getCustomer())[selectCustomer - 1]);	//換一個頁面執行
			break;										//回到選顧客那一層
		}
	}
}

bool MallUI::IsOptionInvalid(string option)							//檢查輸入之指令是否正確
{
	for (unsigned int i = 0; i < option.size(); i++)
	{
		if ((option[i] - '0') > 9 || (option[i] - '0') < 1)			//先檢查是否是數字
		{
			return true;
		}
	}
	if (stoi(option) < 1 || stoi(option) > 3)						//在檢查指令是否是1~3
		return true;

	return false;
}