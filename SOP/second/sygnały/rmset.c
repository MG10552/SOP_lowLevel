/*Program usuwa sygnał z zestawu sygnałów*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void err_quit (char *);

int main(void)
{
   sigset_t newset;
 
   /*utwórz zestaw z wszystkich sygnałow*/
   if((sigfillset(&newset)) < 0)
     err_quit("sigfillset");

   /*usuń SIGALRM z zetawu*/
   if((sigdelset(&newset, SIGALRM)) < 0)
     err_quit("sigdellset");

   /*SIGALRM NIE powinien być w zetawie */
    
   if(sigismember(&newset, SIGALRM))
     puts("SIGALRM IS in signal mask");
   else 
     puts("SIGALRM is NOT in signal mask");

   /* SIGTERM POWINIEN być w zestawie */

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

