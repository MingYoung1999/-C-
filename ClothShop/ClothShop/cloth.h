#pragma once
#include <string>
using namespace std;

class cloth
{
public:
	cloth();
	cloth(int id, string name, string description, double price);
	int GetID();
	string GetName();
	string GetDescription();
	double GetPrice();
private:
	int _id;
	string _name;
	string _description;
	double _price;
};
