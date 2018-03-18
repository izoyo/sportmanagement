#include "stdafx.h"
/*
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
*/
int Event_getlist(SportsEvent* evo){
	FILE * fp= fopen("data\\eveinfo.txt", "r");
	if(fp==NULL) return 1;//���ļ�ʧ��
    int i=sys_info.eve;
	if(i==0) return 2;//0��Ŀ
    fread(evo, sizeof(SportsEvent), i, fp);
    fclose(fp);
	return 0;
}
SportsEvent Event_getinfo(long id){
	SportsEvent msg;
	msg.id=0;
	FILE *fp = fopen("data\\eveinfo.txt", "r");
	if(fp==NULL) return msg;
    int i=sys_info.eve,o;
	if(i==0) return msg;
	SportsEvent* evo;
	evo=(SportsEvent *) malloc(i*sizeof(SportsEvent));
    fread(evo, sizeof(SportsEvent), i, fp);
    fclose(fp);
    for(o = 0; o < sys_info.eve; o++){
		//printf("%d,%s",o,evo[o].name);
		if(evo[o].id==id){
			msg=evo[o];
			break;
		}
	}
	free(evo);
	return msg;//����Żص�msg.idΪ0�򲻴��ڸ���Ŀ
}
int Event_had(long id){
	SportsEvent msg=Event_getinfo(id);
	if(msg.id)
			return 1;//������Ŀ
		else 
			return 0;
}
int Event_hadname(char* ming){
	FILE *fp = fopen("data\\eveinfo.txt", "r");
	if(fp==NULL) return 0;
    int i=sys_info.eve,o;
	if(i==0) return 0;
	SportsEvent* evo;
	evo=(SportsEvent *) malloc(i*sizeof(SportsEvent));
    fread(evo, sizeof(SportsEvent), i, fp);
    fclose(fp);
	long msgid=0;
	char buff[20];
	strcpy(buff,ming);
    for(o = 0; o < sys_info.eve; o++){
		//printf("%s,%s",buff,evo[o].name);
		if(strcmp(evo[o].name,buff)==0){
			msgid=evo[o].id;
			//puts("����");
			break;
		}
	}
	free(evo);
	if(msgid)
			return msgid;//������Ŀ
		else 
			return 0;
}
int Event_inc(long eveid,long peoid,int type){
	if(Event_had(eveid)==0)return 11;//��������Ŀ
	FILE * fp= fopen("data\\eveinfo.txt", "r");
	if(fp==NULL) return 1;//���ļ�ʧ��
    int i=sys_info.eve;//��Ŀ��
	if(i==0) return 2;//0��Ŀ
	SportsEvent* evo,msg;//������Ŀ��������Ŀ
	evo=(SportsEvent *) malloc(i*sizeof(SportsEvent));
    fread(evo, sizeof(SportsEvent), i, fp);
    fclose(fp);
	int o;Participant one;//����������
	one.id=peoid;one.score=0;
	for(int p=0;p<i;p++){
		if(evo[p].id==eveid){
			if(type==0){//��һ��
				if(evo[p].maxpeople==100)return 4;
				for(o = 0; o < 100; o++){//�����û�вμ�
					if(evo[p].prePerson[o].id==peoid){
						free(evo);
						return 3;//�Ѽ���
					}
				}
				for(o = 0; o < 100; o++){//�μ�
					if(evo[p].prePerson[o].id<10001){//����1w�Ͳ����û�
						evo[p].prePerson[o]=one;
						break;//�Ѽ���
					}
				}
				evo[p].maxpeople++;
			}else{//��������
				if(evo[p].finNum==20)return 4;
				for(o = 0; o < 20; o++){
					if(evo[p].finPerson[o].id==peoid){
						free(evo);
						return 3;//�Ѽ���
					}
				}
				for(o = 0; o < 20; o++){//�μ�
					if(evo[p].finPerson[o].id<10001){
						evo[p].finPerson[o]=one;
						break;//�Ѽ���
					}
				}
				evo[p].finNum++;
			}
		}
	}
	fp = fopen("data\\eveinfo.txt", "w");
	fwrite(evo, sizeof(SportsEvent), i, fp);
	fclose(fp);
	free(evo);
	return 0;
}
int Event_dec(long eveid,long peoid,int type){
	if(Event_had(eveid)==0)return 11;//��������Ŀ
	FILE * fp= fopen("data\\eveinfo.txt", "r");
	if(fp==NULL) return 1;//���ļ�ʧ��
    int i=sys_info.eve;//��Ŀ��
	if(i==0) return 2;//0��Ŀ
	SportsEvent* evo,msg;//������Ŀ��������Ŀ
	evo=(SportsEvent *) malloc(i*sizeof(SportsEvent));
    fread(evo, sizeof(SportsEvent), i, fp);
    fclose(fp);
	int o;Participant one;//����������
	one.id=peoid;one.score=0;
	for(int p=0;p<i;p++){
		if(evo[p].id==eveid){
			if(type==0){//��һ��
				if(evo[p].maxpeople==0)return 3;
				for(o = 0; o < 100; o++){//�����û�вμ�
					if(evo[p].prePerson[o].id==peoid){
						evo[p].prePerson[o].id=0;//ɾ������
						fp = fopen("data\\eveinfo.txt", "w");
						evo[p].maxpeople--;
						fwrite(evo, sizeof(SportsEvent), i, fp);
						fclose(fp);
						free(evo);
						return 0;//��ɾ��
					}
				}
				;
			}else{//����
				if(evo[p].finNum==0)return 3;
				for(o = 0; o < 20; o++){
					if(evo[p].finPerson[o].id==peoid){
						evo[p].finPerson[o].id=0;
						evo[p].finNum--;
						fp = fopen("data\\eveinfo.txt", "w");
						fwrite(evo, sizeof(SportsEvent), i, fp);
						fclose(fp);
						free(evo);
						return 0;//��ɾ��
					}
				}
			}
		}
	}
	free(evo);
	return 3;//û���������
}
int Event_changescore(long eveid,long peoid,int type,long score){
	if(Event_had(eveid)==0)return 11;//��������Ŀ
	FILE * fp= fopen("data\\eveinfo.txt", "r");
	if(fp==NULL) return 1;//���ļ�ʧ��
    int i=sys_info.eve;//��Ŀ��
	if(i==0) return 2;//0��Ŀ
	SportsEvent* evo,msg;//������Ŀ��������Ŀ
	evo=(SportsEvent *) malloc(i*sizeof(SportsEvent));
    fread(evo, sizeof(SportsEvent), i, fp);
    fclose(fp);
	int o;Participant one;//����������
	one.id=peoid;one.score=score;
	for(int p=0;p<i;p++){
		if(evo[p].id==eveid){
			if(type==0){//��һ��
				if(evo[p].maxpeople==0)return 3;
				for(o = 0; o < 100; o++){//�����û�вμ�
					if(evo[p].prePerson[o].id==peoid){
						evo[p].prePerson[o].score=score;//�ĳɼ�
						fp = fopen("data\\eveinfo.txt", "w");
						fwrite(evo, sizeof(SportsEvent), i, fp);
						fclose(fp);
						free(evo);
						return 0;//��ɾ��
					}
				}
				;
			}else{//����
				if(evo[p].finNum==0)return 3;
				for(o = 0; o < 20; o++){
					if(evo[p].finPerson[o].id==peoid){
						evo[p].finPerson[o].score=score;
						fp = fopen("data\\eveinfo.txt", "w");
						fwrite(evo, sizeof(SportsEvent), i, fp);
						fclose(fp);
						free(evo);
						return 0;//��ɾ��
					}
				}
			}
		}
	}
	free(evo);
	return 3;//û���������
}
int Event_change(SportsEvent msg,int type){
	if(Event_had(msg.id)==0)return 11;//��������Ŀ
	int i,o;
	switch(type){
		case 1:	
			i=Char_isok(msg.name);
			if(i)return 1;
			i=Event_hadname(msg.name);
			if(i==0)return 1;
			break;
		case 3:
			if(msg.type<0 || msg.type>1) return 3;
			break;
		case 4:
			i=Char_isok(msg.place);
			if(i)return 4;
			break;
		case 5:
			if(msg.timecost<0 )return 5;
			break;
		case 6:
			if(msg.maxpeople<0 || msg.maxpeople>100)return 6;
			break;
		case 7:
			if(msg.hasFinals<0 || msg.hasFinals>1) return 7;
			break;
		case 8:
			if(msg.finNum<0 || msg.finNum>20)return 8;
			break;
		case 9:
			if(msg.time<0 )return 9;
			break;
		default:
			return 10;
	}
	FILE * fp;
	msg.id=0;
	fp = fopen("data\\eveinfo.txt", "r");
	if(fp==NULL) return 9;
    i=sys_info.eve;
	SportsEvent* evo=(SportsEvent *) malloc(i*sizeof(SportsEvent));
    fread(evo, sizeof(SportsEvent), i, fp);
    fclose(fp);
    for(o = 0; o < i; o++){
		if(evo[o].id==msg.id){
			switch(type){
				case 1:	
					strcpy(evo[o].name,msg.name);
					break;
				case 3:
					evo[o].type=msg.type;
					break;
				case 4:
					strcpy(evo[o].place,msg.place);
					break;
				case 5:
					evo[o].timecost=msg.timecost;
					break;
				case 6:
					evo[o].maxpeople=msg.maxpeople;
					break;
				case 7:
					evo[o].hasFinals=msg.hasFinals;
					break;
				case 8:
					evo[o].finNum=msg.finNum;
					break;
				case 9:
					evo[o].time=msg.time;
					break;
				}
			break;
		}
	}
	fp = fopen("data\\eveinfo.txt", "w");
	fwrite(evo, sizeof(SportsEvent), i, fp);
	fclose(fp);
	free(evo);
	return 0;
}
int Event_delete(long id){
	if(id==0)return 1;//����ɾ0
	if(!Event_had(id))return 2;//������
	FILE *fp;
	SportsEvent *evo,*sen;
	int i,p,o=0;
	fp = fopen("data\\eveinfo.txt", "r+");
	if(sys_info.eve){//��1��������
		if(sys_info.eve==1){
			fclose(fp);
			fp = fopen("data\\eveinfo.txt", "w");
		}else{
			i=sys_info.eve;
			evo=(SportsEvent *) malloc((i)*sizeof(SportsEvent));//ԭ�� ��̬��������
			sen=(SportsEvent *) malloc((i-1)*sizeof(SportsEvent));//ʣ�� ɾ����Ŀ-1
			fread(evo, sizeof(SportsEvent), i, fp);
			fclose(fp);
			for(p=0;p<i;p++){
				if(evo[p].id!=id) sen[o++]=evo[p];
			}
			fp = fopen("data\\eveinfo.txt", "w");
			fwrite(sen, sizeof(SportsEvent), o, fp);
			free(evo);
			free(sen);
		}
		fclose(fp);
		sys_dec(1);//������Ŀ��¼
	}else{
		fclose(fp);
		return 3;//��Ŀ��0��ɾ��ʧ��
	}
	return 0;
}
int Event_create(SportsEvent msg){
	int i;
	i=Char_isok(msg.name);
	if(i)return 1;//�������
	i=Event_hadname(msg.name);
	if(i)return 1;
	if(msg.type<0 || msg.type>1) return 3;//����ﾶ
	i=Char_isok(msg.place);
	if(i)return 4;//��鳡��
	if(msg.timecost<0 ) return 5;//����ʱ
	if(msg.hasFinals<0 || msg.hasFinals>1) return 7;//������
	if(sys_info.eve>8888)return 10;//̫����Ŀ
	i=rand()%(9999-1000+1)+1000;
	while(Event_had(i))	i=rand()%(9999-1000+1)+1000;
	msg.time=0;
	//�����ϣ�����¼��
	msg.id=i;
	FILE *fp;
	SportsEvent *evo;
	fp = fopen("data\\eveinfo.txt", "r+");
	if(sys_info.eve){//��1��������
		i=sys_info.eve;
		evo=(SportsEvent *) malloc((i+1)*sizeof(SportsEvent));//��̬��������
		fread(evo, sizeof(SportsEvent), i, fp);
		fclose(fp);
		evo[i++]=msg;
		fp = fopen("data\\eveinfo.txt", "w");
		fwrite(evo, sizeof(SportsEvent), i, fp);
		free(evo);
	}else{
		evo=&msg;
		fwrite(evo, sizeof(SportsEvent), 1, fp);
	}
	fclose(fp);

	sys_inc(1);//������Ŀ��¼
	return msg.id;
}

void Event_list(){//��ȡ���г�Ա����
	if(sys_info.eve==0) return;
	SportsEvent* evo=(SportsEvent *) malloc((sys_info.eve)*sizeof(SportsEvent));
	Event_getlist(evo);
    for(int o = 0; o < sys_info.eve; o++){
		printf("> %d_%s_%d_%s_%d_%d_%d_%d_%d\n",evo[o].id,evo[o].name,evo[o].type,evo[o].place,evo[o].timecost,evo[o].maxpeople,evo[o].hasFinals,evo[o].finNum,evo[o].time);
	}
	free(evo);
}