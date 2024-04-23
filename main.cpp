#include"BookManager.h"
#include<string>
#include<iostream>
#include<stdexcept>
using namespace std;
int main(void)
{
	BookManager* bm = new BookManager;//���ٿռ�ά��
	BookStorage* bs = new BookStorage;//���ٿռ�ά��
	cout << "���������Ϣ" << endl;
	bm->Add_Book(bs);
	string input{};
	bool is_want_borrow = 0;
	bool is_want_return = 0;
	cout << "�������������������1����������0,����ͬ��" << endl;
	cout << "����/ISBN:";
	cin >> input;
	cout << "����:";
	cin >> is_want_borrow;
	cout << "����:";
	cin >> is_want_return;
	if (bm->Book_is_exist_1(input, bs) || bm->Book_is_exist_2(input, bs))
	{
		unsigned int n=bm->Get_Book_Number(input, bs);
		bm->Display_Info(n, bs);
		try
		{
			if (is_want_borrow || is_want_return)
				throw runtime_error("ͬʱ����ͻ��鹦��Ŀǰ��֧��");
		}
		catch (runtime_error err)
		{
			cout << err.what() << endl;
			exit(1);
		}
		if (is_want_borrow)
		{
			bm->Borrow_Book(n, bs);
		}
		if (is_want_return)
		{
			bm->Return_Book(n, bs);
		}
	}
	delete bm;
	delete bs;
	return 0;
}