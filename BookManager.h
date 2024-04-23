#pragma once
#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
const int MAX = 1;//以一本为例
#include<string>
struct Book;
struct BookStorage;
class BookManager;
struct Book
{
	std::string Book_Name;
	std::string Book_Author;
	std::string Book_ISBN;
	unsigned int Book_Price;
	bool is_borrowed;
};
struct BookStorage
{
	Book warehouse[MAX];
};
class BookManager
{
public:
	void Add_Book(BookStorage* bookstorage);
	void Display_Info(unsigned int n,BookStorage* bookstorage);
	bool Book_is_exist_1(std::string Name, BookStorage* bookstorage);
	bool Book_is_exist_2(std::string ISBN, BookStorage* bookstorage);
	unsigned int Get_Book_Number(std::string Name, BookStorage* bookstorage);
	void Borrow_Book(unsigned int n,BookStorage* bookstorage);
	void Return_Book(unsigned int n,BookStorage* bookstorage);
};
#endif 
