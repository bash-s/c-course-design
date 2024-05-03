#include"BookManager.h"
#include"PersonManager.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
	BookManager* bm = new BookManager;//开辟空间维护
	BookStorage* bs = new BookStorage;//开辟空间维护
	PersonManager* pm = new PersonManager;//开辟空间维护
	PersonStorage* ps = new PersonStorage;//开辟空间维护
	int choice = 0;
	string pw{};
	while (1)
	{	//苟峻逸
		cout << "0、退出系统" << endl;
		cout << "1、录入图书" << endl;
		cout << "2、查询图书" << endl;
		cout << "3、修改图书" << endl;
		cout << "4、借/还书，登记借阅者信息" << endl;
		cout << "5、查询借阅者" << endl;
		cout << "6、修改借阅者" << endl;
		cout << "7、查询借阅信息" << endl;
		cout << "8、逾期提醒" << endl;
		cout << endl;
		cout << "欢迎来到主菜单！请输入数字进行功能选择:" << endl;
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
				while (Num_0 > 10)
				{
					cout << "超过录入上限，请重新输入!"<<endl;
					cout << "---------------------------------------" << endl;
					cout << "请问您要录入几本书？（上限10本）" << endl;
					cin >> Num_0;
				}
				bm->Add_Book(Num_0, bs); //bm是：BookManager* bm = new BookManager;
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
				
				if (bm->Book_is_exist(Input_0, bs)) // bm是：BookManager * bm = new BookManager;  作用：bm调用了成员函数
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
				cout << "这是修改图书信息的程序" << endl;
				cout << "请输入书名/ISBN:" << endl;
				int Num_1 = 0;
				string Input_3{};
				cin >> Input_3;
				if (bm->Book_is_exist(Input_3, bs)) // bm是：BookManager * bm = new BookManager;  作用：bm调用了成员函数
				{
					Num_1 = bm->Get_Book_SerialNumber(Input_3, bs);
					bm->Display_Info(Num_1, bs);
					cout << "已查找到此书，这是第" << Num_1 + 1 << "本书" << endl;;
					cout << "请问您需要修改它的信息吗？修改请输入1，维持原状请输入2。" << endl;
					int user_selection = 0;
					cin >> user_selection;
					if (user_selection == 2)
					{						
						system("pause");
						system("cls");
						break;

					}
					else
					{
						bm->Revise_Book(Num_1, bs); //bm是：BookManager* bm = new BookManager;
						break;
					}

				}
				else
				{
					cout << "此书本来就不存在，请按任意键返回主菜单" << endl;
					system("pause");
					system("cls");
				}
				break;
			}
			case 4:
			{
				string Input_1{};
				string Input_p{};
				int Num_2 = 0;
				bool book = 0;
				cout << "请登记借阅者信息：" << endl;
				cout << "姓名：";
				cin >> Input_p;
				cout << "请再次输入以确认:" << endl;
				pm->Add_Person(ps);
				cout << "已录入数据库，请再次输入需要借阅的书籍名称以确认，我们将检索数据库，查看这本书是否存在。" << endl;
				cout << "请输入书名/ISBN:";
				cin >> Input_1;
				//ofstream inflie("f2.txt,ios::in|ios::binary");

				if (bm->Book_is_exist(Input_1, bs))//只是查看f2.txt中是否有这本书的信息，不查看这本书是否有库存
				{
					cout << "图书馆里这一本图书的信息如下" << endl;
					Num_2 = bm->Get_Book_SerialNumber(Input_1, bs);
					bm->Display_Inventory(Num_2, bs);

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
					cout << "此书不存在，请移步其他图书馆" << endl;
					system("pause");
					system("cls");
				}
				break;
			}
			case 5:
			{
				string Input_5{};
				int Num_5 = 0;
				cout << "请输入借阅者姓名" << endl;
				cout << "姓名：" << endl;
				cin >> Input_5;
				if (pm->Person_is_exist(Input_5, ps))
				{
					Num_5 = pm->Get_Person_SerialNumber(Input_5, ps);
					pm->Display_Inform(Num_5, ps);
				}
				else
				{
					cout << "查无此人" << endl;
					system("pause");
					system("cls");
				}
				break;
			}
			case 6:
			{
				string Input_5{};
				int Num_5 = 0;
				cout << "请输入借阅者姓名" << endl;
				cout << "姓名：" << endl;
				cin >> Input_5;
				if (pm->Person_is_exist(Input_5, ps))
				{
					Num_5 = pm->Get_Person_SerialNumber(Input_5, ps);
					pm->Display_Inform(Num_5, ps);
					cout << "现在开始填写借阅者的修改信息" << endl;
					cout << "注意：目前只能修改借阅者的班级，无法修改借阅者的姓名与借阅书籍。" << endl;
					cout << "以防有人借了书以后把名字改成他人姓名或改成借其他书，请大家好自为之。" << endl;
					pm->Revise_Person(Num_5, ps);
				}
				else
				{
					cout << "查无此人" << endl;
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
