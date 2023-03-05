//Program rejestruje procedurę obsługi sygnału SIGINT, która
//wprowadza wiadomość oraz przerywa działanie programu, co
//jest domyślnym działaniem sygnału.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//Procedura obsługi sygnału SIGINT
static void sigint_handler (int signo)
{
   printf("Przechwycono syhnał SIGINT\n");
   exit (EXIT_SUCCESS);
} 

int main (void)
{
  //Zarejestruj funkcję sigint_handler jako procedurę obsługi sygnału SIGINT
   if (signal (SIGINT, sigint_handler) == SIG_ERR )
   {
      fprintf (stderr, "Nie można obsłużyć sygnału SIGINT:\n");
      exit (EXIT_FAILURE);
   }
   
   for (;;)
      pause ();
 
return 0;
}
