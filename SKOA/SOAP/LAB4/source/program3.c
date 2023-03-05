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
    if (child_pid != 0) {
    	    printf("*** To jest proces macierzysty, a jego PID to: %d\n", (int) getpid ());
    	    printf("*** PID procesu potomnego: %d\n", (int) child_pid);
    	    printf("\n");
    	    printf("*** Nacisnij ENTER aby kontynuować ...\n");
    	    getchar();
    } else {
    	    printf("### To jest proces potomny, a jego PID to: %d\n", (int) getpid ());
    	    printf("### PID procesu potomnego: %d\n", (int) child_pid);
    }
    
    return 0;
}
    