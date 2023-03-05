#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{

    // deklaracja zmiennej w ktorej zostanie zapisany identyfikator potomka 	
    pid_t child_pid;
	
    printf ("PID procesu głownego: %d\n", (int) getpid ());
    printf ("PPID procesu głównego: %d\n", (int) getppid ());
	
    child_pid = fork ();
    if (child_pid == 0) {
    	    printf("### To jest proces potomny, a jego PID to: %d\n", (int) getpid ());
    	    printf("### PID procesu potomnego: %d\n", (int) child_pid);
	    printf("\n");
    	    for(int j=0; j<60; j++){
    	      printf("*");
    	      }
    	    printf("\n");  
    } else {
    	    printf("*** To jest proces macierzysty, a jego PID to: %d\n", (int) getpid ());
    	    printf("*** PID procesu potomnego: %d\n", (int) child_pid);
    	    printf("*** ZAKONCZENIE procesu macierzystego\n");
    	    for(int i=0; i<2; i++){
    	      printf("+");
    	      }
    	    printf("\n");  
//    	    return 1;
//    	    printf("*** Nacisnij ENTER aby kontynuować ...\n");
//    	    getchar();


    }
    
    return 0;
}
    
    