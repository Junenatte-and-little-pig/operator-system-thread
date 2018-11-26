#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define T 2

int balance[N];
int flag[N];
pthread_mutex_t mutex,balanceMutex[N];
pthread_t threads[N];
struct thread_data{
	int id,source,dest,money;
};

struct thread_data threadDataArray[N];

void *Pay(void *threadarg){
	struct thread_data *my_data;
	int id,source,dest,money;
	my_data=(struct thread_data *)threadarg;
	id=my_data->id;
	source=my_data->source;
	dest=my_data->dest;
	money=my_data->money;
	while(1){
		pthread_mutex_lock(&mutex);
		if(flag[source]&&flag[dest]){
			flag[source]=flag[dest]=0;
			pthread_mutex_lock(&balanceMutex[source]);
			pthread_mutex_lock(&balanceMutex[dest]);
			pthread_mutex_unlock(&mutex);
			break;
		}
		else
			pthread_mutex_unlock(&mutex);
	}
	if(balance[source]<1000||balance[source]<money)
		printf("thread %d: acoount: %d[%d] can't pay %d\n",id,source,balance[source],money);
	else{
		printf("thread %d: acoount: %d[%d] pay %d to account: %d[%d]\n",id,source,balance[source],money,dest,balance[dest]);
		balance[source]-=money;
		balance[dest]+=money;
		printf("\tbalance[%d] = %d, balance[%d] = %d\n",source,balance[source],dest,balance[dest]);
	}
	pthread_mutex_lock(&mutex);
	flag[source]=flag[dest]=1;
	pthread_mutex_unlock(&balanceMutex[source]);
	pthread_mutex_unlock(&balanceMutex[dest]);
	pthread_mutex_unlock(&mutex);
}

int main(int argc,char *argv[]){
	if(pthread_mutex_init(&mutex,NULL)!=0){
		perror("mutex init failed!");
		exit(1);
	}
	int i;	
	for(i=0;i<N;i++){
		balance[i]=10000;
		flag[i]=1;
		if(pthread_mutex_init(&balanceMutex[i],NULL)!=0){
			printf("balanceMutex[%d] init failed!",i);
			exit(1);
		}	
	}
	srand((int)time(0));
	int j;
	for(j=0;j<T;j++){
		for(i=0;i<N;i++){
		int source=rand()%10;
		int dest=rand()%10;
		while(source==dest)
			dest=rand()%10;
		int money=rand()%10000;
		threadDataArray[i].id=i;
		threadDataArray[i].source=source;
		threadDataArray[i].dest=dest;
		threadDataArray[i].money=money;
		}
		for(i=0;i<N;i++)
			if(pthread_create(&threads[i],NULL,Pay,(void *)&threadDataArray[i])!=0){
				printf("thread[%d] creation failed!",i);
				exit(-1);
			}
		for(i=0;i<N;i++)
			pthread_join(threads[i],NULL);
	}
	int sum=0;
	for(i=0;i<N;i++){
		printf("balance[%d]=%d\n",i,balance[i]);
		sum+=balance[i];
	}
	printf("sum=%d\n",sum);
	return 0;
}
