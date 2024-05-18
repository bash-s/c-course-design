#pragma once

#include <QMainWindow>
#include "ui_btn_2.h"
#include"Book.h"
#include<qstring.h>
#include<qfile.h>
#include<qstringlist.h>
QT_BEGIN_NAMESPACE
namespace Ui { class btn_2Class; };
QT_END_NAMESPACE

class btn_2 : public QMainWindow
{
	Q_OBJECT
public:
	btn_2(QWidget *parent = nullptr);
	~btn_2();
private slots:
	void on_pushButton_clicked();
	void show_book_info();
signals:
	void back();
private:
	Ui::btn_2Class *ui;
};
