#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{

    // deklaracja zmiennej w ktorej zostanie zapisany identyfikator potomka 	
    int pidy[4]={0,0,0,0};
    pid_t child_pid;
    int i=10;	
	
    pidy[0]=getpid();

    child_pid = fork ();
    if (child_pid != 0) {
            printf("*** To jest proces macierzysty\n");
    	    printf("*** Wartosc zmiennej pidy [%d,%d,%d,%d]\n", pidy[0], pidy[1], pidy[2], pidy[3]);
	    wait(NULL);
    } else {
    	    printf("### To jest proces potomny 1\n");
	    pidy[1]=getpid();
	    printf("### Wartosc zmiennej pidy [%d,%d,%d,%d]\n", pidy[0], pidy[1], pidy[2], pidy[3]);
	    child_pid = fork ();
	    if (child_pid != 0) {
//        	printf("### To jest proces macierzysty 2, czekamy na zakonczenie procesu potomnego\n");
    		wait(NULL);
	    } else {
    		printf("$$$ To jest proces potomny 2\n");
		pidy[2]=getpid();
	    printf("$$$ Wartosc zmiennej pidy [%d,%d,%d,%d]\n", pidy[0], pidy[1], pidy[2], pidy[3]);
	    child_pid = fork ();
	    if (child_pid != 0) {
//        	printf("$$$ To jest proces macierzysty 2, czekamy na zakonczenie procesu potomnego\n");
    		wait(NULL);
	    } else {
    		printf("@@@ To jest proces potomny 3\n");
		pidy[3]=getpid();
	    printf("@@@ Wartosc zmiennej pidy [%d,%d,%d,%d]\n", pidy[0], pidy[1], pidy[2], pidy[3]);
		


	    }
}
    }
    
    return 0;
}
    