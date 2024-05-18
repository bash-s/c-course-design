#pragma once
const int MAXIMUM = 10;
#include<string>
struct Person;
class BookManager;
struct PersonStorage;
struct Person
{
	std::string Person_Name;
	//Book Book_Name;
	std::string Book_Name;
	int group;
	std::string Borrow_Time;
};
struct PersonStorage
{
	Person storehouse[MAXIMUM];
};

class PersonManager
{
public:
	void Add_Person(PersonStorage* personstorage);
	bool Person_is_exist(std::string Input, PersonStorage* personstorage);
	int Get_Storage_Number(PersonStorage* personstorage);
	void Display_Inform(int n, PersonStorage* personstorage);
	int Get_Person_SerialNumber(std::string Name, PersonStorage* personstorage);
	void Revise_Person(int n, PersonStorage* personstorage);
};
