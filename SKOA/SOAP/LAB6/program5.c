#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/errno.h>


void my_SIGUSR1();
void my_SIGUSR2();

int i=0;
char a;
// deklaracja zmiennej w ktorej zostanie zapisany identyfikator potomka 	
pid_t child_pid;
int mpid;


int main() 
{
    printf ("PID procesu głownego: %d\n", (int) getpid ());
    printf ("PPID procesu głównego: %d\n", (int) getppid ());
    child_pid = fork();
    if (child_pid != 0) {
        printf("*** Proces macierzysty: PID=%d, PPID=%d, CPID=%d\n",(int)getpid(),(int)getppid(),(int)child_pid);
        wait(NULL);	    
    } else {
//            i++;
        printf("### Proces potomny: PID=%d, PPID=%d, i=%d\n",(int)getpid(),(int)getppid(),i);
	if (signal(SIGUSR1,my_SIGUSR1) == SIG_ERR){
    	    perror("Funkcja signal ma problem z SIGUSR1");
    	    exit(EXIT_FAILURE);
	}
       
       printf("Program tworzy potomka który oczekuje na sygnał SIGUSR1\n");
       printf("Aby zakonczyc program uzyj SIGKILL, badz wprowadz dowolny znak i nacisnij enter\n");
       scanf("%d",&a);
       
	
    }
  

  return 0;
}

void my_SIGUSR1(int sig){
    i++;
    printf("@[%d] Otrzymano SIGUSR1\n",i);
    child_pid = fork();
    if (child_pid != 0) {
    	printf("[%d] Proces macierzysty: PID=%d, PPID=%d, CPID=%d\n",i,(int)getpid(),(int)getppid(),(int)child_pid);
    	wait(NULL);	    
    	printf("[%d] Proces potomny sie zakonczyl");
    	pause();
    } else {
        mpid=(int)getpid();
        printf("[%d] Proces potomny: PID=%d, PPID=%d \n",mpid,mpid,(int)getppid());
        for(int x=0;x<5;x++){
    	  printf("[%d]",mpid);
    	}  
        printf("\n");
    	 
    }	
}
