#include<stdio.h>
#include <unistd.h>
#include "base.h"
//int xyz(int num);
int testnum;
/*
int xyz(int num){
	
	printf("main xyz\n");
	return 0;
}
*/
int main(int argc,char *args[]){
	int id;
	int i=0;
	sscanf(args[1],"%d",&id);
	
	while(1){
		testnum=xyz(id);
		printf("test id:%d num:%d\n",id,testnum);
		sleep(10);
		i++;
	}
	return 0;
}