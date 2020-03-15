#include<stdio.h>
#include <unistd.h>
#include "base.h"
static int testnum;
int xyz(int num){
	
	printf("lib fun xyz run : %d\n",num);
	return num*2;
}


int main(int argc,char *args[]){
	int id;
	int i=0;
	printf("lib main\n");
	return 0;
}