#include "stdafx.h";
SysInfo sys_info;
void datain(){

	int i=0;SportsEvent eve;PerInfo peo;
	/*peo.id=2010101010;
	strcpy(peo.password ,"123");
	Person_change(peo,6);
	//peo=Person_getinfo(2010101010);
	
	
	sys_incyuan("˼Դ");
	sys_incyuan("֪��");
	sys_incxi("��");
	sys_incxi("��");
	

	
	peo.gender=0;
	strcpy(peo.password,"123456");
	strcpy(peo.name ,"С��");
	peo.id=2010101010;
	strcpy(peo.faculty,"��");
	strcpy(peo.organization,"֪��");
	Person_create(peo);
	strcpy(peo.name ,"С��");
	peo.id=2010101011;
	strcpy(peo.faculty,"��");
	strcpy(peo.organization,"˼Դ");
	Person_create(peo);
	strcpy(peo.name ,"С��");
	peo.id=2010101012;
	strcpy(peo.faculty,"��");
	strcpy(peo.organization,"˼Դ");
	Person_create(peo);
	strcpy(peo.name ,"Сa");
	peo.id=2010101013;
	strcpy(peo.faculty,"��");
	strcpy(peo.organization,"˼Դ");
	Person_create(peo);
	strcpy(peo.name ,"Сb");
	peo.id=2010101014;
	strcpy(peo.faculty,"��");
	strcpy(peo.organization,"˼Դ");
	Person_create(peo);
	strcpy(peo.name ,"Сc");
	peo.id=2010101015;
	strcpy(peo.faculty,"��");
	strcpy(peo.organization,"֪��");
	Person_create(peo);
	strcpy(peo.name ,"Сd");
	peo.id=2010101016;
	strcpy(peo.faculty,"��");
	strcpy(peo.organization,"֪��");
	Person_create(peo);
	strcpy(peo.name ,"Сe");
	peo.id=2010101017;
	strcpy(peo.faculty,"��");
	strcpy(peo.organization,"֪��");
	Person_create(peo);
	

	
	strcpy(eve.name,"�ܲ�");
	eve.type=11;
	strcpy(eve.place,"�ٳ�");
	eve.timecost=60;
	eve.hasFinals=1;
	i=Event_create(eve);
	printf("%d\n",i);
	strcpy(eve.name,"��Զ");
	eve.type=10;
	strcpy(eve.place,"�ٳ�");
	eve.timecost=60;
	eve.hasFinals=0;
	i=Event_create(eve);
	
	
	
	Event_inc(1041,2010101010,0);
	Event_inc(1041,2010101011,0);
	Event_inc(1041,2010101012,0);
	Event_inc(1041,2010101013,0);
	Event_inc(1041,2010101014,0);
	Event_inc(1041,2010101015,0);
	Event_inc(1041,2010101016,0);
	Event_inc(1041,2010101017,0);

	Event_changescore(1041,2010101010,0,1);
	Event_changescore(1041,2010101011,0,2);
	Event_changescore(1041,2010101012,0,3);
	Event_changescore(1041,2010101013,0,4);
	Event_changescore(1041,2010101014,0,5);
	Event_changescore(1041,2010101015,0,6);
	Event_changescore(1041,2010101016,0,7);
	Event_changescore(1041,2010101017,0,8);

	Event_inc(1041,2010101010,1);
	Event_inc(1041,2010101011,1);
	Event_inc(1041,2010101012,1);
	Event_inc(1041,2010101013,1);
	Event_inc(1041,2010101014,1);
	Event_inc(1041,2010101015,1);

	Event_changescore(1041,2010101010,1,1);
	Event_changescore(1041,2010101011,1,2);
	Event_changescore(1041,2010101012,1,3);
	Event_changescore(1041,2010101013,1,4);
	Event_changescore(1041,2010101014,1,5);
	Event_changescore(1041,2010101015,1,6);

	Event_inc(1467,2010101010,0);
	Event_inc(1467,2010101011,0);
	Event_inc(1467,2010101012,0);
	Event_inc(1467,2010101013,0);*/
	Person_list();
	Event_list();
	eve=Event_getinfo(1041);
	printf("%d\n",eve.finNum);
	printf("%d\nԤ����\n",eve.maxpeople);
	for(i=0;i<eve.maxpeople;i++)
		printf("%d\t%d\n",eve.prePerson[i].id,eve.prePerson[i].score);
	puts("������\n");
	for(i=0;i<eve.finNum;i++)
		printf("%d\t%d\n",eve.finPerson[i].id,eve.finPerson[i].score);
	printf("%d\n",i);

}
extern int toSituationMenu();
int main()
{
	sys_init();
	//Person_notice(10000,"����һ������");
	//Person_notice(10000,"���ǵڶ�������");
	//datain();
	//getchar();
	//toSituationMenu();
	mainMenu();
	return 0;
}