#pragma once
#include <string>
#include <vector>
#include "cloth.h"
using namespace std;

class shop
{
public:
	shop();
	shop(string name);
	string GetName();
	void CreateNewCloth(int no, string name, string description, double price);
	vector<cloth*>* GetCloth();
private:
	string _name;
	vector<cloth*> _clothes;
};