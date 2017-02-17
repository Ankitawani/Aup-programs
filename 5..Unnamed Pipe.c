		
/*
Program for a Pipe-Sending data from parent to child over a pipe.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#define BUFFSIZE 128

int main()
{
	int fd[2],pid,n;
	char rbuf[BUFFSIZE],wbuf[BUFFSIZE];
	memset(rbuf,'\0',BUFFSIZE);
	memset(wbuf,'\0',BUFFSIZE);
	printf("Enter the data to be send from parent to child over a pipe:\n");
	scanf("%s",wbuf);
	if(pipe(fd)<0)
		printf("pipe error\n");
	pid=fork();
	if(pid<0)
		printf("fork error\n");
	else if(pid>0)
	{
		close(fd[0]);
		write(fd[1],wbuf,BUFFSIZE);
		wait(NULL);
	}
	else if(pid==0)
	{
		sleep(1);
		close(fd[1]);
		read(fd[0],rbuf,BUFFSIZE);
		printf("\nPrinted in child process, by fd[0]\n %s\n",rbuf);
	}
	exit(0);
}






