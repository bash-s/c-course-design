#pragma once

#include <QMainWindow>
#include "ui_btn_1.h"
#include<qstring.h>
#include"Book.h"
#include<qfile.h>
#include<qtextstream.h>
QT_BEGIN_NAMESPACE
namespace Ui { class btn_1Class; };
QT_END_NAMESPACE

class btn_1 : public QMainWindow
{
	Q_OBJECT
public:
	btn_1(QWidget *parent = nullptr);
	~btn_1();
private slots:
	void on_pushButton_clicked();
	void show_book_num();
	void add_book();
	void cancel_add();
signals:
	void back();
private:
	Ui::btn_1Class *ui;
	int *book_total;
};
