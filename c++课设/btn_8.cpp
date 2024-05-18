#include "btn_8.h"
int search_num = -1;
btn_8::btn_8(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::btn_8Class())
{
	ui->setupUi(this);
	connect(ui->pushButton, &QPushButton::clicked, this, &btn_8::on_pushButton_clicked);
	connect(ui->pushButton_3, &QPushButton::clicked, this, &btn_8::inquire_book);
	connect(ui->pushButton_2, &QPushButton::clicked, this, &btn_8::search_person);
	connect(ui->pushButton_4, &QPushButton::clicked, this, &btn_8::change_person);
	connect(ui->pushButton_5, &QPushButton::clicked, this, &btn_8::cancel);

}
btn_8::~btn_8()
{
	delete ui;
}
void btn_8::on_pushButton_clicked()
{
	emit back();
}

void btn_8::inquire_book()
{
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
			search_num = count_num;
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

void btn_8::search_person()
{
	if (search_num != -1)
	{
		bool person_is = false;
		QString num = QString::number(search_num);
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
				person_is = true;
				break;
			}
		}
		if (!person_is)
		{
			ui->label_14->setText("查无此人！");
		}
		else
		{
			ui->label_14->setText("找到！请输入读者信息！");
		}
	}
	else
	{
		ui->label_14->setText("请输入ISBN！");
	}
}

void btn_8::cancel()
{
	ui->lineEdit_3->clear();
	ui->lineEdit_4->clear();
	ui->lineEdit_5->clear();
	ui->lineEdit_6->clear();
	ui->lineEdit_7->clear();
	ui->lineEdit_8->clear();
}

void btn_8::change_person()
{
	QString ID = ui->lineEdit->text();
	if (search_num != -1)
	{
		QString num = QString::number(search_num);
		QFile f_in("person"+num+".txt");
		if (!f_in.open(QIODevice::ReadOnly))
		{
			return;
		}
		QTextStream infile(&f_in);
		QString line;
		QStringList lines;
		QVector<QStringList> arr;
		while (!infile.atEnd())
		{
			line = (infile.readLine());
			lines = line.split(" ");
			arr.append(lines);
		}
		f_in.close();
		for (QStringList& ls : arr)
		{
			if (ls.at(0) == ID)
			{
				if (ui->lineEdit_3->text()=="")
				{
					return;
				}
				ls[0] = ui->lineEdit_3->text();
				ls[1] = ui->lineEdit_4->text();
				ls[2] = ui->lineEdit_5->text();
				ls[3] = ui->lineEdit_6->text();
				ls[4] = ui->lineEdit_7->text();
				ls[5] = ui->lineEdit_8->text();
				break;
			}
		}
		QFile f_out("person"+num+".txt");
		if (!f_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
		{
			return;
		}
		QTextStream out(&f_out);
		for (const QStringList ls : arr)
		{
			for (const QString s : ls)
			{
				out << s << " ";
			}
			out << "\n";
		}
		f_out.close();
		ui->label_3->setText("修改成功！");
		ui->lineEdit_3->clear();
		ui->lineEdit_4->clear();
		ui->lineEdit_5->clear();
		ui->lineEdit_6->clear();
		ui->lineEdit_7->clear();
		ui->lineEdit_8->clear();
	}
	else
	{
		ui->label_14->setText("请输入ISBN！");
	}
}