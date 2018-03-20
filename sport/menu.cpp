#include "stdafx.h";
int toYuanMsgMenu(){
	clearScreen(100);
	printf("\n书院信息\n");
	int count,o,p,i,rank;
	PerInfo peo;
	SportsEvent* eve;
	joinevent* joineve;
	eve = (SportsEvent *)malloc(sys_info.eve*sizeof(SportsEvent));//项目列表
	Event_getlist(eve);
	for(p=0;p<20;p++){
		if(strcmp(sys_info.yuan[p],"-")!=0){//存在院，院名sys_info.yuan[p]
			printf("[%s]\n",sys_info.yuan[p]);
			if(sys_info.peo==0){
				count=0;
			}else{
				joineve=(joinevent *)malloc(sys_info.eve*sizeof(joinevent));//要列出的信息数组 项目名、预赛人数、决赛人数、得分
				for(o=0;o<sys_info.eve;o++){//比赛项目名：eve[o]
					//初始化joineve
					strcpy(joineve[o].evename,eve[o].name);joineve[o].joinnum=joineve[o].joinenum=joineve[o].score=0;
					printf("%s",joineve[o].evename);
					if(eve[o].maxpeople<4){//不足4人，项目取消
						printf("[已取消]");
					}else{//存在比赛
						qsort(eve[o].prePerson, 100, sizeof(Participant), cmp);//小到大
						
						if (eve[o].type % 2){ //径赛，比小
							puts("\t径赛\n");
							for (i=0,rank=0;i<100;i++){//检查预赛每个人
								if(eve[o].prePerson[i].id == 0) continue;
								rank++;
								//printf("\n%d-",rank);
								peo=Person_getinfo(eve[o].prePerson[i].id);
								//printf("%d:",peo.id);
								if(!strcmp(peo.organization,sys_info.yuan[p])){//同一个院
									joineve[o].joinnum++;
									if(eve[o].prePerson[i].score){//有成绩
										if(!eve[o].hasFinals){//没有决赛
											if(rank<6 && eve[o].maxpeople>6)printf("一轮排名：%d %s 成绩：%d\n",rank,peo.name,eve[o].prePerson[i].score);
											else if(rank<4 && eve[o].maxpeople>3)printf("一轮排名：%d %s 成绩：%d\n",rank,peo.name,eve[o].prePerson[i].score);
											if(eve[o].maxpeople>6){
												switch(rank){//多于6人加分
													case 1:
														joineve[o].score+=7;break;
													case 2:
														joineve[o].score+=5;break;
													case 3:
														joineve[o].score+=3;break;
													case 4:
														joineve[o].score+=2;break;
													case 5:
														joineve[o].score+=1;break;
													default:
														break;
												}
											}else{//4-6人加分
												switch(rank){//多于6人加分
													case 1:
														joineve[o].score+=5;break;
													case 2:
														joineve[o].score+=3;break;
													case 3:
														joineve[o].score+=2;break;
													default:
														break;
												}
											}
										}
									}
								}
								
							}
							if(eve[o].hasFinals){//决赛
								qsort(eve[o].finPerson, 20, sizeof(Participant), cmp);//小到大
								for (i=0,rank=0;i<20;i++){//检查决赛每个人
									if(eve[o].finPerson[i].id == 0) continue;
									rank++;
									peo=Person_getinfo(eve[o].finPerson[i].id);
									if(!strcmp(peo.organization,sys_info.yuan[p])){//同一个院
										joineve[o].joinenum++;
										if(eve[o].finPerson[i].score){//有成绩
											if(rank<6 && eve[o].maxpeople>6)printf("决赛排名：%d %s 成绩：%d\n",rank,peo.name,eve[o].finPerson[i].score);
											else if(rank<4 && eve[o].maxpeople>3)printf("决赛排名：%d %s 成绩：%d\n",rank,peo.name,eve[o].finPerson[i].score);
											if(eve[o].maxpeople>6){
													switch(rank){//多于6人加分
														case 1:
															joineve[o].score+=7;break;
														case 2:
															joineve[o].score+=5;break;
														case 3:
															joineve[o].score+=3;break;
														case 4:
															joineve[o].score+=2;break;
														case 5:
															joineve[o].score+=1;break;
														default:
															break;
													}
												}else{//4-6人加分
													switch(rank){//多于6人加分
														case 1:
															joineve[o].score+=5;break;
														case 2:
															joineve[o].score+=3;break;
														case 3:
															joineve[o].score+=2;break;
														default:
															break;
													}
												}
											}
										}
									}

								}
							

						}else{//田赛，比大
							puts("\t田赛\n");
							for (i=99,rank=0;i>=0;i--){//检查预赛每个人
								if(eve[o].prePerson[i].id == 0) continue;
								rank++;
								peo=Person_getinfo(eve[o].prePerson[i].id);
								if(!strcmp(peo.organization,sys_info.yuan[p])){//同一个院
									
									joineve[o].joinnum++;
									if(eve[o].prePerson[i].score){//有成绩
										if(!eve[o].hasFinals){//没有决赛
											if(rank<6 && eve[o].maxpeople>6)printf("一轮排名：%d %s 成绩：%d米%d厘米\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											else if(rank<4 && eve[o].maxpeople>3)printf("一轮排名：%d %s 成绩：%d米%d厘米\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											if(eve[o].maxpeople>6){
												switch(rank){//多于6人加分
													case 1:
														joineve[o].score+=7;break;
													case 2:
														joineve[o].score+=5;break;
													case 3:
														joineve[o].score+=3;break;
													case 4:
														joineve[o].score+=2;break;
													case 5:
														joineve[o].score+=1;break;
													default:
														break;
												}
											}else{//4-6人加分
												switch(rank){//多于6人加分
													case 1:
														joineve[o].score+=5;break;
													case 2:
														joineve[o].score+=3;break;
													case 3:
														joineve[o].score+=2;break;
													default:
														break;
												}
											}
										}
									}
								}

							}
							if(eve[o].hasFinals){//决赛
								qsort(eve[o].finPerson, 20, sizeof(Participant), cmp);//小到大
								for (i=19,rank=0;i>=0;i--){//检查决赛每个人
									if(eve[o].finPerson[i].id == 0) continue;
									rank++;
									peo=Person_getinfo(eve[o].finPerson[i].id);
									if(!strcmp(peo.organization,sys_info.yuan[p])){//同一个院
										joineve[o].joinenum++;
										if(eve[o].finPerson[i].score){//有成绩
											if(rank<6 && eve[o].maxpeople>6)printf("决赛排名：%d %s 成绩：%d米%d厘米\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											else if(rank<4 && eve[o].maxpeople>3)printf("决赛排名：%d %s 成绩：%d米%d厘米\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											if(eve[o].maxpeople>6){
													switch(rank){//多于6人加分
														case 1:
															joineve[o].score+=7;break;
														case 2:
															joineve[o].score+=5;break;
														case 3:
															joineve[o].score+=3;break;
														case 4:
															joineve[o].score+=2;break;
														case 5:
															joineve[o].score+=1;break;
														default:
															break;
													}
												}else{//4-6人加分
													switch(rank){//4人加分
														case 1:
															joineve[o].score+=5;break;
														case 2:
															joineve[o].score+=3;break;
														case 3:
															joineve[o].score+=2;break;
														default:
															break;
													}
												}
											}
									}
								}

							}
						}

					}


					printf("\n\t预赛人数：%d\t决赛人数：%d\t得分：%d\n\n\n",joineve[o].joinnum,joineve[o].joinenum,joineve[o].score);
				}
				int allscore=0;
				for (i=0;i<o;i++)allscore+=joineve[i].score;
				printf("总分：%d\n\n",allscore);
				free(joineve);
				puts("——————————————————");
			}
		}
	}
	free(eve);


	printf("\n输入任意键返回上一级");
	getchar();
	return 0;
}
int toXiMsgMenu(){
	clearScreen(100);
	puts("\n系信息\n");
	int count,o,p,i,rank;
	PerInfo peo;char buff[20]="";
	SportsEvent* eve;
	joinevent* joineve;
	eve = (SportsEvent *)malloc(sys_info.eve*sizeof(SportsEvent));//项目列表
	Event_getlist(eve);
	for(p=0;p<20;p++){
		if(strcmp(sys_info.xi[p],"-")!=0){//存在xi，xi名sys_info.xi[p]
			printf("[%s]\n",sys_info.xi[p]);
			if(sys_info.peo==0){
				count=0;
			}else{
				joineve=(joinevent *)malloc(sys_info.eve*sizeof(joinevent));//要列出的信息数组 项目名、预赛人数、决赛人数、得分
				for(o=0;o<sys_info.eve;o++){//比赛项目名：eve[o]
					//初始化joineve
					strcpy(joineve[o].evename,eve[o].name);joineve[o].joinnum=joineve[o].joinenum=joineve[o].score=0;
					printf("%s",joineve[o].evename);
					if(eve[o].maxpeople<4){//不足4人，项目取消
						printf("[已取消]");
					}else{//存在比赛
						qsort(eve[o].prePerson, 100, sizeof(Participant), cmp);//小到大
						
						if (eve[o].type % 2){ //径赛，比小
							puts("\t径赛\n");
							for (i=0,rank=0;i<100;i++){//检查预赛每个人
								if(eve[o].prePerson[i].id == 0) continue;
								rank++;
								//printf("\n%d-",rank);
								peo=Person_getinfo(eve[o].prePerson[i].id);
								//printf("%d:",peo.id);
								if(!strcmp(peo.faculty,sys_info.xi[p])){//同一个xi
									joineve[o].joinnum++;
									if(eve[o].prePerson[i].score){//有成绩
										if(!eve[o].hasFinals){//没有决赛
											scoreToChar(eve[o].prePerson[i].score,buff);
											if(rank<6 && eve[o].maxpeople>6)printf("一轮排名：%d %s 成绩：%s\n",rank,peo.name,buff);
											else if(rank<4 && eve[o].maxpeople>3)printf("一轮排名：%d %s 成绩：%s\n",rank,peo.name,buff);
											if(eve[o].maxpeople>6){
												switch(rank){//多于6人加分
													case 1:
														joineve[o].score+=7;break;
													case 2:
														joineve[o].score+=5;break;
													case 3:
														joineve[o].score+=3;break;
													case 4:
														joineve[o].score+=2;break;
													case 5:
														joineve[o].score+=1;break;
													default:
														break;
												}
											}else{//4-6人加分
												switch(rank){//多于6人加分
													case 1:
														joineve[o].score+=5;break;
													case 2:
														joineve[o].score+=3;break;
													case 3:
														joineve[o].score+=2;break;
													default:
														break;
												}
											}
										}
									}
								}
								
							}
							if(eve[o].hasFinals){//决赛
								qsort(eve[o].finPerson, 20, sizeof(Participant), cmp);//小到大
								for (i=0,rank=0;i<20;i++){//检查决赛每个人
									if(eve[o].finPerson[i].id == 0) continue;
									rank++;
									peo=Person_getinfo(eve[o].finPerson[i].id);
									if(!strcmp(peo.faculty,sys_info.xi[p])){//同一个xi
										joineve[o].joinenum++;
										if(eve[o].finPerson[i].score){//有成绩
											scoreToChar(eve[o].prePerson[i].score,buff);
											if(rank<6 && eve[o].maxpeople>6)printf("决赛排名：%d %s 成绩：%s\n",rank,peo.name,buff);
											else if(rank<4 && eve[o].maxpeople>3)printf("决赛排名：%d %s 成绩：%s\n",rank,peo.name,buff);
											if(eve[o].maxpeople>6){
													switch(rank){//多于6人加分
														case 1:
															joineve[o].score+=7;break;
														case 2:
															joineve[o].score+=5;break;
														case 3:
															joineve[o].score+=3;break;
														case 4:
															joineve[o].score+=2;break;
														case 5:
															joineve[o].score+=1;break;
														default:
															break;
													}
												}else{//4-6人加分
													switch(rank){//多于6人加分
														case 1:
															joineve[o].score+=5;break;
														case 2:
															joineve[o].score+=3;break;
														case 3:
															joineve[o].score+=2;break;
														default:
															break;
													}
												}
											}
										}
									}

								}
							

						}else{//田赛，比大
							puts("\t田赛\n");
							for (i=99,rank=0;i>=0;i--){//检查预赛每个人
								if(eve[o].prePerson[i].id == 0) continue;
								rank++;
								peo=Person_getinfo(eve[o].prePerson[i].id);
								if(!strcmp(peo.faculty,sys_info.xi[p])){//同一个xi
									
									joineve[o].joinnum++;
									if(eve[o].prePerson[i].score){//有成绩
										if(!eve[o].hasFinals){//没有决赛
											if(rank<6 && eve[o].maxpeople>6)printf("一轮排名：%d %s 成绩：%d米%d厘米\n",rank,peo.name,eve[o].prePerson[i].score/100,eve[o].prePerson[i].score%100);
											else if(rank<4 && eve[o].maxpeople>3)printf("一轮排名：%d %s 成绩：%d米%d厘米\n",rank,peo.name,eve[o].prePerson[i].score/100,eve[o].prePerson[i].score%100);
											if(eve[o].maxpeople>6){
												switch(rank){//多于6人加分
													case 1:
														joineve[o].score+=7;break;
													case 2:
														joineve[o].score+=5;break;
													case 3:
														joineve[o].score+=3;break;
													case 4:
														joineve[o].score+=2;break;
													case 5:
														joineve[o].score+=1;break;
													default:
														break;
												}
											}else{//4-6人加分
												switch(rank){//多于6人加分
													case 1:
														joineve[o].score+=5;break;
													case 2:
														joineve[o].score+=3;break;
													case 3:
														joineve[o].score+=2;break;
													default:
														break;
												}
											}
										}
									}
								}

							}
							if(eve[o].hasFinals){//决赛
								qsort(eve[o].finPerson, 20, sizeof(Participant), cmp);//小到大
								for (i=19,rank=0;i>=0;i--){//检查决赛每个人
									if(eve[o].finPerson[i].id == 0) continue;
									rank++;
									peo=Person_getinfo(eve[o].finPerson[i].id);
									if(!strcmp(peo.faculty,sys_info.xi[p])){//同一个xi
										joineve[o].joinenum++;
										if(eve[o].finPerson[i].score){//有成绩
											if(rank<6 && eve[o].maxpeople>6)printf("决赛排名：%d %s 成绩：%d米%d厘米\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											else if(rank<4 && eve[o].maxpeople>3)printf("决赛排名：%d %s 成绩：%d米%d厘米\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											if(eve[o].maxpeople>6){
													switch(rank){//多于6人加分
														case 1:
															joineve[o].score+=7;break;
														case 2:
															joineve[o].score+=5;break;
														case 3:
															joineve[o].score+=3;break;
														case 4:
															joineve[o].score+=2;break;
														case 5:
															joineve[o].score+=1;break;
														default:
															break;
													}
												}else{//4-6人加分
													switch(rank){//4人加分
														case 1:
															joineve[o].score+=5;break;
														case 2:
															joineve[o].score+=3;break;
														case 3:
															joineve[o].score+=2;break;
														default:
															break;
													}
												}
											}
									}
								}

							}
						}

					}


					printf("\n\t预赛人数：%d\t决赛人数：%d\t得分：%d\n",joineve[o].joinnum,joineve[o].joinenum,joineve[o].score);
				}
				int allscore=0;
				for (i=0;i<o;i++)allscore+=joineve[i].score;
				printf("总分：%d\n\n",allscore);
				free(joineve);
				puts("——————————————————");
			}
		}
	}
	free(eve);
	puts("输入任意键返回上一级");
	getchar();
	return 0;
}
int toSportMsgMenu(){
	clearScreen(100);
	puts("运动员信息");
	long id,i;
	while(1){
		printf("\n\t请输入学号（ID）：");
		scanf("%ld", &id);
		if(Person_had(id)){
			userSignupedEve(id,1);
		}else{
			printf("\n\t请输入学号（ID）不存在\n1：重新输入\n2：返回上级\n");
			if (scanf("%d", &i) == 1 && i!=1)break;
		}
	}
	
	//puts("输入任意键返回上一级");
	//getchar();
	return 0;
}
int toEventMsgMenu(){
	clearScreen(100);
	puts("项目信息");
	int rank,i,o;
	SportsEvent* eve;PerInfo peo;char buff[20];
	eve = (SportsEvent *)malloc(sys_info.eve*sizeof(SportsEvent));//项目列表
	Event_getlist(eve);
	for(o=0;o<sys_info.eve;o++){
		printf("\n\n\n%s",eve[o].name);
		if(eve[o].type % 2){//径
			printf("\t径赛\n");
			for (i = 0, rank = 0; i < 100; i++) { //检查预赛每个人
				if (eve[o].prePerson[i].id == 0)
					continue;
				
				//printf("\n%d-",rank);
				peo = Person_getinfo(eve[o].prePerson[i].id);
				if (eve[o].prePerson[i].score) {
					rank++;
					scoreToChar(eve[o].prePerson[i].score,buff);
					if (rank < 6 && eve[o].maxpeople > 6)printf("一轮排名：%d %s 成绩：%s\n", rank, peo.name, buff);
						else if (rank < 4 && eve[o].maxpeople > 3)printf("一轮排名：%d %s 成绩：%s\n", rank, peo.name, buff);
				}
			}
			if (eve[o].hasFinals) { //决赛
				qsort(eve[o].finPerson, 20, sizeof(Participant), cmp); //小到大
				for (i = 0, rank = 0; i < 20; i++) { //检查决赛每个人
					if (eve[o].finPerson[i].id == 0)
						continue;
					
					peo = Person_getinfo(eve[o].finPerson[i].id);
					if (eve[o].finPerson[i].score) {
						rank++;
						scoreToChar(eve[o].finPerson[i].score,buff);
						if (rank < 6 && eve[o].maxpeople > 6)printf("决赛排名：%d %s 成绩：%s\n", rank, peo.name, buff);
							else if (rank < 4 && eve[o].maxpeople > 3)printf("决赛排名：%d %s 成绩：%s\n", rank, peo.name, buff);
					}
				}
			}
		}else{
			printf("\t田赛\n");
			for (i = 0, rank = 0; i < 100; i++) { //检查预赛每个人
				if (eve[o].prePerson[i].id == 0)
					continue;
				
				//printf("\n%d-",rank);
				peo = Person_getinfo(eve[o].prePerson[i].id);
				if (eve[o].prePerson[i].score) {
					rank++;
					if (rank < 6 && eve[o].maxpeople > 6)printf("一轮排名：%d %s 成绩：%d米%d厘米\n", rank, peo.name, eve[o].prePerson[i].score / 100, eve[o].prePerson[i].score % 100);
						else if (rank < 4 && eve[o].maxpeople > 3)printf("一轮排名：%d %s 成绩：%d米%d厘米\n", rank, peo.name, eve[o].prePerson[i].score / 100, eve[o].prePerson[i].score % 100);
				}
			}
			if (eve[o].hasFinals) { //决赛
				qsort(eve[o].finPerson, 20, sizeof(Participant), cmp); //小到大
				for (i = 0, rank = 0; i < 20; i++) { //检查决赛每个人
					if (eve[o].finPerson[i].id == 0)
						continue;
					
					peo = Person_getinfo(eve[o].finPerson[i].id);
					if (eve[o].finPerson[i].score) {
						rank++;
						if (rank < 6 && eve[o].maxpeople > 6)printf("决赛排名：%d %s 成绩：%d米%d厘米\n", rank, peo.name, eve[o].finPerson[i].score / 100, eve[o].prePerson[i].score % 100);
							else if (rank < 4 && eve[o].maxpeople > 3)printf("决赛排名：%d %s 成绩：%d米%d厘米\n", rank, peo.name, eve[o].finPerson[i].score / 100, eve[o].prePerson[i].score % 100);
					}
				}
			}
		}
		if(!rank)printf("\n\t[无成绩]\n\n");
	}
	free(eve);
	puts("输入任意键返回上一级");
	getchar();
	return 0;
}
int toSituationMenu(){//比赛情况
	//clearScreen(100);
	int choice=0,i=1;
	while(1){
		while (1)
		{
			clearScreen(1000);
			printf("\n\t\t\t 1. 书院信息");
			printf("\n\t\t\t 2. 系信息");
			printf("\n\t\t\t 3. 运动员信息");
			printf("\n\t\t\t 4. 项目信息");
			printf("\n\t\t\t 5. 返回上级\n\n");
			if (scanf("%d", &choice) == 1 && (choice <= 5 && choice >= 1))
				break;
			else
				printf("\t\t\t 您的输入有误，请重新输入");
			
		}
		fflush(stdin);
		switch (choice){
			case 1:
				toYuanMsgMenu();
				break;
			case 2:
				toXiMsgMenu();
				break;
			case 3:
				toSportMsgMenu();
				break;
			case 4:
				toEventMsgMenu();
				break;
			default:
				return 1;
		}
	}
}
int toLoginMenu(int type)//type现在都输入1
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
		//printf("\n\n 你输入的id是 %ld \n", id);
		//printf("\n 你输入的passw是 %s \n\n", password);

		int i=login(id, password, type);
		switch(i){
			case 1://管理员
				printf("\n 管理员登录成功 \n");
				printf("\n 请稍候，页面正在跳转中 ......");
				return adminMenu();
			case 2://用户;
				printf("\n 用户登录成功 \n");
				printf("\n 请稍候，页面正在跳转中 ......");
				return userMenu(id);
			case 0://密码错误
				int choice;
				printf("\n 账号或密码错误\n");
				printf("\n 1. 重新输入 \n");
				printf("\n 2. 返回上一步 \n");
				printf("\n 3. 退出系统（除1, 2以外的键） \n\n");
				scanf("%d", &choice);
				if (choice == 1)
				{
					printf("\n 请稍候，页面正在跳转中 ......");
					clearScreen(1000);
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
	printf("\n\n\n\n");
	Person_mynotice();
	printf("\n\n\n\n");
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
			clearScreen(100);
			printf("\n\t 1.  登录 \n");
			printf("\n\t 2.  注册 \n");
			printf("\n\t 3.  查看秩序册 \n");
			printf("\n\t 4.  比赛信息 \n");
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
				isRetLast = 1;
				break;
			case 3:

				break;
			case 4:
				isRetLast=toSituationMenu();
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