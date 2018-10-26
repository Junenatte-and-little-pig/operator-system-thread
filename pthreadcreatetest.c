#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
=======
#include <unistd.h>
>>>>>>> 791f0ac8830d7e109b1f9f07a799b9d86d176ff2
#define NUM_THREADS 8
char *messages[NUM_THREADS];
struct thread_data{
	int thread_id;
	int sum;
	char *message;
};
struct thread_data thread_data_array[NUM_THREADS];
void *PrintHello(void *threadarg){
	int taskid,sum;
	char *hello_msg;
	struct thread_data *my_data;
	sleep(1);
	my_data=(struct thread_data *)threadarg;
	taskid=my_data->thread_id;
	sum=my_data->sum;
	hello_msg=my_data->message;
	printf("Thread %d: %s Sum=%d\n",taskid,hello_msg,sum);
	pthread_exit(NULL);
}
int main(int argc,char *argv[]){
	pthread_t threads[NUM_THREADS];
	int *taskids[NUM_THREADS];
	int rc,t,sum;
	sum=0;
<<<<<<< HEAD
	message[0]="English: Hello World!";
	message[1]="French: Bonkour, le monde!";
	message[2]="Spanish: Hola al mundo";
	message[3]="Klingon: Nuq neH";
	message[4]="German: Guten Tag, Welt!";
	message[5]="Russian: Zdravstvytye, mir!";
	message[6]="Japan: Sekai e konnichiwa!";
	message[7]="Latin: Orbis, te saluto!";
=======
	messages[0]="English: Hello World!";
	messages[1]="French: Bonjour, le monde!";
	messages[2]="Spanish: Hola al mundo";
	messages[3]="Klingon: Nuq neH";
	messages[4]="German: Guten Tag, Welt!";
	messages[5]="Russian: Zdravstvytye, mir!";
	messages[6]="Japan: Sekai e konnichiwa!";
	messages[7]="Latin: Orbis, te saluto!";
>>>>>>> 791f0ac8830d7e109b1f9f07a799b9d86d176ff2
	for(t=0;t<NUM_THREADS;t++){
		sum=sum+t;
		thread_data_array[t].thread_id=t;
		thread_data_array[t].sum=sum;
		thread_data_array[t].message=messages[t];
		rc=pthread_create(&threads[t],NULL,PrintHello,(void *)&thread_data_array[t]);
		if(rc){
<<<<<<< HEAD
			printf("Error; returncode f is %d\n",rc);
=======
			printf("Error; return code f is %d\n",rc);
>>>>>>> 791f0ac8830d7e109b1f9f07a799b9d86d176ff2
			exit(-1);
		}
	}
	pthread_exit(NULL);
<<<<<<< HEAD
}
=======
}
>>>>>>> 791f0ac8830d7e109b1f9f07a799b9d86d176ff2
