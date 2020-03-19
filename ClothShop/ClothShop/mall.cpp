#include "mall.h"
#include "shop.h"
#include "ShopUI.h"
#include "customer.h"
#include <vector>
#include <fstream>
#include <string>

mall::mall() {}

void mall::LoadData()											//讀檔案資料
{
	_shopIndex = -1;
	int count = 0;
	fstream file;
	string temp;
	ShopUI shopUI;
	file.open("Cloth.txt");
	if (file)
	{
		while (getline(file, temp))								//開讀
		{
			if (temp.find("Shop", 0) != string::npos)			//開切
			{
				ShopPush(temp.find("Shop", 0), temp);
				_shopIndex++;
				count = 0;
			}
			else if (temp != "")
			{
				shopUI.LoadData(*(*getShop())[_shopIndex], temp, count);
			}
		}
	}
	customerPush();												//開存
}

void mall::ShopPush(int position, string temp)					//push資料進去
{
	string str;
	str = temp.substr(position + 5, temp.length() - 6);
	_shops.push_back(new shop(str));
}

void mall::selectShop(int shopIndex)							//選商店用
{
	_shopIndex = shopIndex;
}

void mall::selectCustomer(int customerIndex)					//選顧客用
{
	_customerIndex = customerIndex;
}

vector<shop*>* mall::getShop()									//回傳商店
{
	return &_shops;
}

vector<customer*>* mall::getCustomer()							//回傳顧客
{
	return &_customers;
}

void mall::customerPush()										//丟預設資料進去
{
	_customers.push_back(new customer("Amber"));
	_customers.push_back(new customer("Tim"));
	_customers.push_back(new customer("Marry"));
}