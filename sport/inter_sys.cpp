#include "stdafx.h"

SysInfo sys_info;

int sys_init(){
	FILE * fp;
	SysInfo sys;
    if((fp=fopen("data\\sysinfo.txt", "r"))==NULL) {  
		fp=fopen("data\\sysinfo.txt", "w");
		//printf("write:%d\n",fp);
		sys.not=0;sys.eve=0;sys.peo=0;
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
	printf("用户数：%d 项目数：%d 通知数：%d\n",sys_info.peo,sys_info.eve,sys_info.not);
	return 0;
}
int sys_inc(int type){//增加数量 0 peo 1 eve 2 not 3 yuan 4 xi
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
		case 3:
			sys_info.numyuan++;
			break;
		case 4:
			sys_info.numyuan++;
			break;
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
		case 3:
			return sys_info.numyuan;
		case 4:
			return sys_info.numxi;
	}
	return 0;
}
int sys_dec(int type){//减少数量 0 peo 1 eve 2 not 3 yuan 4 xi
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
		case 3:
			sys_info.numyuan--;
			break;
		case 4:
			sys_info.numyuan--;
			break;
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
		case 3:
			return sys_info.numyuan;
		case 4:
			return sys_info.numxi;
	}
	return 0;
}
