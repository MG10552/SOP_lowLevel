/*
*ids.c - wydrukuj UID i GID
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
 printf("Real user ID: %d\n", getuid());
 printf("Real group ID: %d\n", getgid());
 exit(EXIT_SUCCESS);
}

/* geteuid() i getegid()
* Programy setuid i setgid sa tak nazwane, ponieważ efaktywne UID i GID
* jest ustawione na UID i GID pliku, a nie właściciela czy grupy użytkownika 
* wykonujacego program. Celem programu setuid i setgid jest nadanie użytkownikowi
* specjalnych uprawnień 
*/

