#include "mywidget.h"
#include<qpushbutton>
#include"ui_mywidget.h"
#include"btn_1.h"
#include"btn_2.h"
#include"btn_3.h"
#include"btn_4.h"
#include"btn_5.h"
#include"btn_6.h"
#include"btn_7.h"
#include"btn_8.h"

mywidget::mywidget(QWidget *parent)
:QMainWindow(parent),ui(new Ui::mywidgetClass),w1(nullptr)
,w2(nullptr), w3(nullptr),w4(nullptr),w5(nullptr),w6(nullptr),w7(nullptr),w8(nullptr)
{
    ui->setupUi(this);
    w1 = new btn_1(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &mywidget::on_pushButton_clicked_1);
    w2 = new btn_2(this);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &mywidget::on_pushButton_clicked_2);
    w3 = new btn_3(this);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &mywidget::on_pushButton_clicked_3);
    w4 = new btn_4(this);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &mywidget::on_pushButton_clicked_4);
    w5 = new btn_5(this);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &mywidget::on_pushButton_clicked_5);
    w6 = new btn_6(this);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &mywidget::on_pushButton_clicked_6);
    w7 = new btn_7(this);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &mywidget::on_pushButton_clicked_7);
    w8 = new btn_8(this);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &mywidget::on_pushButton_clicked_8);

}
mywidget::~mywidget()
{
    delete ui;
    delete w1;
    delete w2;
    delete w3;
    delete w4;
    delete w5;
    delete w6;
    delete w7;
    delete w8;
}
void mywidget::on_pushButton_clicked_1()
{
    this->hide();
    w1->show();
    connect(w1, &btn_1::back, this, &mywidget::comeback_1);
}
void mywidget::comeback_1()
{
    this->show();
    w1->close();
}
void mywidget::on_pushButton_clicked_2()
{
    this->hide();
    w2->show();
    connect(w2, &btn_2::back, this, &mywidget::comeback_2);
}
void mywidget::comeback_2()
{
    this->show();
    w2->close();
}
void mywidget::on_pushButton_clicked_3()
{
    this->hide();
    w3->show();
    connect(w3, &btn_3::back, this, &mywidget::comeback_3);
}
void mywidget::comeback_3()
{
    this->show();
    w3->close();
}
void mywidget::on_pushButton_clicked_4()
{
    this->hide();
    w4->show();
    connect(w4, &btn_4::back, this, &mywidget::comeback_4);
}
void mywidget::comeback_4()
{
    this->show();
    w4->close();
}
void mywidget::on_pushButton_clicked_5()
{
    this->hide();
    w5->show();
    connect(w5, &btn_5::back, this, &mywidget::comeback_5);
}
void mywidget::comeback_5()
{
    this->show();
    w5->close();
}
void mywidget::on_pushButton_clicked_6()
{
    this->hide();
    w6->show();
    connect(w6, &btn_6::back, this, &mywidget::comeback_6);
}
void mywidget::comeback_6()
{
    this->show();
    w6->close();
}
void mywidget::on_pushButton_clicked_7()
{
    this->hide();
    w7->show();
    connect(w7, &btn_7::back, this, &mywidget::comeback_7);
}
void mywidget::comeback_7()
{
    this->show();
    w7->close();
}
void mywidget::on_pushButton_clicked_8()
{
    this->hide();
    w8->show();
    connect(w8, &btn_8::back, this, &mywidget::comeback_8);
}
void mywidget::comeback_8()
{
    this->show();
    w8->close();
}