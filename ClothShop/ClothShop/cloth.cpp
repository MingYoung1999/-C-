#include <string>
#include "cloth.h"
using namespace std;

cloth::cloth() {}				//default constructer

cloth::cloth(int id, string name, string description, double price)	//�]�w��A
{
	_id = id;
	_name = name;
	_description = description;
	_price = price;
}

int cloth::GetID()				//�^�ǧǸ�
{
	return _id;
}

string cloth::GetName()			//�^�ǦW��
{
	return _name;
}

string cloth::GetDescription()	//�^�Ǵy�z
{
	return _description;
}

double cloth::GetPrice()		//�^�ǻ���
{
	return _price;
}
