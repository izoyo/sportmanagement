#include "stdafx.h";

int adminMenu()
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
			printf("\n\t\t\t 1. ���˹���               \t 2. �˶������    \n");
			printf("\n\t\t\t 3. �˶�Ա����            \t 4. ������Ŀ����  \n");
			printf("\n\t\t\t 5. ������֯����         \t 6. �ɼ��÷ֹ���  \n");
			printf("\n\t\t\t 7. ���������		       \t 8. ֪ͨ������     \n");
			printf("\n\t\t\t 9. �˳���¼               \t 10.�˳�ϵͳ   \n\n");

			if (scanf("%d", &choice) == 1 && (choice <= 10 && choice >= 1))
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
			case 7:
			case 8:
				break;
			case 9:
				return -1;
			default:
				return 0;
		}
	}
}