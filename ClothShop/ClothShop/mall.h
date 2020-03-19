#pragma once
#include "shop.h"
#include "customer.h"
#include <vector>
#include <string>
using namespace std;

class mall
{
public:
	mall();
	void LoadData();
	void ShopPush(int position, string temp);
	void selectShop(int shopIndex);
	void selectCustomer(int customerIndex);
	void customerPush();
	vector<shop*>* getShop();
	vector<customer*>* getCustomer();
private:
	int _shopIndex;
	int _customerIndex;
	vector<shop*> _shops;
	vector<customer*> _customers;
};