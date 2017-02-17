//program for file handling

#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>

#define SIZE 255
#define BUFFSIZE 4096

void create_file(),read_file(),write_file(),append_file();
void truncate_file(),remove_file(),rename_file(),hole_file(),type_file();
void err_msg();

char name[SIZE];
char buf[BUFFSIZE];
int fd,n;

int main(void)
{
	int ch;
	system("clear");
	while(1)
	{
	   printf("\n ******** File Management ***********");
	   printf("\n1.Create file ");
	   printf("\n2.Read file ");
	   printf("\n3.Write file ");
	   printf("\n4.append file ");
	   printf("\n5.truncate file ");
	   printf("\n6.remove file ");
	   printf("\n7.rename file ");
	   printf("\n8.hole file ");
	   printf("\n9.type of file ");
	   printf("\n10.Exit");
	   printf("\n Enter your choice ");
	   scanf("%d",&ch);
	#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>

#define SIZE 255
#define BUFFSIZE 4096

void create_file(),read_file(),write_file(),append_file();
void truncate_file(),remove_file(),rename_file(),hole_file(),type_file();
void err_msg();

char name[SIZE];
char buf[BUFFSIZE];
int fd,n;

int main(void)
{
	int ch;
	system("clear");
	while(1)
	{
	   printf("\n ******** File Management ***********");
	   printf("\n1.Create file ");
	   printf("\n2.Read file ");
	   printf("\n3.Write file ");
	   printf("\n4.append file ");
	   printf("\n5.truncate file ");
	   printf("\n6.remove file ");
	   printf("\n7.rename file ");
	   printf("\n8.hole file ");
	  
	switch(ch)
	{
		case 1: create_file();		break;
		case 2: read_file();		break;
		case 3: write_file();		break;
		case 4: append_file();		break;
		case 5: truncate_file();	break;
		case 6: remove_file();		break;
		case 7: rename_file();		break;
		case 8: hole_file();		break;
		case 9: type_file();		break;
		case 10:exit(0);
                default:printf("\nInvalid choice.");	break;
	}
	}
}

void create_file() 	//Code for creating a file
{
	int fd;
	char name[SIZE];
	printf("\nEnter a file name: ");
	scanf("%s",name);
	fd=creat(name,00700);
	if(fd==-1)
		err_msg();
	else
	{
		printf("\nFile created successfully");
		printf("\nFile Descriptor :%d",fd);

	}
	close(fd);
}
void read_file()	//Code for reading a file
{
	int fd,n;
	char name[SIZE],buf[BUFFSIZE];
	printf("\nEnter a file name: ");
	scanf("%s",name);
	fd=open(name,O_RDWR);
	memset(buf,'\0',BUFFSIZE);
	if(fd==-1)
		err_msg();
	else
	{
		printf("\nContents of file is :\n");
		while((n=read(fd,buf,BUFFSIZE))>0)
			printf("%s",buf);
	}
	close(fd);		
}	
void write_file()	//Code for writing a file
{
	int fd,n,index=0;
	char name[SIZE],buf[BUFFSIZE],ch='\0';
	printf("\nEnter a file name: ");
	scanf("%s",name);
	fd=open(name,O_RDWR|O_CREAT,00700);
	if(fd==-1)
		err_msg();
	else
	{
		printf("\nEnter data : \n");
		memset(buf,'\0',BUFFSIZE);
		while((ch=getc(stdin))!=EOF)
		{
			if(ch=='\b')
				buf[--index]=ch;
			else
				buf[index++]=ch;
		}
		write(fd,buf,index); 
		printf("\nData written successfully(%d bytes)",index);

	}
	close(fd);		
}

void append_file()	//Code to append in file
{
	int fd,n,index=0;
	char name[SIZE],buf[BUFFSIZE],ch='\0';
	printf("\nEnter a file name: ");
	scanf("%s",name);
	fd=open(name,O_RDWR|O_APPEND,00700);
	if(fd==-1)
		err_msg();
	else
	{
		printf("\nEnter data : \n");
		memset(buf,'\0',BUFFSIZE);
		while((ch=getc(stdin))!=EOF)
		{
			if(ch=='\b')
				buf[--index]=ch;
			else
				buf[index++]=ch;
		}
		write(fd,buf,index); 
		printf("\nData written successfully(%d bytes)",index);
	}
	close(fd);		
}	


void truncate_file()
{
	int length;
	printf("Enter file name to truncate");
	scanf("%s",name);
	printf("Enter the length to truncate the data");
	scanf("%d",&length);
	
	length=truncate(name,length);
	printf("The file is truncated successfully.");
}

void remove_file()	//Code for removing a file
{
	int fd;
	char name[SIZE],buf[BUFFSIZE],ch='\0';
	printf("\nEnter a file name: ");
	scanf("%s",name);
	fd=remove(name);
	if(fd==-1)
		err_msg();
	else
		printf("\nFile removed successfully.");		
}
void rename_file()	//Code for renaming a file
{
	int fd;
	char name[SIZE],newname[SIZE],buf[BUFFSIZE],ch='\0';
	printf("\nEnter a file name: ");
	scanf("%s",name);
	printf("\nEnter new file name: ");
	scanf("%s",newname);
	fd=rename(name,newname);
	if(fd==-1)
		err_msg();
	else
		printf("\nFile renamed successfully.");		
}

void hole_file()	//Code for creating a file with hole
{
	
	char buf1[] = "abcdefghij";
	char buf2[] = "ABCDEFGHIJ";
	int offset;

	printf("Enter the file name to create \n");
	scanf("%s",name);
	fd = creat(name,00700);
	
	n = write(fd,buf1,10);
	printf("%d bytes written to %s\n",n,name);
	
	offset = lseek(fd,8192,SEEK_SET);
	printf("HOle is created \n");

	n = write(fd,buf2,10);
	printf("%d bytes written after hole in %s\n",n,name);
}

void type_file()	//Code for checking type of a file
{
	char name[SIZE];
	struct stat buf;
	printf("\nEnter a file name: ");
	scanf("%s",name);
	if(lstat(name,&buf)<0)
		err_msg();
	if(S_ISREG(buf.st_mode))
		printf("\nRegular File");
	else if(S_ISDIR(buf.st_mode))
		printf("\nDirectory");
	else if(S_ISCHR(buf.st_mode))
		printf("\nCharacter Special File");
	else if(S_ISBLK(buf.st_mode))
		printf("\nBlock Special File");
	else if(S_ISFIFO(buf.st_mode))
		printf("\nFIFO File");
	else if(S_ISLNK(buf.st_mode))
		printf("\nSymbolic Link");
	else if(S_ISSOCK(buf.st_mode))
		printf("\nSocket");
	else
		printf("\nUnknown File Type");	
}

void err_msg()		//Code for error msg a file
{
	int errsv;
	errsv=errno;
	printf("\nError : %s",strerror(errsv));
}

/*output
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 1

Enter a file name: sneha

File created successfully
File Descriptor :3
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 3

Enter a file name: sneha

Enter data : 
hello good morning

Data written successfully(20 bytes)
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 2

Enter a file name: sneha

Contents of file is :

hello good morning
...

 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 4

Enter a file name: sneha

Enter data : 
how are you...

Data written successfully(16 bytes)
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 5
Enter file name to truncatesneha
Enter the length to truncate the data4
The file is truncated successfully.
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 6

Enter a file name: f60

File removed successfully.
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 7

Enter a file name: sneha

Enter new file name: shiwani

File renamed successfully.
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 8
Enter the file name to create 
xyz.hole
10 bytes written to xyz.hole
HOle is created 
10 bytes written after hole in xyz.hole

 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice ^Z
[1]+  Stopped                 ./a.out
student@student:~$ od -c xyz.hole
0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0020000   A   B   C   D   E   F   G   H   I   J
0020012
student@student:~$ gcc pr1.c
student@student:~$ ./a.out


 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 9

Enter a file name: /etc/passwd

Regular File
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 9

Enter a file name: /dev/log

Socket
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 9

Enter a file name: /dev/cdrom

Symbolic Link
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 9

Enter a file name: /dev/tty

Character Special File
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 9

Enter a file name: /etc

Directory
 ******** File Management ***********
1.Create file 
2.Read file 
3.Write file 
4.append file 
5.truncate file 
6.remove file 
7.rename file 
8.hole file 
9.type of file 
10.Exit
 Enter your choice 10
student@student:~$ 
	
*/
