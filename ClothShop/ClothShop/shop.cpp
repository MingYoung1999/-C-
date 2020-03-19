#include <string>
#include <vector>
#include "shop.h"
#include "cloth.h"
using namespace std;

shop::shop() {}				//default constructer

shop::shop(string name)		//�]�w�W�l
{
	_name = name;
}

string shop::GetName()		//�^�ǰө��W
{
	return _name;
}

void shop::CreateNewCloth(int no, string name, string description, double price)	//���s�f��~~~
{
	_clothes.push_back(new cloth(no, name, description, price));
}

vector<cloth*>* shop::GetCloth()		//�^�ǧڪ���Ʈw�s
{
	return &_clothes;
}