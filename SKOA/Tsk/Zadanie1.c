#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/errno.h>

int n = 0;
void signalHandler(int sig);

double shoot(int v) 
{
float a0=100;
	
if(v == 0)
return a0;
	
if(v < 115)
return shoot(v-1)+1;

if(v >= 115)
return shoot(v-1)+2;
}

int main (int argc, char *argv) 
{
	 
signal(SIGQUIT,signalHandler);
FILE *file;

if((file = fopen("s10552", "w+")) == NULL){
	printf("Sorry, but file cannot be opened.");
	exit(1);
}
	fprintf(file, "%i", (int)getpid());
	printf ("PID of main process: %d\n", (int)getpid());
	fclose(file);
	
for(;; n++)
	{
	sleep(1);
	printf("%i: %f \n", n, shoot(n));
	} 
return 0;
}

void signalHandler(int sig)
{
n=101;
}


