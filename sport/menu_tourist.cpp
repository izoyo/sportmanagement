#include "stdafx.h";

int touristMenu()
{
	int choice;
	while (1)
	{

		while (1)
		{
			clearScreen(500);
			printf("\t\t\t *************************************************** \n");
			printf("\n\t\t\t\t\t��ͷ��ѧУ�˻����ϵͳ\t\t    \n");
			printf("\n\t\t\t *************************************************** \n\n");

			printf("\n\t\t\t 1. �鿴�˶���          \t 2. �鿴Ժϵ�÷�\n");
			printf("\n\t\t\t 3. �鿴֪ͨ��          \t 4. ���ص�¼����\n");
			printf("\n\t\t\t 5. �˳�ϵͳ \n\n");

			if (scanf("%d", &choice) == 1 && (choice <= 5 && choice >= 1))
				break;
			else
				printf("\t\t         ����������������������");
		}
		switch (choice)
		{

			case 1:
			case 2:
			case 3:
				break;
			case 4:
				return -1;
			default:
				return 0;
		}
	}
}