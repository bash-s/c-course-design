#include "btn_5.h"
int s_num = -1;

btn_5::btn_5(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::btn_5Class())
{
	ui->setupUi(this);
	connect(ui->pushButton, &QPushButton::clicked, this, &btn_5::on_pushButton_clicked);
	connect(ui->pushButton_2, &QPushButton::clicked, this, &btn_5::show_info);
	connect(ui->pushButton_3, &QPushButton::clicked, this, &btn_5::inquire_book);
}

btn_5::~btn_5()
{
	delete ui;
}
void btn_5::on_pushButton_clicked()
{
	emit back();
}


void btn_5::inquire_book()
{
	int count_num = -1;
	QFile file("f2.txt");
	if (!file.open(QIODevice::ReadOnly))
	{
		ui->label_10->setText("仓库内无书！");
		return;
	}
	QString ISBN;
	if (ui->lineEdit_2->text()!= "")
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
			s_num = count_num;
			break;
		}
	}
	file.close();
	if (count_num == -1)
	{
		ui->label_10->setText("查无此书！");
	}
	else
	{
		ui->label_10->setText("找到！请输入读者ID！");
	}
}

void btn_5::show_info()
{
	ui->label_2->setText("");
	ui->label_3->setText("");
	ui->label_4->setText("");
	ui->label_5->setText("");
	ui->label_6->setText("");
	ui->label_9->setText("");
	if (s_num != -1)
	{
		bool person_is=false;
		QString num = QString::number(s_num);
		QFile file("person" + num + ".txt");
		if (!file.open(QIODevice::ReadOnly))
		{
			return;
		}
		QTextStream in(&file);
		QString ID = ui->lineEdit->text();
		QStringList list;
		QString line;
		while (!in.atEnd())
		{
			line = in.readLine();
			list = line.split(" ");
			if (list.at(0) == ID)
			{
				ui->label_2->setText("名字："+list.at(1));
				ui->label_3->setText("性别："+list.at(2));
				ui->label_4->setText("电话："+list.at(3));
				ui->label_5->setText("地址："+list.at(4));
				ui->label_6->setText("本数："+list.at(5));

				person_is = true;
				break;
			}
			person_is = false;
		}
		if (!person_is)
		{
			ui->label_9->setText("查无此人！");
		}
	}
	else
	{
		ui->label_9->setText("请输入ISBN！");
	}
}
