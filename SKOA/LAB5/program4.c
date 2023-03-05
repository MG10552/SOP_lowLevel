#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/errno.h>



int main()
{
  int a=1;
  printf("PID procesu: %d\n",(int) getpid());
  printf("Wyslanie do siebie SIGUSR1 za pomoca funkcji kill\n");

  printf("Za 5 sekund wysylam do siebie SIGUSR1!\n");
  sleep(5);
  if(kill(getpid(),SIGUSR1)){
     printf("ERROR: blad funkcji kill\n");
     exit(EXIT_FAILURE);
  }

  return 0;
}


