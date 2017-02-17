/* Name :- Ankita K.Wani
   Batch:-B4(67)
Aim: Program for creating the daemon process in UNIX/Linux
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/resource.h>
#include<stdlib.h>

int main(void)
{
	pid_t pid,sid;
	FILE *fp;

	//CALLING UMASK()
	umask(0);

	//FORK-LET PARENT EXIT
	pid=fork();
	if(pid<0)
		printf("Fork error\n");
	else if(pid>0)
		exit(0);

	//CALL SETSID() TO CREATE NEW SESSION
	sid=setsid();
	if(sid<0)
		printf("setsid error..\n");

	//CHANGE WORKONG DIR TO /
	chdir("/");

	//writing to log file
	fp=fopen("/home/student/daemon.log","a+");
	while(1)
	{
		fprintf(fp,"printing in daemon log file..\n");
		sleep(2);
		printf("daemon\n");
	}
}

/*Output:
student@student-HCL-Desktop:~$ gcc daemon.c
student@student-HCL-Desktop:~$ ./a.out
student@student-HCL-Desktop:~$ daemon
daemon
daemon
daemon
daemon
daemon
daemon
daemon
daemon
daemon
daemon
daemon
daemon
daemon
daemon
daemon

*/
