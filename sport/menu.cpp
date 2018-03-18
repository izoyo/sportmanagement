#include "stdafx.h";

int toLoginMenu(int type)//1 ����Ա 2 �û�
{
	int length = 0;

	long int id;
	char password[20];

	clearScreen(100);
	while (1)
	{
		printf("\n �˺ţ�");
		scanf("%ld", &id);
		printf("\n ���룺");
		length = inputPasswd(password);
		printf("\n\n �������id�� %ld \n", id);
		printf("\n �������passw�� %s \n\n", password);

		if (login(id, password, type))
		{
			printf("\n ��¼�ɹ� \n");
			printf("\n ���Ժ�ҳ��������ת�� ......");
			if (type == 1) return adminMenu();
			else if (type == 2) return userMenu();
		}
		else
		{
			int choice;
			printf("\n �˺Ż��������\n");
			printf("\n 1. �������� \n");
			printf("\n 2. ������һ�� \n");
			printf("\n 3. �˳�ϵͳ����1, 2����ļ��� \n\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				printf("\n ���Ժ�ҳ��������ת�� ......");
				clearScreen(2000);
			}
			else if (choice == 2)
			{

				printf("\n ���Ժ�ҳ��������ת�� ......");
				clearScreen(1000);
				return -1;
			}
			else
			{
				printf("\n ���Ժ������˳�ϵͳ ...... \n ");
				return 0;
			}
		}
	}

}





void welcome()
{
	printf("\n\n\n\n\n");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t    �� ͷ �� ѧ У �� �� �� �� ϵ ͳ\n");
	printf("\n\n\n\n\n");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t      �밴�س�������");
	getchar();
}

int loginMenu()
{
	int type;
	int isRetLast;
	int  signupSuccess;
	//while (!scanf("%d", &type) == 1 || !(type <= 3 && type >= 1))

	do
	{
		isRetLast = 0;
		while (1)
		{
			clearScreen(400);
			printf("\n\t 1.  ��¼ \n");
			printf("\n\t 2.  ע�� \n");
			printf("\n\t 3.  �鿴����� \n");
			printf("\n\t 4.  �鿴�÷� \n");
			printf("\n\t 5.  �˳�ϵͳ\n\n");

			if (scanf("%d", &type) == 1 && (type <= 5 && type >= 1))
				break;
			else
				printf("\t ����������������������");

		}
		switch (type)
		{
			case 1:
				isRetLast = toLoginMenu(1);
				break;
			case 2:
				signupSuccess = toSignupMenu();
				isRetLast = signupSuccess;
				break;
			case 3:

				break;
			case 4:

				break;
			default:
				printf("\n  ���Ժ������˳�ϵͳ ...... \n\n  ");
				return 0;
		}


	} while (isRetLast);
	printf("\n  ���Ժ������˳�ϵͳ ...... \n\n  ");
	return 0;
}

void mainMenu()
{
	welcome();
	loginMenu();

}