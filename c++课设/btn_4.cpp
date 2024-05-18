#include "btn_4.h"
int count_num = -1;

btn_4::btn_4(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::btn_4Class())
{
	ui->setupUi(this);
	connect(ui->pushButton, &QPushButton::clicked, this, &btn_4::on_pushButton_clicked);
	connect(ui->pushButton_2, &QPushButton::clicked, this, &btn_4::inquire_book);
	connect(ui->pushButton_3, &QPushButton::clicked, this, &btn_4::add_person);

}

btn_4::~btn_4()
{
	delete ui;
}
void btn_4::on_pushButton_clicked()
{
	emit back();
}

void btn_4::inquire_book()
{
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
			count_num = list.at(0).toInt();
			break;
		}
	}
	file.close();
	if (count_num == -1)
	{
		ui->label_4->setText("查无此书！");
	}
	else
	{
		ui->label_4->setText("找到！请输入个人信息和借阅信息！");
	}
}

void btn_4::add_person()
{
	if (count_num != -1)
	{
		int max = 0;
		count_num = btn_4::search(&max);
		QString num = QString::number(count_num);
		QFile f("person" +num+".txt");
		if (!f.open(QIODevice::Append))
		{
			return;
		}
		QFile f_1("record"+num+".txt");
		if (!f_1.open(QIODevice::Append))
		{
			return;
		}
		QTextStream out_1(&f);
		QTextStream out_2(&f_1);
		Person person;
		if (ui->lineEdit_2->text() == "")
		{
			return;
		}
		person.person_id = ui->lineEdit_2->text();
		person.name = ui->lineEdit_3->text();
		person.gender = ui->lineEdit_4->text();
		person.phone_number= ui->lineEdit_5->text();
		person.address= ui->lineEdit_6->text();
		person.borrow = ui->lineEdit_7->text();
		QString t;
		if (ui->radioButton->isChecked())
		{
			t = "借";
			max-=person.borrow.toInt();
		}
		else
		{
			t = "还";
			max+= person.borrow.toInt();
		}
		if (max >= 0)
		{
			QFile temp("f2.txt");
			if (!temp.open(QIODevice::ReadOnly))
			{
				return;
			}
			QTextStream infile(&temp);
			QString line;
			QStringList lines;
			QVector<QStringList> arr;
			while (!infile.atEnd())
			{
				line = (infile.readLine());
				lines = line.split(" ");
				arr.append(lines);
			}
			for (QStringList& ls : arr)
			{
				if (ls.at(0).toInt() == count_num)
				{
					ls[5] = QString::number(max);
					break;
				}
			}
			QFile outfile("f2.txt");
			if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
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
			out_1 << person.person_id << " "
				<< person.name << " " << person.gender
				<< " " << person.phone_number << " "
				<< person.address << " "
				<< person.borrow << "\n";
			out_2 << person.person_id << " "
				<< person.name << " " << person.gender
				<< " " << person.phone_number << " "
				<< person.address << " "
				<< person.borrow<<" "<<t<< "\n";
			f.close();
			f_1.close();
			ui->label_8->setText("借/还书成功！");
		}
		else
		{
			ui->label_8->setText("借/还书失败！");
		}
	}
	else
	{
		ui->label_8->setText("请先查询！");
		return;
	}
	ui->lineEdit_2->clear();
	ui->lineEdit_3->clear();
	ui->lineEdit_4->clear();
	ui->lineEdit_5->clear();
	ui->lineEdit_6->clear();
	ui->lineEdit_7->clear();
}
int btn_4::search(int* max)
{
	int count_num = -1;
	QString ISBN;
	QFile file("f2.txt");
	if (!file.open(QIODevice::ReadOnly))
	{
		ui->label_4->setText("仓库内无书！");
		return -1;
	}
	if (ui->lineEdit->text() != "")
	{
		ISBN = (ui->lineEdit->text());
	}
	else
	{
		ui->label_4->setText("请输入ISBN！");
		return -1;
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
			*max = list.at(5).toInt();
			break;
		}
	}
	file.close();
	return count_num;
}
