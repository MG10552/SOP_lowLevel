/*
*getname.c - pobierz nazwę logowania
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int main (void)
{
   char *login;
   struct passwd *pentry;

   /*Pobierz nazwę logowania*/
   if ((login=getlogin()) == NULL) {
      perror("getlogin");
      exit(EXIT_FAILURE);
   }
   printf("Mój login to:  %s\n", login);

   /*Pobierz nazwę użytkownika*/
   if ((pentry=getpwnam(login)) == NULL) {
      perror("getpwnam");
      exit(EXIT_FAILURE);
   }
  
   /*Wyświetl pełną nazwę użytkownika*/
   printf("Moja nazwa w systemie to:  %s\n", pentry->pw_gecos); 
 
   exit(EXIT_SUCCESS);
}

