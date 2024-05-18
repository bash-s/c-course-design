#pragma once

#include <QMainWindow>
#include "ui_btn_6.h"
#include<qfile.h>
#include<qstring.h>
#include<qstringlist.h>
QT_BEGIN_NAMESPACE
namespace Ui { class btn_6Class; };
QT_END_NAMESPACE

class btn_6 : public QMainWindow
{
	Q_OBJECT

public:
	btn_6(QWidget *parent = nullptr);
	~btn_6();
private slots:
	void on_pushButton_clicked();
	void show_info();
signals:
	void back();
private:
	Ui::btn_6Class *ui;
};
