#pragma once
#include <iostream>
#include "cloth.h"
#include "shop.h"
#include "customer.h"
using namespace std;

class ShopUI
{
public:
	ShopUI();
	void Execute(shop &store, customer &customer);
	void LoadData(shop &store, string temp, int &count);
	void Push(shop &store, string str, int count);
	void Performance(shop store,customer customer);
	void showCloth(shop &store);
	bool IsOptionInvalid(string option);
	bool IsPriceInvalid(string price);
};
