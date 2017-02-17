/* Name :- Ankita K. Wani
   Batch:-B4(67)
 Program for signal catching
*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>

static void sig_user(int);

int main(void)
{
	if(signal(SIGUSR1,sig_user)==SIG_ERR)
		printf("Can't catch user signal SIGUSR1");
	if(signal(SIGUSR2,sig_user)==SIG_ERR)
		printf("\n Can't catch SIGUSR2");
	for(;;)            //unused work
	pause();
}
static void sig_user(int signo)
{
	if(signo==SIGUSR1)
		printf("\n Caught SIGUSR1\n");
	else if(signo==SIGUSR2)
		printf("\n Caught SIGUSR2\n");
	else
		printf("\n Received Signal %d\n",signo);	
}

/*Output:
student@student-HCL-Desktop:~$ gcc sig.c
student@student-HCL-Desktop:~$ ./a.out &
[1] 2517
student@student-HCL-Desktop:~$ kill -USR1 2517

 Caught SIGUSR1
student@student-HCL-Desktop:~$ kill -USR2 2517

 Caught SIGUSR2
student@student-HCL-Desktop:~$ ./a.out &
[2] 2518
student@student-HCL-Desktop:~$ kill -USR2 2518

 Caught SIGUSR2

*/
