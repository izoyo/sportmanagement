#include "stdafx.h"
int Char_isok(char* msg){
	char buff[20];
	strncpy(buff,msg,20);
	//strlen(buff))可能出现大于20，大概strncpy会把msg都复制过去没有在21的地方填\0结束，而strlen会检查到\0的长度
	for(int i=0;i<(int)strlen(buff);i++){
		if(buff[i]>0 && buff[i]<48) return ++i;
		if(buff[i]>=58 && buff[i]<65) return ++i;
		if(buff[i]>=91 && buff[i]<97) return ++i;
		if(buff[i]>=123 && buff[i]<128) return ++i;
	}
	return 0;
}

int cmp(const void*a,const void*b){//从小到大  qsort(evo,3,sizeof(Participant),cmp);
	struct Participant *c = (Participant *)a;
	struct Participant *d = (Participant *)b;
	if(c->score != d->score) return c->score - d->score;
	else return d->score - c->score;
}

void  scoreToChar(long score, char * msg)//把比赛的时间成绩转化为时间格式字符串（如12'12''12)
{
	char t[20];

	itoa(score / 60000, t, 10);
	strcpy(msg, t);
	strcat(msg, "'");

	itoa((score % 60000) / 1000, t, 10);
	strcat(msg, t);
	strcat(msg, "''");
	if (score % 1000 > 100)
		itoa((score % 1000) / 10, t, 10);
	else if (score % 1000 < 10)
		strcat(msg, "0");
	itoa(score % 1000, t, 10);
	strcat(msg, t);
}