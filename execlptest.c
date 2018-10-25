#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <wait.h>
#include <errno.h>
#include <error.h>
char command[256];
void main(){
	int rtn;
	int errorno;
	while(1){
		printf(">");
		fgets(command,256,stdin);
		command[strlen[command]-1]=0;
		if(fork==0){
			execlp(command,command);
			peror(command);
			exit(errorno);
		}
		else{
			wait(&rtn);
			printf("child process return %d\n",rtn);
		}
	}
}