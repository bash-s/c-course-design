#include"BookManager.h"
#include<string>
#include<iostream>
using namespace std;
int main(void)
{
	BookManager* bm = new BookManager;//开辟空间维护
	BookStorage* bs = new BookStorage;//开辟空间维护
	int choice = 0;
	string pw{};
	while (1)
	{
		cout << "0、退出系统" << endl;
		cout << "1、录入图书" << endl;
		cout << "2、查看图书" << endl;
		cout << "3、借/还书" << endl;
		cout << endl;
		cout << "请输入数字:" << endl;
		cin >> choice;
		switch (choice)
		{
			case 0:
				exit(1);
				break;
			case 1:
			{
				int Num_0 = 0;
				cout << "请问您要录入几本书？（上限10本）" << endl;
				cin >> Num_0;
				bm->Add_Book(Num_0, bs);
				break;
			}
		case 2:
			{
				string Input_0{};
				int Num_1 = 0;
				cout << "请输入书名/ISBN" << endl;
				cout << "同名书籍建议用ISBN查找" << endl;
				cout << "书名:" << endl;
				cin >> Input_0;
				if (bm->Book_is_exist(Input_0, bs))
				{
					Num_1 = bm->Get_Book_SerialNumber(Input_0, bs);
					bm->Display_Info(Num_1, bs);
				}
				else
				{
					cout << "此书不存在" << endl;
					system("pause");
					system("cls");
				}
				break;
			}
		case 3:
			{
				string Input_1{};
				int Num_2 = 0;
				bool book = 0;
				cout << "请输入书名/ISBN:" << endl;
				cin >> Input_1;
				if (bm->Book_is_exist(Input_1, bs))
				{
					cout << "借书为1，还书为0" << endl;
					cin >> book;
					Num_2 = bm->Get_Book_SerialNumber(Input_1, bs);
					if (book)
					{
					bm->Borrow_Book(Num_2, bs);
					}
					else
					{
					bm->Return_Book(Num_2, bs);
					}
					system("pause");
					system("cls");
				}
				else
				{
					cout << "此书不存在" << endl;
					system("pause");
					system("cls");
				}
				break;
			}
		default:
			exit(1);
			break;
		}
	}
	delete bm;
	delete bs;
	return 0;
}
