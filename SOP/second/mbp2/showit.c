/*
  showit.c - program obsługi ekranu
*/
#include <stdio.h>
#include "msg.h"

int main(void)
{
   char msg_hi[] = {"Hej jak tam?"};
   char msg_bye [] = {"Do widzenia."};

   printf("%s\n", msg_hi);
   prmsg(msg_bye);
   
   return 0;
}
