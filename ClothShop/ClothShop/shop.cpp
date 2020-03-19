#include <string>
#include <vector>
#include "shop.h"
#include "cloth.h"
using namespace std;

shop::shop() {}				//default constructer

shop::shop(string name)		//設定名子
{
	_name = name;
}

string shop::GetName()		//回傳商店名
{
	return _name;
}

void shop::CreateNewCloth(int no, string name, string description, double price)	//有新貨喔~~~
{
	_clothes.push_back(new cloth(no, name, description, price));
}

vector<cloth*>* shop::GetCloth()		//回傳我的資料庫存
{
	return &_clothes;
}