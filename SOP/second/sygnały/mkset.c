/*program dodaje SIGCHLD do pustego zetawu sygnałów, 
 a następnie używa funkcji "sigismember" do potwierdzenia,
 że sygnał znajduje się w zestawie*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void err_quit (char *);

int main(void)
{
   sigset_t newset;
 
   /*utwórz zestaw*/
   if((sigemptyset(&newset)) < 0)
     err_quit("sigemtyset");

   /*dodaj SIGCHILD do zetawu*/
   if((sigaddset(&newset, SIGCHLD)) < 0)
     err_quit("sigaddset");

   /*sprawdź maskę sygnałów
     SIGCHILD powinien być w zetawie */
    
   if(sigismember(&newset, SIGCHLD))
     puts("SIGCHLD IS in signal mask");
   else 
     puts("SIGCHLD is NOT in signal mask");

   /* SIGTERM NIE powinien być w zestawie */

   if(sigismember(&newset, SIGTERM))
     puts("SIGTERM IS in signal mask");
   else 
     puts("SIGTERM is NOT in signal mask");

   exit(EXIT_SUCCESS);
}

   void err_quit(char *msg)
{
   perror(msg);
   exit(EXIT_FAILURE);
}



