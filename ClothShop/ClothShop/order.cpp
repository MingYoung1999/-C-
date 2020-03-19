#include <vector>
#include "cloth.h"
#include "shop.h"
#include "order.h"

order::order()	{}

order::order(shop* shop)							//�ŧi���
{
	_shop = shop;
	_totalPrice = 0;
}

shop* order::getShop()								//�^�ǥثe�ө�
{
	return _shop;
}

void order::addCloth(cloth* addedCloth, int amount)	//�[��A�μƶq
{
	_orderedClothes.push_back(addedCloth);
	_totalPrice += addedCloth->GetPrice()*amount;	//�����
}

double order::getTotalPrice()						//�����
{
	return _totalPrice;
}