//Rejestracja procedury dla sygnałów SIGTERM oraz SIGINT. 
//Dla sygnału SIGPROF zostaje przywrócone domyślne zachowanie,
//którym jest przerwanie działania procesu. Sygnał
//SIGHUP zostanie zignorowany.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//Procedura obsługi sygnałów: SIGINT oraz SIGTERM
static void signal_handler (int signo)
{
   if (signo == SIGINT)
     printf ("Przechwycono sygnał SIGINT ! \n");
   else if (signo == SIGTERM)
     printf ("Przechwycono sygnał SIGTERM ! \n");
   else
   {
     fprintf(stderr, "Nieoczekiwany sygnał!\n");
     exit(EXIT_FAILURE);
   }
   exit (EXIT_SUCCESS);
}

int main (void)
{
   //Rejestracja funkcji signal_handler jako procedury obsługi sygnału SIGINT
   if (signal(SIGINT, signal_handler) == SIG_ERR)
   {
      fprintf(stderr, "Nie można obsłużyć sygnału SIGINT\n");
      exit(EXIT_FAILURE);
   }
   //Rejestracja funkcji signal_handler jako procedury obsługi sygnału SIGTERM
   if (signal(SIGTERM, signal_handler) == SIG_ERR)
   {
      fprintf(stderr, "Nie można obsłużyć sygnału SIGTERM\n");
      exit(EXIT_FAILURE);
   }
   //Przywróć domyślne zachowanie dla sygnału SIGPROF
   if (signal(SIGPROF, SIG_DFL) == SIG_ERR)
   {
      fprintf(stderr, "Nie można domyślnego zachowania dla sygnału SIGPROF\n");
      exit(EXIT_FAILURE);
   } 
   //Zignoruj sygnał SIGHUP
   if (signal(SIGHUP, SIG_IGN) == SIG_ERR)
   {
      fprintf(stderr, "Nie można zignorować sygnału SIGHUP\n");
      exit(EXIT_FAILURE);
   }
   for (;;)
      pause();
   return 0;
}

