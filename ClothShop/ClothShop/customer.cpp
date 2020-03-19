#include <string>
#include "order.h"
#include "shop.h"
#include "cloth.h"
#include "customer.h"
using namespace std;

customer::customer()	{ }

customer::customer(string name)				//宣告顧客，預設資料
{
	_name = name;
	_point = 2000;
}

string customer::getName()					//回傳顧客名子
{
	return _name;
}

double customer::getCash()					//回傳顧客錢錢
{
	return _point;
}

order* customer::getCurrentOrder()			//回傳目前之訂單
{
	return _order;
}

bool customer::isPointEnough()				//判斷錢錢夠不夠
{
	if (getCash() > getOrderTotalPrice())
		return true;
	else
		return false;
}

void customer::reducePointFromOrder()		//扣錢錢的功能
{
	_point -= getOrderTotalPrice();
}

void customer::addClothToOrder(cloth* cloth, int amount)	//加入訂單
{
	_order->addCloth(cloth, amount);
}

void customer::makeNewOrder(shop* shop)		//配記憶體代表建立訂單
{
	_order = new order(shop);
}

void customer::cancelOrder()				//結束掉訂單
{
	delete _order;							//資料清掉
	_order = NULL;							//還是要指回NULL才會正常
}

double customer::getOrderTotalPrice()
{
	return _order->getTotalPrice();			//算總帳
}