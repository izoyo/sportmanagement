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
			printf("\n\t\t\t\t\t汕头大学校运会管理系统\t\t    \n");
			printf("\n\t\t\t *************************************************** \n\n");
			printf("\n\t\t\t 1. 个人管理              \t 2. 查看运动会 \n");
			printf("\n\t\t\t 3. 报名运动会           \t 4. 查看通知栏     \n");
			printf("\n\t\t\t 5. 查看我的项目        \t 6. 查看运动项目 \n");
			printf("\n\t\t\t 7. 退出登录              \t 8. 退出系统        \n\n");


			if (scanf("%d", &choice) == 1 && (choice <= 8 && choice >= 1))
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
				break;
			case 7:
				return -1;
			default:
				return 0;
		}
	}
}
int toSignupMenu()//注册菜单
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
		printf("\n 请稍候，页面正在跳转中 ......");
		clearScreen(500);
		printf("\n\t注册界面 \n");
		while (1)
		{
			printf("\n\t请输入学号（ID）：");
			scanf("%ld", &id);
			if (1) //检查
			{
				printf("\n\t您输入的学号（ID）有误\n");
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
			printf("\n\t请输入姓名（Name）：");
			scanf("%s", name);
			if (1) //检查
			{
				printf("\n\t您输入的姓名（Name）有误\n");
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
			printf("\n\t请输入性别（Gender：0 -- 男；1 -- 女）：");
			scanf("%d", &gender);
			if (1) //检查
			{
				printf("\n\t您输入的性别（Gender：0 -- 男；1 -- 女）有误\n");
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
			printf("\n\t请输入所在院（Organization）：");
			scanf("%s", org);
			if (1) //检查
			{
				printf("\n\t您输入的所在院（Organization）有误\n");
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
			printf("\n\t请输入所在系（Faculty）：");
			scanf("%s", faculty);
			if (1) //检查
			{
				printf("\n\t您输入的所在系（Faculty）有误\n");
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
			printf("\n\t请输入密码（Password）：");
			scanf("%s", passwd);
			if (1) //检查
			{
				printf("\n\t您输入的密码（Password）有误\n");
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
	printf("\n\t 注册成功\n");
	return 0;
}
int signupErrorMenu()//注册出错
{
	int choice;
	while (1)
	{
		printf("\n\t1. 重新输入该项信息\n");
		printf("\n\t2. 重新输入所有信息\n");
		printf("\n\t3. 退出注册\n");
		if (scanf("%d", &choice) == 1 && (choice <= 3 && choice >= 1))
			break;
		else
			printf("\n\t\t 您的输入有误，请重新输入");
	}
	return  choice;
}