#include "stdafx.h";

int changeEventProperty(long eve_id)
{
	SportsEvent eve;
	int choice;
	char name[20];
	int type;//10���11�о���20Ů�21Ů��
	char place[20];//����
	int timecost;//��ʱ������
	int maxpeople;//��������
	int hasFinals;//���޾��� 0�� 1��
	int finNum;//�о���ʱ��������
	long time;//����ʱ�������
	long etime;//����ʱ��
	int ppp;
	char* p;
	const char delim[2] = "-";//�ָ����ַ���
	eve.id = eve_id;
	while (1)
	{
		clearScreen(400);
		printf("\n\t��ѡ����Ҫ�޸ĵ�����\n");
		printf("\n\t 1.  �޸����� \n");
		printf("\n\t 2.  �޸���Ŀ���� \n");
		printf("\n\t 3.  �޸ĳ���\n");
		printf("\n\t 4.  �޸���ʱ\n");
		printf("\n\t 5.  �޸�Ԥ������ \n");
		printf("\n\t 6.  �޸�Ԥ��ʱ��\n");
		printf("\n\t 7.  ���޾���\n");
		printf("\n\t 8.  ������һ��\n\n");
		scanf("%d", &choice);
		if (choice <= 8 && choice >= 1)
			break;
		else
			printf("\t ����������������������\n");
	}
	int state;
	switch (choice)
	{
		case 1:
			printf("\t���޸Ĵ���Ŀ������\n");
			scanf("%s", &name);
			strcpy(eve.name, name);
			state = Event_change(eve, 1);
			if (state == 1)
				printf("�Ƿ�����");
			else if (state == 11)
				printf("�����ڴ���Ŀ");
			else printf("�޸ĳɹ�");
			break;
		case 2:
			printf("\t���������Ŀ���������������10����������11��Ů����������20����������21��\n");
			scanf("%d", &type);
			eve.type = type;
			state = Event_change(eve, 3);
			printf("stateֵΪ%d", state);
			if (state == 3)
				printf("�Ƿ�����");
			else if (state == 11)
				printf("�����ڴ���Ŀ");
			else
				printf("�޸ĳɹ�");
			break;
		case 3:
			printf("\t���޸Ĵ���Ŀ�ĳ���\n");
			scanf("%s", &place);
			strcpy(eve.place, place);
			state = Event_change(eve, 4);
			printf("stateֵΪ%d", state);
			if (state == 4)
				printf("�Ƿ�����");
			else if (state == 11)
				printf("�����ڴ���Ŀ");
			else
				printf("�޸ĳɹ�");
			break;
		case 4:
			printf("\t���޸Ĵ���Ŀ����ʱ\n");
			scanf("%d", &timecost);
			eve.timecost = timecost;
			state = Event_change(eve, 5);
			if (state == 5)
				printf("�Ƿ�����");
			else if (state == 11)
				printf("�����ڴ���Ŀ");
			else
				printf("�޸ĳɹ�");
			break;
		case 5:
			printf("\t���޸Ĵ���Ŀ��Ԥ������\n");
			scanf("%d", &maxpeople);
			eve.maxpeople = maxpeople;
			state = Event_change(eve, 6);
			if (state == 6)
				printf("�Ƿ�����");
			else if (state == 11)
				printf("�����ڴ���Ŀ");
			else
				printf("�޸ĳɹ�");
			break;
		case 6:
			char strtime[50];
			printf("\t���޸�Ԥ����ʱ�䣨2010-01-01-10-00��\n");
			scanf("%s", strtime);
			struct tm p_stm;
			p = strtok(strtime, delim);//��һ�ε���strtok
			char pp[5][20];
			ppp = 0;
			char str[20];
			int year;
			int mon;
			int day;
			int hour;
			int min;
			strcpy(pp[ppp++], p);
			while (p != NULL)
			{//������ֵ��ΪNULLʱ������ѭ��
				//printf("%s\n", p);//����ֽ���ַ���
				p = strtok(NULL, delim);//��������strtok���ֽ�ʣ�µ��ַ���
				strcpy(pp[ppp++], p);
				if (ppp >= 5)break;
			}
			if (ppp == 5)
			{
				strcpy(str, pp[0]);
				year = atoi(str);
				strcpy(str, pp[1]);
				mon = atoi(str);
				strcpy(str, pp[2]);
				day = atoi(str);
				strcpy(str, pp[3]);
				hour = atoi(str);
				strcpy(str, pp[4]);
				min = atoi(str);
				printf("\n%d\t%d\t%d\t%d\t%d\t", year, mon, day, hour, min);


				p_stm.tm_year = year - 1900;
				p_stm.tm_mon = mon - 1;
				p_stm.tm_mday = day;
				p_stm.tm_hour = hour;
				p_stm.tm_min = min;
				p_stm.tm_sec = 0;
				p_stm.tm_isdst = -1;

				time_t time = mktime(&p_stm);
				printf("\n%ld\n", time);
				eve.time = (long)time;//2018-03-20-1-45
				printf("%ld", eve.time);
				state = Event_change(eve, 9);
				if (state == 9)
					printf("�Ƿ�����");
				else if (state == 11)
					printf("�����ڴ���Ŀ");
				else
				{
					printf("�޸ĳɹ�");
					printf("%ld", time);
				}
			}
			else
			{
				printf("�������");
			}
			break;
		case 7:
			printf("\t1.�о��� 2.�޾���\n");
			scanf("%d", &hasFinals);
			eve.hasFinals = hasFinals;
			state = Event_change(eve, 7);
			if (state == 7)
				printf("�Ƿ�����");
			else if (state == 11)
				printf("�����ڴ���Ŀ");
			else if (hasFinals == 0)
				printf("�޸ĳɹ�");
			else
			{
				int finchoice = 3;
				while (finchoice != 3)
				{
					while (1)
					{
						printf("\n\t 1.  �޸ľ������� \n");
						printf("\n\t 2.  �޸ľ���ʱ�� \n");
						printf("\n\t 3.  ������һ��\n");
						scanf("%d", finchoice);
						if (type >= 1 && finchoice <= 3)
							break;
						else
							printf("�����������������");
					}
					if (finchoice == 1)
					{
						printf("\t���޸Ĵ���Ŀ�ľ���������С��20��\n");
						scanf("%d", &finNum);
						eve.finNum = finNum;
						int state = Event_change(eve, 8);
						if (state == 8)
							printf("�Ƿ�����");
						else
							printf("�޸ĳɹ�");
					}
					else if (finchoice == 2)
					{
						printf("\t���޸Ĵ���Ŀ�ľ���ʱ��\n");
						scanf("%ld", &etime);
						eve.etime = etime;
						int state = Event_change(eve, 10);
						if (state == 9)
							printf("�Ƿ�����");
						else
							printf("�޸ĳɹ�");
					}
				}
			}
			break;
		default:
			break;
	}
	return 0;
}

int showEventProperty(long id)
{
	SportsEvent eve;
	eve = Event_getinfo(id);

	clearScreen(400);
	printf("[��Ŀ]   ��ĿID:%d    ��Ŀ��:%s", eve.id, eve.name);
	if (eve.type / 20)
		printf("Ů����Ŀ ");
	else
		printf("������Ŀ ");
	if (eve.type % 2)
		printf("���� ");
	else
		printf("���� ");
	printf("\n\n\t%s (ʱ��:%d����)  Ԥ������:%d�� ", eve.place, eve.timecost, eve.maxpeople);
	//eve.time = 1521421395;
	if (eve.time == 0)
		printf(" ����ʱ��δ��");
	else
	{
		time_t  tt = (time_t)eve.time;   //�ٶ�ʱ��
		char now[64];
		struct tm *ttime;
		ttime = localtime(&tt);
		strftime(now, 64, "%Y%m%d %H:%M:%S", ttime);
		printf(" Ԥ��ʱ��:%d��%d��%d��  %02d:%02d ", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min);
	}
	if (eve.hasFinals)
	{
		printf("\n\t�о��� (ʱ��:%d����) ��������:%d��", eve.timecost, eve.finNum);
		//eve.etime = 1521421395;
		if (eve.etime == 0)
			printf(" ����ʱ��δ��\n");
		else
		{
			time_t  tt = (time_t)eve.etime;   //�ٶ�ʱ��
			char now[64];
			struct tm *ttime;
			ttime = localtime(&tt);
			strftime(now, 64, "%Y%m%d %H:%M:%S", ttime);
			printf(" ����ʱ��:%d��%d��%d��  %02d:%02d \n", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min);

		}
	}
	else
		printf("�޾���\n");
	return 0;
}


//��ʾ��Ŀ������Ϣ
int showAllEventID()		//��ʾĿǰ������ĿID
{
	int i;
	SportsEvent *evo = (SportsEvent*)malloc(sys_info.eve * sizeof(SportsEvent));
	Event_getlist(evo);
	printf("\tĿǰ������Ŀ\n");
	for (i = 0; i < sys_info.eve; i++)
	{
		printf("%ld,%s, Ԥ������:%d\n", evo[i].id, evo[i].name, evo[i].maxpeople);
	}
	free(evo);
	return 0;

}

//�޸���Ŀ�е��˶�Ա����
int EveSporterManage(long eveid)
{
	int choice;
	int ret;
	while (1)
	{

		while (1)
		{
			clearScreen(400);
			printf("\n\t�����˶�Ա����\n");
			printf("\n\t\t 1. �鿴Ԥ�����      \t 2. ����Ԥ���˶�Ա \n");
			printf("\n\t\t 3. ɾ��Ԥ���˶�Ա   \t 4. �Ǽ�Ԥ���ɼ� \n");
			printf("\n\t\t 5. ɸѡ�����˶�Ա   \t 6. �鿴�������   \n");
			printf("\n\t\t 7. ���Ӿ����˶�Ա    \t 8. ɾ�������˶�Ա   \n");
			printf("\n\t\t 9. �ǼǾ����ɼ�       \t 10. ������һ��  \n");
			if (scanf("%d", &choice) == 1 && (choice <= 10 && choice >= 1))
				break;
			else
				printf("\t\t\t ����������������������");
		}
		SportsEvent	spEve;
		long peoid;
		int rank;
		switch (choice)
		{
			case 1:
				rank = 0;
				spEve = Event_getinfo(eveid);
				qsort(spEve.prePerson, 100, sizeof(Participant), cmp);

				if (spEve.type % 2) //����
				{

					for (int p = 0; p < 100; p++)
					{
						if (spEve.prePerson[p].score == 0)
							continue;
						rank++;

						printf("\n��%d�� : ", rank);
						printf("%s   ", Person_getinfo(spEve.prePerson[p].id).name);

						char s[20] = "";
						scoreToChar(spEve.prePerson[p].score, s);
						printf("  �ɼ�:%s ", s);

					}

				}
				else     //����
				{
					for (int p = spEve.maxpeople; p > 0; p--)
					{
						if (spEve.prePerson[p].score == 0)
							continue;
						rank++;
						printf("\n��%d�� :", rank);
						printf("%s", Person_getinfo(spEve.prePerson[p].id).name);
						if (spEve.prePerson[p].score > 1000)
							printf("  �ɼ�:%dm", spEve.prePerson[p].score / 1000);

						printf("  �ɼ�:%dcm", spEve.prePerson[p].score % 1000);

					}

				}
				if (rank == 0)
					printf("\n  ����Ԥ���ɼ�\n");
				fflush(stdin);
				puts("\n\n���س���������һ��");
				getchar();
				break;
			case 2:
				//long peoid;
				printf("\n\t�������˶�ԱID��");
				scanf("%ld", &peoid);
				if (Person_getinfo(peoid).id == 0)
					puts("\n  ��Ǹ�����޸��û�\n");
				ret = Event_inc(eveid, peoid, 0);
				if (ret == 0)
					puts("\n  ���˶�Ա����Ԥ���Ѿ��ɹ�\n");
				else if (ret == 3)
					puts("\n  ���˶�Ա֮ǰ�Ѿ��ɹ�����Ԥ����\n");
				else
					puts("\n  ���˶�Ա����Ԥ��ʧ��\n");
				Sleep(1000);
				break;
			case 3:
				//long peoid;
				printf("\n\t�������˶�ԱID��");
				scanf("%ld", &peoid);
				if (Person_getinfo(peoid).id == 0)
					puts("\n  ��Ǹ�����޸��û�\n");
				else
				{
					spEve = Event_getinfo(eveid);
					for (int p = 0; p < 100; p++)
					{
						if (spEve.prePerson[p].id == peoid)

							spEve.prePerson[p].score = 0;
					}
					if (Event_dec(eveid, peoid, 0) == 0)
						puts("\n  ɾ���˶�Ա�ɹ�\n");
					else
						puts("\n  ɾ���˶�Աʧ��\n");
				}
				Sleep(1000);
				break;
			case 4:
				printf("\n\t�������˶�ԱID��");
				scanf("%ld", &peoid);
				if (Person_getinfo(peoid).id == 0)
					puts("\n  ��Ǹ��ϵͳ���޸��û�\n");
				else
				{
					clearScreen(500);
					spEve = Event_getinfo(eveid);
					int isExisted = 1;
					for (int p = 0; p < spEve.maxpeople; p++)
					{
						if (spEve.prePerson[p].id == peoid)
						{
							isExisted = 1;
							break;
						}
						else
							isExisted = 0;
					}
					if (!isExisted)
					{
						printf("\n����Ŀ�����ڸ�id");
						break;
					}
					printf("\n[��Ŀ]   ��ĿID:%d    ��Ŀ��:%s", spEve.id, spEve.name);
					if (spEve.type % 2)
						printf("���� ");
					else
						printf("���� ");

					long score;
					printf("\n\n  ����������˶�Ա��Ԥ���ɼ�(ע�����Ŀ��");
					if (spEve.type % 2)
						printf("����)\n");
					else
						printf("����)\n");
					scanf("%ld", &score);
					Event_changescore(eveid, peoid, 0, score);
					puts("\n  �Ǽǳɼ��ɹ�");
				}
				break;
			case 5:
				spEve = Event_getinfo(eveid);
				qsort(spEve.finPerson, 20, sizeof(Participant), cmp);
				rank = 0;
				if (spEve.type % 2) //����
				{
					int finNum;
					printf("\n��ǰԤ���˶�Ա����:%d", spEve.maxpeople);
					while (1)
					{
						printf("\n  �������ܽ�����������(�������)\n");
						scanf("%d", &finNum);
						if (finNum >= spEve.maxpeople)
							printf("\n  ����������\n");
						else
							break;
					}
					for (int p = 0; p < finNum; p++)
					{
						if (spEve.prePerson[p].score == 0)
							continue;
						rank++;

						printf("\n��%d�� : ", rank);
						printf("%s", Person_getinfo(spEve.prePerson[p].id).name);

						char s[20] = "";
						scoreToChar(spEve.prePerson[p].score, s);
						printf("  �ɼ�:%s ", s);
						ret = Event_inc(eveid, peoid, 1);
						printf("����ֵ%d",ret );
						if (ret == 0)
							printf("�����˶�Ա�ɹ��������");
						else
							printf("����ʧ��");

					}

				}
				else     //����
				{
					int finNum;
					printf("\n��ǰԤ���˶�Ա����:%d", spEve.maxpeople);
					while (1)
					{
						printf("\n  �������ܽ�����������(�������)\n");
						scanf("%d", &finNum);
						if (finNum >= spEve.maxpeople)
							printf("\n  ����������\n");
						else
							break;
					}

					for (int p = finNum; p > 0; p--)
					{
						if (spEve.prePerson[p].score == 0)
							continue;
						rank++;
						printf("\n��%d�� :", rank);
						printf("%s", Person_getinfo(spEve.finPerson[p].id).name);
						if (spEve.finPerson[p].score > 1000)
							printf("  �ɼ�:%dm", spEve.prePerson[p].score / 1000);

						printf("  �ɼ�:%dcm", spEve.prePerson[p].score % 1000);

						if (Event_inc(eveid, peoid, 1) == 0)
							printf("�����˶�Ա�ɹ��������");
						else
							printf("����ʧ��");
					}

				}
				if (rank == 0)
					printf("\n  ����Ԥ���ɼ�");
				fflush(stdin);
				puts("\n\n���س���������һ��");
				getchar();
				break;
			case 6:
				spEve = Event_getinfo(eveid);
				qsort(spEve.finPerson, 20, sizeof(Participant), cmp);

				rank = 0;
				if (spEve.type % 2) //����
				{

					for (int p = 0; p < 20; p++)
					{
						spEve.prePerson[p].score = 0;
						if (spEve.finPerson[p].score == 0)
							continue;
						rank++;

						printf("\n��%d�� : ", rank);
						printf("%s", Person_getinfo(spEve.finPerson[p].id).name);

						char s[20] = "";
						scoreToChar(spEve.finPerson[p].score, s);
						printf("  �ɼ�:%s ", s);

					}
				}
				else     //����
				{
					for (int p = spEve.finNum; p > 0; p--)
					{
						if (spEve.finPerson[p].score == 0)
							continue;
						rank++;
						printf("\n��%d�� : ", rank);
						printf("%s", Person_getinfo(spEve.finPerson[p].id).name);
						if (spEve.finPerson[p].score > 1000)
							printf("  �ɼ�:%dm", spEve.finPerson[p].score / 1000);

						printf("  �ɼ�:%dcm", spEve.finPerson[p].score % 1000);

					}

				}
				//printf("%d", rank);
				if (rank == 0)
					printf("\n  ���޾����ɼ�\n");
				fflush(stdin);
				puts("\n\n���س���������һ��");
				getchar();
				break;
			case 7:
				//long peoid;
				printf("\n\t�������˶�ԱID��");
				scanf("%ld", &peoid);
				if (Person_getinfo(peoid).id == 0)
					puts("\n  ��Ǹ�����޸��û�\n");
				else if (Event_inc(eveid, peoid, 1) == 0)
					puts("\n  ���˶�Ա�Ѿ��ɹ��������\n");
				else
					puts("\n  ����ʧ��\n");
				Sleep(1000);
				break;
			case 8:
				//long peoid;
				printf("\n\t�������˶�ԱID��");
				scanf("%ld", &peoid);
				if (Person_getinfo(peoid).id == 0)
					puts("\n  ��Ǹ�����޸��û�\n");

				else
				{
					spEve = Event_getinfo(eveid);

					for (int p = 0; p < 100; p++)
					{
						if (spEve.finPerson[p].id == peoid)
							spEve.finPerson[p].score = 0;
					}
					if (Event_dec(eveid, peoid, 1) == 0)
						puts("\n  ɾ���˶�Ա�ɹ�\n");
					else
						puts("\n  ɾ���˶�Աʧ��\n");
				}
				Sleep(100);
				break;
			case 9:
				//long peoid;
				printf("\n\t�������˶�ԱID��");
				scanf("%ld", &peoid);
				if (Person_getinfo(peoid).id == 0)
					puts("\n  ��Ǹ��ϵͳ���޸��û�\n");
				else
				{
					clearScreen(500);
					spEve = Event_getinfo(eveid);
					int isExisted = 1;
					for (int p = 0; p < spEve.finNum; p++)
					{
						if (spEve.finPerson[p].id == peoid)
						{
							isExisted = 1;
							break;
						}
						else
							isExisted = 0;
					}
					if (!isExisted)
					{
						printf("\n����Ŀ�����ڸ�id");
						break;
					}

					printf("[��Ŀ]   ��ĿID:%d    ��Ŀ��:%s", spEve.id, spEve.name);
					if (spEve.type % 2)
						printf("���� ");
					else
						printf("���� ");
					long score;
					printf("\n  ����������˶�Ա�ľ����ɼ�(ע�����Ŀ��");
					if (spEve.type % 2)
						printf("����)\n");
					else
						printf("����)\n");
					scanf("%ld", &score);
					if (Event_changescore(eveid, peoid, 1, score) == 0)
						puts("\n  �Ǽǳɼ��ɹ�");
					else
						puts("\n  �Ǽǳɼ�ʧ��");
				}

				break;
			default:
				return 0;
		}
	}
}

//�޸���Ŀ
int changeEventInfo()			
{
	clearScreen(400);
	showAllEventID();
	long id;
	printf("\n\t������Ҫ�޸���Ŀ��ID:\n");
	scanf("%ld", &id);
	int state = Event_had(id);
	if (state == 1)
	{
		int type;
		do
		{
			SportsEvent eve;
			eve = Event_getinfo(id);

			clearScreen(400);
			printf("[��Ŀ]   ��ĿID:%d    ��Ŀ��:%s", eve.id, eve.name);
			if (eve.type / 20)
				printf("Ů����Ŀ ");
			else
				printf("������Ŀ ");
			if (eve.type % 2)
				printf("���� ");
			else
				printf("���� ");
			printf("\n\n\t%s (ʱ��:%d����)  Ԥ������:%d�� ", eve.place, eve.timecost, eve.maxpeople);
			//eve.time = 1521421395;
			if (eve.time == 0)
				printf(" ����ʱ��δ��");
			else
			{
				time_t  tt = (time_t)eve.time;   //�ٶ�ʱ��
				char now[64];
				struct tm *ttime;
				ttime = localtime(&tt);
				strftime(now, 64, "%Y%m%d %H:%M:%S", ttime);
				printf(" Ԥ��ʱ��:%d��%d��%d��  %02d:%02d \n", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min);
			}
			if (eve.hasFinals)
			{
				printf("\n\t�о��� (ʱ��:%d����) ��������:%d��", eve.timecost, eve.finNum);
				//eve.etime = 1521421395;
				if (eve.etime == 0)
					printf(" ����ʱ��δ��");
				else
				{
					time_t  tt = (time_t)eve.etime;   //�ٶ�ʱ��
					char now[64];
					struct tm *ttime;
					ttime = localtime(&tt);
					strftime(now, 64, "%Y%m%d %H:%M:%S", ttime);
					printf(" ����ʱ��:%d��%d��%d��  %02d:%02d \n", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min);

				}
			}

			while (1)
			{
				printf("\n\t 1.  �˶�Ա���� \n");
				printf("\n\t 2.  �޸���Ŀ���� \n");
				printf("\n\t 3.  ������һ�� \n");
				if (scanf("%d", &type) == 1 && (type <= 3 && type >= 1))
					break;
				else
					printf("\n\t ����������������������\n");
			}
			if (type == 1)
				EveSporterManage(id);
			else if (type == 2)
				changeEventProperty(id);
		} while (type != 3);


	}
	else
	{
		printf("�����ڴ���Ŀ");
	}
	return 0;
}

//���˵�
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
			printf("\n\t\t\t 1. �˺Ź���               \t 2. ֪ͨ������    \n");
			printf("\n\t\t\t 3. ��Ŀ����            \t 4. ��֯����  \n");
			printf("\n\t\t\t 5. ���������		  \t 6. �˳���¼  \n");
			printf("\n\t\t\t 7. �˳�ϵͳ\n");

			if (scanf("%d", &choice) == 1 && (choice <= 7 && choice >= 1))
				break;
			else
				printf("\t\t\t ����������������������");
		}
		switch (choice)
		{
			case 1:
				int type;
				do
				{
					while (1)
					{
						clearScreen(400);
						printf("\n\t 1.  ��ѯ��ע���û� \n");
						printf("\n\t 2.  �����û����� \n");
						printf("\n\t 3.  ɾ���û��˺� \n");
						printf("\n\t 4.  ���ù���Ա���� \n");
						printf("\n\t 5.  ������һ��\n\n");

						if (scanf("%d", &type) == 1 && (type <= 5 && type >= 1))
							break;
						else
							printf("\t ����������������������");
					}
					if (type == 1)
					{
						Person_list();
						Sleep(2000);
					}
					else if (type == 2)
					{
						printf("\n\t ��������Ҫ�޸ĵ��û�ID \n");
						long id;
						PerInfo user;
						scanf("%ld", &id);
						user.id = id;
						printf("\n\t ���������� \n");
						char password[20];
						inputPasswd(password);
						strcpy(user.password, password);
						int state = Person_change(user, 6);
						if (state == 0) printf("\n\t�޸ĳɹ���\n");
						else if (state == 7) printf("\n\t�����ڴ��˺�\n");
						else if (state == 9) printf("\n\t���ļ�ʧ��\n");
					}
					else if (type == 3)
					{
						printf("\n\t ��������Ҫɾ�����û�id \n");
						long id;
						PerInfo user;
						scanf("%ld", &id);
						int state = Person_delete(id);
						if (state == 0) printf("\n\tɾ���ɹ���\n");
						else if (state == 1) printf("\n\t����ɾ��idΪ0���û�\n");
						else if (state == 2) printf("\n\t���û�������\n");
						else if (state == 3) printf("\n\t��ԱΪ0��ɾ��ʧ�ܣ�\n");
					}
					else if (type == 4)
					{
						PerInfo admin;
						printf("\n\t ���������� \n");
						char password1[20];
						inputPasswd(password1);
						printf("\n\t ���ٴ��������� \n");
						char password2[20];
						inputPasswd(password2);
						if (strcmp(password1, password2) == 0)
						{
							int state = sys_changepsw(password1);
							if (state == 0) printf("\n\t�޸ĳɹ���\n");
							else if (state == 1) printf("\n\t�Ƿ��ַ�\n");
						}
						else
						{
							printf("\n\tǰ�����벻һ��\n");
						}
					}
				} while (type != 5);
				break;
			case 2:
				do
				{
					while (1)
					{
						clearScreen(400);
						printf("\n\t 1.  ��������֪ͨ \n");
						printf("\n\t 2.  ������Ŀ֪ͨ \n");
						printf("\n\t 3.  �������� \n");
						printf("\n\t 4.  ������һ�� \n");
						if (scanf("%d", &type) == 1 && (type <= 4 && type >= 1))
							break;
						else
							printf("\n\t ����������������������\n");
					}
					if (type == 1)
					{
						long id;
						printf("\n\t�����뱻֪ͨ�û���id(�������10000)\n");
						scanf("%ld", &id);
						if (id > 10000)
						{
							printf("\n\t������֪ͨ\n");
							char msg[300];
							scanf("%s", &msg);
							int state = Person_notice(id, msg);
							if (state == 0)printf("\n\t֪ͨ�ɹ�\n");
							else
							{
								printf("\n\t���ļ�ʧ��\n");
							}
						}
						else
						{
							printf("\n\t����id�Ƿ�\n");
						}
					}
					else if (type == 2)
					{
						long id;
						printf("\n\t��������Ŀ��id(1000-9999)\n");
						scanf("%ld", &id);
						if (id >= 1000 && id <= 9999)
						{
							if (Event_had(id) == 0) printf("\n\t�����ڴ���Ŀ\n");
							else
							{
								int match = 0, i = 0;
								printf("\n\t��ѡ���ʱ�ı����׶� 1.Ԥ�� 2.����\n");
								scanf("%d", match);
								SportsEvent eve;
								eve = Event_getinfo(id);
								if (match == 1)
								{
									long prePersonid[100];
									for (int i = 0; i <= 100; i++)
										prePersonid[i] = eve.prePerson[i].id;
									printf("\n\t������֪ͨ\n");
									char* msg;
									scanf("%s", &msg);
									int state;
									for (int i = 0; i <= 100; i++)
									{
										state = Person_notice(prePersonid[i], msg);
									}
									if (state == 0)printf("\n\t֪ͨ�ɹ�\n");
									else
									{
										printf("\n\t���ļ�ʧ��\n");
									}
								}
								else
								{
									if (match == 2)
									{
										long finPersonid[20];
										for (int i = 0; i <= 20; i++)
											finPersonid[i] = eve.finPerson[i].id;
										printf("\n\t������֪ͨ\n");
										char* msg;
										scanf("%s", &msg);
										int state;
										for (int i = 0; i <= 20; i++)
										{
											state = Person_notice(finPersonid[i], msg);
										}
										if (state == 0)printf("\n\t֪ͨ�ɹ�\n");
										else
										{
											printf("\n\t���ļ�ʧ��\t");
										}
									}
									else printf("\n\t�������\n");
								}
							}
						}
						else
						{
							printf("\n\t����id�Ƿ�\n");
						}
					}
					else if (type == 3)
					{
						printf("\n\t������֪ͨ\t");
						char msg[300];
						scanf("%s", &msg);
						int state = Person_notice(10000, msg);
						if (state == 0)printf("\n\t֪ͨ�ɹ�\n");
						else
						{
							printf("\n\t���ļ�ʧ��\n");
						}
					}
				} while (type != 4);
				break;
			case 3:
				do
				{
					while (1)
					{
						clearScreen(400);
						showAllEventID();
						printf("\n\t 1.  �޸���Ŀ \n");
						printf("\n\t 2.  ������Ŀ \n");
						printf("\n\t 3.  ������Ŀ\n");
						printf("\n\t 4.  �������� \n");
						printf("\n\t 5.  ���ű��� \n");
						printf("\n\t 6.  ������һ��\n\n");
						scanf("%d", &type);
						if (type <= 6 && type >= 1)
							break;
						else
							printf("\t ����������������������\n");
					}
					if (type == 1)
					{
						changeEventInfo();
					}
					else if (type == 2)
					{
						clearScreen(400);
						char name[20];
						int type;//10���11�о���20Ů�21Ů��
						char place[20];//����
						int timecost;//��ʱ������
						int hasFinals = 0;//���޾��� 0�� 1��
						printf("\t����������Ŀ������\n");
						scanf("%s", &name);
						printf("\t���������Ŀ���������������10����������11��Ů����������20����������21��\n");
						scanf("%d", &type);
						printf("\t���������Ŀ�ĳ���\n");
						scanf("%s", &place);
						printf("\t���������Ŀ����ʱ\n");
						scanf("%d", &timecost);
						printf("\t���޾�����1.�� 2.�ޣ�\n");
						scanf("%d", &hasFinals);
						SportsEvent msg;
						strcpy(msg.name, name);
						msg.type = type;
						strcpy(msg.place, place);
						msg.timecost = timecost;
						msg.hasFinals = hasFinals;
						int state = Event_create(msg);
						if (state == 1)
							printf("\n\t�����������\n");
						else if (state == 3)
							printf("\n\t�ﾶ����������\n");
						else if (state == 4)
							printf("\n\t�����������\n");
						else if (state == 5)
							printf("\n\t��ʱ�������\n");
						if (state == 7)
							printf("\n\t���޾����������\n");
						else if (state == 10)
							printf("\n\t̫����Ŀ\n");
						else printf("\n\t�����ɹ�\n");
					}
					else if (type == 3)
					{
						long id = -1;
						int state;
						printf("\n\t��������Ҫɾ������Ŀ��ID\n");
						scanf("%ld", &id);
						state = Event_delete(id);
						if (state == 1)
							printf("\n\t����Ŀ����ɾ��\n");
						else if (state == 2)
							printf("\n����Ŀ������\t\n");
						else if (state == 3)
							printf("\n\tɾ��ʧ��\n");
					}
					else if (type == 4)
					{
						sys_changecj(0);
						printf("\n\t����������\n");
					}
					else if (type == 5)
					{
						sys_changecj(1);
						printf("\n\t�����ѿ���\n");
					}
				} while (type != 6);
				break;
			case 4:
				do
				{
					while (1)
					{
						clearScreen(400);
						printf("ĿǰԺ\n");
						for (int i = 0; i < sys_info.numyuan; i++)
						{
							printf("\t%s\n", sys_info.yuan[i]);
						}
						printf("Ŀǰϵ\n");
						for (int i = 0; i < sys_info.numxi; i++)
						{
							printf("\t%s\n", sys_info.xi[i]);
						}
						printf("\n\t 1.  ����Ժ \n");
						printf("\n\t 2.  ����Ժ \n");
						printf("\n\t 3.  ����ϵ\n");
						printf("\n\t 4.  ����ϵ \n");
						printf("\n\t 5.  ������һ��\n\n");
						scanf("%d", &type);
						if (type <= 5 && type >= 1)
							break;
						else
							printf("\t ����������������������\n");
					}
					if (type == 1)
					{
						printf("\n\t�������Ժ������\n");
						char yuan[20];
						scanf("%s", yuan);
						int state = sys_incyuan(yuan);
						if (state == 0)
							printf("\n\t���ӳɹ�\n");
						else if (state == 1)
							printf("\n\t�Ѵ���\n");
						else if (state == 2)
							printf("\n\t����Ա\n");
						else if (state == 3)
							printf("\n\t�������\n");
					}
					else if (type == 2)
					{
						printf("\n\t�������Ժ������\n");
						char yuan[20];
						scanf("%s", yuan);
						int state = sys_decyuan(yuan);
						if (state == 0)
							printf("\n\t���ٳɹ�\n");
						else if (state == 1)
							printf("\n\tѧԺ��ĿΪ0\n");
						else if (state == 2)
							printf("\n\t�����ڸ�ѧԺ\n");
						else if (state == 3)
							printf("\n\t�������\n");
					}
					else if (type == 3)
					{
						printf("\n\t�������ϵ������\n");
						char xi[20];
						scanf("%s", xi);
						int state = sys_incxi(xi);
						if (state == 0)
							printf("\n\t���ӳɹ�\n");
						else if (state == 1)
							printf("\n\t�Ѵ��ڸ�ϵ\n");
						else if (state == 2)
							printf("\n\t����Ա\n");
						else if (state == 3)
							printf("\n\t�������\n");
					}
					else if (type == 4)
					{
						printf("\n\t�������ϵ������\n");
						char xi[20];
						scanf("%s", xi);
						int state = sys_decxi(xi);
						if (state == 0)
							printf("\n\t���ٳɹ�\n");
						else if (state == 1)
							printf("\n\t�����ڸ�ϵ\n");
						else if (state == 2)
							printf("\n\t�����ڸ�ϵ\n");
						else if (state == 3)
							printf("\n\t�������\n");
					}
				} while (type != 5);
				break;
			case 5:

				break;
			case 6:
				return -1;
			default:
				return 0;
		}
	}
}