#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/errno.h>

int main (int argc, char *argv) 
{
	int pid;
	FILE *file;
	if((file = fopen("s10552", "r")) == NULL)
{
	printf("Sorry, but file cannot be opened.");
	exit(1);
}
	fscanf(file, "%d", &pid);
	fclose(file);
		
	printf("Sending SIGQUIT for good!\n");
	sleep(1);
	
	if(kill(pid, SIGQUIT))	
		printf("ERROR: Kill function error\n");
		
	return 0;
}

