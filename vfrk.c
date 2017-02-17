/*Program for VFork function.
Name:Ankita K.Wani
Roll no.:67 BE[B]
*/

#include<stdlib.h>          /*Header files*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int v_glob=8;
 
int main(void)

{
     int var2;       /*variables declaration*/
     pid_t pid;
     var2=88;

      
       printf("before fork\n");

           if((pid=vfork())<0)
            {
               printf("Vfork error");
               }

         /*child creation.*/

            else if(pid==0)      
            {
                v_glob++;
                var2++;
                _exit(0);
             }


        printf("pid=%d,v_glob=%d,var2=%d",getpid(),v_glob,var2);
        exit(0);
 }

  /*Output:
student@student-HCL-Desktop:~$ gcc vfrk.c
student@student-HCL-Desktop:~$ ./a.out

  before fork
pid=2526,v_glob=9,var2=89
*/           

