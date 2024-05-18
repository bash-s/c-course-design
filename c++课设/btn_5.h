#pragma once

#include <QMainWindow>
#include "ui_btn_5.h"
#include<qfile.h>
#include<qstringlist.h>
QT_BEGIN_NAMESPACE
namespace Ui { class btn_5Class; };
QT_END_NAMESPACE

class btn_5 : public QMainWindow
{
	Q_OBJECT

public:
	btn_5(QWidget *parent = nullptr);
	~btn_5();
private slots:
	void on_pushButton_clicked();
	void show_info();
	void inquire_book();
signals:
	void back();
private:
	Ui::btn_5Class *ui;
};
