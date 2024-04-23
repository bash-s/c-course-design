#include"BookManager.h"
#include<iostream>
#include<string>
using namespace std;
void BookManager::Add_Book( int Book_Number,BookStorage* bookstorage)
//添加书的信息
{
	int j = this->Get_Storage_Number(bookstorage);
	for(int i=j;i<j+Book_Number;i++)
	{
			cout << "第" << i+1 << "本书：" << endl;
			cout << "书名:";
			cin >> bookstorage->warehouse[i].Book_Name;
			cout << "作者:";
			cin >> bookstorage->warehouse[i].Book_Author;
			cout << "ISBN:";
			cin >> bookstorage->warehouse[i].Book_ISBN;
			cout << "价格:";
			cin >> bookstorage->warehouse[i].Book_Price;
			cout << "库存:";
			cin >> bookstorage->warehouse[i].Book_Number_In_Storage;
	}
	system("pause");
	system("cls");//清屏
}
int BookManager::Get_Book_SerialNumber(std::string Name, BookStorage* bookstorage)
//获取编号
{
	for ( int i = 0; i < MAX; i++)
	{
		if (bookstorage->warehouse[i].Book_Name == Name||bookstorage->warehouse[i].Book_ISBN==Name)
		{
			return i;
		}
	}
}
void BookManager::Display_Info( int n,BookStorage* bookstorage)
//展示书的信息
{
	cout <<"书名:" << bookstorage->warehouse[n].Book_Name << endl;
	cout <<"作者:" << bookstorage->warehouse[n].Book_Author << endl;
	cout << "ISBN:" << bookstorage->warehouse[n].Book_ISBN << endl;
	cout << "价格:" << bookstorage->warehouse[n].Book_Price << endl;
	cout << "库存：" << bookstorage->warehouse[n].Book_Number_In_Storage <<"本" << endl;
	system("pause");
	system("cls");
}
bool BookManager::Book_is_exist(std::string Input, BookStorage* bookstorage)
//判断书的存在（书名）
{
	for(int i=0;i<MAX;i++)
	{ 
		if (bookstorage->warehouse[i].Book_Name == Input||bookstorage->warehouse[i].Book_ISBN==Input)
		{
			return true;
		}
		//查找编号
	}
	return false;
}
void BookManager::Borrow_Book( int n, BookStorage* bookstorage)
{
	if (bookstorage->warehouse[n].Book_Number_In_Storage == 0)
	{
		cout << "库存不足，借书失败" << endl;
	}
	else
	{
		bookstorage->warehouse[n].Book_Number_In_Storage--;
		cout << "借书成功" << endl;
		cout << "还有" << bookstorage->warehouse[n].Book_Number_In_Storage << "本" << endl;
	}
}
void BookManager::Return_Book( int n, BookStorage* bookstorage)
{
	bookstorage->warehouse[n].Book_Number_In_Storage++;
	cout << "还书成功" << endl;
	cout << "还有" << bookstorage->warehouse[n].Book_Number_In_Storage << "本" << endl;
}
int BookManager::Get_Storage_Number(BookStorage* bookstorage)
{
	for (int i = 0; i < MAX; i++)
	{
		if (bookstorage->warehouse[i].Book_Name == "")
		{
			return i;
		}
	}
}
