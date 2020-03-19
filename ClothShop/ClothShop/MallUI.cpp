#include "MallUI.h"
#include "ShopUI.h"
#include "mall.h"
#include <iostream>
using namespace std;

MallUI::MallUI() {};

MallUI::MallUI(mall mall) : _mall(mall) {};

void MallUI::showCustomer()								//�L�X�Ȥ�W��
{
	int i = 0;
	for (vector<customer*>::iterator v = _mall.getCustomer()->begin(); v != _mall.getCustomer()->end(); v++)
	{
		cout << ++i << "." << (*v)->getName() << endl;
	}
	cout << ++i << ".���}" << endl;
	cout << "select customer : ";
}

void MallUI::showShop()									//�L�X�ө��W��
{
	int i = 0;
	for (vector<shop*>::iterator v = _mall.getShop()->begin(); v != _mall.getShop()->end(); v++)
	{
		cout << ++i << "." << (*v)->GetName() << endl;
	}
	cout << "Select Shop : ";
}

void MallUI::Execute()									//����
{
	ShopUI shopUI;
	_mall.LoadData();
	int selectCustomer;
	string option;
	while (1)
	{
		showCustomer();
		cin >> selectCustomer;
		if (selectCustomer == 4)						//�ثe�u��3���U�ȡA�ĥ|�ӬO���}
			break;
		while (1)
		{
			showShop();
			while (cin >> option)						//�ϥΪ̿�J
			{
				if (IsOptionInvalid(option) == true)	//�ˬd���O�O�_���T
				{
					cout << "�п�J���T�ﶵ�G";
				}
				else
					break;								//�Ѩ쥿�T����
			}
			_mall.selectShop(stod(option) - 1);			//��n�ө�
			_mall.selectCustomer(selectCustomer - 1);	//��n�U��
			shopUI.Execute(*(*_mall.getShop())[stoi(option) - 1], *(*_mall.getCustomer())[selectCustomer - 1]);	//���@�ӭ�������
			break;										//�^����U�Ȩ��@�h
		}
	}
}

bool MallUI::IsOptionInvalid(string option)							//�ˬd��J�����O�O�_���T
{
	for (unsigned int i = 0; i < option.size(); i++)
	{
		if ((option[i] - '0') > 9 || (option[i] - '0') < 1)			//���ˬd�O�_�O�Ʀr
		{
			return true;
		}
	}
	if (stoi(option) < 1 || stoi(option) > 3)						//�b�ˬd���O�O�_�O1~3
		return true;

	return false;
}