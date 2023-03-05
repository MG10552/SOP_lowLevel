/*Blokuje sygnały SIGALRM i SIGTERM*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void err_quit (char *);

int main(void)
{
   sigset_t newset;
 
   /*Utwórz zestaw*/
   if((sigemptyset(&newset)) < 0)
     err_quit("sigemtyset");

   /*Dodaj SIGALRM do zestawu*/
   if((sigaddset(&newset, SIGALRM)) < 0)
     err_quit("sigaddset");
   /*Dodaj SIGTERM do zestawu*/
   if((sigaddset(&newset, SIGTERM)) < 0)
     err_quit("sigaddset");
   /*Dodaj SIGQUIT do zestawu*/
   if((sigaddset(&newset, SIGQUIT)) < 0)
     err_quit("sigaddset");
   /*Dodaj SIGKILL do zestawu*/
   if((sigaddset(&newset, SIGKILL)) < 0)
     err_quit("sigaddset");

   /*Zablokuj sygnały bez ich obsługiwania*/
   if ((sigprocmask(SIG_BLOCK, &newset, NULL))<0)
     err_quit("sigprocmask");
   
   /*Czekaj na sygnał*/
   pause();
   

   exit(EXIT_SUCCESS);
}

   void err_quit(char *msg)
{
   perror(msg);
   exit(EXIT_FAILURE);
}
