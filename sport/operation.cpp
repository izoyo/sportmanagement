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
		if (ch != 8)//���ǻس���¼��
		{
			password[length] = ch;
			putchar('*');//�������*��
			length++;
		}
		else
		{
			putchar('\b');//������ɾ��һ��������ͨ������س��� /b���س�һ��
			putchar(' ');//����ʾ�ո���Ѹղŵ�*����ס��
			putchar('\b');//Ȼ���� �س�һ��ȴ�¼�롣
			length--;
		}
	}
	password[length] = '\0';
	return length;
}

int login(long id, char password[], int type)
{
	
	
	
	
	return 1; //��ʾ��¼�ɹ�
	//return 0; //��ʾ�˻���������󣬵�¼ʧ��
}

int signup(PerInfo  msg)
{
	int retValue = Person_create(msg);
	if (retValue == 0)
	{
		printf("ע��ɹ�");
		return 0;
	}
	else
	{
		if (retValue == 1)
		{
			printf("���֣��Ƿ��ַ���");
		}
		else if (retValue == 2)
		{
			printf("ID���Ƿ�ID");
		}
		else if (retValue == 3)
		{
			printf("�Ա𣺷Ƿ�����");
		}
		else if (retValue == 4)
		{
			printf("Ժ���Ƿ��ַ���");
		}
		else if (retValue == 5)
		{
			printf("ϵ���Ƿ��ַ���");
		}
		else if (retValue == 6)
		{
			printf("���룺�Ƿ��ַ���");
		}
		else if (retValue == 7)
		{
			printf("���󣺸��˺��Ѵ���");
		}
		else
		{
			printf("����ֵ����");
		}
		printf("ע��ʧ��");
		return -1;
	}
}

