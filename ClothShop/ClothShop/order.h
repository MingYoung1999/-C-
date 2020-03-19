#pragma once
#include <vector>
#include "cloth.h"
#include "shop.h"

class order
{
public:
	order();
	order(shop* shop);
	shop* getShop();
	void addCloth(cloth* addedCloth, int amount);
	double getTotalPrice();
private:
	shop* _shop;
	vector<cloth*> _orderedClothes;
	double _totalPrice;
};