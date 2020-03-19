#pragma once
#include <string>
#include "order.h"
#include "shop.h"
#include "cloth.h"

class customer
{
public:
	customer();
	customer(string name);
	string getName();
	double getCash();
	void makeNewOrder(shop* store);
	void addClothToOrder(cloth* cloth, int amount);
	double getOrderTotalPrice();
	bool isPointEnough();
	void reducePointFromOrder();
	void cancelOrder();
	order* getCurrentOrder();
private:
	string _name;
	double _point;
	order* _order;
};