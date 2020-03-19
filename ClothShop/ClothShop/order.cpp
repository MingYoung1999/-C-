#include <vector>
#include "cloth.h"
#include "shop.h"
#include "order.h"

order::order()	{}

order::order(shop* shop)							//宣告資料
{
	_shop = shop;
	_totalPrice = 0;
}

shop* order::getShop()								//回傳目前商店
{
	return _shop;
}

void order::addCloth(cloth* addedCloth, int amount)	//加衣服及數量
{
	_orderedClothes.push_back(addedCloth);
	_totalPrice += addedCloth->GetPrice()*amount;	//算錢錢
}

double order::getTotalPrice()						//算錢錢
{
	return _totalPrice;
}