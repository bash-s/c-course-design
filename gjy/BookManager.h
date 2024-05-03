#pragma once
#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
const int MAX = 10;//书的本数
#include<string>
struct Book;
struct BookStorage;
class BookManager;
struct Book
{
	std::string Book_Name;
	std::string Book_Author;
	std::string Book_ISBN;
	int Book_Price;
    int Book_Number_In_Storage;
};
struct BookStorage
{
	Book warehouse[MAX];

};

class BookManager
{
public:
	void Add_Book(int Book_Number,BookStorage* bookstorage);
	void Display_Info(int n,BookStorage* bookstorage);
	bool Book_is_exist(std::string Input, BookStorage* bookstorage);
	int Get_Book_SerialNumber(std::string Name, BookStorage* bookstorage);
	void Borrow_Book( int n,BookStorage* bookstorage);
	void Return_Book(int n, BookStorage* bookstorage);
	int Get_Storage_Number(BookStorage* bookstorage);
	void Revise_Book(int n, BookStorage* bookstorage);
	void Display_Inventory(int n, BookStorage* bookstorage);
	bool Person_is_exist(std::string Input, BookStorage* bookstorage);
private:
	std::string PassWord;
};


#endif 
