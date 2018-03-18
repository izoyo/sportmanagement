#include "stdafx.h"

int Person_getlist(PerInfo* evo){
	FILE * fp;
	fp = fopen("data\\perinfo.txt", "r");
	if(fp==NULL) return 1;//���ļ�ʧ��
    int i=sys_info.peo;
	if(i==0) return 2;//0�û�
    fread(evo, sizeof(PerInfo), i, fp);
    fclose(fp);
	return 0;
}

int Person_notice(long id,char* msg){
	FILE * fp;
	Notice *notice,msn;
	time_t now;
	time(&now);
	msn.id=id;strcpy(msn.msg,msg);msn.time=now;
	notice=&msn;
	fp = fopen("data\\notinfo.txt", "r+");
	if(fp==NULL) return 1;//���ļ�ʧ��
	fseek(fp,0,SEEK_END);
    fwrite(notice, sizeof(Notice), 1, fp);
    fclose(fp);
	sys_inc(2);
	return 0;
}
int Person_getnotice(long id,Notice *msn){//�޶���ʾ���20����Ϣ
	FILE * fp;
	fp = fopen("data\\notinfo.txt", "r");
	if(fp==NULL) return 1;//���ļ�ʧ��
    int i=sys_info.not;
	if(i==0) return 2;//0֪ͨ
	Notice *allmsn=(Notice *) malloc((sys_info.not)*sizeof(Notice));
    fread(allmsn, sizeof(Notice), i, fp);
    fclose(fp);
	int o=0,p;
	for(p=i-1;p>=0;p--){
		if(allmsn[p].id==id){
			msn[o++]=allmsn[p];
			if(o==20)break;
		}
	}
	return 0;
}

PerInfo Person_getinfo(long id){
	FILE * fp;
	PerInfo msg;
	msg.id=0;
	fp = fopen("data\\perinfo.txt", "r");
	if(fp==NULL) return msg;
    int i=sys_info.peo,o;
	if(i==0) return msg;
	PerInfo* evo;
	evo=(PerInfo *) malloc(i*sizeof(PerInfo));
    fread(evo, sizeof(PerInfo), i, fp);
    fclose(fp);
    for(o = 0; o < sys_info.peo; o++){
		//printf("%d,%s",o,evo[o].name);
		if(evo[o].id==id){
			msg=evo[o];
			break;
		}
	}
	free(evo);
	return msg;//����Żص�msg.idΪ0�򲻴��ڸ�ѧ��
}
int Person_had(long id){
	PerInfo peo;
	peo=Person_getinfo(id);
	if(peo.id)
			return 1;//�����û�
		else 
			return 0;
}
int Person_delete(long id){
	if(id==0)return 1;//����ɾ0
	if(!Person_had(id))return 2;//������
	FILE *fp = NULL;
	PerInfo *evo,*sen;
	int i,p,o=0;
	fp = fopen("data\\perinfo.txt", "r+");
	if(sys_info.peo){//��1��������
		if(sys_info.peo==1){
			fclose(fp);
			fp = fopen("data\\perinfo.txt", "w");
		}else{
			i=sys_info.peo;
			evo=(PerInfo *) malloc((i)*sizeof(PerInfo));//ԭ�� ��̬��������
			sen=(PerInfo *) malloc((i-1)*sizeof(PerInfo));//ʣ�� ɾ����-1
			fread(evo, sizeof(PerInfo), i, fp);
			fclose(fp);
			for(p=0;p<i;p++){
				if(evo[p].id!=id) sen[o++]=evo[p];
			}
			fp = fopen("data\\perinfo.txt", "w");
			fwrite(sen, sizeof(PerInfo), o, fp);
			free(evo);
			free(sen);
		}
		fclose(fp);
		sys_dec(0);//����������¼
	}else{
		fclose(fp);
		return 3;//��Ա��0��ɾ��ʧ��
	}
	return 0;
}
int Person_change(PerInfo msg,int type){
	if(Person_had(msg.id)==0)return 8;//�������û�
	int i,o;
	switch(type){
		case 1:	
			i=Char_isok(msg.name);
			if(i)return 1;
			break;
		case 3:
			if(msg.gender<0 || msg.gender>1) return 3;
			break;
		case 4:
			i=Char_isok(msg.organization);
			if(i)return 4;
			break;
		case 5:
			i=Char_isok(msg.faculty);
			if(i)return 5;
			break;
		case 6:
			i=Char_isok(msg.password);
			if(i)return 6;
			break;
		default:
			return 8;
	}
	FILE * fp;
	msg.id=0;
	fp = fopen("data\\perinfo.txt", "r");
	if(fp==NULL) return 9;
    i=sys_info.peo;
	PerInfo* evo=(PerInfo *) malloc(i*sizeof(PerInfo));
    fread(evo, sizeof(PerInfo), i, fp);
    fclose(fp);
    for(o = 0; o < i; o++){
		if(evo[o].id==msg.id){
			switch(type){
				case 1:	
					strcpy(evo[o].name,msg.name);
					break;
				case 3:
					evo[o].gender=msg.gender;
					break;
				case 4:
					strcpy(evo[o].organization,msg.organization);
					break;
				case 5:
					strcpy(evo[o].faculty,msg.faculty);
					break;
				case 6:
					strcpy(evo[o].password,msg.password);
					break;
				}
			break;
		}
	}
	fp = fopen("data\\perinfo.txt", "w");
	fwrite(evo, sizeof(PerInfo), i, fp);
	fclose(fp);
	free(evo);
	return 0;
}
int Person_create(PerInfo msg){//ע��ע��ID��Ҫ����21��
	//��ʼ���¼��
	int i;
	i=Char_isok(msg.name);
	if(i)return 1;//�������
	if(msg.id<=10000) return 2;//���ID
	if(msg.gender<0 || msg.gender>1) return 3;//����Ա�
	i=Char_isok(msg.organization);
	if(i)return 4;//ѧԺ��Ժ
	i=Char_isok(msg.faculty);
	if(i)return 5;//ϵ
	i=Char_isok(msg.password);
	if(i)return 6;//����
	//����ظ�
	if(Person_had(msg.id))return 7;//�ظ�¼��
	//�����ϣ�����¼��
	FILE *fp;
	PerInfo *evo;
	fp = fopen("data\\perinfo.txt", "r+");
	if(sys_info.peo){//��1��������
		i=sys_info.peo;
		evo=(PerInfo *) malloc((i+1)*sizeof(PerInfo));//��̬��������
		fread(evo, sizeof(PerInfo), i, fp);
		fclose(fp);
		evo[i++]=msg;
		fp = fopen("data\\perinfo.txt", "w");
		fwrite(evo, sizeof(PerInfo), i, fp);
		free(evo);
	}else{
		evo=&msg;
		fwrite(evo, sizeof(PerInfo), 1, fp);
	}
	fclose(fp);
	
	sys_inc(0);//����������¼
	return 0;
}


void Person_mynotice(){//��ȡ��Ա֪ͨ���ӣ���ע����û����20��
	Notice msn[20];
	Person_getnotice(10000,msn);
	printf("%d-%s-%d\n",msn[0].id,msn[0].msg,msn[0].time);
}
void Person_list(){//��ȡ���г�Ա����
	if(sys_info.peo==0) return;
	PerInfo* evo=(PerInfo *) malloc((sys_info.peo)*sizeof(PerInfo));
	Person_getlist(evo);
    for(int o = 0; o < sys_info.peo; o++){
		printf("> %d_%s_%d_%s_%s_%s\n",evo[o].id,evo[o].name,evo[o].gender,evo[o].organization,evo[o].faculty,evo[o].password);
	}
	free(evo);
}