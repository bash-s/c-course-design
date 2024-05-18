#include "btn_6.h"

btn_6::btn_6(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::btn_6Class())
{
	ui->setupUi(this);
	connect(ui->pushButton, &QPushButton::clicked, this, &btn_6::on_pushButton_clicked);
	connect(ui->pushButton_3, &QPushButton::clicked,this,&btn_6::show_info);
}

btn_6::~btn_6()
{
	delete ui;
}
void btn_6::on_pushButton_clicked()
{
	emit back();
}

void btn_6::show_info()
{
	ui->textEdit->clear();
	int count_num = -1;
	QFile file("f2.txt");
	if (!file.open(QIODevice::ReadOnly))
	{
		ui->label_10->setText("仓库内无书！");
		return;
	}
	QString ISBN;
	if (ui->lineEdit_2->text() != "")
	{
		ISBN = (ui->lineEdit_2->text());
	}
	else
	{
		ui->label_10->setText("请输入ISBN！");
		return;
	}
	QTextStream infile(&file);
	QStringList list;
	QString line;
	while (!infile.atEnd())
	{
		line = infile.readLine();
		list = line.split(" ");
		if (ISBN == list.at(3))
		{
			count_num = list.at(0).toInt();
			break;
		}
	}
	file.close();
	if (count_num != -1)
	{
		QString num = QString::number(count_num);
		QFile f("record" + num + ".txt");
		if (!f.open(QIODevice::ReadOnly))
		{
			return;
		}
		QTextStream in(&f);
		QString line;
		QStringList list;
		QString text;
		while (!in.atEnd())
		{
			line = in.readLine();
			list = line.split(" ");
			QString s1 = "ID: " + list[0];
			QString s2 = "姓名: " + list[1];
			QString s3 = "性别: " + list[2];
			QString s4 = "电话: " + list[3];
			QString s5 = "地址: " + list[4];
			QString s6 = "本数: " + list[5];
			QString s7 = list[6];
			QString s = s1 +"  " + s2 + "  " + s3 + "  " +
			+"  "+s4 + "  " + s5 + "  " + s6 + "  "+s7+"书"+"\n";
			text += s;
		}
		ui->textEdit->setPlainText(text);
	}
	else
	{
		ui->label_10->setText("查无此书！");
	}
}