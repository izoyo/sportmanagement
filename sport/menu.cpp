#include "stdafx.h";
int toYuanMsgMenu(){
	clearScreen(100);
	printf("\n��Ժ��Ϣ\n");
	int count,o,p,i,rank;
	PerInfo peo;
	SportsEvent* eve;
	joinevent* joineve;
	eve = (SportsEvent *)malloc(sys_info.eve*sizeof(SportsEvent));//��Ŀ�б�
	Event_getlist(eve);
	for(p=0;p<20;p++){
		if(strcmp(sys_info.yuan[p],"-")!=0){//����Ժ��Ժ��sys_info.yuan[p]
			printf("[%s]\n",sys_info.yuan[p]);
			if(sys_info.peo==0){
				count=0;
			}else{
				joineve=(joinevent *)malloc(sys_info.eve*sizeof(joinevent));//Ҫ�г�����Ϣ���� ��Ŀ����Ԥ�������������������÷�
				for(o=0;o<sys_info.eve;o++){//������Ŀ����eve[o]
					//��ʼ��joineve
					strcpy(joineve[o].evename,eve[o].name);joineve[o].joinnum=joineve[o].joinenum=joineve[o].score=0;
					printf("%s",joineve[o].evename);
					if(eve[o].maxpeople<4){//����4�ˣ���Ŀȡ��
						printf("[��ȡ��]\n\n");
					}else{//���ڱ���
						qsort(eve[o].prePerson, 100, sizeof(Participant), cmp);//С����
						
						if (eve[o].type % 2){ //��������С
							printf("\t����\n");
							for (i=0,rank=0;i<100;i++){//���Ԥ��ÿ����
								if(eve[o].prePerson[i].id == 0) continue;
								rank++;
								//printf("\n%d-",rank);
								peo=Person_getinfo(eve[o].prePerson[i].id);
								//printf("%d:",peo.id);
								if(!strcmp(peo.organization,sys_info.yuan[p])){//ͬһ��Ժ
									joineve[o].joinnum++;
									if(eve[o].prePerson[i].score){//�гɼ�
										if(!eve[o].hasFinals){//û�о���
											if(rank<6 && eve[o].maxpeople>6)printf("\t������%d %s �ɼ���%d\n",rank,peo.name,eve[o].prePerson[i].score);
											else if(rank<4 && eve[o].maxpeople>3)printf("\t������%d %s �ɼ���%d\n",rank,peo.name,eve[o].prePerson[i].score);
											if(eve[o].maxpeople>6){
												switch(rank){//����6�˼ӷ�
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
											}else{//4-6�˼ӷ�
												switch(rank){//����6�˼ӷ�
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
							if(eve[o].hasFinals){//����
								qsort(eve[o].finPerson, 20, sizeof(Participant), cmp);//С����
								for (i=0,rank=0;i<20;i++){//������ÿ����
									if(eve[o].finPerson[i].id == 0) continue;
									rank++;
									peo=Person_getinfo(eve[o].finPerson[i].id);
									if(!strcmp(peo.organization,sys_info.yuan[p])){//ͬһ��Ժ
										joineve[o].joinenum++;
										if(eve[o].finPerson[i].score){//�гɼ�
											if(rank<6 && eve[o].maxpeople>6)printf("\t������%d %s �ɼ���%d\n",rank,peo.name,eve[o].finPerson[i].score);
											else if(rank<4 && eve[o].maxpeople>3)printf("\t������%d %s �ɼ���%d\n",rank,peo.name,eve[o].finPerson[i].score);
											if(eve[o].maxpeople>6){
													switch(rank){//����6�˼ӷ�
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
												}else{//4-6�˼ӷ�
													switch(rank){//����6�˼ӷ�
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
							

						}else{//�������ȴ�
							printf("\t����\n");
							for (i=99,rank=0;i>=0;i--){//���Ԥ��ÿ����
								if(eve[o].prePerson[i].id == 0) continue;
								rank++;
								peo=Person_getinfo(eve[o].prePerson[i].id);
								if(!strcmp(peo.organization,sys_info.yuan[p])){//ͬһ��Ժ
									
									joineve[o].joinnum++;
									if(eve[o].prePerson[i].score){//�гɼ�
										if(!eve[o].hasFinals){//û�о���
											if(rank<6 && eve[o].maxpeople>6)printf("\t������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											else if(rank<4 && eve[o].maxpeople>3)printf("\t������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											if(eve[o].maxpeople>6){
												switch(rank){//����6�˼ӷ�
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
											}else{//4-6�˼ӷ�
												switch(rank){//����6�˼ӷ�
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
							if(eve[o].hasFinals){//����
								qsort(eve[o].finPerson, 20, sizeof(Participant), cmp);//С����
								for (i=19,rank=0;i>=0;i--){//������ÿ����
									if(eve[o].finPerson[i].id == 0) continue;
									rank++;
									peo=Person_getinfo(eve[o].finPerson[i].id);
									if(!strcmp(peo.organization,sys_info.yuan[p])){//ͬһ��Ժ
										joineve[o].joinenum++;
										if(eve[o].finPerson[i].score){//�гɼ�
											if(rank<6 && eve[o].maxpeople>6)printf("\t������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											else if(rank<4 && eve[o].maxpeople>3)printf("\t������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											if(eve[o].maxpeople>6){
													switch(rank){//����6�˼ӷ�
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
												}else{//4-6�˼ӷ�
													switch(rank){//4�˼ӷ�
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
					if(eve[o].maxpeople>=4)
					if(eve[o].hasFinals) printf("\tԤ��������%d\t����������%d\t�÷֣�%d\n\n",joineve[o].joinnum,joineve[o].joinenum,joineve[o].score);
					else printf("\tһ��������%d\t�÷֣�%d\n\n\n",joineve[o].joinnum,joineve[o].score);

					
				}
				int allscore=0;
				for (i=0;i<o;i++)allscore+=joineve[i].score;
				printf("�ܷ֣�%d\n\n",allscore);
				free(joineve);
				printf("������������������������������������");
			}
		}
	}
	free(eve);


	printf("\n���������������һ��");
	getchar();
	return 0;
}
int toXiMsgMenu(){
	clearScreen(100);
	printf("\nϵ��Ϣ\n");
	int count,o,p,i,rank;
	PerInfo peo;char buff[20]="";
	SportsEvent* eve;
	joinevent* joineve;
	eve = (SportsEvent *)malloc(sys_info.eve*sizeof(SportsEvent));//��Ŀ�б�
	Event_getlist(eve);
	for(p=0;p<20;p++){
		if(strcmp(sys_info.xi[p],"-")!=0){//����xi��xi��sys_info.xi[p]
			printf("[%s]\n",sys_info.xi[p]);
			if(sys_info.peo==0){
				count=0;
			}else{
				joineve=(joinevent *)malloc(sys_info.eve*sizeof(joinevent));//Ҫ�г�����Ϣ���� ��Ŀ����Ԥ�������������������÷�
				for(o=0;o<sys_info.eve;o++){//������Ŀ����eve[o]
					//��ʼ��joineve
					strcpy(joineve[o].evename,eve[o].name);joineve[o].joinnum=joineve[o].joinenum=joineve[o].score=0;
					printf("%s",joineve[o].evename);
					if(eve[o].maxpeople<4){//����4�ˣ���Ŀȡ��
						printf("[��ȡ��]\n\n");
					}else{//���ڱ���
						qsort(eve[o].prePerson, 100, sizeof(Participant), cmp);//С����
						
						if (eve[o].type % 2){ //��������С
							printf("\t����\n");
							for (i=0,rank=0;i<100;i++){//���Ԥ��ÿ����
								if(eve[o].prePerson[i].id == 0) continue;
								rank++;
								//printf("\n%d-",rank);
								peo=Person_getinfo(eve[o].prePerson[i].id);
								//printf("%d:",peo.id);
								if(!strcmp(peo.faculty,sys_info.xi[p])){//ͬһ��xi
									joineve[o].joinnum++;
									if(eve[o].prePerson[i].score){//�гɼ�
										if(!eve[o].hasFinals){//û�о���
											scoreToChar(eve[o].prePerson[i].score,buff);
											if(rank<6 && eve[o].maxpeople>6)printf("\t������%d %s �ɼ���%s\n",rank,peo.name,buff);
											else if(rank<4 && eve[o].maxpeople>3)printf("\t������%d %s �ɼ���%s\n",rank,peo.name,buff);
											if(eve[o].maxpeople>6){
												switch(rank){//����6�˼ӷ�
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
											}else{//4-6�˼ӷ�
												switch(rank){//����6�˼ӷ�
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
							if(eve[o].hasFinals){//����
								qsort(eve[o].finPerson, 20, sizeof(Participant), cmp);//С����
								for (i=0,rank=0;i<20;i++){//������ÿ����
									if(eve[o].finPerson[i].id == 0) continue;
									rank++;
									peo=Person_getinfo(eve[o].finPerson[i].id);
									if(!strcmp(peo.faculty,sys_info.xi[p])){//ͬһ��xi
										joineve[o].joinenum++;
										if(eve[o].finPerson[i].score){//�гɼ�
											scoreToChar(eve[o].prePerson[i].score,buff);
											if(rank<6 && eve[o].maxpeople>6)printf("\t������%d %s �ɼ���%s\n",rank,peo.name,buff);
											else if(rank<4 && eve[o].maxpeople>3)printf("\t������%d %s �ɼ���%s\n",rank,peo.name,buff);
											if(eve[o].maxpeople>6){
													switch(rank){//����6�˼ӷ�
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
												}else{//4-6�˼ӷ�
													switch(rank){//����6�˼ӷ�
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
							

						}else{//�������ȴ�
							printf("\t����\n");
							for (i=99,rank=0;i>=0;i--){//���Ԥ��ÿ����
								if(eve[o].prePerson[i].id == 0) continue;
								rank++;
								peo=Person_getinfo(eve[o].prePerson[i].id);
								if(!strcmp(peo.faculty,sys_info.xi[p])){//ͬһ��xi
									
									joineve[o].joinnum++;
									if(eve[o].prePerson[i].score){//�гɼ�
										if(!eve[o].hasFinals){//û�о���
											if(rank<6 && eve[o].maxpeople>6)printf("\t������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].prePerson[i].score/100,eve[o].prePerson[i].score%100);
											else if(rank<4 && eve[o].maxpeople>3)printf("\t������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].prePerson[i].score/100,eve[o].prePerson[i].score%100);
											if(eve[o].maxpeople>6){
												switch(rank){//����6�˼ӷ�
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
											}else{//4-6�˼ӷ�
												switch(rank){//����6�˼ӷ�
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
							if(eve[o].hasFinals){//����
								qsort(eve[o].finPerson, 20, sizeof(Participant), cmp);//С����
								for (i=19,rank=0;i>=0;i--){//������ÿ����
									if(eve[o].finPerson[i].id == 0) continue;
									rank++;
									peo=Person_getinfo(eve[o].finPerson[i].id);
									if(!strcmp(peo.faculty,sys_info.xi[p])){//ͬһ��xi
										joineve[o].joinenum++;
										if(eve[o].finPerson[i].score){//�гɼ�
											if(rank<6 && eve[o].maxpeople>6)printf("\t������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											else if(rank<4 && eve[o].maxpeople>3)printf("\t������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											if(eve[o].maxpeople>6){
													switch(rank){//����6�˼ӷ�
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
												}else{//4-6�˼ӷ�
													switch(rank){//4�˼ӷ�
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


					if(eve[o].maxpeople>=4)
					if(eve[o].hasFinals) printf("\tԤ��������%d\t����������%d\t�÷֣�%d\n\n",joineve[o].joinnum,joineve[o].joinenum,joineve[o].score);
					else printf("\tһ��������%d\t�÷֣�%d\n\n",joineve[o].joinnum,joineve[o].score);
				}
				int allscore=0;
				for (i=0;i<o;i++)allscore+=joineve[i].score;
				printf("�ܷ֣�%d\n\n",allscore);
				free(joineve);
				printf("������������������������������������");
			}
		}
	}
	free(eve);
	puts("���������������һ��");
	getchar();
	return 0;
}
int userSignupedEve2(long id, int type)
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

	return count;
}
int toSportMsgMenu(){
	clearScreen(100);
	puts("�˶�Ա��Ϣ");
	long id,i;
	while(1){
		printf("\n\t������ѧ�ţ�����2�����ϼ�����");
		scanf("%ld", &id);
		if(id==2)break;
		if(Person_had(id)){
			userSignupedEve2(id,1);
		}else{
			printf("\n\t������ѧ�ţ�ID��������\n1����������\n2�������ϼ�\n");
			if (scanf("%d", &i) == 1 && i!=1)break;
		}
	}
	
	//puts("���������������һ��");
	//getchar();
	return 0;
}
int toEventMsgMenu(){
	clearScreen(100);
	puts("��Ŀ��Ϣ");
	int rank,i,o;
	SportsEvent* eve;PerInfo peo;char buff[20];
	eve = (SportsEvent *)malloc(sys_info.eve*sizeof(SportsEvent));//��Ŀ�б�
	Event_getlist(eve);
	for(o=0;o<sys_info.eve;o++){
		printf("\n%s",eve[o].name);
		rank=0;
		if(eve[o].maxpeople>=4)
		if(eve[o].type % 2){//��
			printf("\t����\n");
			if (eve[o].hasFinals) { //����
				qsort(eve[o].finPerson, 20, sizeof(Participant), cmp); //С����
				for (i = 0, rank = 0; i < 20; i++) { //������ÿ����
					if (eve[o].finPerson[i].id == 0)
						continue;
					peo = Person_getinfo(eve[o].finPerson[i].id);
					if (eve[o].finPerson[i].score) {
						rank++;
						scoreToChar(eve[o].finPerson[i].score,buff);
						if (rank < 6 && eve[o].maxpeople > 6)printf("������%d %s �ɼ���%s\n", rank, peo.name, buff);
							else if (rank < 4 && eve[o].maxpeople > 3)printf("����������%d %s �ɼ���%s\n", rank, peo.name, buff);
					}
				}
			}
			else for (i = 0, rank = 0; i < 100; i++) { //���Ԥ��ÿ����
				if (eve[o].prePerson[i].id == 0)
					continue;
				//printf("\n%d-",rank);
				peo = Person_getinfo(eve[o].prePerson[i].id);
				if (eve[o].prePerson[i].score) {
					rank++;
					scoreToChar(eve[o].prePerson[i].score,buff);
					if (rank < 6 && eve[o].maxpeople > 6)printf("������%d %s �ɼ���%s\n", rank, peo.name, buff);
						else if (rank < 4 && eve[o].maxpeople > 3)printf("������%d %s �ɼ���%s\n", rank, peo.name, buff);
				}
			}
		}else{
			printf("\t����\n");
			if (eve[o].hasFinals) { //����
				qsort(eve[o].finPerson, 20, sizeof(Participant), cmp); //С����
				for (i = 0, rank = 0; i < 20; i++) { //������ÿ����
					if (eve[o].finPerson[i].id == 0)
						continue;
					
					peo = Person_getinfo(eve[o].finPerson[i].id);
					if (eve[o].finPerson[i].score) {
						rank++;
						if (rank < 6 && eve[o].maxpeople > 6)printf("������%d %s �ɼ���%d��%d����\n", rank, peo.name, eve[o].finPerson[i].score / 100, eve[o].prePerson[i].score % 100);
							else if (rank < 4 && eve[o].maxpeople > 3)printf("������%d %s �ɼ���%d��%d����\n", rank, peo.name, eve[o].finPerson[i].score / 100, eve[o].prePerson[i].score % 100);
					}
				}
			}
			else for (i = 0, rank = 0; i < 100; i++) { //���Ԥ��ÿ����
				if (eve[o].prePerson[i].id == 0)
					continue;
				
				//printf("\n%d-",rank);
				peo = Person_getinfo(eve[o].prePerson[i].id);
				if (eve[o].prePerson[i].score) {
					rank++;
					if (rank < 6 && eve[o].maxpeople > 6)printf("������%d %s �ɼ���%d��%d����\n", rank, peo.name, eve[o].prePerson[i].score / 100, eve[o].prePerson[i].score % 100);
						else if (rank < 4 && eve[o].maxpeople > 3)printf("������%d %s �ɼ���%d��%d����\n", rank, peo.name, eve[o].prePerson[i].score / 100, eve[o].prePerson[i].score % 100);
				}
			}
		}
		if(eve[o].maxpeople>=4){
			if(!rank)printf("\t[���޳ɼ�]\n");
		}else{
			printf("\t[��ȡ��]\n");
		}
	}
	free(eve);
	puts("���������������һ��");
	getchar();
	return 0;
}
int toSituationMenu(){//�������
	//clearScreen(100);
	int choice=0,i=1;
	while(1){
		while (1)
		{
			clearScreen(1000);
			printf("\n\t 1. ��Ժ��Ϣ\n");
			printf("\n\t 2. ϵ��Ϣ\n");
			printf("\n\t 3. �˶�Ա��Ϣ\n");
			printf("\n\t 4. ��Ŀ��Ϣ\n");
			printf("\n\t 5. �����ϼ�\n\n");
			if (scanf("%d", &choice) == 1 && (choice <= 5 && choice >= 1))
				break;
			else
				printf("\t\t\t ����������������������");
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
int toLoginMenu(int type)//type���ڶ�����1
{
	int length = 0;

	long int id;
	char password[20];

	clearScreen(100);
	while (1)
	{
		printf("\n �˺ţ�");
		scanf("%ld", &id);
		printf("\n ���룺");
		length = inputPasswd(password);
		//printf("\n\n �������id�� %ld \n", id);
		//printf("\n �������passw�� %s \n\n", password);

		int i=login(id, password, type);
		switch(i){
			case 1://����Ա
				printf("\n ����Ա��¼�ɹ� \n");
				printf("\n ���Ժ�ҳ��������ת�� ......");
				return adminMenu();
			case 2://�û�;
				printf("\n �û���¼�ɹ� \n");
				printf("\n ���Ժ�ҳ��������ת�� ......");
				return userMenu(id);
			case 0://�������
				int choice;
				fflush(stdin);
				printf("\n �˺Ż��������\n");
				printf("\n 1. �������� \n");
				printf("\n 2. ������һ�� \n");
				printf("\n 3. �˳�ϵͳ����1, 2����ļ��� \n\n");
				scanf("%d", &choice);
				if (choice == 1)
				{
					printf("\n ���Ժ�ҳ��������ת�� ......");
					clearScreen(1000);
				}
				else if (choice == 2)
				{

					printf("\n ���Ժ�ҳ��������ת�� ......");
					clearScreen(1000);
					return -1;
				}
				else
				{
					printf("\n ���Ժ������˳�ϵͳ ...... \n ");
					return 0;
				}
		}
		
		
	}

}
int toTableMenu(){
	clearScreen(100);
	if(!sys_info.eve) return 1;
	SportsEvent* evo=(SportsEvent *) malloc((sys_info.eve)*sizeof(SportsEvent)),a;
	sorteve *st=(sorteve *) malloc((2*sys_info.eve)*sizeof(sorteve));
	Event_getlist(evo);
	int i=0,p;
    for(int o = 0; o < sys_info.eve; o++){
		st[i].id=evo[o].id;
		st[i].isFinals=0;
		if(evo[o].maxpeople<4)st[i].cancle=1;else st[i].cancle=0;
		st[i++].time=evo[o].time;
		if(evo[o].hasFinals){
			st[i].isFinals=1;
			if(evo[o].maxpeople<4)st[i].cancle=1;else st[i].cancle=0;
			st[i].id=evo[o].id;
			st[i++].time=evo[o].etime;
		}
	}
	//printf("-\n%d\n",i);
	qsort(st,i,sizeof(sorteve),cmp2);
	PerInfo peo;
	int nowaday;
	for(int o = 0; o < i; o++){
		time_t  tt = (time_t)st[o].time;   //�ٶ�ʱ��
		char now[64];
		int u,yu,zu=0,maxzu=6;
		struct tm *ttime;
		ttime = localtime(&tt);
		strftime(now, 64, "%Y%m%d %H:%M:%S", ttime);

		a = Event_getinfo(st[o].id);
		
		if (i == 1)
		{
			nowaday = ttime->tm_mday;
			printf("\t%d��%d��%d��\n\n\t  %02d:%02d   ����ʱ����%d����", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min, a.timecost);
		}
		if (i != 1)
		{
			if (nowaday != ttime->tm_mday)
			{
				nowaday = ttime->tm_mday;
				printf("\t%d��%d��%d��\n\n\t  %02d:%02d   ����ʱ����%d����", ttime->tm_year + 1900, ttime->tm_mon + 1, ttime->tm_mday, ttime->tm_hour, ttime->tm_min, a.timecost);
			}
			else
			{
				printf("\t  %02d:%02d   ����ʱ����%d����", ttime->tm_hour, ttime->tm_min, a.timecost);
			}
		}
		printf(" [%s-%s]",a.name,a.place);
		if(st[o].cancle)if(st[o].isFinals)printf("[������ȡ��]\n\n\n"); else printf("[��һ����ȡ��]\n\n\n"); 
		else if(!st[o].isFinals){//�Ƿ����
			printf("��һ��\n");
			for(p = 0; p < sys_info.eve; p++){
				//printf("\n%d.%d\n",evo[p].id,st[o].id);
				if(evo[p].id==st[o].id){
					u=1;
					printf("\n\t    ��%d��:\t",u++);//�ڼ���
					if(evo[p].maxpeople%6==1)maxzu=5;else maxzu=6;
					for(int y=0;y<evo[p].maxpeople;y++){
						if(evo[p].prePerson[y].id){
							if(zu==maxzu){//��Ա��
								zu=0;
								printf("\n\t    ��%d��:\t",u++);//�ڼ���
							}
							peo=Person_getinfo(evo[p].prePerson[y].id);
							printf("%s(%s)  ",peo.name,peo.organization);
							zu++;
						}
					}
					printf("\n\n");

				}
			}
		}else{
			printf("����\n");
			for(p = 0; p < sys_info.eve; p++){
				//printf("\n%d.%d\n",evo[p].id,st[o].id);
				if(evo[p].id==st[o].id){
					if(!evo[p].finNum) printf("\n\t�ȴ�Ԥ������\t",u++);
					else{
					u=1;
					printf("\n\t    ��%d��:\t",u++);//�ڼ���
					if(evo[p].finNum%6==1)maxzu=5;else maxzu=6;
					for(int y=0;y<evo[p].finNum;y++){
						if(evo[p].finPerson[y].id){
							if(zu==maxzu){//��Ա��
								zu=0;
								printf("\n\t    ��%d��:\t",u++);//�ڼ���
							}
							peo=Person_getinfo(evo[p].finPerson[y].id);
							printf("%s(%s)  ",peo.name,peo.organization);
							zu++;
						}
					}
					}
					printf("\n\n");
					
				}
			}
		}
	
	
	}
	free(evo);free(st);
	printf("\n\n\n\n      �밴�س�������");
	fflush(stdin);
	getchar();
	return 1;
}
void welcome()
{
	printf("\n\n\n\n\n");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t    �� ͷ �� ѧ У �� �� �� �� ϵ ͳ V1\n");
	printf("\n\n\n\n");
	Person_mynotice();
	printf("\n\n\n\n");
	printf("\t\t\t\t\t      �밴�س�������");
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
			printf("\n\t 1.  ��¼ \n");
			printf("\n\t 2.  ע�� \n");
			printf("\n\t 3.  �鿴����� \n");
			printf("\n\t 4.  ������Ϣ \n");
			printf("\n\t 5.  �˳�ϵͳ\n\n");

			if (scanf("%d", &type) == 1 && (type <= 5 && type >= 1))
				break;
			else
				printf("\t ����������������������");

		}
		switch (type)
		{
			case 1:
				isRetLast = toLoginMenu(1);
				isRetLast = 1;
				break;
			case 2:
				signupSuccess = toSignupMenu();
				isRetLast = 1;
				break;
			case 3:
				toTableMenu();
				isRetLast = 1;
				break;
			case 4:
				isRetLast=toSituationMenu();
				break;
			default:
				printf("\n  ���Ժ������˳�ϵͳ ...... \n\n  ");
				return 0;
		}


	} while (isRetLast);
	printf("\n  ���Ժ������˳�ϵͳ ...... \n\n  ");
	return 0;
}

void mainMenu()
{
	welcome();
	loginMenu();

}