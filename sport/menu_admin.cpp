#include "stdafx.h";

int changeEventProperty(long eve_id)
{
	SportsEvent eve;
	int choice;
	char name[20];
	int type;//10男田、11男径、20女田、21女径
	char place[20];//场地
	int timecost;//用时，分钟
	int maxpeople;//上限人数
	int hasFinals;//有无决赛 0无 1有
	int finNum;//有决赛时决赛人数
	long time;//比赛时间戳，秒
	long etime;//决赛时间
	int ppp;
	char* p;
	const char delim[2] = "-";//分隔符字符串
	eve.id = eve_id;
	while (1)
	{
		clearScreen(400);
		printf("\n\t请选择需要修改的属性\n");
		printf("\n\t 1.  修改名字 \n");
		printf("\n\t 2.  修改项目类型 \n");
		printf("\n\t 3.  修改场地\n");
		printf("\n\t 4.  修改用时\n");
		printf("\n\t 5.  修改预赛人数 \n");
		printf("\n\t 6.  修改预赛时间\n");
		printf("\n\t 7.  有无决赛\n");
		printf("\n\t 8.  返回上一级\n\n");
		scanf("%d", &choice);
		if (choice <= 8 && choice >= 1)
			break;
		else
			printf("\t 您的输入有误，请重新输入\n");
	}
	int state;
	switch (choice)
	{
		case 1:
			printf("\t请修改此项目的名称\n");
			scanf("%s", &name);
			strcpy(eve.name, name);
			state = Event_change(eve, 1);
			if (state == 1)
				printf("非法输入");
			else if (state == 11)
				printf("不存在此项目");
			else printf("修改成功");
			break;
		case 2:
			printf("\t请输入此项目类别（男子田赛输入10，径赛输入11，女子田赛输入20，径赛输入21）\n");
			scanf("%d", &type);
			eve.type = type;
			state = Event_change(eve, 3);
			printf("state值为%d", state);
			if (state == 3)
				printf("非法输入");
			else if (state == 11)
				printf("不存在此项目");
			else
				printf("修改成功");
			break;
		case 3:
			printf("\t请修改此项目的场地\n");
			scanf("%s", &place);
			strcpy(eve.place, place);
			state = Event_change(eve, 4);
			printf("state值为%d", state);
			if (state == 4)
				printf("非法输入");
			else if (state == 11)
				printf("不存在此项目");
			else
				printf("修改成功");
			break;
		case 4:
			printf("\t请修改此项目的用时\n");
			scanf("%d", &timecost);
			eve.timecost = timecost;
			state = Event_change(eve, 5);
			if (state == 5)
				printf("非法输入");
			else if (state == 11)
				printf("不存在此项目");
			else
				printf("修改成功");
			break;
		case 5:
			printf("\t请修改此项目的预赛人数\n");
			scanf("%d", &maxpeople);
			eve.maxpeople = maxpeople;
			state = Event_change(eve, 6);
			if (state == 6)
				printf("非法输入");
			else if (state == 11)
				printf("不存在此项目");
			else
				printf("修改成功");
			break;
		case 6:
			char strtime[50];
			printf("\t请修改预赛的时间（2010-01-01-10-00）\n");
			scanf("%s", strtime);
			struct tm p_stm;
			p = strtok(strtime, delim);//第一次调用strtok
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
			{//当返回值不为NULL时，继续循环
				//printf("%s\n", p);//输出分解的字符串
				p = strtok(NULL, delim);//继续调用strtok，分解剩下的字符串
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
					printf("非法输入");
				else if (state == 11)
					printf("不存在此项目");
				else
				{
					printf("修改成功");
					printf("%ld", time);
				}
			}
			else
			{
				printf("输入错误");
			}
			break;
		case 7:
			printf("\t1.有决赛 2.无决赛\n");
			scanf("%d", &hasFinals);
			eve.hasFinals = hasFinals;
			state = Event_change(eve, 7);
			if (state == 7)
				printf("非法输入");
			else if (state == 11)
				printf("不存在此项目");
			else if (hasFinals == 0)
				printf("修改成功");
			else
			{
				int finchoice = 3;
				while (finchoice != 3)
				{
					while (1)
					{
						printf("\n\t 1.  修改决赛人数 \n");
						printf("\n\t 2.  修改决赛时间 \n");
						printf("\n\t 3.  返回上一级\n");
						scanf("%d", finchoice);
						if (type >= 1 && finchoice <= 3)
							break;
						else
							printf("输入错误，请重新输入");
					}
					if (finchoice == 1)
					{
						printf("\t请修改此项目的决赛人数（小于20）\n");
						scanf("%d", &finNum);
						eve.finNum = finNum;
						int state = Event_change(eve, 8);
						if (state == 8)
							printf("非法输入");
						else
							printf("修改成功");
					}
					else if (finchoice == 2)
					{
						printf("\t请修改此项目的决赛时间\n");
						scanf("%ld", &etime);
						eve.etime = etime;
						int state = Event_change(eve, 10);
						if (state == 9)
							printf("非法输入");
						else
							printf("修改成功");
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
	printf("[项目]   项目ID:%d    项目名:%s", eve.id, eve.name);
	if (eve.type / 20)
		printf("女子项目 ");
	else
		printf("男子项目 ");
	if (eve.type % 2)
		printf("径赛 ");
	else
		printf("田赛 ");
	printf("\n\n\t%s (时长:%d分钟)  预赛人数:%d人 ", eve.place, eve.timecost, eve.maxpeople);
	//eve.time = 1521421395;
	if (eve.time == 0)
		printf(" 比赛时间未定");
	else
	{
		time_t  tt = (time_t)eve.time;   //假定时间
		char now[64];
		struct tm *ttime;
		ttime = localtime(&tt);
		strftime(now, 64, "%Y%m%d %H:%M:%S", ttime);
		printf(" 预赛时间:%d年%d月%d日  %02d:%02d ", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min);
	}
	if (eve.hasFinals)
	{
		printf("\n\t有决赛 (时长:%d分钟) 决赛人数:%d人", eve.timecost, eve.finNum);
		//eve.etime = 1521421395;
		if (eve.etime == 0)
			printf(" 比赛时间未定\n");
		else
		{
			time_t  tt = (time_t)eve.etime;   //假定时间
			char now[64];
			struct tm *ttime;
			ttime = localtime(&tt);
			strftime(now, 64, "%Y%m%d %H:%M:%S", ttime);
			printf(" 决赛时间:%d年%d月%d日  %02d:%02d \n", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min);

		}
	}
	else
		printf("无决赛\n");
	return 0;
}


//显示项目部分信息
int showAllEventID()		//显示目前所有项目ID
{
	int i;
	SportsEvent *evo = (SportsEvent*)malloc(sys_info.eve * sizeof(SportsEvent));
	Event_getlist(evo);
	printf("\t目前所有项目\n");
	for (i = 0; i < sys_info.eve; i++)
	{
		printf("%ld,%s, 预赛人数:%d\n", evo[i].id, evo[i].name, evo[i].maxpeople);
	}
	free(evo);
	return 0;

}

//修改项目中的运动员管理
int EveSporterManage(long eveid)
{
	int choice;
	int ret;
	while (1)
	{

		while (1)
		{
			clearScreen(400);
			printf("\n\t管理运动员界面\n");
			printf("\n\t\t 1. 查看预赛情况      \t 2. 增加预赛运动员 \n");
			printf("\n\t\t 3. 删除预赛运动员   \t 4. 登记预赛成绩 \n");
			printf("\n\t\t 5. 筛选决赛运动员   \t 6. 查看决赛情况   \n");
			printf("\n\t\t 7. 增加决赛运动员    \t 8. 删除决赛运动员   \n");
			printf("\n\t\t 9. 登记决赛成绩       \t 10. 返回上一级  \n");
			if (scanf("%d", &choice) == 1 && (choice <= 10 && choice >= 1))
				break;
			else
				printf("\t\t\t 您的输入有误，请重新输入");
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

				if (spEve.type % 2) //径赛
				{

					for (int p = 0; p < 100; p++)
					{
						if (spEve.prePerson[p].score == 0)
							continue;
						rank++;

						printf("\n第%d名 : ", rank);
						printf("%s   ", Person_getinfo(spEve.prePerson[p].id).name);

						char s[20] = "";
						scoreToChar(spEve.prePerson[p].score, s);
						printf("  成绩:%s ", s);

					}

				}
				else     //田赛
				{
					for (int p = spEve.maxpeople; p > 0; p--)
					{
						if (spEve.prePerson[p].score == 0)
							continue;
						rank++;
						printf("\n第%d名 :", rank);
						printf("%s", Person_getinfo(spEve.prePerson[p].id).name);
						if (spEve.prePerson[p].score > 1000)
							printf("  成绩:%dm", spEve.prePerson[p].score / 1000);

						printf("  成绩:%dcm", spEve.prePerson[p].score % 1000);

					}

				}
				if (rank == 0)
					printf("\n  暂无预赛成绩\n");
				fflush(stdin);
				puts("\n\n按回车键返回上一步");
				getchar();
				break;
			case 2:
				//long peoid;
				printf("\n\t请输入运动员ID：");
				scanf("%ld", &peoid);
				if (Person_getinfo(peoid).id == 0)
					puts("\n  抱歉，暂无该用户\n");
				ret = Event_inc(eveid, peoid, 0);
				if (ret == 0)
					puts("\n  该运动员报名预赛已经成功\n");
				else if (ret == 3)
					puts("\n  该运动员之前已经成功报名预赛啦\n");
				else
					puts("\n  该运动员报名预赛失败\n");
				Sleep(1000);
				break;
			case 3:
				//long peoid;
				printf("\n\t请输入运动员ID：");
				scanf("%ld", &peoid);
				if (Person_getinfo(peoid).id == 0)
					puts("\n  抱歉，暂无该用户\n");
				else
				{
					spEve = Event_getinfo(eveid);
					for (int p = 0; p < 100; p++)
					{
						if (spEve.prePerson[p].id == peoid)

							spEve.prePerson[p].score = 0;
					}
					if (Event_dec(eveid, peoid, 0) == 0)
						puts("\n  删除运动员成功\n");
					else
						puts("\n  删除运动员失败\n");
				}
				Sleep(1000);
				break;
			case 4:
				printf("\n\t请输入运动员ID：");
				scanf("%ld", &peoid);
				if (Person_getinfo(peoid).id == 0)
					puts("\n  抱歉，系统暂无该用户\n");
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
						printf("\n该项目不存在该id");
						break;
					}
					printf("\n[项目]   项目ID:%d    项目名:%s", spEve.id, spEve.name);
					if (spEve.type % 2)
						printf("径赛 ");
					else
						printf("田赛 ");

					long score;
					printf("\n\n  请输入该名运动员的预赛成绩(注意该项目是");
					if (spEve.type % 2)
						printf("径赛)\n");
					else
						printf("田赛)\n");
					scanf("%ld", &score);
					Event_changescore(eveid, peoid, 0, score);
					puts("\n  登记成绩成功");
				}
				break;
			case 5:
				spEve = Event_getinfo(eveid);
				qsort(spEve.finPerson, 20, sizeof(Participant), cmp);
				rank = 0;
				if (spEve.type % 2) //径赛
				{
					int finNum;
					printf("\n当前预赛运动员总数:%d", spEve.maxpeople);
					while (1)
					{
						printf("\n  请输入能进决赛的人数(请合理安排)\n");
						scanf("%d", &finNum);
						if (finNum >= spEve.maxpeople)
							printf("\n  错误，请重输\n");
						else
							break;
					}
					for (int p = 0; p < finNum; p++)
					{
						if (spEve.prePerson[p].score == 0)
							continue;
						rank++;

						printf("\n第%d名 : ", rank);
						printf("%s", Person_getinfo(spEve.prePerson[p].id).name);

						char s[20] = "";
						scoreToChar(spEve.prePerson[p].score, s);
						printf("  成绩:%s ", s);
						ret = Event_inc(eveid, peoid, 1);
						printf("返回值%d",ret );
						if (ret == 0)
							printf("该名运动员成功进入决赛");
						else
							printf("操作失败");

					}

				}
				else     //田赛
				{
					int finNum;
					printf("\n当前预赛运动员总数:%d", spEve.maxpeople);
					while (1)
					{
						printf("\n  请输入能进决赛的人数(请合理安排)\n");
						scanf("%d", &finNum);
						if (finNum >= spEve.maxpeople)
							printf("\n  错误，请重输\n");
						else
							break;
					}

					for (int p = finNum; p > 0; p--)
					{
						if (spEve.prePerson[p].score == 0)
							continue;
						rank++;
						printf("\n第%d名 :", rank);
						printf("%s", Person_getinfo(spEve.finPerson[p].id).name);
						if (spEve.finPerson[p].score > 1000)
							printf("  成绩:%dm", spEve.prePerson[p].score / 1000);

						printf("  成绩:%dcm", spEve.prePerson[p].score % 1000);

						if (Event_inc(eveid, peoid, 1) == 0)
							printf("该名运动员成功进入决赛");
						else
							printf("操作失败");
					}

				}
				if (rank == 0)
					printf("\n  暂无预赛成绩");
				fflush(stdin);
				puts("\n\n按回车键返回上一步");
				getchar();
				break;
			case 6:
				spEve = Event_getinfo(eveid);
				qsort(spEve.finPerson, 20, sizeof(Participant), cmp);

				rank = 0;
				if (spEve.type % 2) //径赛
				{

					for (int p = 0; p < 20; p++)
					{
						spEve.prePerson[p].score = 0;
						if (spEve.finPerson[p].score == 0)
							continue;
						rank++;

						printf("\n第%d名 : ", rank);
						printf("%s", Person_getinfo(spEve.finPerson[p].id).name);

						char s[20] = "";
						scoreToChar(spEve.finPerson[p].score, s);
						printf("  成绩:%s ", s);

					}
				}
				else     //田赛
				{
					for (int p = spEve.finNum; p > 0; p--)
					{
						if (spEve.finPerson[p].score == 0)
							continue;
						rank++;
						printf("\n第%d名 : ", rank);
						printf("%s", Person_getinfo(spEve.finPerson[p].id).name);
						if (spEve.finPerson[p].score > 1000)
							printf("  成绩:%dm", spEve.finPerson[p].score / 1000);

						printf("  成绩:%dcm", spEve.finPerson[p].score % 1000);

					}

				}
				//printf("%d", rank);
				if (rank == 0)
					printf("\n  暂无决赛成绩\n");
				fflush(stdin);
				puts("\n\n按回车键返回上一步");
				getchar();
				break;
			case 7:
				//long peoid;
				printf("\n\t请输入运动员ID：");
				scanf("%ld", &peoid);
				if (Person_getinfo(peoid).id == 0)
					puts("\n  抱歉，暂无该用户\n");
				else if (Event_inc(eveid, peoid, 1) == 0)
					puts("\n  该运动员已经成功进入决赛\n");
				else
					puts("\n  操作失败\n");
				Sleep(1000);
				break;
			case 8:
				//long peoid;
				printf("\n\t请输入运动员ID：");
				scanf("%ld", &peoid);
				if (Person_getinfo(peoid).id == 0)
					puts("\n  抱歉，暂无该用户\n");

				else
				{
					spEve = Event_getinfo(eveid);

					for (int p = 0; p < 100; p++)
					{
						if (spEve.finPerson[p].id == peoid)
							spEve.finPerson[p].score = 0;
					}
					if (Event_dec(eveid, peoid, 1) == 0)
						puts("\n  删除运动员成功\n");
					else
						puts("\n  删除运动员失败\n");
				}
				Sleep(100);
				break;
			case 9:
				//long peoid;
				printf("\n\t请输入运动员ID：");
				scanf("%ld", &peoid);
				if (Person_getinfo(peoid).id == 0)
					puts("\n  抱歉，系统暂无该用户\n");
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
						printf("\n该项目不存在该id");
						break;
					}

					printf("[项目]   项目ID:%d    项目名:%s", spEve.id, spEve.name);
					if (spEve.type % 2)
						printf("径赛 ");
					else
						printf("田赛 ");
					long score;
					printf("\n  请输入该名运动员的决赛成绩(注意该项目是");
					if (spEve.type % 2)
						printf("径赛)\n");
					else
						printf("田赛)\n");
					scanf("%ld", &score);
					if (Event_changescore(eveid, peoid, 1, score) == 0)
						puts("\n  登记成绩成功");
					else
						puts("\n  登记成绩失败");
				}

				break;
			default:
				return 0;
		}
	}
}

//修改项目
int changeEventInfo()			
{
	clearScreen(400);
	showAllEventID();
	long id;
	printf("\n\t请输入要修改项目的ID:\n");
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
			printf("[项目]   项目ID:%d    项目名:%s", eve.id, eve.name);
			if (eve.type / 20)
				printf("女子项目 ");
			else
				printf("男子项目 ");
			if (eve.type % 2)
				printf("径赛 ");
			else
				printf("田赛 ");
			printf("\n\n\t%s (时长:%d分钟)  预赛人数:%d人 ", eve.place, eve.timecost, eve.maxpeople);
			//eve.time = 1521421395;
			if (eve.time == 0)
				printf(" 比赛时间未定");
			else
			{
				time_t  tt = (time_t)eve.time;   //假定时间
				char now[64];
				struct tm *ttime;
				ttime = localtime(&tt);
				strftime(now, 64, "%Y%m%d %H:%M:%S", ttime);
				printf(" 预赛时间:%d年%d月%d日  %02d:%02d \n", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min);
			}
			if (eve.hasFinals)
			{
				printf("\n\t有决赛 (时长:%d分钟) 决赛人数:%d人", eve.timecost, eve.finNum);
				//eve.etime = 1521421395;
				if (eve.etime == 0)
					printf(" 比赛时间未定");
				else
				{
					time_t  tt = (time_t)eve.etime;   //假定时间
					char now[64];
					struct tm *ttime;
					ttime = localtime(&tt);
					strftime(now, 64, "%Y%m%d %H:%M:%S", ttime);
					printf(" 决赛时间:%d年%d月%d日  %02d:%02d \n", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min);

				}
			}

			while (1)
			{
				printf("\n\t 1.  运动员管理 \n");
				printf("\n\t 2.  修改项目属性 \n");
				printf("\n\t 3.  返回上一级 \n");
				if (scanf("%d", &type) == 1 && (type <= 3 && type >= 1))
					break;
				else
					printf("\n\t 您的输入有误，请重新输入\n");
			}
			if (type == 1)
				EveSporterManage(id);
			else if (type == 2)
				changeEventProperty(id);
		} while (type != 3);


	}
	else
	{
		printf("不存在此项目");
	}
	return 0;
}

//主菜单
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
			printf("\n\t\t\t 1. 账号管理               \t 2. 通知栏管理    \n");
			printf("\n\t\t\t 3. 项目管理            \t 4. 组织管理  \n");
			printf("\n\t\t\t 5. 生成秩序册		  \t 6. 退出登录  \n");
			printf("\n\t\t\t 7. 退出系统\n");

			if (scanf("%d", &choice) == 1 && (choice <= 7 && choice >= 1))
				break;
			else
				printf("\t\t\t 您的输入有误，请重新输入");
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
						printf("\n\t 1.  查询已注册用户 \n");
						printf("\n\t 2.  重置用户密码 \n");
						printf("\n\t 3.  删除用户账号 \n");
						printf("\n\t 4.  重置管理员密码 \n");
						printf("\n\t 5.  返回上一级\n\n");

						if (scanf("%d", &type) == 1 && (type <= 5 && type >= 1))
							break;
						else
							printf("\t 您的输入有误，请重新输入");
					}
					if (type == 1)
					{
						Person_list();
						Sleep(2000);
					}
					else if (type == 2)
					{
						printf("\n\t 请输入需要修改的用户ID \n");
						long id;
						PerInfo user;
						scanf("%ld", &id);
						user.id = id;
						printf("\n\t 请重置密码 \n");
						char password[20];
						inputPasswd(password);
						strcpy(user.password, password);
						int state = Person_change(user, 6);
						if (state == 0) printf("\n\t修改成功！\n");
						else if (state == 7) printf("\n\t不存在此账号\n");
						else if (state == 9) printf("\n\t打开文件失败\n");
					}
					else if (type == 3)
					{
						printf("\n\t 请输入需要删除的用户id \n");
						long id;
						PerInfo user;
						scanf("%ld", &id);
						int state = Person_delete(id);
						if (state == 0) printf("\n\t删除成功！\n");
						else if (state == 1) printf("\n\t不能删除id为0的用户\n");
						else if (state == 2) printf("\n\t此用户不存在\n");
						else if (state == 3) printf("\n\t成员为0，删除失败！\n");
					}
					else if (type == 4)
					{
						PerInfo admin;
						printf("\n\t 请重置密码 \n");
						char password1[20];
						inputPasswd(password1);
						printf("\n\t 请再次输入密码 \n");
						char password2[20];
						inputPasswd(password2);
						if (strcmp(password1, password2) == 0)
						{
							int state = sys_changepsw(password1);
							if (state == 0) printf("\n\t修改成功！\n");
							else if (state == 1) printf("\n\t非法字符\n");
						}
						else
						{
							printf("\n\t前后密码不一致\n");
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
						printf("\n\t 1.  发布个人通知 \n");
						printf("\n\t 2.  发布项目通知 \n");
						printf("\n\t 3.  发布公告 \n");
						printf("\n\t 4.  返回上一级 \n");
						if (scanf("%d", &type) == 1 && (type <= 4 && type >= 1))
							break;
						else
							printf("\n\t 您的输入有误，请重新输入\n");
					}
					if (type == 1)
					{
						long id;
						printf("\n\t请输入被通知用户的id(必须大于10000)\n");
						scanf("%ld", &id);
						if (id > 10000)
						{
							printf("\n\t请输入通知\n");
							char msg[300];
							scanf("%s", &msg);
							int state = Person_notice(id, msg);
							if (state == 0)printf("\n\t通知成功\n");
							else
							{
								printf("\n\t打开文件失败\n");
							}
						}
						else
						{
							printf("\n\t输入id非法\n");
						}
					}
					else if (type == 2)
					{
						long id;
						printf("\n\t请输入项目的id(1000-9999)\n");
						scanf("%ld", &id);
						if (id >= 1000 && id <= 9999)
						{
							if (Event_had(id) == 0) printf("\n\t不存在此项目\n");
							else
							{
								int match = 0, i = 0;
								printf("\n\t请选择此时的比赛阶段 1.预赛 2.决赛\n");
								scanf("%d", match);
								SportsEvent eve;
								eve = Event_getinfo(id);
								if (match == 1)
								{
									long prePersonid[100];
									for (int i = 0; i <= 100; i++)
										prePersonid[i] = eve.prePerson[i].id;
									printf("\n\t请输入通知\n");
									char* msg;
									scanf("%s", &msg);
									int state;
									for (int i = 0; i <= 100; i++)
									{
										state = Person_notice(prePersonid[i], msg);
									}
									if (state == 0)printf("\n\t通知成功\n");
									else
									{
										printf("\n\t打开文件失败\n");
									}
								}
								else
								{
									if (match == 2)
									{
										long finPersonid[20];
										for (int i = 0; i <= 20; i++)
											finPersonid[i] = eve.finPerson[i].id;
										printf("\n\t请输入通知\n");
										char* msg;
										scanf("%s", &msg);
										int state;
										for (int i = 0; i <= 20; i++)
										{
											state = Person_notice(finPersonid[i], msg);
										}
										if (state == 0)printf("\n\t通知成功\n");
										else
										{
											printf("\n\t打开文件失败\t");
										}
									}
									else printf("\n\t输入错误\n");
								}
							}
						}
						else
						{
							printf("\n\t输入id非法\n");
						}
					}
					else if (type == 3)
					{
						printf("\n\t请输入通知\t");
						char msg[300];
						scanf("%s", &msg);
						int state = Person_notice(10000, msg);
						if (state == 0)printf("\n\t通知成功\n");
						else
						{
							printf("\n\t打开文件失败\n");
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
						printf("\n\t 1.  修改项目 \n");
						printf("\n\t 2.  增加项目 \n");
						printf("\n\t 3.  减少项目\n");
						printf("\n\t 4.  锁定报名 \n");
						printf("\n\t 5.  开放报名 \n");
						printf("\n\t 6.  返回上一级\n\n");
						scanf("%d", &type);
						if (type <= 6 && type >= 1)
							break;
						else
							printf("\t 您的输入有误，请重新输入\n");
					}
					if (type == 1)
					{
						changeEventInfo();
					}
					else if (type == 2)
					{
						clearScreen(400);
						char name[20];
						int type;//10男田、11男径、20女田、21女径
						char place[20];//场地
						int timecost;//用时，分钟
						int hasFinals = 0;//有无决赛 0无 1有
						printf("\t请输入新项目的名称\n");
						scanf("%s", &name);
						printf("\t请输入此项目类别（男子田赛输入10，径赛输入11，女子田赛输入20，径赛输入21）\n");
						scanf("%d", &type);
						printf("\t请输入此项目的场地\n");
						scanf("%s", &place);
						printf("\t请输入此项目的用时\n");
						scanf("%d", &timecost);
						printf("\t有无决赛（1.有 2.无）\n");
						scanf("%d", &hasFinals);
						SportsEvent msg;
						strcpy(msg.name, name);
						msg.type = type;
						strcpy(msg.place, place);
						msg.timecost = timecost;
						msg.hasFinals = hasFinals;
						int state = Event_create(msg);
						if (state == 1)
							printf("\n\t名字输入错误\n");
						else if (state == 3)
							printf("\n\t田径类别输入错误\n");
						else if (state == 4)
							printf("\n\t场地输入错误\n");
						else if (state == 5)
							printf("\n\t用时输入错误\n");
						if (state == 7)
							printf("\n\t有无决赛输入错误\n");
						else if (state == 10)
							printf("\n\t太多项目\n");
						else printf("\n\t创建成功\n");
					}
					else if (type == 3)
					{
						long id = -1;
						int state;
						printf("\n\t请输入需要删除的项目的ID\n");
						scanf("%ld", &id);
						state = Event_delete(id);
						if (state == 1)
							printf("\n\t此项目不能删除\n");
						else if (state == 2)
							printf("\n此项目不存在\t\n");
						else if (state == 3)
							printf("\n\t删除失败\n");
					}
					else if (type == 4)
					{
						sys_changecj(0);
						printf("\n\t报名已锁定\n");
					}
					else if (type == 5)
					{
						sys_changecj(1);
						printf("\n\t报名已开放\n");
					}
				} while (type != 6);
				break;
			case 4:
				do
				{
					while (1)
					{
						clearScreen(400);
						printf("目前院\n");
						for (int i = 0; i < sys_info.numyuan; i++)
						{
							printf("\t%s\n", sys_info.yuan[i]);
						}
						printf("目前系\n");
						for (int i = 0; i < sys_info.numxi; i++)
						{
							printf("\t%s\n", sys_info.xi[i]);
						}
						printf("\n\t 1.  增加院 \n");
						printf("\n\t 2.  减少院 \n");
						printf("\n\t 3.  增加系\n");
						printf("\n\t 4.  减少系 \n");
						printf("\n\t 5.  返回上一级\n\n");
						scanf("%d", &type);
						if (type <= 5 && type >= 1)
							break;
						else
							printf("\t 您的输入有误，请重新输入\n");
					}
					if (type == 1)
					{
						printf("\n\t请输入该院的名称\n");
						char yuan[20];
						scanf("%s", yuan);
						int state = sys_incyuan(yuan);
						if (state == 0)
							printf("\n\t增加成功\n");
						else if (state == 1)
							printf("\n\t已存在\n");
						else if (state == 2)
							printf("\n\t已满员\n");
						else if (state == 3)
							printf("\n\t输入错误\n");
					}
					else if (type == 2)
					{
						printf("\n\t请输入该院的名称\n");
						char yuan[20];
						scanf("%s", yuan);
						int state = sys_decyuan(yuan);
						if (state == 0)
							printf("\n\t减少成功\n");
						else if (state == 1)
							printf("\n\t学院数目为0\n");
						else if (state == 2)
							printf("\n\t不存在该学院\n");
						else if (state == 3)
							printf("\n\t输入错误\n");
					}
					else if (type == 3)
					{
						printf("\n\t请输入该系的名称\n");
						char xi[20];
						scanf("%s", xi);
						int state = sys_incxi(xi);
						if (state == 0)
							printf("\n\t增加成功\n");
						else if (state == 1)
							printf("\n\t已存在该系\n");
						else if (state == 2)
							printf("\n\t已满员\n");
						else if (state == 3)
							printf("\n\t输入错误\n");
					}
					else if (type == 4)
					{
						printf("\n\t请输入该系的名称\n");
						char xi[20];
						scanf("%s", xi);
						int state = sys_decxi(xi);
						if (state == 0)
							printf("\n\t减少成功\n");
						else if (state == 1)
							printf("\n\t不存在该系\n");
						else if (state == 2)
							printf("\n\t不存在该系\n");
						else if (state == 3)
							printf("\n\t输入错误\n");
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