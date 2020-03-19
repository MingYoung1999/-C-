#include <string>
#include "order.h"
#include "shop.h"
#include "cloth.h"
#include "customer.h"
using namespace std;

customer::customer()	{ }

customer::customer(string name)				//�ŧi�U�ȡA�w�]���
{
	_name = name;
	_point = 2000;
}

string customer::getName()					//�^���U�ȦW�l
{
	return _name;
}

double customer::getCash()					//�^���U�ȿ���
{
	return _point;
}

order* customer::getCurrentOrder()			//�^�ǥثe���q��
{
	return _order;
}

bool customer::isPointEnough()				//�P�_����������
{
	if (getCash() > getOrderTotalPrice())
		return true;
	else
		return false;
}

void customer::reducePointFromOrder()		//���������\��
{
	_point -= getOrderTotalPrice();
}

void customer::addClothToOrder(cloth* cloth, int amount)	//�[�J�q��
{
	_order->addCloth(cloth, amount);
}

void customer::makeNewOrder(shop* shop)		//�t�O����N��إ߭q��
{
	_order = new order(shop);
}

void customer::cancelOrder()				//�������q��
{
	delete _order;							//��ƲM��
	_order = NULL;							//�٬O�n���^NULL�~�|���`
}

double customer::getOrderTotalPrice()
{
	return _order->getTotalPrice();			//���`�b
}