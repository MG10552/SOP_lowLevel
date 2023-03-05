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
pid_t child_pid1, child_pid2;

int main() 
{
    printf ("PID procesu głownego: %d\n", (int) getpid ());
    printf ("PPID procesu głównego: %d\n", (int) getppid ());
    child_pid1 = fork();
    if (child_pid1 != 0) child_pid2 = fork();
    if ((child_pid1 != 0)&&(child_pid2 != 0)) {
	printf("*** Proces macierzysty: PID=%d, PPID=%d, CPID1=%d, CPID2=%d\n",(int)getpid(),(int)getppid(),(int)child_pid1,(int)child_pid2);
        wait(NULL);
        printf("*** Proces potomny zakonczyl dzialanie\n");
        wait(NULL);
        printf("*** Proces potomny zakonczyl dzialanie\n");
       printf("Aby zakonczyc program uzyj SIGKILL, badz wprowadz dowolny znak i nacisnij enter\n");       
       scanf("%d",&a);
    //    pause();
    }else if(child_pid1 == 0) {
        printf("### Proces potomny1: PID=%d, PPID=%d\n",(int)getpid(),(int)getppid());
    	    if (signal(SIGUSR1,my_SIGUSR1) == SIG_ERR){
    		perror("Funkcja signal ma problem z SIGUSR1");
    		exit(EXIT_FAILURE);
	    }
        pause();    
    } else {
        printf("### Proces potomny2: PID=%d, PPID=%d\n",(int)getpid(),(int)getppid());
	if (signal(SIGUSR2,my_SIGUSR2) == SIG_ERR){
    	    perror("Funkcja signal ma problem z SIGUSR2");
    	    exit(EXIT_FAILURE);
	}
       
       pause();
	
    }
  

  return 0;
}

void my_SIGUSR1(int sig){
    printf("@ Otrzymano SIGUSR1\n");
    for(int x=0;x<10;x++){
      printf("*");
    }  
    printf("\n");    	
}
void my_SIGUSR2(int sig){
    printf("@ Otrzymano SIGUSR2\n");
    for(int x=0;x<10;x++){
      printf("#");
    }  
    printf("\n");    	
}
