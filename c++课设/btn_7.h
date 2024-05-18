#pragma once

#include <QMainWindow>
#include "ui_btn_7.h"
#include<qstringlist.h>
#include<qfile.h>
#include<qevent.h>
#include<qtimer.h>
QT_BEGIN_NAMESPACE
namespace Ui { class btn_7Class; };
QT_END_NAMESPACE

class btn_7 : public QMainWindow
{
	Q_OBJECT

public:
	btn_7(QWidget *parent = nullptr);
	~btn_7();
private slots:
	void on_pushButton_clicked();
	void show_info();
signals:
	void back();
private:
	Ui::btn_7Class *ui;
};
