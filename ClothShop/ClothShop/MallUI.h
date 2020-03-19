#pragma once
#include "mall.h"
#include "order.h"
#include "customer.h"

class MallUI
{
public:
	MallUI();
	MallUI(mall mall);
	void showCustomer();
	void showShop();
	void Execute();
	bool IsOptionInvalid(string option);
private:
	mall _mall;
};