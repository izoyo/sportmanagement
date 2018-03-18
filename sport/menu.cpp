#include "stdafx.h";

int toLoginMenu(int type)//1 管理员 2 用户
{
	int length = 0;

	long int id;
	char password[20];

	clearScreen(100);
	while (1)
	{
		printf("\n 账号：");
		scanf("%ld", &id);
		printf("\n 密码：");
		length = inputPasswd(password);
		printf("\n\n 你输入的id是 %ld \n", id);
		printf("\n 你输入的passw是 %s \n\n", password);

		if (login(id, password, type))
		{
			printf("\n 登录成功 \n");
			printf("\n 请稍候，页面正在跳转中 ......");
			if (type == 1) return adminMenu();
			else if (type == 2) return userMenu();
		}
		else
		{
			int choice;
			printf("\n 账号或密码错误\n");
			printf("\n 1. 重新输入 \n");
			printf("\n 2. 返回上一步 \n");
			printf("\n 3. 退出系统（除1, 2以外的键） \n\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				printf("\n 请稍候，页面正在跳转中 ......");
				clearScreen(2000);
			}
			else if (choice == 2)
			{

				printf("\n 请稍候，页面正在跳转中 ......");
				clearScreen(1000);
				return -1;
			}
			else
			{
				printf("\n 请稍候，正在退出系统 ...... \n ");
				return 0;
			}
		}
	}

}





void welcome()
{
	printf("\n\n\n\n\n");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t    汕 头 大 学 校 运 会 管 理 系 统\n");
	printf("\n\n\n\n\n");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t      请按回车键进入");
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
			printf("\n\t 1.  登录 \n");
			printf("\n\t 2.  注册 \n");
			printf("\n\t 3.  查看秩序册 \n");
			printf("\n\t 4.  查看得分 \n");
			printf("\n\t 5.  退出系统\n\n");

			if (scanf("%d", &type) == 1 && (type <= 5 && type >= 1))
				break;
			else
				printf("\t 您的输入有误，请重新输入");

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
				printf("\n  请稍候，正在退出系统 ...... \n\n  ");
				return 0;
		}


	} while (isRetLast);
	printf("\n  请稍候，正在退出系统 ...... \n\n  ");
	return 0;
}

void mainMenu()
{
	welcome();
	loginMenu();

}