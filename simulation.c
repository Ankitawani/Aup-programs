/*Name: Ankita K. Wani
Roll no.:67
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>				
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include<time.h>
#include<utmp.h>
#include<signal.h>

#define SIZE 255
#define BUFFSIZE 4096

void make_d(),remove_d(),hard_l(),soft_l();
char name[SIZE];
char buf[BUFFSIZE];
int fd,n;

int main(void)				
{
	int ch;
	system("clear");
	while(1)
	{
		printf("\n*******  Simulation *******");	
		printf("\n1. Create directory.");
		printf("\n2. Remove directory.");
		printf("\n3. Hard link.");
		printf("\n4. Soft link.");
                printf("\n5.pwd.");
		printf("\n6. date");
                printf("\n7. uname");
                printf("\n8. who");
		printf("\n9. wc");
		printf("\n10.sleep");
	        printf("\n11.exit.");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:make_d();		
                               break;
			case 2:remove_d();		
                               break;
			case 3:hard_l();		
                               break;
                        case 4:soft_l();		
                               break;
                        case 5:_pwd();
                                break;
                        case 6:_date();
                               break;
                        case 7:_uname();
                               break;
                        case 8:who();
                               break;
                        case 9:wc();
                               break;
                        case 10:sleep1();
                               break;
                         case 11:exit(0);
                       default:
				printf("\nInvalid choice.");	break;
		}	
	}
}		

void make_d() 	
{
	
	char name[SIZE];
	printf("\nEnter a directory name: ");
	scanf("%s",name);
	
	if(!mkdir(name,00700))
	   printf("\nDirectory created successfully");
	else
			
		printf("\n Error: %s",strerror(errno));


}

void remove_d() 	
{
	
	char name[SIZE];
	printf("\nEnter a directory name: ");
	scanf("%s",name);
	
	if(!rmdir(name))
	   printf("\nDirectory removed. ");
	else
			
		printf("\n Error: %s",strerror(errno));

}

void hard_l() 	
{
	int f;
	char oldfile[SIZE],  newfile[SIZE];
	printf("\nEnter old path : ");
	scanf("%s",oldfile);
        printf("\n Enter new path:");
        scanf("%s",newfile);
	
        f=link(oldfile,newfile);
	if(f==-1)
	   printf("\nError: %s",strerror(errno));
	else
	{
		
		printf("\nHard link is created.");

	}
	
}

void soft_l() 	
{
	int f;
	char oldfile[SIZE],  newfile[SIZE];
	printf("\nEnter old path : ");
	scanf("%s",oldfile);
        printf("\n Enter new path:");
        scanf("%s",newfile);
	
        f=symlink(oldfile,newfile);
	if(f==-1)
	   printf("\nError:%s",strerror(errno));
	else
	{
		
		printf("\nSoft(symbolic) link is created.");

	}
	
}

void _pwd()
{
 char dte[50];
  getcwd(dte,sizeof(dte));
  printf("%s",(dte));
}

void _date()
{
   char dte[50];
   time_t tme=0;
struct tm *ctm;
 time(&tme);
ctm=(struct tm*)localtime(&tme);
strftime(dte,sizeof(dte),"%a %b %d %x %z %y\n",ctm);
   printf("%s",dte);
}

void _uname()	// Code for uname command
{
	struct utsname name_sys;	
	if(uname(&name_sys)==-1)
{
err_msg();
}
else
		printf("%s\n",name_sys.sysname);
	
					
}
  void wc()
{
 unsigned int w=0,l=0,c=0,flag=0;
 FILE *fp;
 char name[SIZE],ch, back='\0';
 printf("\n Enter File name");
 scanf("%s",name);
  fp=fopen(name,"r");	
	if(fp==NULL)
err_msg();
s
		
	else
	{
		while((ch=getc(fp))!=EOF)
		{	
			c++;
			if(ch=='\n')				
				l++;
			if(isgraph(ch))
				w++;
			
		}	
		printf("\t%d\t%d\t%d\t%s\n",l,w,c,name);
		close(fp);
	}	
}

void who()			// Code for who command
{
	struct utmp *ut;
	struct tm *tme;
	char buf[30];
	system("clear");
	setutent();
	while((ut=getutent())!=NULL)
	{
		if(ut->ut_type==7)
		{
			tme=localtime(&ut->ut_time);
			strftime(buf,sizeof(buf),"%F %R ",tme);
			printf("%-9s%-8s%-20s (%s)\n",ut->ut_user,ut->ut_line,buf,ut->ut_host);
		}
	}
}



void sleep1()			// Code for sleep command
{
	int sec;
	printf("\nEnter number of seconds: ");
	scanf("%d",&sec);
	signal(SIGALRM,sig_alrm);
	alarm(sec);
	pause();	
}

void err_msg()		//Code for error msg a file
{
	int errsv;
	errsv=errno;
	printf("\nError : %s",strerror(errsv));
}

 

/*Output:
 *******  Simulation *******
1. Create directory.
2. Remove directory.
3. Hard link.
4. Soft link.
5.Exit.
Enter your choice: 1

Enter a directory name: aup1

Directory created successfully
*******  Simulation *******
1. Create directory.
2. Remove directory.
3. Hard link.
4. Soft link.
5.Exit.
Enter your choice: 2     

Enter a directory name: ankita

 Error: No such file or directory
*******  Simulation *******
1. Create directory.
2. Remove directory.
3. Hard link.
4. Soft link.
5.Exit.
Enter your choice: 1

Enter a directory name: ankita

Directory created successfully
*******  Simulation *******
1. Create directory.
2. Remove directory.
3. Hard link.
4. Soft link.
5.Exit.
Enter your choice: 3

Enter old path : aup1

 Enter new path:ankita

Error: File exists
*******  Simulation *******
1. Create directory.
2. Remove directory.
3. Hard link.
4. Soft link.
5.Exit.
Enter your choice: 3

Enter old path : mm      

 Enter new path:my 

Hard link is created.

*******  Simulation *******
1. Create directory.
2. Remove directory.
3. Hard link.
4. Soft link.
5.Exit.
Enter your choice: 4

Enter old path : aup1

 Enter new path:aup2

Soft(symbolic) link is created.
*******  Simulation *******
1. Create directory.
2. Remove directory.
3. Hard link.
4. Soft link.
5.Exit.
Enter your choice: 2

Enter a directory name: ankita

Directory removed. 

*/
