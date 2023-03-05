//Ilustracja użycia execve
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
   char *args[] = {"/bin/ls", NULL};
   if (execve("/bin/ls", args, NULL) == -1) {
      perror("execve");
   }
   puts ("Program nie powinien tutaj dotrzeć");
   exit(EXIT_SUCCESS);
}

//Funkcja "puts" nie wykona się. Jeżeli wywołanie funkcji "exec"
//odnosi sukces, nie wraca ona do procesu wywołującego.
//Funkcja "exec" całkowicie zastepuje proces wywołujacy nowym
//programem, więc nie pozostaje ślad starego programu.
//Grupa funkcji "exec" : "execl, execlp, execle, execv, execve,execvp".
//
//Funkcja "execve" pobiera trzy argumenty: path, argv i envp.
//path jest pełną scieżką do binarnego pliku wykonywalnego lub
//skryptu, który chcemy wykonać. argv jest kompletna listą argumentów,
//którą chcemy przekazać do programu, w tym argv[0]jest tradycyjnie 
//nazwą wykonywanego programu. envp jest wskaźnikiem do wyspecjalizowanego
//środowiska, jeżeli takie istnieje.


