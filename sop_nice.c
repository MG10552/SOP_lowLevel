#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void)
{
    int n = 2;
   setpriority(PRIO_PGRP, 0, 2);
   printf("Mój aktualny priorytet wynosi: %d\n", getpriority(PRIO_PROCESS,0));

  
    //printf("Za 30 s. zmienię go na 12");
   //sleep(10);
  
    setpriority(PRIO_PGRP, 0, 12);
   
   //puts("Teraz jestem uprzejmy i mam wartość 11 :)");
   pause();
   return (0);
}

//'ps -ely | grep nice'
//lub w 'gnome-system-monitor' albo 'htop' w czasie rzeczywistym
//inny sposób ustawiania priorytetów to 'nice()'
//'getpriority()' i 'setpriority()' są zalecane