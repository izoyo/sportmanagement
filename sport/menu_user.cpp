#include "stdafx.h";

//�޸�����
//����0���ɹ�������1��ʧ��
int changePwd(long id)
{
	PerInfo msg;
	char nowPwd[20]; 
	char inputPwd[20];
	char passwd[20];
	char repeatPwd[20];
	msg.id = id;

		strcpy(nowPwd, Person_getinfo(id).password);
		int wrong = 0;
		while (wrong < 3)
		{
			clearScreen(100);
			printf("\n\t���������ĵ�ǰ����\n");
			inputPasswd(inputPwd);
			if (!strcmp(nowPwd, inputPwd))
				break;
			else
			{
				wrong++;
				printf("\n\t�����������������\n");
				Sleep(1000);
				continue;
			}
		}
		if (wrong == 3)
		{
			printf("\n    �����������3�Σ����ڷ�����һ��......");
			Sleep(1500);
			return -1;
		}
		while (1)
		{
			printf("\n\t����������������\n");
			inputPasswd(passwd);
			printf("\n\t���ٴ���������������\n");
			inputPasswd(repeatPwd);
			if (!strcmp(passwd, repeatPwd))
			{
				if (!strcmp(passwd, nowPwd))
					printf("\n\t�벻Ҫ������ͬ������\n");
				else
				{
					puts("\n\t�޸ĳɹ�������������......");
					Sleep(500);
					break;
				}
					
			}
			else
				printf("\n\t��������������벻һ��\n");

		}
		
	
	strcpy(msg.password, passwd);
	int i = Person_change(msg, 6);
	return i;
}

//�޸ĸ�����Ϣ
//����0���ɹ�������1��ʧ��
int changeInfo(long id, int type)
{
	PerInfo msg;
	msg.id = id;
	if (type == 1)
	{
		char name[20];
		puts("\n\t���������֣�");
		scanf("%s", name);
		strcpy(msg.name, name);
	}
	else if (type == 3)
	{
		int gender;
		puts("\n\t�������Ա�(0���У�1��Ů����");
		scanf("%d", &gender);
		msg.gender = gender;
	}
	else if (type == 4)
	{
		char org[20];
		puts("\n\t��������֯��");
		scanf("%s", org);
		strcpy(msg.organization, org);
	}
	else if (type == 5)
	{
		char faculty[20];
		puts("\n\t������ϵ��");
		scanf("%s", faculty);
		strcpy(msg.faculty, faculty);
	}
	if (!Person_change(msg, type))
	{
		puts("\n�޸ĳɹ�");
		return 0;
	}
	else
	{
		puts("\n�޸�ʧ��");
		return 1;
	}
}


//�ú�����ʾ�û��ѱ�������Ŀ
//�����ѱ�������Ŀ��    type��0������ӡ��1����ӡ
int userSignupedEve(long id, int type)
{
	if (sys_info.eve == 0)
	{
		printf("\n\tû�б�����Ŀ\n");
		return 0;
	}
	int count = 0;
	SportsEvent* evo = (SportsEvent *)malloc((sys_info.eve)*sizeof(SportsEvent));
	Event_getlist(evo);

	for (int o = 0; o < sys_info.eve; o++)
	{
		for (int p = 0; p < evo[o].maxpeople; p++)
		{
			if (evo[o].prePerson[p].id == id)
			{
				count++;
				if (type)
				{
					printf("\n\n[��Ŀ%d] ID:%ld  ", count, evo[o].id);
					if (evo[o].type / 10 == 1)
						printf("���� ");
					else
						printf("Ů�� ");
					printf("%s ",evo[o].name);
					if (evo[o].type % 2)
						printf("���� ");
					else
						printf("���� ");
					printf("%s (ʱ��:%d����)  Ԥ������:%d�� ", evo[o].place, evo[o].timecost, evo[o].maxpeople);
					//printf("%d", evo[o].time);
					//evo[o].time = 1521421395;
					if (evo[o].time == 0)
						printf(" ����ʱ��δ��");
					else
					{
						time_t  tt = (time_t)evo[o].time;   //�ٶ�ʱ��
						char now[64];
						struct tm *ttime;
						ttime = localtime(&tt);
						strftime(now, 64, "%Y%m%d %H:%M:%S", ttime);
						printf(" %d��%d��%d��  %02d:%02d ", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min);
						}

					if (evo[o].type % 2) //����
					{

						char sc[20] = "";
						//printf(" [����:%d] ", evo[o].prePerson[p].score);
						scoreToChar(evo[o].prePerson[p].score, sc);
						printf(" �ɼ�:%s ", sc);
					}
					else
					{
						if (evo[o].prePerson[p].score > 1000)
							printf(" �ɼ�:%dm ", evo[o].prePerson[p].score / 1000);

						printf(" �ɼ�:%dcm ", evo[o].prePerson[p].score % 1000);
					}
					qsort(evo[o].prePerson, 100, sizeof(Participant), cmp);
					int rank = 0;
					if (evo[o].type % 2)   //����
					{

						for (int i = 0; i < 100; i++)
						{
							if (evo[o].prePerson[i].score == 0)
								continue;
							else
							{
								rank++;
								if (evo[o].prePerson[i].id == id)
									break;
							}
						}
						if (rank == 0)
							printf(" ��������");
						else
							printf(" ��%d��\n", rank);
					}
					else
					{

						for (int i = 100; i > 0; i--)
						{
							if (evo[o].prePerson[i].score == 0)
								continue;
							else
							{

								rank++;
								if (evo[o].prePerson[i].id == id)
									break;
							}
						}
						if (rank == 0)
							printf(" ��������");
						else
							printf(" ��%d��\n", rank);
					}


					if (evo[o].hasFinals)
					{

						printf("\n\t�о��� (ʱ��:%d����) ��������:%d��", evo[o].timecost, evo[o].finNum);

						for (int p = 0; p < evo[o].finNum; p++)
						{
							if (evo[o].finPerson[p].id == id)
							{
								if (type)
								{
									//evo[o].etime = 1521421395;
									if (evo[o].etime == 0)
										printf(" ����ʱ��δ��");
									else
									{
										time_t  tt = (time_t)evo[o].etime;   //�ٶ�ʱ��
										char now[64];
										struct tm *ttime;
										ttime = localtime(&tt);
										strftime(now, 64, "%Y%m%d %H:%M:%S", ttime);
										printf(" %d��%d��%d��  %02d:%02d ", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min);

									}
									if (evo[o].type % 2) //����
									{
										char sc[20]="";
										scoreToChar(evo[o].finPerson[p].score, sc);
										printf(" �ɼ�:%s ", sc);
									}
									else
									{
										if (evo[o].finPerson[p].score > 1000)
											printf(" �ɼ�:%dm ", evo[o].finPerson[p].score / 1000);

										printf(" �ɼ�:%dcm ", evo[o].finPerson[p].score % 1000);
									}
									qsort(evo[o].finPerson, 20, sizeof(Participant), cmp);
									int finRank = 0;
									if (evo[o].type % 2)   //����
									{

										for (int i = 0; i < 20; i++)
										{
											if (evo[o].finPerson[i].score == 0)
												continue;
											else
											{
												finRank++;
												if (evo[o].finPerson[i].id == id)
													break;
											}
										}
										if (finRank == 0)
											printf("�������� ");
										else
											printf("��%d��\n", finRank);
									}
									else
									{
										for (int i = 20, rank = 0; i > 0; i--)
										{
											if (evo[o].finPerson[i].score == 0)
												continue;
											else
											{
												rank++;
												if (evo[o].finPerson[i].id == id)
													break;
											}
										}
										if (finRank == 0)
											printf("�������� ");
										else
											printf("��%d��\n", finRank);
									}
								}
							}
						}

					}
					else
						printf(" �޾���\n");
				}
				break;
			}
			else
				continue;

		}
	}

	free(evo);
	
	fflush(stdin);
	if (type)
	{
		if (count == 0)
			printf("\n  �����ѱ������˶���Ŀ\n");
		else
		{
			int ch;
			printf("\n  �Ƿ�ȡ��������Ŀ\n\n  1. �� 2. ��(���������1����ļ�)  ");
			scanf("%d", &ch);
			if (ch == 1)
			{
				int eveid;
				printf("\n ������Ҫȡ����������ĿID  ");
				if (scanf("%ld", &eveid))
				{
					if (Event_dec(eveid, id, 0) == 0)
					{
						printf("\n  ȡ�������ɹ�\n");
						Sleep(1000);
						return 1;
					}
					else
					{
						printf("\n  ȡ������ʧ�ܣ���������������");
						Sleep(1000);
					}
				}
				else
				{
					printf("\n  �������");
					Sleep(1000);
				}


			}

		}
		fflush(stdin);
		printf("\n  ���س���������һ��");
		getchar();
	}

	return count;
}

//�ú������ڱ�����Ŀ��Ԥ����
//����0���ɹ�������1��ʧ��
int signupSports(long  peoid)
{
	if (sys_info.eve == 0)
	{
		printf("\n\tû�б�����Ŀ������ʧ��\n");
		Sleep(1000);
		return 1;
	}
	if (sys_info.canjoin == 0)
	{
		printf("\n\tĿǰ���Ǳ���ʱ�䣬����ʧ��\n");
		Sleep(1000);
		return 1;
	}
	int count = 0;
	SportsEvent* evo = (SportsEvent *)malloc((sys_info.eve)*sizeof(SportsEvent));
	Event_getlist(evo);
	for (int o = 0; o < sys_info.eve; o++)
	{
		printf("\n[��Ŀ%d]   ", o);
		printf("ID:%ld ", evo[o].id);
		if (evo[o].type / 10 == 1)
			printf("���� ");
		else
			printf("Ů�� ");
		if (evo[o].type % 2)
			printf("���� ");
		else
			printf("���� ");
		printf("%s (ʱ��:%d����) Ԥ������:%d�� -", evo[o].place, evo[o].timecost, evo[o].maxpeople);
		//evo[o].time = 1521421395;
		if (evo[o].time == 0)
			printf(" ����ʱ��δ��");
		else
		{
			time_t  tt = (time_t)evo[o].time;   //�ٶ�ʱ��
			char now[64];
			struct tm *ttime;
			ttime = localtime(&tt);
			strftime(now, 64, "%Y-%m-%d %H:%M:%S", ttime);
			printf(" %d��%d��%d��  %02d:%02d", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min);
		}

		if (evo[o].hasFinals)
			printf(" �о���\n");
		else
			printf(" �޾���\n");
	}
	free(evo);

	long eveid;
	count = userSignupedEve(peoid, 0);

	if (count >= 3)
	{
		printf("\n  ����������Ŀ���������������\n");
		Sleep(1000);
		return 1;
	}

	printf("\n  ���������뱨������Ŀ��ID : ");
	scanf("%ld", &eveid);
	if (Event_had(eveid))
	{
		if (Event_getinfo(eveid).type / 20 != Person_getinfo(peoid).gender)
		{
			printf("\n  ����������Ŀ�����Ա����\n");
			Sleep(1000);
			printf("\n  ������ת��������һ��.......");
			return 1;
		}
		/*printf("��������ֵΪ:%d", Event_inc(eveid, peoid, 0));*/
		if (Event_inc(eveid, peoid, 0) == 3)
		{
			printf("\n  ��Ҫ�ظ���������Ŀ\n");
			Sleep(1000);
			return 1;
		}

		printf("\n ���������ɹ�\n");
		fflush(stdin);
		printf("\n  ���س���������һ��");
		getchar();
		return 0;
	}
	else
		printf("\n  �����ڴ���Ŀ\n");

	fflush(stdin);
	printf("\n  ���س���������һ��");
	getchar();
	return 1;

}


//�ú�����ʾ�û�׼��ע�����
//����0���ɹ���1��ʧ��
int toSignupMenu()
{
	int choice;

	PerInfo perInfo;

	printf("\n ���Ժ�ҳ��������ת�� ......");
	while (1)
	{

		clearScreen(500);
		printf("\n\tע����� \n");

		printf("\n\t������ѧ�ţ�ID����");
		scanf("%ld", &perInfo.id);

		printf("\n\t������������Name����");
		scanf("%s", perInfo.name);

		printf("\n\t�������Ա�Gender��0 -- �У�1 -- Ů����");
		scanf("%d", &perInfo.gender);

		printf("\n\t����������Ժ��Organization����");
		scanf("%s", perInfo.organization);

		printf("\n\t����������ϵ��Faculty����");
		scanf("%s", perInfo.faculty);

		printf("\n\t���������루Password����");
		inputPasswd(perInfo.password);

		if (!signup(perInfo)) break;
		else
		{

			while (1)
			{
				printf("\n\t1. ��������\n");
				printf("\n\t2. �˳�ע��\n");
				if (scanf("%d", &choice) == 1 && (choice <= 2 && choice >= 1))
					break;
				else
					printf("\n\t\t ����������������������");
			}
			if (choice == 1)
				continue;
			else
			{
				printf("\n\tע��ʧ��");
				return 1;
			}

		}
	}

	return 0;
}
//�ú�����ʾ�û���¼��Ĳ˵�
int userMenu(long id)
{
	int choice;
	while (1)
	{

		while (1)
		{
			clearScreen(500);
			Notice * not = (Notice *)malloc((sys_info.not)*sizeof(Notice));
			int i = 0;
			if (!Person_getnotice(id, not))
			{
				if (!(not[i].time > 0)) printf("[���޸���֪ͨ]\n");
				else printf("[����֪ͨ]\n\n");
				while (not[i].time > 0)
				{
					
					printf("[֪ͨ%d] ", i + 1);
					time_t  tt = (time_t)not[i].time;   //�ٶ�ʱ��
					char now[64];
					struct tm *ttime;
					ttime = localtime(&tt);
					strftime(now, 64, "%Y-%m-%d %H:%M:%S", ttime);
					printf(" ֪ͨʱ�䣺%d��%d��%d��  %02d:%02d  ", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min);

					printf(" ֪ͨ��Ϣ��%s\n", not[i].msg);
					puts("");
					i++;
				}
			}
			
				
			free(not);
			printf("\n\t\t\t *************************************************** \n");
			printf("\n\t\t\t\t\t��ͷ��ѧУ�˻����ϵͳ\t\t    \n");
			printf("\n\t\t\t *************************************************** \n\n");
			printf("\n\t\t\t 1. �޸�����		\t 2. �޸���Ϣ \n");
			printf("\n\t\t\t 3. �����ѱ�����Ŀ	\t 4. �����˶��� \n");
			printf("\n\t\t\t 5. �˳���¼		\t 6. �˳�ϵͳ  \n\n");


			if (scanf("%d", &choice) == 1 && (choice <= 6 && choice >= 1))
				break;
			else
				printf("\t\t\t ����������������������");
		}
		switch (choice)
		{
			case 1:
				changePwd(id);
				break;
			case 2:
				while (1)
				{
					clearScreen(100);
					PerInfo per = Person_getinfo(id);
					printf("\n\t\t\t  ������%s", per.name);
					if (per.gender) printf(" �Ա�Ů");
					else printf(" �Ա���");
					printf(" ��Ժ��%s   ϵ��%s\n", per.organization, per.faculty);
					printf("\n\t\t\t *************************************************** \n");
					printf("\n\t\t\t\t\t��ͷ��ѧУ�˻����ϵͳ\t\t    \n");
					printf("\n\t\t\t *************************************************** \n\n");
					printf("\n\t\t\t 1. �޸�����		\t 2. �޸��Ա� \n");
					printf("\n\t\t\t 3. �޸���Ժ		\t 4. �޸�ϵ \n");
					printf("\n\t\t\t 5. ������һ��\n\n");


					if (scanf("%d", &choice) == 1 && (choice <= 5 && choice >= 1))
						break;
					else
						printf("\t\t\t ����������������������");
				}
				switch (choice)
				{
					case 1:
						changeInfo(id, 1);
						break;
					case 2:
						changeInfo(id, 3);
						break;
					case 3:
						changeInfo(id, 4);
						break;
					case 4:
						changeInfo(id, 5);
					default:
						continue;
				}
				fflush(stdin);
				puts("\n\n���س���������һ��");
				getchar();
				break;
			case 3:
				userSignupedEve(id, 1);
				break;
			case 4:
				signupSports(id);
				break;
			case 5:
				return -1;
			default:
				return 0;
		}
	}
	return 0;
}



