#include "mywidget.h"
#include <QtWidgets/QApplication>
#include"Book.h"
#include<fstream>
#include<iostream>

extern int book_num;
static int count = 0;
int count_book_num()
{
	std::ifstream infile("f2.txt", std::ios_base::binary|std::ios_base::in);
	if (!infile)
	{
		return 0;
	}
	std::string line;
	int count = 0;
	while (std::getline(infile, line)) 
	{
		count++;
	}
	infile.close();
	return count;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mywidget w;
	if (count == 0)
	{
		book_num = count_book_num();
		count++;
	}
	w.show();
    return a.exec();
}
