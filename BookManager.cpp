#include"BookManager.h"
#include<iostream>
#include<string>
using namespace std;
void BookManager::Add_Book(BookStorage* bookstorage)
//添加一本书的信息
{
	cout << "书名:";
	cin >> bookstorage->warehouse[0].Book_Name;
	cout << "作者:";
	cin >> bookstorage->warehouse[0].Book_Author;
	cout << "ISBN:";
	cin >> bookstorage->warehouse[0].Book_ISBN;
	cout << "价格：";
	cin >> bookstorage->warehouse[0].Book_Price;
	bookstorage->warehouse[0].is_borrowed = false;//初始状态为没有借出
}
unsigned int BookManager::Get_Book_Number(std::string Name, BookStorage* bookstorage)
//获取编号
{
	for (int i = 0; i < MAX; i++)
	{
		if (bookstorage->warehouse[i].Book_Name == Name)
		{
			return i;
		}
	}
}
void BookManager::Display_Info(unsigned int n,BookStorage* bookstorage)
//展示书的信息
{
	cout <<"书名:" << bookstorage->warehouse[n].Book_Name << endl;
	cout <<"作者:" << bookstorage->warehouse[n].Book_Author << endl;
	cout << "ISBN:" << bookstorage->warehouse[n].Book_ISBN << endl;
	cout << "价格:" << bookstorage->warehouse[n].Book_Price << endl;
}
bool BookManager::Book_is_exist_1(std::string Name, BookStorage* bookstorage)
//判断书的存在（书名）
{
	for(int i=0;i<MAX;i++)
	{ 
		if (bookstorage->warehouse[i].Book_Name == Name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
bool BookManager::Book_is_exist_2(std::string ISBN, BookStorage* bookstorage)
//判断书的存在（ISBN）
{
	for (int i = 0; i < MAX; i++)
	{
		if (bookstorage->warehouse[i].Book_ISBN == ISBN)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
void BookManager::Borrow_Book(unsigned int n, BookStorage* bookstorage)
{
	bookstorage->warehouse[n].is_borrowed = true;
}
void BookManager::Return_Book(unsigned int n, BookStorage* bookstorage)
{
	bookstorage->warehouse[n].is_borrowed = false;
}