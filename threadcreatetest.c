<<<<<<< HEAD
#include <pthread.h>
#include <stdio.h>
void *create(void *arg) {
	printf("new thread created ..... ");
}
int main(int argc,char *argv[]){
	pthread_t tidp;
	int error;
    error=pthread_create(&tidp, NULL, create, NULL);
    if(error!=0){
    	printf("pthread_create is not created ... ");
    	return -1;
    }
    printf("prthread_create is created... ");
    return 0;
}
=======
#include <pthread.h>
#include <stdio.h>
void *create(void *arg) {
	printf("new thread created ..... ");
}
int main(int argc,char *argv[]){
	pthread_t tidp;
	int error;
	error=pthread_create(&tidp, NULL, create, NULL);
	if(error!=0){
		printf("pthread_create is not created ... ");
		return -1;
	}
	printf("prthread_create is created... ");
	return 0;
}
>>>>>>> 791f0ac8830d7e109b1f9f07a799b9d86d176ff2
