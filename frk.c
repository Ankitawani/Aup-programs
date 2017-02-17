/*Program for Fork function.
Name:Ankita K.Wani
Roll no.:67 BE[B]
*/

#include<stdlib.h>     /*Header files*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int v_glob=10;                        
 char buf1[]="a write to stdout\n";
int main(void)

{
     int var1;             /*Variables declaration*/
     pid_t pid;
     var1=56;
      
    /*if child & parentworking on same process*/

       if(write(STDOUT_FILENO,buf1,sizeof(buf1)-1)!=sizeof(buf1)-1)
         printf("before fork\n");

           if((pid=fork())<0)             
            {
               printf("write fork error");
               }
            else if(pid==0)                  /*Creating child*/ 
            {
                v_glob++;
                var1++;
             }
             else {
                   sleep(2);
                  }

       /*Printing all values*/
        printf("pid=%d,v_glob=%d,var1=%d",getpid(),v_glob,var1);
        exit(0);
 }


/*Output:
 student@student-HCL-Desktop:~$ gcc frk.c
student@student-HCL-Desktop:~$ ./a.out
before fork
pid=2360,v_glob=11,var1=57pid=2359,v_glob=10,var1=56
*/
