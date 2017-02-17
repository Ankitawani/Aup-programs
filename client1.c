/*  Name :- Ankita K.Wani
   Batch:-B4(67)
Title : Program for named pipe (client)
*/

#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define filename "/home/student/Namepipe"

int main(int argc,char *argv[])
{
	int fd;
	if(argc!=2)
	{
		printf("Single argument required\n");
		exit(0);
	}
	fd=open(filename,O_WRONLY);
	write(fd,argv[1],strlen(argv[1]));
}

