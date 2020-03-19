#include <string>
#include "cloth.h"
using namespace std;

cloth::cloth() {}				//default constructer

cloth::cloth(int id, string name, string description, double price)	//設定衣服
{
	_id = id;
	_name = name;
	_description = description;
	_price = price;
}

int cloth::GetID()				//回傳序號
{
	return _id;
}

string cloth::GetName()			//回傳名稱
{
	return _name;
}

string cloth::GetDescription()	//回傳描述
{
	return _description;
}

double cloth::GetPrice()		//回傳價格
{
	return _price;
}
