#include"BookManager.h"
#include"PersonManager.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------
// 



//---------------------------------------------------------------------------------------------------------------------------------------
// 第五个功能 查询借阅者信息
void PersonManager::Add_Person(PersonStorage* personstorage)
{
	int k = this->Get_Storage_Number(personstorage);
	cout << "姓名：";
	cin >> personstorage->storehouse[k].Person_Name;
	cout << "班级（输入数字）：";
	cin >> personstorage->storehouse[k].group;
	cout << "您希望借哪一本书呢？请您先输入，您的意向书籍在本图书馆可能暂时没有库存，但该信息可能作为宝贵的图书馆改善意见：" << endl;
	cout << "书籍名称：" ;
	cin >> personstorage->storehouse[k].Book_Name;
	ofstream outfile("f3.txt", ios::in | ios::app | ios::binary);
	outfile.write((char*)&personstorage->storehouse[k], sizeof(personstorage->storehouse[k]));
	outfile.close();
}



bool PersonManager::Person_is_exist(std::string Input, PersonStorage* personstorage)
{
	ifstream infile("f3.txt", ios::binary);
		for (int k = 0; k < MAXIMUM; k++)//读取存储借阅者信息的文档
			infile.read((char*)&personstorage->storehouse[k], sizeof(personstorage->storehouse[k]));
	infile.close();//读取完毕
	for (int k = 0; k < MAXIMUM; k++)
	{
			if (personstorage->storehouse[k].Person_Name == Input)  
				return true;//查找编号（借阅者信息被存储在哪一个“房间”里了）
	}
	return false;
}



void PersonManager::Display_Inform(int n, PersonStorage* personstorage)
{
	cout << "查有此人，信息如下："<<endl;
	cout << "姓名：" << personstorage->storehouse[n].Person_Name << endl;
	cout << "班级：" << personstorage->storehouse[n].group << endl;
	cout << "借阅书籍：" << personstorage->storehouse[n].Book_Name << endl;
	system("pause");
	system("cls");//清屏
}



int PersonManager::Get_Storage_Number(PersonStorage* personstorage)
{

	for (int i = 0; i < MAX; i++)
	{

		if (personstorage->storehouse[i].Book_Name == "")//warehouse里面有十个“房间”，这里是在查找空房间，找到一个空房间马上分给他
		{
			return i;
		}
	}
}


int PersonManager::Get_Person_SerialNumber(std::string Name, PersonStorage* personstorage)
{
	for (int k = 0; k < MAXIMUM; k++)
	{
		if (personstorage->storehouse[k].Person_Name == Name) 
			return k;
	}
	// 如果没有找到匹配的项，则返回一个表示“未找到”的值  
	return -1; // 或者其他合适的值 
}

//---------------------------------------------------------------------------------------------------------------------------------------
// 第六个功能 修改借阅者信息
void PersonManager::Revise_Person(int n, PersonStorage* personstorage)
{
	
	fstream iofile("f3.txt", ios::in | ios::out | ios::binary);
	cout << "请写出修改后的班级：" ;
	cin>>personstorage->storehouse[n].group;
	iofile.seekp(n * sizeof(personstorage->storehouse[0]), ios::beg);
	iofile.write((char*)&personstorage->storehouse[n], sizeof(personstorage->storehouse[0]));
	cout << "修改后的信息已成功录入数据库" << endl;
	iofile.close();
	system("pause");
	system("cls");//清屏
}