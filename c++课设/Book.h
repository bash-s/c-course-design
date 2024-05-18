#pragma once
#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
#include<qstring.h>
class Book;
class Book
{
public:
	QString Book_Name;
	QString Book_Author;
	QString Book_ISBN;
	QString Book_Price;
	QString Book_Number_In_Storage;
	QString classification;
	QString press;
	QString publish_date;
	Book(){}
	~Book(){}
};
#endif	