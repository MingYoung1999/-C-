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

void ShopUI::Execute(shop &store, customer &customer)								//�ާ@
{
	string option;
	string name, description, price;
	int id = 0, enable = 1, input = 0, amount = 0;
	while (1)
	{
		Performance(store, customer);												//�L�X�ާ@����
		while (cin >> option)														//�ϥΪ̿�J
		{
			if (IsOptionInvalid(option) == true)									//�ˬd���O�O�_���T
			{
				cout << "�п�J���T�ﶵ�G";
			}
			else
				break;																//�Ѩ쥿�T����
		}
		switch (stoi(option))
		{
		case 1:
			cout << "�п�J��A�W�١G";
			cin >> name;															//��J�W�l
			cout << "�п�J��A�y�z�G";
			cin >> description;														//��J�y�z
			cout << "�п�J��A����G";
			while (cin >> price)
			{
				if (IsPriceInvalid(price) == true)									//�ˬd�������
					cout << "�������~��J�A�ШϥΪ̭��s��J" << endl << "�п�J���T����G";
				else
					break;															//��J�쥿�T����
			}
			id++;
			store.CreateNewCloth(id, name, description, stod(price));				//�s��A
			cout << endl;
			break;
		case 2:																		//�L�X�Ҧ����
			showCloth(store);
			break;
		case 3:																		//�حq��
			if (customer.getCurrentOrder())
				cout << "�|��������e�q�� ! " << endl;								//�|���������e���q��L�k�طs��
			else
			{
				cout << "�إ߭q�榨�\ !!! " << endl;
				customer.makeNewOrder(&store);
			}
			break;
		case 4:																		//�R��A
			if (customer.getCurrentOrder())
			{
				showCloth(store);													//�q���
				while (1)
				{
					cout << "�п�J��AID�A���}�п�J-1 : ";
					cin >> input;
					if (input == -1)												//break����
						break;
					else
					{
						cout << "�п�J��A�ƶq : ";
						cin >> amount;
						customer.addClothToOrder((*store.GetCloth())[input - 1], amount);	//�[�Jorder
					}
				}
			}
			else
			{
				cout << "�Ыإ߭q��A�~���ʶR��A ! " << endl;
			}
			break;
		case 5:
			if (customer.isPointEnough() == true)									//�ݾl�B������
			{
				customer.reducePointFromOrder();									//���I��
				cout << "�q�浲�����\ ! " << endl;
				customer.cancelOrder();												//�����q��
			}
			else
			{
				cout << "�Ѿl�I�Ƥ����A�L�k�i���ʶR ! " << endl;
				customer.cancelOrder();												//�����٬O�o�����q��
			}
			break;
		case 6:																		//�Ѿl���I�ƬO�h��
			cout << "�z�Ѿl���I�ƳѤU : " << customer.getCash() << endl;
			break;
		case 7:
			cout << "���\��[��10000��A��i����" << endl;							//�|�����X���\��
			break;
		case 8:
			enable = 0;																//���}
			break;
		}
		if (enable == 0)
			break;
	}
}

void ShopUI::LoadData(shop &store, string temp, int &count)			//Ū��
{
	count++;
	Push(store, temp, count);										//����push�i�h													
}

void ShopUI::Push(shop &store, string str, int count)				//�s���
{
	int i = 0;
	string token[3], temp;
	istringstream text(str);
	while (getline(text, temp, ','))								//��
	{
		token[i] = temp;
		i++;
	}
	store.CreateNewCloth(count, token[0], token[1], stod(token[2]));//create�@���A
}

void ShopUI::Performance(shop store, customer customer)				//�ϥΪ̤���
{
	cout << endl;
	cout << "�˷R���U�� : " << customer.getName() << "�A�z�n ! " << endl;
	cout << "(" << store.GetName() << ")1.�s�W��A" << endl;
	cout << "(" << store.GetName() << ")2.�d�ݩҦ���A" << endl;
	cout << "(" << store.GetName() << ")3.�إ߷s�q��" << endl;
	cout << "(" << store.GetName() << ")4.�ʶR��A" << endl;
	cout << "(" << store.GetName() << ")5.�����q��" << endl;
	cout << "(" << store.GetName() << ")6.�d�ݳѾl�I��" << endl;
	cout << "(" << store.GetName() << ")7.�d�ݾ��v����" << endl;
	cout << "(" << store.GetName() << ")8.���}" << endl;
	cout << "�п�ܿ�J�G";
}

void ShopUI::showCloth(shop &store)									//�o���צn�o�A��X�O������A�L�X��A���
{
	cout << std::left << setw(10) << "No." << std::left << setw(40) << "��A�W��" << std::left << setw(10) << "����" << std::left << setw(50) << "�y�z" << endl;
	for (vector<cloth*>::iterator v = store.GetCloth()->begin(); v != store.GetCloth()->end(); v++)
		cout << std::left << setw(10) << (*v)->GetID() << std::left << setw(40) << (*v)->GetName() << std::left << setw(10) << (*v)->GetPrice() << std::left << setw(50) << (*v)->GetDescription() << endl;
	cout << endl;
}

bool ShopUI::IsOptionInvalid(string option)							//�ˬd��J�����O�O�_���T
{
	for (unsigned int i = 0; i < option.size(); i++)
	{
		if ((option[i] - '0') > 9 || (option[i] - '0') < 1)			//���ˬd�O�_�O�Ʀr
		{
			return true;
		}
	}
	if (stoi(option) < 1 || stoi(option) > 8)						//�b�ˬd���O�O�_�O1~8
		return true;

	return false;
}

bool ShopUI::IsPriceInvalid(string price)							//�ˬd�������ҬO�_���T
{
	int check = 0, len = price.length(), countDot = 0;
	for (int i = 0; i < len; i++)
	{
		if ((price[i] - '0') <= 9 && (price[i] - '0' >= 0))
			check++;
		else if (price[i] == '.')									//�i�H�e�Ԥ@�Ӥp���I
		{
			check++;
			countDot++;
		}
	}
	if (check == len && countDot < 2)								//���T���r����r����� && �p���I�u���@�өΨS��
		return false;												//���N�O�諸
	else
		return true;
}