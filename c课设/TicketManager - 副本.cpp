#include<stdio.h>
#include<string.h>
#include"TicketManager.h"
int main()
{
	printf("要管理几条航线?\n");
	int n_max=0;
	scanf_s("%d", &n_max);
	AirRoute* ap = (AirRoute*)malloc(n_max * sizeof(AirRoute));
	system("cls");
	int choice = 0;
	while (1)
	{
		showmenu();
		printf("\n");
		printf("请输入数字:\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:	//录入航线
		{
			int n = 0;
			printf("要录入第几条航线的信息?\n");
			scanf_s("%d", &n);
			if (n <= n_max)
			{
				add_route(&ap[n-1]);
			}
			else
			{
				printf("The air route is not found!\n");
				system("pause");
				system("cls");
			}
			break;
		}
		case 2:	//查询航线
		{
			int n = 0;
			printf("要显示第几条航线的信息?\n");
			scanf_s("%d", &n);
			if (n <= n_max)
			{
				show_route(&ap[n - 1]);
			}
			else
			{
				printf("The airroute is not found!\n");
				system("pause");
				system("cls");
			}
			break;
		}
		case 3:	//订票
		{
			char user_destination[20];
			printf("请输入目的地:\n");
			input_str(user_destination);
			int n = search_route(user_destination, ap, n_max);
			if (n != -1)
			{
				int ret=purchase(&ap[n]);
				if (ret==1)
				{
					printf("购票成功!\n");
					system("pause");
					system("cls");
				}
				else
				{
					char choice;
					printf("购票失败!\n");
					printf("您是否需要候补\n(Y or N)?\n");
					int temp=getchar();
					scanf_s("%c", &choice,1);
					if (choice =='Y')
					{
						add_wait_passenger(&ap[n]);
					}
					else
					{
						system("pause");
						system("cls");
					}
				}
			}
			else
			{
				printf("Your destination is unaccessible\n");
				system("pause");
				system("cls");
			}
			break;
		}
		case 4:	//退票
		{
			char user_destination[20];
			printf("请输入目的地:\n");
			input_str(user_destination);
			int n = search_route(user_destination, ap, n_max);
			if (n != -1)
			{
				char name[20];
				printf("请输入您的名字:\n");
				input_str(name);
				int i=refund(&ap[n],name);
				if (i>=0)
				{
					printf("退票成功!\n");
					fill(&ap[n], i);
				}
				else
				{
					printf("Your name is not found!\n");
					system("pause");
					system("cls");
				}
			}
			else
			{
				printf("Your destination is unaccessible\n");
				system("pause");
				system("cls");
			}
			break;
		}
		case 5:	//修改航线信息
		{
			int n = 0;
			printf("要修改第几条航线的信息？\n");
			scanf_s("%d", &n);
			if (n <= n_max&& ap[n - 1].destination[19] == '\0')
			{
				add_route(&ap[n - 1]);
			}
			else
			{
				printf("The air route is not found!\n");
				system("pause");
				system("cls");
			}
			break;
		}
		case 6:	//删除航线
		{
			int n =0 ;
			printf("请输入要删除第几条航线:\n");
			scanf_s("%d", &n);
			if(ap[n-1].destination[19]=='\0')
			{
				free_manager(&ap[n - 1]);
				printf("删除成功!\n");
			}
			else
			{
				printf("The airroute is not found!\n");
			}
			system("pause");
			system("cls");
			break;
		}
		case 7:	//退出
			exit(1);
		case 8:
		{
			char user_destination[20];
			printf("请输入目的地:\n");
			input_str(user_destination);
			int n = search_route(user_destination, ap, n_max);
			if (n != -1)
			{
				char name[20];
				printf("请输入您的名字:\n");
				input_str(name);
				int i = search_person(&ap[n], name);
				if (i == 1)
				{
					printf("您在乘客名单中!\n");
					system("pause");
					system("cls");
				}
				else
				{
					printf("您不在乘客名单中!\n");
					system("pause");
					system("cls");
				}
			}
			else
			{
				printf("Your destination is unaccessible\n");
				system("pause");
				system("cls");
			}
			break;
		}
		default:
			printf("error!");
			break;
		}
	}
	return 0;
}
