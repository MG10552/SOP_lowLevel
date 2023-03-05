//Tworzy program obsługi dla SIGUSR1

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void err_quit(char *); //funkcja błędów
void hndl_usr1(int);  //funkcja obsługi sygnału

int main(void)
{
    struct sigaction action;
    
    //Ustaw funkcję obsługi sygnału
    action.sa_handler = hndl_usr1;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_NOCLDSTOP;
    
    //Zarejestruj funkcję obsługi sygnału
    if((sigaction(SIGUSR1, &action, NULL)) < 0)
        err_quit("sigaction");
    //Wystarczająco długi czas na wysłanie sygnału
    sleep(60);

    exit(EXIT_SUCCESS);    
}

void err_quit(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

void hndl_usr1(int signum)
{
    if(signum==SIGUSR1)
        puts("Złapałem SIGUSR1 !!!");
    else
        printf("Złapałem %d\n", signum);
}
