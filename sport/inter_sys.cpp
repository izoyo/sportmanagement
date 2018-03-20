#include "stdafx.h"


int sys_init(){
	FILE * fp;
	int i;
	SysInfo sys;
	_mkdir("data");
    if((fp=fopen("data\\sysinfo.txt", "r"))==NULL) {  
		fp=fopen("data\\sysinfo.txt", "w");
		//printf("write:%d\n",fp);
		sys.not=0;sys.eve=0;sys.peo=0;sys.numyuan=0;sys.numxi=0;sys.canjoin=1;
		strcpy(sys.password,"admin");
		for(i=0;i<20;i++)strcpy(sys.yuan[i],"-");
		for(i=0;i<20;i++)strcpy(sys.xi[i],"-");
		fwrite(&sys, sizeof(SysInfo), 1, fp);
		fclose(fopen("data\\perinfo.txt", "w"));
		fclose(fopen("data\\eveinfo.txt", "w"));
		fclose(fopen("data\\notinfo.txt", "w"));
	}else{
		//printf("read:%d\n",fp);
		fread(&sys, sizeof(SysInfo), 1, fp);
	}
	if (fp!=0) fclose(fp);
	sys_info=sys;
	printf("�û�����%d ��Ŀ����%d ֪ͨ����%d Ժ����%d ϵ����%d\n",sys_info.peo,sys_info.eve,sys_info.not,sys_info.numyuan,sys_info.numxi);
	return 0;
}
int sys_inc(int type){//�������� 0 peo 1 eve 2 not
	FILE * fp;
	if((fp=fopen("data\\sysinfo.txt", "w"))==NULL)
		return 0;
	SysInfo sys;
	switch(type){
		case 0:
			sys_info.peo++;
			break;
		case 1:
			sys_info.eve++;
			break;
		case 2:
			sys_info.not++;
			break;
		default:
			return 0;
	}
	sys=sys_info;
	fwrite(&sys, sizeof(SysInfo), 1, fp);
	fclose(fp);
	switch(type){
		case 0:
			return sys_info.peo;
		case 1:
			return sys_info.eve;
		case 2:
			return sys_info.not;
	}
	return 0;
}
int sys_dec(int type){//�������� 0 peo 1 eve 2 not
	FILE * fp;
	if((fp=fopen("data\\sysinfo.txt", "w"))==NULL)
		return 0;
	SysInfo sys;
	switch(type){
		case 0:
			sys_info.peo--;
			break;
		case 1:
			sys_info.eve--;
			break;
		case 2:
			sys_info.not--;
			break;
		default:
			return 0;
	}
	sys=sys_info;
	fwrite(&sys, sizeof(SysInfo), 1, fp);
	fclose(fp);
	switch(type){
		case 0:
			return sys_info.peo;
		case 1:
			return sys_info.eve;
		case 2:
			return sys_info.not;
	}
	return 0;
}
int sys_incyuan(char* yuan){
	if(sys_info.numyuan>=20)return 2;//����
	int i=Char_isok(yuan);
	if(i)return 3;
	FILE * fp;
	char buff[20];
	strcpy(buff,yuan);
	for(int i=0;i<20;i++){
		if(strcmp(buff,sys_info.yuan[i])==0)
			return 1;//�Ѵ���
		if(strcmp(sys_info.yuan[i],"-")==0){
			strcpy(sys_info.yuan[i],buff);
			sys_info.numyuan++;

			if((fp=fopen("data\\sysinfo.txt", "w"))==NULL)return 3;
			fwrite(&sys_info, sizeof(SysInfo), 1, fp);
			fclose(fp);
			return 0;
		}
	}
	return 2;//����
}
int sys_decyuan(char* yuan){
	if(sys_info.numyuan==0)return 1;//ûԺ
	FILE * fp;
	char buff[20];
	strcpy(buff,yuan);
	for(int i=0;i<20;i++){
		if(strcmp(buff,sys_info.yuan[i])==0){
			strcpy(sys_info.yuan[i],"-");
			sys_info.numyuan--;

			if((fp=fopen("data\\sysinfo.txt", "w"))==NULL)return 3;
			fwrite(&sys_info, sizeof(SysInfo), 1, fp);
			fclose(fp);
			return 0;
		}
	}
	return 2;//������
}

int sys_incxi(char* xi){
	if(sys_info.numxi>=20)return 2;//����
	int i=Char_isok(xi);
	if(i)return 3;
	FILE * fp;
	char buff[20];
	strcpy(buff,xi);
	for(int i=0;i<20;i++){
		if(strcmp(buff,sys_info.xi[i])==0)
			return 1;//�Ѵ���
		if(strcmp(sys_info.xi[i],"-")==0){
			strcpy(sys_info.xi[i],buff);
			sys_info.numxi++;

			if((fp=fopen("data\\sysinfo.txt", "w"))==NULL)return 3;
			fwrite(&sys_info, sizeof(SysInfo), 1, fp);
			fclose(fp);
			return 0;
		}
	}
	return 2;//����
}
int sys_decxi(char* xi){
	if(sys_info.numxi==0)return 1;//ûϵ
	FILE * fp;
	char buff[20];
	strcpy(buff,xi);
	for(int i=0;i<20;i++){
		if(strcmp(buff,sys_info.xi[i])==0){
			strcpy(sys_info.xi[i],"-");
			sys_info.numxi--;

			if((fp=fopen("data\\sysinfo.txt", "w"))==NULL)return 3;
			fwrite(&sys_info, sizeof(SysInfo), 1, fp);
			fclose(fp);
			return 0;
		}
	}
	return 2;//������
}
int sys_changepsw(char* msg){
	int i=Char_isok(msg);
	if(i)return 1;
	strcpy(sys_info.password,msg);
	FILE * fp=fopen("data\\sysinfo.txt", "w");
	fwrite(&sys_info, sizeof(SysInfo), 1, fp);
	fclose(fp);
	return 0;
}
int sys_changecj(int i){//�ı��ܷ���
	sys_info.canjoin=i;
	FILE * fp=fopen("data\\sysinfo.txt", "w");
	fwrite(&sys_info, sizeof(SysInfo), 1, fp);
	fclose(fp);
	return 0;
}