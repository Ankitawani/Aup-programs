/* Name :- Ankita K. Wani
   Batch:-B4(67)
Title : Program for named pipe (server)
*/

#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

#define filename "/home/student/Namepipe"
#define BUFFSIZE 128

int main()
{
	int fd,ret_val,count,numread;
	char buf[BUFFSIZE];
	
	memset(buf,'\0',BUFFSIZE);
	
	ret_val=mkfifo(filename,0666);
	if(ret_val==-1)
	{
		printf("mkfifo error\n");
		exit(0);
	}
	fd=open(filename,O_RDONLY);
	numread=read(fd,buf,BUFFSIZE);
//buf[numread]='\0';
	printf("Via Server program :read from the pipe:- %s\n",buf);
	count=0;
	while(count<numread)
	{
		buf[count]=toupper(buf[count]);
		count++;
	}
	printf("Via server program :converted String is : %s\n",buf);
}
/*Output:
student@student-HCL-Desktop:~$ gcc -o server server1.c
student@student-HCL-Desktop:~$ ./server &
[1] 2844
student@student-HCL-Desktop:~$ gcc -o client client1.c
student@student-HCL-Desktop:~$ ./client ssbtcoet
Via Server program :read from the pipe:- ssbtcoet
Via server program :converted String is : SSBTCOET
[1]+  Exit 51                 ./server
student@student-HCL-Desktop:~$ 

*/



