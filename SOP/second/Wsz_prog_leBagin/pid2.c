/* Przykład użycia fork() */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
 pid_t child;
 
 if ((child = fork()) == -1) {  
       perror("fork");
       exit(EXIT_FAILURE);
 } else if (child == 0 ){
       printf("Jestem potomkiem PID: %d, PPID: %d\n", getpid(), getppid());
       exit(EXIT_SUCCESS); 
	  
 } else if (child > 0 ) {
	  printf("Jestem rodzicem PID: %d, PPID: %d\n", getpid(), getppid());
 }
 exit(EXIT_SUCCESS);
}
