#include"BookManager.h"
#include<string>
#include<iostream>
#include<stdexcept>
using namespace std;
int main(void)
{
	BookManager* bm = new BookManager;//开辟空间维护
	BookStorage* bs = new BookStorage;//开辟空间维护
	cout << "输入书的信息" << endl;
	bm->Add_Book(bs);
	string input{};
	bool is_want_borrow = 0;
	bool is_want_return = 0;
	cout << "输入书名，想借书输入1，不想输入0,还书同理" << endl;
	cout << "书名/ISBN:";
	cin >> input;
	cout << "借书:";
	cin >> is_want_borrow;
	cout << "还书:";
	cin >> is_want_return;
	if (bm->Book_is_exist_1(input, bs) || bm->Book_is_exist_2(input, bs))
	{
		unsigned int n=bm->Get_Book_Number(input, bs);
		bm->Display_Info(n, bs);
		try
		{
			if (is_want_borrow || is_want_return)
				throw runtime_error("同时借书和还书功能目前不支持");
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