#include "stdafx.h";

int userMenu()
{
	int choice;
	while (1)
	{

		while (1)
		{
			clearScreen(1000);
			printf("\t\t\t *************************************************** \n");
			printf("\n\t\t\t\t\t��ͷ��ѧУ�˻����ϵͳ\t\t    \n");
			printf("\n\t\t\t *************************************************** \n\n");
			printf("\n\t\t\t 1. ���˹���              \t 2. �鿴�˶��� \n");
			printf("\n\t\t\t 3. �����˶���           \t 4. �鿴֪ͨ��     \n");
			printf("\n\t\t\t 5. �鿴�ҵ���Ŀ        \t 6. �鿴�˶���Ŀ \n");
			printf("\n\t\t\t 7. �˳���¼              \t 8. �˳�ϵͳ        \n\n");


			if (scanf("%d", &choice) == 1 && (choice <= 8 && choice >= 1))
				break;
			else
				printf("\t\t\t ����������������������");
		}
		switch (choice)
		{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				break;
			case 7:
				return -1;
			default:
				return 0;
		}
	}
}
int toSignupMenu()//ע��˵�
{
	//PerInfo perInfo;
	char name[20];
	long int id;
	int gender;
	char org[20];
	char faculty[20];
	char passwd[20];

	int choice;
	int isReset;
	int isSuccess;

	while (1)
	{
		isSuccess = 0;
		isReset = 0;
		printf("\n ���Ժ�ҳ��������ת�� ......");
		clearScreen(500);
		printf("\n\tע����� \n");
		while (1)
		{
			printf("\n\t������ѧ�ţ�ID����");
			scanf("%ld", &id);
			if (1) //���
			{
				printf("\n\t�������ѧ�ţ�ID������\n");
				choice = signupErrorMenu();
				if (choice == 1)
					continue;
				else if (choice == 2)
				{
					isReset = 1;
					break;
				}
				else return -1;
			}
			else
				break;
		}
		if (isReset)
		{
			fflush(stdin);
			continue;
		}

		while (1)
		{
			printf("\n\t������������Name����");
			scanf("%s", name);
			if (1) //���
			{
				printf("\n\t�������������Name������\n");
				choice = signupErrorMenu();
				if (choice == 1)
					continue;
				else if (choice == 2)
				{
					isReset = 1;
					break;
				}
				else return -1;
			}
			else
				break;
		}
		if (isReset)
		{
			fflush(stdin);
			continue;
		}

		while (1)
		{
			printf("\n\t�������Ա�Gender��0 -- �У�1 -- Ů����");
			scanf("%d", &gender);
			if (1) //���
			{
				printf("\n\t��������Ա�Gender��0 -- �У�1 -- Ů������\n");
				choice = signupErrorMenu();
				if (choice == 1)
					continue;
				else if (choice == 2)
				{
					isReset = 1;
					break;
				}
				else return -1;
			}
			else
				break;
		}
		if (isReset)
		{
			fflush(stdin);
			continue;
		}

		while (1)
		{
			printf("\n\t����������Ժ��Organization����");
			scanf("%s", org);
			if (1) //���
			{
				printf("\n\t�����������Ժ��Organization������\n");
				choice = signupErrorMenu();
				if (choice == 1)
					continue;
				else if (choice == 2)
				{
					isReset = 1;
					break;
				}
				else return -1;
			}
			else
				break;
		}
		if (isReset)
		{
			fflush(stdin);
			continue;
		}

		while (1)
		{
			printf("\n\t����������ϵ��Faculty����");
			scanf("%s", faculty);
			if (1) //���
			{
				printf("\n\t�����������ϵ��Faculty������\n");
				choice = signupErrorMenu();
				if (choice == 1)
					continue;
				else if (choice == 2)
				{
					isReset = 1;
					break;
				}
				else return -1;
			}
			else
				break;
		}
		if (isReset)
		{
			fflush(stdin);
			continue;
		}

		while (1)
		{
			printf("\n\t���������루Password����");
			scanf("%s", passwd);
			if (1) //���
			{
				printf("\n\t����������루Password������\n");
				choice = signupErrorMenu();
				if (choice == 1)
					continue;
				else if (choice == 2)
				{
					isReset = 1;
					break;
				}
				else return -1;
			}
			else
			{
				break;
				isSuccess = 1;
			}
		}
		if (isReset)
		{
			fflush(stdin);
			continue;
		}

		if (isSuccess)
		{
			fflush(stdin);
			break;
		}
	}
	PerInfo perInfo = {
		name[20],
		id,
		gender,
		org[20],
		faculty[20],
		passwd[20]
	};
	printf("\n\t ע��ɹ�\n");
	return 0;
}
int signupErrorMenu()//ע�����
{
	int choice;
	while (1)
	{
		printf("\n\t1. �������������Ϣ\n");
		printf("\n\t2. ��������������Ϣ\n");
		printf("\n\t3. �˳�ע��\n");
		if (scanf("%d", &choice) == 1 && (choice <= 3 && choice >= 1))
			break;
		else
			printf("\n\t\t ����������������������");
	}
	return  choice;
}