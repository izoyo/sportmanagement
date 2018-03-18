// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "targetver.h"
#include "conio.h"

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

typedef struct SysInfo{
	int peo;//����
	int eve;//��Ŀ��
	int not;//֪ͨ��
	char password[20];
	int canjoin;//�Ƿ񿪷ű���
	int numyuan;//Ժ��
	int numxi;//ϵ��
	char yuan[20][20];//20��Ժ����
	char xi[20][20];//20��ϵ����
}SysInfo;//ϵͳ��Ϣ

typedef struct PerInfo{
	char name[20];
	long id;
	int gender;//�Ա� 0�� 1Ů
	char organization[20];//ѧԺ��Ժ
	char faculty[20];//ϵ
	char password[20];//����
}PerInfo;//�˶�Ա������Ϣ

typedef struct Notice{
	long id;
	char msg[300];
	long time;
}Notice;//֪ͨ

typedef struct Participant{
	long id;
	long score;
}Participant;//��������Ϣ

typedef struct SportsEvent{
	char name[20];
	long id;//���
	int type;//0�1��
	char place[20];//����
	int timecost;//��ʱ������
	int maxpeople;//��������
	int hasFinals;//���޾��� 0�� 1��
	int finNum;//�о���ʱ��������
	long time;//����ʱ�������
	Participant prePerson[100] ;//Ԥ���������100
	Participant finPerson[20] ;//�����������20
}SportsEvent;//������Ŀ��Ϣ

//����
extern void clearScreen(int sleepS);
extern int inputPasswd(char * password);
extern int login(long id, char password[], int type);
extern int signup(PerInfo  msg);

//�˵�
extern int adminMenu();
extern int userMenu(long id);
extern int touristMenu();
extern int signupErrorMenu();
extern int toSignupMenu();
extern int toLoginMenu(int type);
extern void welcome();
extern int loginMenu();
extern void mainMenu();

//�ӿ�
extern int Char_isok(char * msg);//����ַ��Ƿ����
extern int sys_dec(int type);//������Ŀ
extern int sys_inc(int type);//������Ŀ
extern int sys_init();//��ʼ��
extern PerInfo Person_getinfo(long id);			//��ȡ��Ϣ��֪ͨ��		
extern int Person_create(PerInfo msg);		//�����û�		
extern int Person_delete(long id);		//ɾ���û�			
extern int Person_had(long id);	//�Ƿ�����û�		
extern int Person_change(PerInfo msg, int id);	//�޸��û���Ϣ
extern int Person_getlist(PerInfo * evo);	//��ȡ�����û�
extern int Person_notice(long id, char * msg);		//֪ͨ�û�	
extern int Person_getnotice(long id, Notice * msn);	//��ʾ�����Ϣ��֪ͨ��					
extern void Person_list();		//��ȡ���г�Ա����		
extern void Person_mynotice();		//��ȡ��Ա֪ͨ����						
extern SportsEvent Event_getinfo(long id);	//��ѯ��Ŀ���˶�Ա��
extern int Event_create(SportsEvent msg);	//������Ŀ
extern int Event_delete(long id);	//ɾ����Ŀ
extern int Event_had(long id);	//�Ƿ������Ŀ����ID�飩
extern int Event_hadbyname(char * name);	//�Ƿ������Ŀ����name�飩
extern int Event_change(SportsEvent msg, int type);	//�޸���Ŀ
extern int Event_getlist(SportsEvent * evo);	//��ȡ������Ŀ
extern int Event_inc(long eveid, long period, int type);	//������Ŀ���˶�Ա����ĿID���û�ID����/����
extern int Event_dec(long eveid, long period, int type);	// ɾ����Ŀ���˶�Ա����ĿID���û�ID���� / ����
extern int Event_changescore(long eveid, long period, int type, long score);	//�޸���Ŀ���˶�Ա�ɼ� ����ĿID���û�ID����/�����ɼ���

//����
extern SysInfo sys_info;