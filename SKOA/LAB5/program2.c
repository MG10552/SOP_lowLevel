#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/errno.h>


int main()
{
  int a=1;

  printf("Wybierz sposob dzialania programu:\n"
    "1 - Wykonanie operacji domyslnej\n"
    "2 - Ignorowanie sygnalu\n"
    "3 - Przechwycenie sygnalu\n"
  scanf("%d",&a);

  switch(a){
    case 1:
      printf("Program odpowie domyslnie na sygnal\n");
       if (......){
         perror("Funkcja signal ma problem z SIGQUIT");
         exit(EXIT_FAILURE);
       }
       if (......){
         perror("Funkcja signal ma problem z SIGINT");
         exit(EXIT_FAILURE);
       }
       if (pause() < 0){
         perror("ERROR: sygnal nie powoduje zakoczenia procesu");
         exit(EXIT_FAILURE);
       }
       break;

    case 2:
      printf("Program zignoruje sygnal\n");
       if (......){
         perror("Funkcja signal ma problem z SIGQUIT");
         exit(EXIT_FAILURE);
       }
       if (......){
         perror("Funkcja signal ma problem z SIGINT");
         exit(EXIT_FAILURE);
       }
       // Tutaj pause nie ma sensu bo sygnaly zostana zignorowane
       // aby popchnac program do przodu trzeba uzyc SIGKILL, lub
       //   wpisac dowolny znak i nacisnac enter
       printf("Aby zakonczyc program uzyj SIGKILL, badz wprowadz\n"
              "dowolny znak i nacisnij enter\n");
       scanf("%d",&a);
       // if (pause() < 0){
       //  perror("ERROR: sygnal nie powoduje zakoczenia procesu");
       //  exit(EXIT_FAILURE);
       //}
       break;
     case 3:
       printf("Program wypisze rodzaj otrzymanego sygnalu\n");
       if (......){
         perror("Funkcja signal ma problem z SIGQUIT");
         exit(EXIT_FAILURE);
       }
       if (......){
         perror("Funkcja signal ma problem z SIGINT");
         exit(EXIT_FAILURE);
       }
       pause(); //tutaj na pewno pause zwroci blad, nasza obsluga sygnalu nie pozwala na zakonczenie programu! Dlatego ignorujemy zwracana przez pause wartosc
       break;
      
     default:
       printf("bledny wybor menu, konczenie pracy\n");
       exit(1);
  }

  return 0;
}


