#include"BookManager.h"
#include<iostream>
#include<string>
using namespace std;
void BookManager::Add_Book(BookStorage* bookstorage)
//���һ�������Ϣ
{
	cout << "����:";
	cin >> bookstorage->warehouse[0].Book_Name;
	cout << "����:";
	cin >> bookstorage->warehouse[0].Book_Author;
	cout << "ISBN:";
	cin >> bookstorage->warehouse[0].Book_ISBN;
	cout << "�۸�";
	cin >> bookstorage->warehouse[0].Book_Price;
	bookstorage->warehouse[0].is_borrowed = false;//��ʼ״̬Ϊû�н��
}
unsigned int BookManager::Get_Book_Number(std::string Name, BookStorage* bookstorage)
//��ȡ���
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
//չʾ�����Ϣ
{
	cout <<"����:" << bookstorage->warehouse[n].Book_Name << endl;
	cout <<"����:" << bookstorage->warehouse[n].Book_Author << endl;
	cout << "ISBN:" << bookstorage->warehouse[n].Book_ISBN << endl;
	cout << "�۸�:" << bookstorage->warehouse[n].Book_Price << endl;
}
bool BookManager::Book_is_exist_1(std::string Name, BookStorage* bookstorage)
//�ж���Ĵ��ڣ�������
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
//�ж���Ĵ��ڣ�ISBN��
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