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
						printf("[��ȡ��]");
					}else{//���ڱ���
						qsort(eve[o].prePerson, 100, sizeof(Participant), cmp);//С����
						
						if (eve[o].type % 2){ //��������С
							puts("\t����\n");
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
											if(rank<6 && eve[o].maxpeople>6)printf("һ��������%d %s �ɼ���%d\n",rank,peo.name,eve[o].prePerson[i].score);
											else if(rank<4 && eve[o].maxpeople>3)printf("һ��������%d %s �ɼ���%d\n",rank,peo.name,eve[o].prePerson[i].score);
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
											if(rank<6 && eve[o].maxpeople>6)printf("����������%d %s �ɼ���%d\n",rank,peo.name,eve[o].finPerson[i].score);
											else if(rank<4 && eve[o].maxpeople>3)printf("����������%d %s �ɼ���%d\n",rank,peo.name,eve[o].finPerson[i].score);
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
							puts("\t����\n");
							for (i=99,rank=0;i>=0;i--){//���Ԥ��ÿ����
								if(eve[o].prePerson[i].id == 0) continue;
								rank++;
								peo=Person_getinfo(eve[o].prePerson[i].id);
								if(!strcmp(peo.organization,sys_info.yuan[p])){//ͬһ��Ժ
									
									joineve[o].joinnum++;
									if(eve[o].prePerson[i].score){//�гɼ�
										if(!eve[o].hasFinals){//û�о���
											if(rank<6 && eve[o].maxpeople>6)printf("һ��������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											else if(rank<4 && eve[o].maxpeople>3)printf("һ��������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
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
											if(rank<6 && eve[o].maxpeople>6)printf("����������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											else if(rank<4 && eve[o].maxpeople>3)printf("����������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
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


					printf("\n\tԤ��������%d\t����������%d\t�÷֣�%d\n\n\n",joineve[o].joinnum,joineve[o].joinenum,joineve[o].score);
				}
				int allscore=0;
				for (i=0;i<o;i++)allscore+=joineve[i].score;
				printf("�ܷ֣�%d\n\n",allscore);
				free(joineve);
				puts("������������������������������������");
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
	puts("\nϵ��Ϣ\n");
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
						printf("[��ȡ��]");
					}else{//���ڱ���
						qsort(eve[o].prePerson, 100, sizeof(Participant), cmp);//С����
						
						if (eve[o].type % 2){ //��������С
							puts("\t����\n");
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
											if(rank<6 && eve[o].maxpeople>6)printf("һ��������%d %s �ɼ���%s\n",rank,peo.name,buff);
											else if(rank<4 && eve[o].maxpeople>3)printf("һ��������%d %s �ɼ���%s\n",rank,peo.name,buff);
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
											if(rank<6 && eve[o].maxpeople>6)printf("����������%d %s �ɼ���%s\n",rank,peo.name,buff);
											else if(rank<4 && eve[o].maxpeople>3)printf("����������%d %s �ɼ���%s\n",rank,peo.name,buff);
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
							puts("\t����\n");
							for (i=99,rank=0;i>=0;i--){//���Ԥ��ÿ����
								if(eve[o].prePerson[i].id == 0) continue;
								rank++;
								peo=Person_getinfo(eve[o].prePerson[i].id);
								if(!strcmp(peo.faculty,sys_info.xi[p])){//ͬһ��xi
									
									joineve[o].joinnum++;
									if(eve[o].prePerson[i].score){//�гɼ�
										if(!eve[o].hasFinals){//û�о���
											if(rank<6 && eve[o].maxpeople>6)printf("һ��������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].prePerson[i].score/100,eve[o].prePerson[i].score%100);
											else if(rank<4 && eve[o].maxpeople>3)printf("һ��������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].prePerson[i].score/100,eve[o].prePerson[i].score%100);
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
											if(rank<6 && eve[o].maxpeople>6)printf("����������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
											else if(rank<4 && eve[o].maxpeople>3)printf("����������%d %s �ɼ���%d��%d����\n",rank,peo.name,eve[o].finPerson[i].score/100,eve[o].prePerson[i].score%100);
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


					printf("\n\tԤ��������%d\t����������%d\t�÷֣�%d\n",joineve[o].joinnum,joineve[o].joinenum,joineve[o].score);
				}
				int allscore=0;
				for (i=0;i<o;i++)allscore+=joineve[i].score;
				printf("�ܷ֣�%d\n\n",allscore);
				free(joineve);
				puts("������������������������������������");
			}
		}
	}
	free(eve);
	puts("���������������һ��");
	getchar();
	return 0;
}
int toSportMsgMenu(){
	clearScreen(100);
	puts("�˶�Ա��Ϣ");
	long id,i;
	while(1){
		printf("\n\t������ѧ�ţ�ID����");
		scanf("%ld", &id);
		if(Person_had(id)){
			userSignupedEve(id,1);
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
		printf("\n\n\n%s",eve[o].name);
		if(eve[o].type % 2){//��
			printf("\t����\n");
			for (i = 0, rank = 0; i < 100; i++) { //���Ԥ��ÿ����
				if (eve[o].prePerson[i].id == 0)
					continue;
				
				//printf("\n%d-",rank);
				peo = Person_getinfo(eve[o].prePerson[i].id);
				if (eve[o].prePerson[i].score) {
					rank++;
					scoreToChar(eve[o].prePerson[i].score,buff);
					if (rank < 6 && eve[o].maxpeople > 6)printf("һ��������%d %s �ɼ���%s\n", rank, peo.name, buff);
						else if (rank < 4 && eve[o].maxpeople > 3)printf("һ��������%d %s �ɼ���%s\n", rank, peo.name, buff);
				}
			}
			if (eve[o].hasFinals) { //����
				qsort(eve[o].finPerson, 20, sizeof(Participant), cmp); //С����
				for (i = 0, rank = 0; i < 20; i++) { //������ÿ����
					if (eve[o].finPerson[i].id == 0)
						continue;
					
					peo = Person_getinfo(eve[o].finPerson[i].id);
					if (eve[o].finPerson[i].score) {
						rank++;
						scoreToChar(eve[o].finPerson[i].score,buff);
						if (rank < 6 && eve[o].maxpeople > 6)printf("����������%d %s �ɼ���%s\n", rank, peo.name, buff);
							else if (rank < 4 && eve[o].maxpeople > 3)printf("����������%d %s �ɼ���%s\n", rank, peo.name, buff);
					}
				}
			}
		}else{
			printf("\t����\n");
			for (i = 0, rank = 0; i < 100; i++) { //���Ԥ��ÿ����
				if (eve[o].prePerson[i].id == 0)
					continue;
				
				//printf("\n%d-",rank);
				peo = Person_getinfo(eve[o].prePerson[i].id);
				if (eve[o].prePerson[i].score) {
					rank++;
					if (rank < 6 && eve[o].maxpeople > 6)printf("һ��������%d %s �ɼ���%d��%d����\n", rank, peo.name, eve[o].prePerson[i].score / 100, eve[o].prePerson[i].score % 100);
						else if (rank < 4 && eve[o].maxpeople > 3)printf("һ��������%d %s �ɼ���%d��%d����\n", rank, peo.name, eve[o].prePerson[i].score / 100, eve[o].prePerson[i].score % 100);
				}
			}
			if (eve[o].hasFinals) { //����
				qsort(eve[o].finPerson, 20, sizeof(Participant), cmp); //С����
				for (i = 0, rank = 0; i < 20; i++) { //������ÿ����
					if (eve[o].finPerson[i].id == 0)
						continue;
					
					peo = Person_getinfo(eve[o].finPerson[i].id);
					if (eve[o].finPerson[i].score) {
						rank++;
						if (rank < 6 && eve[o].maxpeople > 6)printf("����������%d %s �ɼ���%d��%d����\n", rank, peo.name, eve[o].finPerson[i].score / 100, eve[o].prePerson[i].score % 100);
							else if (rank < 4 && eve[o].maxpeople > 3)printf("����������%d %s �ɼ���%d��%d����\n", rank, peo.name, eve[o].finPerson[i].score / 100, eve[o].prePerson[i].score % 100);
					}
				}
			}
		}
		if(!rank)printf("\n\t[�޳ɼ�]\n\n");
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
			printf("\n\t\t\t 1. ��Ժ��Ϣ");
			printf("\n\t\t\t 2. ϵ��Ϣ");
			printf("\n\t\t\t 3. �˶�Ա��Ϣ");
			printf("\n\t\t\t 4. ��Ŀ��Ϣ");
			printf("\n\t\t\t 5. �����ϼ�\n\n");
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
void welcome()
{
	printf("\n\n\n\n\n");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t    �� ͷ �� ѧ У �� �� �� �� ϵ ͳ\n");
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