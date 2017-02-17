/* Name :- Ankita K. Wani
   Batch:-B4(67)
 Program for thread creation.
*/

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[2];
void  * thr_fn(void *arg)
{
	unsigned long i=0;
	pthread_t id = pthread_self();
 	if(pthread_equal(id,tid[0]))
 	{
	  printf("\n First thread processing \n ");
	}
	else
	{
 	  printf("\n Second thread processing \n");
	}
	
	for(i=0;i<(0xfffffff);i++)
	return NULL;
}

int main(void)
{
	int i=0;
	int err;
	while(i<2)
	{
	  err=pthread_create(&tid[i],NULL,&thr_fn,NULL);  //thread creation
	  if(err!=0)
	    printf("\n Can't create thread");
	  else
	    printf("\n Thread created successfully");
	  i++;
	}
  sleep(5);
  return 0;
}

/*student@student-HCL-Desktop:~$ gcc thread.c -lpthread
student@student-HCL-Desktop:~$ ./a.out

 Thread created successfully
 First thread processing 
 
 Thread created successfully
 Second thread processing 
*/
