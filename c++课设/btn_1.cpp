#include "btn_1.h"
#include<fstream>
int book_num = 0;
btn_1::btn_1(QWidget *parent)
	: QMainWindow(parent),ui(new Ui::btn_1Class())
	,book_total(nullptr)
{
	ui->setupUi(this);
	connect(ui->pushButton, &QPushButton::clicked, this, &btn_1::on_pushButton_clicked);
	connect(ui->pushButton_2, &QPushButton::clicked, this,&btn_1::show_book_num);
	connect(ui->pushButton_3, &QPushButton::clicked, this, &btn_1::add_book);
	connect(ui->pushButton_4, &QPushButton::clicked, this, &btn_1::cancel_add);
	book_total = &book_num;
}

btn_1::~btn_1()
{
	delete ui;
}

void btn_1::on_pushButton_clicked()
{
	emit back();
}

void btn_1::show_book_num()
{
	QString book = QString::number(*(this->book_total));
	ui->lineEdit->setText(book);
}

void btn_1::add_book()
{
	if (ui->lineEdit1->text() != "")
	{
		(*(this->book_total))++;
	}
	QString num = QString::number(*(this->book_total));
	Book book;
	if (ui->lineEdit1->text() == "")
	{
		return;
	}
	book.Book_Name = ui->lineEdit1->text();
	book.Book_Author = ui->lineEdit_2->text();
	book.Book_ISBN = ui->lineEdit_3->text();
	book.Book_Price = ui->lineEdit_4->text();
	book.Book_Number_In_Storage = ui->lineEdit_5->text();
	book.classification = ui->lineEdit_6->text();
	book.press =ui->lineEdit_7->text();
	book.publish_date = ui->lineEdit_8->text();
	QFile file("f2.txt");
	if (!file.open(QIODevice::Append | QIODevice::Text))
	{
		return;
	}
	QTextStream outfile(&file);
	outfile << book_num << " " 
	<< book.Book_Name<< " "<< book.Book_Author
	<<" "<< book.Book_ISBN<<" "<< book.Book_Price<<" "
	<< book.Book_Number_In_Storage<<" "<< book.classification
	<<" "<< book.press<<" "<< book.publish_date<<" "
	<< "\n";
	QString name = "person" + num+".txt";
	QString name_1 = "record" + num + ".txt";
	QFile f(name);
	f.open(QIODevice::WriteOnly);
	QFile f_1(name_1);
	f_1.open(QIODevice::WriteOnly);
	file.close();
	f.close();
	f_1.close();
	btn_1::cancel_add();
}

void btn_1::cancel_add()
{
	ui->lineEdit1->clear();
	ui->lineEdit_2->clear();
	ui->lineEdit_3->clear();
	ui->lineEdit_4->clear();
	ui->lineEdit_5->clear();
	ui->lineEdit_6->clear();
	ui->lineEdit_7->clear();
	ui->lineEdit_8->clear();
}

