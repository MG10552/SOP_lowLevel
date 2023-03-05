#include <stdlib.h>
#include <stdio.h>

int main() 
{
    printf ("PID: %d [identyfikator procesu]\n", (int) getpid ());
    printf ("PPID: %d [identyfikator procesu macierzystego]\n", (int) getppid ());
    printf ("UID: %d [rzeczywisty identyfikator użytkownika]\n", (int) getuid ());
    printf ("EUID: %d [efektywny identyfikator użytkownika]\n", (int) geteuid ());
    printf ("GID: %d [rzeczywisty identyfikator grupy]\n", (int) getgid ());
    printf ("EGID: %d [efektywny identyfikator grupy]\n", (int) getegid ());
	
    printf("Nacisnij ENTER aby kontynuować ...");
    getchar();
    return 0;
}
    
    