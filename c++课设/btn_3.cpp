#include "btn_3.h"
int serial_num = -1;

btn_3::btn_3(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::btn_3Class())
{
	ui->setupUi(this);
	connect(ui->pushButton, &QPushButton::clicked, this, &btn_3::on_pushButton_clicked);
	connect(ui->pushButton_2, &QPushButton::clicked, this, &btn_3::inquire_book);
	connect(ui->pushButton_3, &QPushButton::clicked, this, &btn_3::change_book);
	connect(ui->pushButton_4, &QPushButton::clicked, this, &btn_3::cancel);
}

btn_3::~btn_3()
{
	delete ui;
}
void btn_3::on_pushButton_clicked()
{
	emit back();
}

void btn_3::inquire_book()
{
	ui->lineEdit1->clear();
	ui->lineEdit_2->clear();
	ui->lineEdit_3->clear();
	ui->lineEdit_4->clear();
	ui->lineEdit_5->clear();
	ui->lineEdit_6->clear();
	ui->lineEdit_7->clear();
	ui->lineEdit_8->clear();
	QFile file("f2.txt");
	if (!file.open(QIODevice::ReadOnly))
	{
		ui->label_4->setText("仓库内无书！");
		return;
	}
	QString ISBN;
	if (ui->lineEdit->text() != "")
	{
		ISBN = (ui->lineEdit->text());
	}
	else
	{
		ui->label_4->setText("请输入ISBN！");
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
			serial_num = list.at(0).toInt();
			break;
		}
	}
	file.close();
	if (serial_num == -1)
	{
		ui->label_4->setText("查无此书！");
	}
	else
	{
		ui->label_4->setText("找到！请修改！");
	}
}

void btn_3::change_book()
{
	if (serial_num != -1)
	{
		QFile file("f2.txt");
		if (!file.open(QIODevice::ReadOnly))
		{
			ui->label_9->setText("仓库内无书！");
			return;
		}
		QTextStream infile(&file);
		QString line;
		QStringList lines;
		QVector<QStringList> arr;
		while (!infile.atEnd())
		{
			line = (infile.readLine());
			lines = line.split(" ");
			arr.append(lines);
		}
		file.close();
		for (QStringList &ls : arr)
		{
			if (ls.at(0).toInt() == serial_num)
			{
				if (ui->lineEdit1->text() == "")
				{
					return;
				}
				ls[1] = (ui->lineEdit1->text());
				ls[2] = (ui->lineEdit_2->text());
				ls[3] = (ui->lineEdit_3->text());
				ls[4] = (ui->lineEdit_4->text());
				ls[5] = (ui->lineEdit_5->text());
				ls[6] = (ui->lineEdit_6->text());
				ls[7] = (ui->lineEdit_7->text());
				ls[8]= (ui->lineEdit_8->text());
				break;
			}
		}
		QFile outfile("f2.txt");
		if (!outfile.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
		{
			return;
		}
		QTextStream out(&outfile);
		for (const QStringList ls : arr)
		{
			for (const QString s : ls)
			{
				out << s << " ";
			}
			out << "\n";
		}
		outfile.close();
		ui->label_3->setText("修改成功！");
	}
	else
	{
		ui->label_3->setText("请先查询！");
		return;
	}
	ui->lineEdit1->clear();
	ui->lineEdit_2->clear();
	ui->lineEdit_3->clear();
	ui->lineEdit_4->clear();
	ui->lineEdit_5->clear();
	ui->lineEdit_6->clear();
	ui->lineEdit_7->clear();
	ui->lineEdit_8->clear();
}

void btn_3::cancel()
{
	ui->lineEdit1->clear();
	ui->lineEdit_2->clear();
	ui->lineEdit_3->clear();
	ui->lineEdit_4->clear();
	ui->lineEdit_5->clear();
	ui->lineEdit_6->clear();
	ui->lineEdit_7->clear();
	ui->lineEdit_8->clear();
}