#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int balances[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
void *Transfer(void *arg){
	int i=rand()%10;
	int j=rand()%10;
	int money=rand()%1000;
	while(balances[i]<1000)
		sleep(1000);
	if(i!=j&&balances[i]>=money){
		balances[i]-=money;
		balances[j]+=money;
	}
	printf("Transfer money:%d from account %d to account %d\n",money, i, j);
}
int main(int argc,char *argv[]){
	pthread_t threads[10];
	int i,rc,t,sum;
	for(i=0;i<20;i++){
		for(t=0;t<10;t++){
			rc=pthread_create(&threads[t],NULL,Transfer,NULL);
			if(rc){
				printf("Error; return code f is %d\n",rc);
				exit(-1);
			}
		}
	}
	sum=0;
	for(i=0;i<10;i++){
		printf("account %d has money %d\n",i,balances[i]);
		sum+=balances[i];
	}
	printf("sum=%d\n",sum);
}
