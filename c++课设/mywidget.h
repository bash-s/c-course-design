#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mywidget.h"
#include"btn_1.h"
#include"btn_2.h"
#include"btn_3.h"
#include"btn_4.h"
#include"btn_5.h"
#include"btn_6.h"
#include"btn_7.h"
#include"btn_8.h"

class mywidget : public QMainWindow
{
    Q_OBJECT
public:
    mywidget(QWidget *parent = nullptr);
    ~mywidget();
private slots:
    void on_pushButton_clicked_1();
    void comeback_1();
    void on_pushButton_clicked_2();
    void comeback_2();
    void on_pushButton_clicked_3();
    void comeback_3();
    void on_pushButton_clicked_4();
    void comeback_4();
    void on_pushButton_clicked_5();
    void comeback_5();
    void on_pushButton_clicked_6();
    void comeback_6();
    void on_pushButton_clicked_7();
    void comeback_7();
    void on_pushButton_clicked_8();
    void comeback_8();

private:
    Ui::mywidgetClass*ui;
    btn_1*w1;
    btn_2* w2;
    btn_3* w3;
    btn_4* w4;
    btn_5* w5;
    btn_6* w6;
    btn_7* w7;
    btn_8* w8;
};
