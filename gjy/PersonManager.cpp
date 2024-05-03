#include"BookManager.h"
#include"PersonManager.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------
// 



//---------------------------------------------------------------------------------------------------------------------------------------
// ��������� ��ѯ��������Ϣ
void PersonManager::Add_Person(PersonStorage* personstorage)
{
	int k = this->Get_Storage_Number(personstorage);
	cout << "������";
	cin >> personstorage->storehouse[k].Person_Name;
	cout << "�༶���������֣���";
	cin >> personstorage->storehouse[k].group;
	cout << "��ϣ������һ�����أ����������룬���������鼮�ڱ�ͼ��ݿ�����ʱû�п�棬������Ϣ������Ϊ�����ͼ��ݸ��������" << endl;
	cout << "�鼮���ƣ�" ;
	cin >> personstorage->storehouse[k].Book_Name;
	ofstream outfile("f3.txt", ios::in | ios::app | ios::binary);
	outfile.write((char*)&personstorage->storehouse[k], sizeof(personstorage->storehouse[k]));
	outfile.close();
}



bool PersonManager::Person_is_exist(std::string Input, PersonStorage* personstorage)
{
	ifstream infile("f3.txt", ios::binary);
		for (int k = 0; k < MAXIMUM; k++)//��ȡ�洢��������Ϣ���ĵ�
			infile.read((char*)&personstorage->storehouse[k], sizeof(personstorage->storehouse[k]));
	infile.close();//��ȡ���
	for (int k = 0; k < MAXIMUM; k++)
	{
			if (personstorage->storehouse[k].Person_Name == Input)  
				return true;//���ұ�ţ���������Ϣ���洢����һ�������䡱���ˣ�
	}
	return false;
}



void PersonManager::Display_Inform(int n, PersonStorage* personstorage)
{
	cout << "���д��ˣ���Ϣ���£�"<<endl;
	cout << "������" << personstorage->storehouse[n].Person_Name << endl;
	cout << "�༶��" << personstorage->storehouse[n].group << endl;
	cout << "�����鼮��" << personstorage->storehouse[n].Book_Name << endl;
	system("pause");
	system("cls");//����
}



int PersonManager::Get_Storage_Number(PersonStorage* personstorage)
{

	for (int i = 0; i < MAX; i++)
	{

		if (personstorage->storehouse[i].Book_Name == "")//warehouse������ʮ�������䡱���������ڲ��ҿշ��䣬�ҵ�һ���շ������Ϸָ���
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
	// ���û���ҵ�ƥ�����򷵻�һ����ʾ��δ�ҵ�����ֵ  
	return -1; // �����������ʵ�ֵ 
}

//---------------------------------------------------------------------------------------------------------------------------------------
// ���������� �޸Ľ�������Ϣ
void PersonManager::Revise_Person(int n, PersonStorage* personstorage)
{
	
	fstream iofile("f3.txt", ios::in | ios::out | ios::binary);
	cout << "��д���޸ĺ�İ༶��" ;
	cin>>personstorage->storehouse[n].group;
	iofile.seekp(n * sizeof(personstorage->storehouse[0]), ios::beg);
	iofile.write((char*)&personstorage->storehouse[n], sizeof(personstorage->storehouse[0]));
	cout << "�޸ĺ����Ϣ�ѳɹ�¼�����ݿ�" << endl;
	iofile.close();
	system("pause");
	system("cls");//����
}