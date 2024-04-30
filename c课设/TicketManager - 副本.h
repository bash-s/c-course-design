#pragma once

#define wait_person_max 50

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

struct AirRoute;
struct passenger;
struct wait_passenger;

void showmenu();
passenger* create_passenger(int n);
wait_passenger* create_wait_passenger(int n);
void free_manager(AirRoute* airptr);
void add_route(AirRoute* air);
void show_route(AirRoute* air);
int search_route(char* destination,AirRoute* ap,int n_max);
int purchase(AirRoute*air);
void add_wait_passenger(AirRoute* air);
int refund(AirRoute* air);
void fill(AirRoute* air,int i);
int search_person(AirRoute* air,char *name);

struct AirRoute
{
	char destination[20];
	char flight_number[20];
	char air_number[20];
	char start_time[20];
	char end_time[20];
	int person_max;
	int ticket_remain_1;
	int ticket_remain_2;
	passenger* ptr = NULL;
	wait_passenger* wait_ptr = NULL;
	int purchase_total;
	int wait_total;
};

struct passenger
{
	char name[20];
	int ticket_need;
	int degree;
};

struct wait_passenger
{
	char name[20];
	int ticket_need;
};

void showmenu()
{
	printf("1.录入航线\n");
	printf("2.查询航线\n");
	printf("3.订票\n");
	printf("4.退票\n");
	printf("5.修改航线信息\n");
	printf("6.删除航线\n");
	printf("7.退出\n");
	printf("8.查询购票情况\n");

}
passenger* create_passenger(int n)
{
	passenger* ptr = (passenger*)malloc(n * sizeof(passenger));
	return ptr;
}
wait_passenger* create_wait_passenger(int n)
{
	wait_passenger* ptr = (wait_passenger*)malloc(n * sizeof(wait_passenger));
	return ptr;
}

void free_manager(AirRoute* airptr)
{
	if (airptr != NULL)
	{
		free((void*)airptr);
	}
}

void input_str(char* str)
{
	scanf_s("%s",str,20);
	str[19] = '\0';
}

void add_route(AirRoute *air)
{
	printf("目的地:\n");
	input_str(air->destination);
	printf("航班编号:\n");
	input_str(air->flight_number);
	printf("飞机编号:\n");
	input_str(air->air_number);
	printf("开始时间:\n");
	input_str(air->start_time);
	printf("结束时间:\n");
	input_str(air->end_time);
	printf("最大定额:\n");
	scanf_s("%d", &air->person_max);
	printf("一等座余票额:\n");
	scanf_s("%d", &air->ticket_remain_1);
	printf("二等座余票额:\n");
	scanf_s("%d", &air->ticket_remain_2);
	printf("操作成功!\n");
	air->ptr = create_passenger(air->person_max);
	air->wait_ptr = create_wait_passenger(wait_person_max);
	air->purchase_total = 0;
	air->wait_total = 0;
	system("pause");
	system("cls");
}

void show_route(AirRoute* air)
{
	if (air->destination[19]=='\0')
	{
		printf("目的地:%s\n",air->destination);
		printf("航班编号:%s\n",air->flight_number);
		printf("飞机编号:%s\n",air->air_number);
		printf("开始时间:%s\n",air->start_time);
		printf("结束时间:%s\n",air->end_time);
		printf("最大定额:%d\n",air->person_max);
		printf("一等座余票额:%d\n",air->ticket_remain_1);
		printf("二等座余票额:%d\n", air->ticket_remain_2);
	}
	else
	{
		printf("The air route is null!\n");
	}
	system("pause");
	system("cls");
}

int search_route(char* destination,
	AirRoute* ap, int n_max)
{
	int i = 0;
	for (i; i < n_max; i++)
	{
		if (strcmp(destination, ap[i].destination) == 0)
		{
			return i;
		}
	}
	return -1;
}

int purchase(AirRoute* air)
{
	if ((air->ticket_remain_1 != 0 || air->ticket_remain_2 != 0)&&air->purchase_total<=air->person_max)
	{
		printf("请输入名字:\n");
		input_str(air->ptr[air->purchase_total].name);
		printf("请输入需要多少票:\n");
		scanf_s("%d", &(air->ptr[air->purchase_total].ticket_need));
		printf("请输入需要几等座(默认二等座):\n");
		scanf_s("%d", &(air->ptr[air->purchase_total].degree));
		air->purchase_total++;
		if (air->ptr[air->purchase_total-1].degree==1&& air->ptr[air->purchase_total-1].ticket_need<=air->ticket_remain_1)
		{
			air->ticket_remain_1 -= air->ptr[air->purchase_total-1].ticket_need;
		}
		else if(air->ptr[air->purchase_total-1].ticket_need<=air->ticket_remain_2)
		{
			air->ticket_remain_2 -= air->ptr[air->purchase_total-1].ticket_need;
		}
		else
		{
			air->ptr[air->purchase_total-1].name[0] = '\0';
			return -1;
		}
		return 1;
	}
	else
	{
		return -1;
	}
}
void add_wait_passenger(AirRoute* air)
{
	if (air->wait_total <=wait_person_max)
	{
		printf("请输入名字:\n");
		input_str(air->wait_ptr[air->wait_total].name);
		printf("请输入需要多少票:\n");
		scanf_s("%d", &(air->wait_ptr[air->wait_total].ticket_need));
		printf("操作成功!\n");
		air->wait_total++;
	}
	else
	{
		printf("候补已经出售完!\n");
	}
	system("pause");
	system("cls");
}
int refund(AirRoute* air,char*name)
{
	for (int i = 0; i < air->purchase_total; i++)
	{
		if (strcmp(name, air->ptr[i].name) == 0)
		{
			air->purchase_total--;
			if (air->ptr[i].degree == 1)
			{
				air->ticket_remain_1 += air->ptr[i].ticket_need;
			}
			else
			{
				air->ticket_remain_2 += air->ptr[i].ticket_need;
			}
			return i;
		}
	}
	return -1;
}
void fill(AirRoute* air, int i)
{
	for (int j = 0; j < air->wait_total; j++)
	{
		if (air->wait_ptr[j].ticket_need <= air->ticket_remain_2)
		{
			air->ptr[i].degree = 2;
			air->ptr[i].ticket_need = air->wait_ptr[j].ticket_need;
			for (int m = 0; m < 20; m++)
			{
				air->ptr[i].name[m] = air->wait_ptr[j].name[m];
			}
			air->ticket_remain_2+= air->wait_ptr[j].ticket_need;
			for (int n = j; n < air->wait_total; n++)
			{
				air->wait_ptr[n].ticket_need = air->wait_ptr[n + 1].ticket_need;
				for (int s = 0; s < 20; s++)
				{
					air->wait_ptr[n].name[s] = air->wait_ptr[n + 1].name[s];
				}
			}
			break;
		}
		else if (air->wait_ptr[j].ticket_need <= air->ticket_remain_1)
		{
			air->ptr[i].degree = 1;
			air->ptr[i].ticket_need = air->wait_ptr[j].ticket_need;
			for (int m = 0; m < 20; m++)
			{
				air->ptr[i].name[m] = air->wait_ptr[j].name[m];
			}
			air->ticket_remain_1 += air->wait_ptr[j].ticket_need;
			for (int n = j; n < air->wait_total; n++)
			{
				air->wait_ptr[n].ticket_need = air->wait_ptr[n + 1].ticket_need;
				for (int s = 0; s < 20; s++)
				{
					air->wait_ptr[n].name[s] = air->wait_ptr[n + 1].name[s];
				}
			}

		}
	}
	air->purchase_total++;
	system("pause");
	system("cls");
}
int search_person(AirRoute* air, char* name)
{
	for (int i = 0; i < air->purchase_total; i++)
	{
		if (strcmp(name, air->ptr[i].name) == 0)
		{
			return 1;
		}
	}
	return 0;
}