#include "stdafx.h"
int Char_isok(char* msg){
	char buff[20];
	strncpy(buff,msg,20);
	//strlen(buff))���ܳ��ִ���20�����strncpy���msg�����ƹ�ȥû����21�ĵط���\0��������strlen���鵽\0�ĳ���
	for(int i=0;i<(int)strlen(buff);i++){
		if(buff[i]>0 && buff[i]<48) return ++i;
		if(buff[i]>=58 && buff[i]<65) return ++i;
		if(buff[i]>=91 && buff[i]<97) return ++i;
		if(buff[i]>=123 && buff[i]<128) return ++i;
	}
	return 0;
}

int cmp(const void*a,const void*b){//��С����  qsort(evo,3,sizeof(Participant),cmp);
	struct Participant *c = (Participant *)a;
	struct Participant *d = (Participant *)b;
	if(c->score != d->score) return c->score - d->score;
	else return d->score - c->score;
}
int cmp2(const void*a,const void*b){//��С����  qsort(evo,sys_info.eve,sizeof(sorteve),cmp2);
	struct sorteve *c = (sorteve *)a;
	struct sorteve *d = (sorteve *)b;
	if(c->time != d->time) return c->time - d->time;
	else return d->time - c->time;
}

void  scoreToChar(long score, char * msg)//�ѱ�����ʱ��ɼ�ת��Ϊʱ���ʽ�ַ�������12'12''12)
{
	char t[20];

	itoa(score / 60000, t, 10);
	strcpy(msg, t);
	strcat(msg, "'");

	itoa((score % 60000) / 1000, t, 10);
	strcat(msg, t);
	strcat(msg, "\"");
	if (score % 1000 >= 100)
		itoa((score % 1000) / 10, t, 10);
	else if (score % 1000 >= 10)
	{
		strcat(msg, "0");
		itoa((score % 1000) / 10, t, 10);
	}
		
	if (score % 1000 >= 10)
		itoa(score % 1000, t, 10);
	strcat(msg, t);
}
long  charToScore(char * str)//��ʱ��ɼ��ַ�������12'12"12)ת��Ϊ������ʱ��ɼ�������-1��ʽ����
{
	
	const char s[2] = "'",s2[2]="\"";
	char *token1,*token2,*token3,*token4;
	int i=0;
	token1 = strtok(str, s);
	if( token1 != NULL ) {
		//printf( " %s\n", token1 );
		token2 = strtok(NULL, s);
		if( token2 != NULL )i=1;
	}
	if(!i)return -1;
	i=0;
	//printf( " %s\n", token2 );
	token3 = strtok(token2, s2);
	if( token3 != NULL ) {
		//printf( " %s\n", token3 );
		token4 = strtok(NULL, s2);
		i=1;
	}
	if(!i)return -1;
	//printf( " %s\n", token4 );
	if( token4 == NULL )token4="0";
	return atoi(token1)*60000+atoi(token3)*1000+atoi(token4)*10;

}