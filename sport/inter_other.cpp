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