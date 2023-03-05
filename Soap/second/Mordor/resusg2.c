//'resusg2.c' - pobierz czasy procesu i wykorzystanie zasobow.
//Program 'resusg2.c' robi to samo co 'resusg1.c', używając funkcji getrusage zamiast times.
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/resource.h>
#include <time.h>
#include <unistd.h>

void err_quit(char *);
void doit (char *, long); 

int main (void)
{
  struct rusage usage;
//  system("grep the /usr/doc/*/* > /dev/null 2>/dev/null"); //przekieruj wyjście aby zapobiec przepełnieniu ekranu
   system("find / -name stdio.h -print > /dev/null 2>/dev/null");
  //weź strukturę nadrzędną 
  if ((getrusage(RUSAGE_SELF, &usage)) == -1)
     err_quit("getrusage");
  puts("Parent times ");
  doit("\tuser CPU", usage.ru_utime.tv_sec);
  doit("\tsys CPU", usage.ru_stime.tv_sec);
//  puts("Parent memory stats");
//  doit("\tminor faults", usage.ru_minflt);
//  doit("\tmajor faults", usage.ru_majflt);
//  doit("\tpage   swaps", usage.ru_nswap);

  //weź strukturę podrzedną
  if ((getrusage(RUSAGE_CHILDREN, &usage)) == -1)
     err_quit("getrusage");
  puts("Child times ");
  doit("\tuser CPU", usage.ru_utime.tv_sec);
  doit("\tsys CPU", usage.ru_stime.tv_sec);
//  puts("Child memory stats ");
//  doit("\tminor faults", usage.ru_minflt);
//  doit("\tmajor faults", usage.ru_majflt);
//  doit("\tpage   swaps", usage.ru_nswap);

  exit(EXIT_SUCCESS);
}


void doit (char *str, long resval)
{
  printf("%s: %ld\n", str, resval);
}

void err_quit(char *str)
{
  perror(str);
  exit(EXIT_FAILURE);
}
