#pragma once

#include <QMainWindow>
#include "ui_btn_3.h"
#include<qfile.h>
#include<qstring.h>
#include<qvector.h>

QT_BEGIN_NAMESPACE
namespace Ui { class btn_3Class; };
QT_END_NAMESPACE

class btn_3 : public QMainWindow
{
	Q_OBJECT
public:
	btn_3(QWidget *parent = nullptr);
	~btn_3();
private slots:
	void on_pushButton_clicked();
	void inquire_book();
	void change_book();
	void cancel();
signals:
	void back();
private:
	Ui::btn_3Class *ui;
};
