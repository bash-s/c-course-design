#include<stdio.h>
#include<string.h>
#include"TicketManager.h"
int main()
{
	printf("Ҫ����������?\n");
	int n_max=0;
	scanf_s("%d", &n_max);
	AirRoute* ap = (AirRoute*)malloc(n_max * sizeof(AirRoute));
	system("cls");
	int choice = 0;
	while (1)
	{
		showmenu();
		printf("\n");
		printf("����������:\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:	//¼�뺽��
		{
			int n = 0;
			printf("Ҫ¼��ڼ������ߵ���Ϣ?\n");
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
		case 2:	//��ѯ����
		{
			int n = 0;
			printf("Ҫ��ʾ�ڼ������ߵ���Ϣ?\n");
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
		case 3:	//��Ʊ
		{
			char user_destination[20];
			printf("������Ŀ�ĵ�:\n");
			input_str(user_destination);
			int n = search_route(user_destination, ap, n_max);
			if (n != -1)
			{
				int ret=purchase(&ap[n]);
				if (ret==1)
				{
					printf("��Ʊ�ɹ�!\n");
					system("pause");
					system("cls");
				}
				else
				{
					char choice;
					printf("��Ʊʧ��!\n");
					printf("���Ƿ���Ҫ��\n(Y or N)?\n");
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
		case 4:	//��Ʊ
		{
			char user_destination[20];
			printf("������Ŀ�ĵ�:\n");
			input_str(user_destination);
			int n = search_route(user_destination, ap, n_max);
			if (n != -1)
			{
				char name[20];
				printf("��������������:\n");
				input_str(name);
				int i=refund(&ap[n],name);
				if (i>=0)
				{
					printf("��Ʊ�ɹ�!\n");
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
		case 5:	//�޸ĺ�����Ϣ
		{
			int n = 0;
			printf("Ҫ�޸ĵڼ������ߵ���Ϣ��\n");
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
		case 6:	//ɾ������
		{
			int n =0 ;
			printf("������Ҫɾ���ڼ�������:\n");
			scanf_s("%d", &n);
			if(ap[n-1].destination[19]=='\0')
			{
				free_manager(&ap[n - 1]);
				printf("ɾ���ɹ�!\n");
			}
			else
			{
				printf("The airroute is not found!\n");
			}
			system("pause");
			system("cls");
			break;
		}
		case 7:	//�˳�
			exit(1);
		case 8:
		{
			char user_destination[20];
			printf("������Ŀ�ĵ�:\n");
			input_str(user_destination);
			int n = search_route(user_destination, ap, n_max);
			if (n != -1)
			{
				char name[20];
				printf("��������������:\n");
				input_str(name);
				int i = search_person(&ap[n], name);
				if (i == 1)
				{
					printf("���ڳ˿�������!\n");
					system("pause");
					system("cls");
				}
				else
				{
					printf("�����ڳ˿�������!\n");
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
