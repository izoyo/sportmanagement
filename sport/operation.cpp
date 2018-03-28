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
	while ((ch = _getch()) != '\r')
	{
		if (ch != 8)//���ǻس���¼��
		{
			password[length] = ch;
			putchar('*');//�������*��
			length++;
		}
		else
		{
			if(!length)continue;
			putchar('\b');//������ɾ��һ��������ͨ������س��� /b���س�һ��
			putchar(' ');//����ʾ�ո���Ѹղŵ�*����ס��
			putchar('\b');//Ȼ���� �س�һ��ȴ�¼�롣
			length--;
		}
	}
	password[length] = '\0';
	return length;
}

int login(long id, char* psw, int type)//0���� 1���� 2�û�
{
	if(id<10000)return 0;
	if(id==10000){
		if(strcmp(sys_info.password ,psw)==0){
			return 1;
		}else{
			return 0;
		}
	}else{
		PerInfo peo;
		peo=Person_getinfo(id);
		if(peo.id==0)return 0;
		if(strcmp(peo.password ,psw)==0){
			return 2;
		}else{
			return 0;
		}
	}
	return 0; //��ʾ��¼�ɹ�
	//return 0; //��ʾ�˻���������󣬵�¼ʧ��
}

int signup(PerInfo  msg)
{
	int retValue = Person_create(msg);
	if (retValue == 0)
	{
		printf("\n\tע��ɹ�");
		Sleep(500);
		return 0;
	}
	else
	{
		puts("");
		if (retValue == 1)
		{
			printf("\n\t���֣��Ƿ��ַ���\n");
		}
		else if (retValue == 2)
		{
			printf("\n\tID���Ƿ�ID\n");
		}
		else if (retValue == 3)
		{
			printf("\n\t�Ա𣺷Ƿ�����\n");
		}
		else if (retValue == 4)
		{
			printf("\n\tԺ���Ƿ��ַ���\n");
		}
		else if (retValue == 5)
		{
			printf("\n\tϵ���Ƿ��ַ���\n");
		}
		else if (retValue == 6)
		{
			printf("\n\t���룺�Ƿ��ַ���\n");
		}
		else if (retValue == 7)
		{
			printf("\n\t���󣺸��˺��Ѵ���\n");
		}
		else
		{
			printf("\n\t����ֵ����\n");
		}
		printf("\n\tע��ʧ��\n");
		Sleep(500);
		return -1;
	}
}

