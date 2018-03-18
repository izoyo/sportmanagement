#include "stdafx.h";

void clearScreen(int sleepS)
{
	fflush(stdin);
	Sleep(sleepS);
	system("cls");
}

int inputPasswd(char * password)
{
	char ch;
	int length = 0;
	while ((ch = getch()) != '\r')
	{
		if (ch != 8)//不是回撤就录入
		{
			password[length] = ch;
			putchar('*');//并且输出*号
			length++;
		}
		else
		{
			putchar('\b');//这里是删除一个，我们通过输出回撤符 /b，回撤一格，
			putchar(' ');//再显示空格符把刚才的*给盖住，
			putchar('\b');//然后再 回撤一格等待录入。
			length--;
		}
	}
	password[length] = '\0';
	return length;
}

int login(long id, char password[], int type)
{
	
	
	
	
	return 1; //表示登录成功
	//return 0; //表示账户或密码错误，登录失败
}

int signup(PerInfo  msg)
{
	int retValue = Person_create(msg);
	if (retValue == 0)
	{
		printf("注册成功");
		return 0;
	}
	else
	{
		if (retValue == 1)
		{
			printf("名字：非法字符串");
		}
		else if (retValue == 2)
		{
			printf("ID：非法ID");
		}
		else if (retValue == 3)
		{
			printf("性别：非法数字");
		}
		else if (retValue == 4)
		{
			printf("院：非法字符串");
		}
		else if (retValue == 5)
		{
			printf("系：非法字符串");
		}
		else if (retValue == 6)
		{
			printf("密码：非法字符串");
		}
		else if (retValue == 7)
		{
			printf("错误：该账号已存在");
		}
		else
		{
			printf("返回值错误");
		}
		printf("注册失败");
		return -1;
	}
}

