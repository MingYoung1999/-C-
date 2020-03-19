#include "mall.h"
#include "shop.h"
#include "ShopUI.h"
#include "customer.h"
#include <vector>
#include <fstream>
#include <string>

mall::mall() {}

void mall::LoadData()											//Ū�ɮ׸��
{
	_shopIndex = -1;
	int count = 0;
	fstream file;
	string temp;
	ShopUI shopUI;
	file.open("Cloth.txt");
	if (file)
	{
		while (getline(file, temp))								//�}Ū
		{
			if (temp.find("Shop", 0) != string::npos)			//�}��
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
	customerPush();												//�}�s
}

void mall::ShopPush(int position, string temp)					//push��ƶi�h
{
	string str;
	str = temp.substr(position + 5, temp.length() - 6);
	_shops.push_back(new shop(str));
}

void mall::selectShop(int shopIndex)							//��ө���
{
	_shopIndex = shopIndex;
}

void mall::selectCustomer(int customerIndex)					//���U�ȥ�
{
	_customerIndex = customerIndex;
}

vector<shop*>* mall::getShop()									//�^�ǰө�
{
	return &_shops;
}

vector<customer*>* mall::getCustomer()							//�^���U��
{
	return &_customers;
}

void mall::customerPush()										//��w�]��ƶi�h
{
	_customers.push_back(new customer("Amber"));
	_customers.push_back(new customer("Tim"));
	_customers.push_back(new customer("Marry"));
}