#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "cloth.h"
#include "shop.h"
#include "ShopUI.h"
#include "customer.h"
#include "order.h"
using namespace std;

ShopUI::ShopUI() {}																	//default constructer

void ShopUI::Execute(shop &store, customer &customer)								//操作
{
	string option;
	string name, description, price;
	int id = 0, enable = 1, input = 0, amount = 0;
	while (1)
	{
		Performance(store, customer);												//印出操作屆面
		while (cin >> option)														//使用者輸入
		{
			if (IsOptionInvalid(option) == true)									//檢查指令是否正確
			{
				cout << "請輸入正確選項：";
			}
			else
				break;																//書到正確為止
		}
		switch (stoi(option))
		{
		case 1:
			cout << "請輸入衣服名稱：";
			cin >> name;															//輸入名子
			cout << "請輸入衣服描述：";
			cin >> description;														//輸入描述
			cout << "請輸入衣服價格：";
			while (cin >> price)
			{
				if (IsPriceInvalid(price) == true)									//檢查價格標籤
					cout << "此為錯誤輸入，請使用者重新輸入" << endl << "請輸入正確價格：";
				else
					break;															//輸入到正確為止
			}
			id++;
			store.CreateNewCloth(id, name, description, stod(price));				//新衣服
			cout << endl;
			break;
		case 2:																		//印出所有資料
			showCloth(store);
			break;
		case 3:																		//建訂單
			if (customer.getCurrentOrder())
				cout << "尚未結束當前訂單 ! " << endl;								//尚未結束之前的訂單無法建新的
			else
			{
				cout << "建立訂單成功 !!! " << endl;
				customer.makeNewOrder(&store);
			}
			break;
		case 4:																		//買衣服
			if (customer.getCurrentOrder())
			{
				showCloth(store);													//秀資料
				while (1)
				{
					cout << "請輸入衣服ID，離開請輸入-1 : ";
					cin >> input;
					if (input == -1)												//break條件
						break;
					else
					{
						cout << "請輸入衣服數量 : ";
						cin >> amount;
						customer.addClothToOrder((*store.GetCloth())[input - 1], amount);	//加入order
					}
				}
			}
			else
			{
				cout << "請建立訂單，才能購買衣服 ! " << endl;
			}
			break;
		case 5:
			if (customer.isPointEnough() == true)									//看餘額夠不夠
			{
				customer.reducePointFromOrder();									//扣點數
				cout << "訂單結束成功 ! " << endl;
				customer.cancelOrder();												//結束訂單
			}
			else
			{
				cout << "剩餘點數不足，無法進行購買 ! " << endl;
				customer.cancelOrder();												//不夠還是得結束訂單
			}
			break;
		case 6:																		//剩餘的點數是多少
			cout << "您剩餘的點數剩下 : " << customer.getCash() << endl;
			break;
		case 7:
			cout << "此功能加值10000圓，方可解鎖" << endl;							//尚未推出此功能
			break;
		case 8:
			enable = 0;																//離開
			break;
		}
		if (enable == 0)
			break;
	}
}

void ShopUI::LoadData(shop &store, string temp, int &count)			//讀黨
{
	count++;
	Push(store, temp, count);										//把資料push進去													
}

void ShopUI::Push(shop &store, string str, int count)				//存資料
{
	int i = 0;
	string token[3], temp;
	istringstream text(str);
	while (getline(text, temp, ','))								//切
	{
		token[i] = temp;
		i++;
	}
	store.CreateNewCloth(count, token[0], token[1], stod(token[2]));//create一件衣服
}

void ShopUI::Performance(shop store, customer customer)				//使用者介面
{
	cout << endl;
	cout << "親愛的顧客 : " << customer.getName() << "，您好 ! " << endl;
	cout << "(" << store.GetName() << ")1.新增衣服" << endl;
	cout << "(" << store.GetName() << ")2.查看所有衣服" << endl;
	cout << "(" << store.GetName() << ")3.建立新訂單" << endl;
	cout << "(" << store.GetName() << ")4.購買衣服" << endl;
	cout << "(" << store.GetName() << ")5.結束訂單" << endl;
	cout << "(" << store.GetName() << ")6.查看剩餘點數" << endl;
	cout << "(" << store.GetName() << ")7.查看歷史收據" << endl;
	cout << "(" << store.GetName() << ")8.離開" << endl;
	cout << "請選擇輸入：";
}

void ShopUI::showCloth(shop &store)									//這次修好囉，輸出是整齊的，印出衣服資料
{
	cout << std::left << setw(10) << "No." << std::left << setw(40) << "衣服名稱" << std::left << setw(10) << "價格" << std::left << setw(50) << "描述" << endl;
	for (vector<cloth*>::iterator v = store.GetCloth()->begin(); v != store.GetCloth()->end(); v++)
		cout << std::left << setw(10) << (*v)->GetID() << std::left << setw(40) << (*v)->GetName() << std::left << setw(10) << (*v)->GetPrice() << std::left << setw(50) << (*v)->GetDescription() << endl;
	cout << endl;
}

bool ShopUI::IsOptionInvalid(string option)							//檢查輸入之指令是否正確
{
	for (unsigned int i = 0; i < option.size(); i++)
	{
		if ((option[i] - '0') > 9 || (option[i] - '0') < 1)			//先檢查是否是數字
		{
			return true;
		}
	}
	if (stoi(option) < 1 || stoi(option) > 8)						//在檢查指令是否是1~8
		return true;

	return false;
}

bool ShopUI::IsPriceInvalid(string price)							//檢查價錢標籤是否正確
{
	int check = 0, len = price.length(), countDot = 0;
	for (int i = 0; i < len; i++)
	{
		if ((price[i] - '0') <= 9 && (price[i] - '0' >= 0))
			check++;
		else if (price[i] == '.')									//可以容忍一個小數點
		{
			check++;
			countDot++;
		}
	}
	if (check == len && countDot < 2)								//正確的字等於字串長度 && 小數點只有一個或沒有
		return false;												//那就是對的
	else
		return true;
}