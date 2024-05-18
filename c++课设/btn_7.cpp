#include "btn_7.h"

btn_7::btn_7(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::btn_7Class())
{
	ui->setupUi(this);
	connect(ui->pushButton, &QPushButton::clicked, this, &btn_7::on_pushButton_clicked);
	connect(ui->pushButton_2, &QPushButton::clicked, this,&btn_7::show_info );
}

btn_7::~btn_7()
{
	delete ui;
}
void btn_7::on_pushButton_clicked()
{
	emit back();
}

void btn_7::show_info()
{
	ui->textEdit->clear();
	QEventLoop loop;
	QTimer::singleShot(int(1000 * 10), &loop, SLOT(quit()));
	loop.exec();
	QFile f("record1.txt");
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
		QString s = s1 + "  " + s2 + "  " + s3 + "  " +
			+"  " + s4 + "  " + s5 + "  " + s6 + "  " + s7 + "书" + "\n";
		text += s;
	}
	ui->textEdit->setPlainText(text);
	f.close();
}
