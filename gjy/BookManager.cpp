#include"BookManager.h"
#include"PersonManager.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


//---------------------------------------------------------------------------------------------------------------------------------------
// 第一个功能 录入书籍
void BookManager::Add_Book(int Book_Number,BookStorage* bookstorage)
{
	ifstream infile("f2.txt", ios::binary);
	if (!infile) { cerr << "读取错误，请联系工作人员。"; }
	for (int i = 0; i < MAX; i++)
		infile.read((char*)&bookstorage->warehouse[i], sizeof(bookstorage->warehouse[i]));
	infile.close();
	int j = this->Get_Storage_Number(bookstorage);
	int DetermineWhetherEnterInfo = 0;
	for(int i=j;i<j+Book_Number;i++)
	{
			cout << "第" << i+1 << "本书：" << endl;
			cout << "书名:";
			string bookname;
			//下面是在查找以前是不是被录入过了

			//if () // 
			//{
			//	cout << "这本书已经被录入过了，如需修改图书信息，请在主菜单选择3";
			//	DetermineWhetherEnterInfo = 1;
			//	break;				
			//}								
			cin >> bookstorage->warehouse[i].Book_Name;
			
			
			cout << "作者:";
			cin >> bookstorage->warehouse[i].Book_Author;
			cout << "ISBN:";
			cin >> bookstorage->warehouse[i].Book_ISBN;
			cout << "价格:";
			cin >> bookstorage->warehouse[i].Book_Price;
			cout << "库存:";
			cin >> bookstorage->warehouse[i].Book_Number_In_Storage;
			cout << "您输入的第" << i+1 << "本书的数据为：" << endl;
			cout << "书名:" << bookstorage->warehouse[i].Book_Name << endl;
			cout << "作者:" << bookstorage->warehouse[i].Book_Author << endl;
			cout << "ISBN:" << bookstorage->warehouse[i].Book_ISBN << endl;
			cout << "价格:" << bookstorage->warehouse[i].Book_Price << endl;
			cout << "库存:" << bookstorage->warehouse[i].Book_Number_In_Storage<< endl;
			cout << "请确认，无误请输入1，有误请输入2" << endl;
			int confirm = 0;
			cin >> confirm;
			if (confirm == 2)
			{
				cout << "第" << i + 1 << "本书的信息已重置，请重新输入，谢谢";
				i = i - 1;
			}
			else continue;

	}
	////if (DetermineWhetherEnterInfo == 1)
	////{
	////	cout << "以上录入的信息作废" << endl;
	////}
	//else cout << "以上信息已录入数据库中" << endl;
	cout << "以上信息已录入数据库中" << endl;
	ofstream outfile("f2.txt", ios::in|ios::app|ios::binary);
		for (int i = j; i < j + Book_Number; i++)
			outfile.write((char*)&bookstorage->warehouse[i], sizeof(bookstorage->warehouse[i]));
			outfile.close();

	system("pause");
	system("cls");//清屏
}

int BookManager::Get_Storage_Number(BookStorage* bookstorage)
{
	ifstream infile("f2.txt", ios::binary);
	if (!infile) { cerr << "读取错误，请联系工作人员。"; }
	for (int i = 0; i < MAX; i++)
		infile.read((char*)&bookstorage->warehouse[i], sizeof(bookstorage->warehouse[i]));
	infile.close();
	for (int i = 0; i < MAX; i++)
	{

		if (bookstorage->warehouse[i].Book_Name == "")//warehouse里面有十个“房间”，这里是在查找空房间，找到一个空房间马上分给他
		{
			return i;
		}
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
// 第二个功能  查找书籍 
// 判断书的存在（书名）
bool BookManager::Book_is_exist(std::string Input, BookStorage* bookstorage)

{
	ifstream infile("f2.txt", ios::binary);
	if (!infile) { cerr << "读取错误，请联系工作人员。"; }
	for (int i = 0; i < MAX; i++)
		infile.read((char*)&bookstorage->warehouse[i], sizeof(bookstorage->warehouse[i]));
	infile.close();
	for(int i=0;i<MAX;i++)
	{ 
		if (bookstorage->warehouse[i].Book_Name == Input||bookstorage->warehouse[i].Book_ISBN==Input)
		{			
			return true;
		}
		//查找编号
	}
	return false;
}

void BookManager::Display_Info( int n,BookStorage* bookstorage)
//展示书的信息
{
	ifstream infile("f2.txt", ios::binary);
	if (!infile) { cerr << "读取错误，请联系工作人员。"; }
	for (int i = 0; i < MAX; i++)
		infile.read((char*)&bookstorage->warehouse[i], sizeof(bookstorage->warehouse[i]));
	infile.close();
	cout << "已查找到此书！结果如下："<<endl;
	cout <<"书名:" << bookstorage->warehouse[n].Book_Name << endl;
	cout <<"作者:" << bookstorage->warehouse[n].Book_Author << endl;
	cout << "ISBN:" << bookstorage->warehouse[n].Book_ISBN << endl;
	cout << "价格:" << bookstorage->warehouse[n].Book_Price << endl;
	cout << "库存：" << bookstorage->warehouse[n].Book_Number_In_Storage <<"本" << endl;
	system("pause");
	system("cls");
}

//---------------------------------------------------------------------------------------------------------------------------------------
// 第三个功能  修改书籍信息 
void BookManager::Revise_Book(int Book_Number, BookStorage* bookstorage)
{
	ifstream infile("f2.txt", ios::binary);
	if (!infile) { cerr << "读取错误，请联系工作人员。"; }
	for (int i = 0; i < MAX; i++)
		infile.read((char*)&bookstorage->warehouse[i], sizeof(bookstorage->warehouse[i]));
	infile.close();
	cout << "请输入修改后的书籍信息：" << endl;
	cout << "书名:";
	cin >> bookstorage->warehouse[Book_Number].Book_Name;
	cout << "作者:";
	cin >> bookstorage->warehouse[Book_Number].Book_Author;
	cout << "ISBN:";
	cin >> bookstorage->warehouse[Book_Number].Book_ISBN;
	cout << "价格:";
	cin >> bookstorage->warehouse[Book_Number].Book_Price;
	cout << "库存:";
	cin >> bookstorage->warehouse[Book_Number].Book_Number_In_Storage;
	cout << "您输入的数据为：" << endl;
	cout << "书名:" << bookstorage->warehouse[Book_Number].Book_Name << endl;
	cout << "作者:" << bookstorage->warehouse[Book_Number].Book_Author << endl;
	cout << "ISBN:" << bookstorage->warehouse[Book_Number].Book_ISBN << endl;
	cout << "价格:" << bookstorage->warehouse[Book_Number].Book_Price << endl;
	cout << "库存:" << bookstorage->warehouse[Book_Number].Book_Number_In_Storage << endl;
	cout << "以上是第" << Book_Number +1 << "本书修改之后的数据" << endl;

	//定位于那一本书存放空间的开头
	fstream iofile("f2.txt", ios::in | ios::app | ios::binary);
	iofile.seekp(Book_Number * sizeof(bookstorage->warehouse[0]), ios::beg);
	iofile.write((char*)&bookstorage->warehouse[Book_Number], sizeof(bookstorage->warehouse[Book_Number]));
	iofile.close();
	cout << "修改后的信息已成功录入数据库" << endl;
	/*for (int i = 0; i < MAX; i++)
	{
		iofile.read((char*)&bookstorage->warehouse[i], sizeof(bookstorage->warehouse[i]));
		cout << bookstorage->warehouse[i].Book_Name << "是第" << i << "本" << endl;
	}*/
	system("pause");
	system("cls");//清屏
}


int BookManager::Get_Book_SerialNumber(std::string Name, BookStorage* bookstorage)
//获取编号
{
	ifstream infile("f2.txt", ios::binary);
	if (!infile) { cerr << "读取错误，请联系工作人员。"; }
	for (int i = 0; i < MAX; i++)
		infile.read((char*)&bookstorage->warehouse[i], sizeof(bookstorage->warehouse[i]));
	infile.close();
	for ( int i = 0; i < MAX; i++)
	{
		if (bookstorage->warehouse[i].Book_Name == Name||bookstorage->warehouse[i].Book_ISBN==Name)
		{
			return i;
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------
// 第四个功能  借书还书
void BookManager::Borrow_Book( int n, BookStorage* bookstorage)
{
	if (bookstorage->warehouse[n].Book_Number_In_Storage == 0)
	{	
		cout << "库存不足，借书失败" << endl;
	}
	else
	{
		bookstorage->warehouse[n].Book_Number_In_Storage--;
		cout << "借书成功" << endl;
		cout << "还有" << bookstorage->warehouse[n].Book_Number_In_Storage << "本" << endl;
		//定位于那一本书存放空间的开头，录入信息
		fstream iofile("f2.txt", ios::in | ios::app | ios::binary);
		iofile.seekp(n * sizeof(bookstorage->warehouse[0]), ios::beg);
		iofile.write((char*)&bookstorage->warehouse[n], sizeof(bookstorage->warehouse[n]));
		iofile.close();
		cout << "以上信息已录入数据库中" << endl;
	}

}
void BookManager::Display_Inventory(int n, BookStorage* bookstorage)
//展示书的库存
{
	cout << "这本书库存还有：" << bookstorage->warehouse[n].Book_Number_In_Storage << "本，"  ;
	if (bookstorage->warehouse[n].Book_Number_In_Storage > 0) cout << "可以借阅。";
	else cout << "库存不足，请移步其他图书馆。" << endl;
}










void BookManager::Return_Book( int n, BookStorage* bookstorage)
{
	bookstorage->warehouse[n].Book_Number_In_Storage++;
	cout << "还书成功" << endl;
	cout << "还有" << bookstorage->warehouse[n].Book_Number_In_Storage << "本" << endl;
}

bool Person_is_exist(std::string Input, PersonStorage* personstorage)
{
	return 0;
}
