#include "btn_2.h"

btn_2::btn_2(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::btn_2Class())
{
	ui->setupUi(this);
	connect(ui->pushButton, &QPushButton::clicked, this, &btn_2::on_pushButton_clicked);
	connect(ui->pushButton_2, &QPushButton::clicked, this, &btn_2::show_book_info);
}

btn_2::~btn_2()
{
	delete ui;
}
void btn_2::on_pushButton_clicked()
{
	emit back();
}

void btn_2::show_book_info()
{
	ui->label_9->setText("");
	ui->label_2->setText("");
	ui->label_3->setText("");
	ui->label_4->setText("");
	ui->label_5->setText("");
	ui->label_6->setText("");
	ui->label_7->setText("");
	ui->label_8->setText("");
	int serial_num = -1;
	QString ISBN;
	if (ui->lineEdit->text() != "")
	{
		ISBN = (ui->lineEdit->text());
	}
	else
	{
		ui->label_9->setText("请输入ISBN！");
		return;
	}
	QFile file("f2.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
	}
	QTextStream infile(&file);
	QStringList list;
	QString line;
	while (!infile.atEnd())
	{
		line = infile.readLine();
		list = line.split(" ");
		if (ISBN == list[3])
		{
			serial_num = list.at(0).toInt();
			break;
		}
	}
	file.close();
	if (serial_num == -1)
	{
		ui->label_9->setText("查无此书！");
	}
	else
	{
		QString BookName = list[1];
		QString BookAuthor = list[2];
		QString BookPrice=list[4];
		QString BookStorage = list[5];
		QString BookClass = list[6];
		QString BookPress= list[7];
		QString BookDate = list[8];
		ui->label_2->setText("书名：" +BookName);
		ui->label_3->setText("作者：" + BookAuthor);
		ui->label_4->setText("价格：" + BookPrice);
		ui->label_5->setText("库存：" + BookStorage);
		ui->label_6->setText("类别：" + BookClass);
		ui->label_7->setText("出版社：" + BookPress);
		ui->label_8->setText("出版时间："+BookDate);
	}
	ui->lineEdit->clear();
}