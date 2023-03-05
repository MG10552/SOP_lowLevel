#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{

    // deklaracja zmiennej w ktorej zostanie zapisany identyfikator potomka 	
    pid_t child_pid;
    int i=10;	
    printf ("PID procesu głownego: %d\n", (int) getpid ());
    printf ("PPID procesu głównego: %d\n", (int) getppid ());
	
    child_pid = fork ();
    if (child_pid != 0) {
            i=i+2;
            printf("*** To jest proces macierzysty, czekamy na zakonczenie procesu potomnego\n");
    	    wait(NULL);
    	    printf("*** To jest proces macierzysty, a jego PID to: %d\n", (int) getpid ());
    	    printf("*** PID procesu potomnego: %d\n", (int) child_pid);
    	    printf("*** Wartosc zmiennej i = %d\n", i);
    	    
    	    printf("\n");
    	    printf("*** Nacisnij ENTER aby kontynuować ...\n");
    	    
    	    getchar();
    } else {
    	    printf("### To jest proces potomny, a jego PID to: %d\n", (int) getpid ());
    	    printf("### PID procesu potomnego: %d\n", (int) child_pid);
    	    printf("### Wartosc zmiennej i = %d\n", i);
    }
    
    return 0;
}
    