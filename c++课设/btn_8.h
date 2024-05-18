#pragma once

#include <QMainWindow>
#include "ui_btn_8.h"
#include<qfile.h>
#include<qstringlist.h>

QT_BEGIN_NAMESPACE
namespace Ui { class btn_8Class; };
QT_END_NAMESPACE

class btn_8 : public QMainWindow
{
	Q_OBJECT
public:
	btn_8(QWidget *parent = nullptr);
	~btn_8();
private slots:
	void on_pushButton_clicked();
	void inquire_book();
	void search_person();
	void change_person();
	void cancel();
signals:
	void back();
private:
	Ui::btn_8Class *ui;
};
