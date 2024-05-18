#pragma once

#include <QMainWindow>
#include "ui_btn_4.h"
#include"Person.h"
#include<qfile.h>
#include<qvector.h>
#include<qstringlist.h>
QT_BEGIN_NAMESPACE
namespace Ui { class btn_4Class; };
QT_END_NAMESPACE

class btn_4 : public QMainWindow
{
	Q_OBJECT

public:
	btn_4(QWidget *parent = nullptr);
	~btn_4();
	int search(int* max);
private slots:
	void on_pushButton_clicked();
	void inquire_book();
	void add_person();
signals:
	void back();
private:
	Ui::btn_4Class *ui;
};
