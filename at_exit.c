/*  Name :- Madhuri Rajendra Patil
   Batch:-B1(08)
Title : Program for named pipe (client)
*/

#include<stdlib.h>
#include<stdio.h>

static void my_exit1(void);
static void my_exit2(void);
static void my_exit3(void);
static void my_exit4(void);

int main(void)
{
   if(atexit(my_exit4)!=0)
    printf("Can't regester my_exit4");
     if(atexit(my_exit3)!=0)
    printf("Can't regester my_exit3");
     if(atexit(my_exit2)!=0)
    printf("Can't regester my_exit2");
    if(atexit(my_exit1)!=0)
    printf("Can't regester my_exit1");
    return(0);
}

static void my_exit1(void)
{
  printf("First exit handler\n");
}

static void my_exit2(void)
{
  printf("Second exit handler\n");
}

static void my_exit3(void)
{
  printf("Third exit handler\n");
}

static void my_exit4(void)
{
  printf("Fourth exit handler\n");
}

/* OUTPUT:-
student@student-HCL-Desktop:~$ gcc at_exit.c
student@student-HCL-Desktop:~$ ./a.out
First exit handler
Second exit handler
Third exit handler
Fourth exit handler
student@student-HCL-Desktop:~$ 
*/
 

