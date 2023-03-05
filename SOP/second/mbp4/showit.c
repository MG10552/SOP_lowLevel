/*
 * showit.c - program obsługi ekranu, dynamicznie ładowana biblioteka
 *           i wywołanie prmsg()
*/
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "msg.h"

int main(void)
{
   char msg_hi[] = {"Hej jak tam?"};
   char msg_bye [] = {"Do widzenia."};
   void *handle;
   void (*my_pr) (); //wskaźnik do załadowanego kodu
   const char *errmsg;

   //załaduj odpowiedni obiekt
   handle = dlopen("libmsg.so", RTLD_NOW);
     if(handle == NULL) {
       printf("Nie mogę załadować biblioteki libmsg.so: %s\n", dlerror());
       exit(EXIT_FAILURE);
     }
   //wyczyść łańcuch błędu, jeśli taki instnieje
   dlerror();
     if((errmsg = dlerror()) != NULL) {
       printf("Nie mogę znaleźć funkcji prmsg(): %s\n", errmsg);
       exit(EXIT_FAILURE);
     } 
   my_pr = dlsym(handle, "prmsg"); 
   
    
      
   printf("%s\n", msg_hi);
   my_pr(msg_bye);
   
   //bądź człowiekiem i zwróć obiekt :)
   dlclose(handle);
   exit(EXIT_SUCCESS);
}
