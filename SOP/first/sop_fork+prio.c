#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void)
{
 pid_t child;
 int status;
 
 if ((child = fork()) == -1) { 
       perror("fork");
       exit(EXIT_FAILURE);
 } else if (child == 0 ){
      setpriority(PRIO_PGRP, 0, 8);
    printf("i'M A KID, MY PRIORI IS: %d\n", getpriority(PRIO_PROCESS, 0));
   pause();
   return (0);
    exit(EXIT_SUCCESS);      

 } else if (child > 0 ) {
      setpriority(PRIO_PGRP, 0, 5);
    printf("IMA FATHER MY PRIORI IS: %d\n", getpriority(PRIO_PROCESS, 0));
       pause();
   return (0);
 }
   pause();
   return (0);
 exit(EXIT_SUCCESS);
}