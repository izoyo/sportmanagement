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
			printf("\n\t\t\t\t\t汕头大学校运会管理系统\t\t    \n");
			printf("\n\t\t\t *************************************************** \n\n");
			printf("\n\t\t\t 1. 个人管理               \t 2. 运动会管理    \n");
			printf("\n\t\t\t 3. 运动员管理            \t 4. 参赛项目管理  \n");
			printf("\n\t\t\t 5. 参赛组织管理         \t 6. 成绩得分管理  \n");
			printf("\n\t\t\t 7. 生成秩序册		       \t 8. 通知栏管理     \n");
			printf("\n\t\t\t 9. 退出登录               \t 10.退出系统   \n\n");

			if (scanf("%d", &choice) == 1 && (choice <= 10 && choice >= 1))
				break;
			else
				printf("\t\t\t 您的输入有误，请重新输入");
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