#include <unistd.h> 
#include <stdio.h> 
#include <errno.h> 
                                 
main(int argc, char *argv[]) 
{ 
int i,p, coin=0; 
int pid,status; 
                             
for (i=0; i<10; i++) 
{ 
coin+=i;
if ((p=fork())==0) 
{ 
printf("PID = %d\n", getpid()); 
sleep(2); 
exit(i); 
} 
else if (p<0) 
perror("fork"); 
} 
sleep(2);printf("BOOOOOOOOOOOOOOM\n");
while ((pid=wait(status)) >= 0) 
printf("PID = %d, status = %d\n", pid, (status<<8)); 
printf("To(l)k(i)en ==> %d\n", coin);
exit(0); 
} 
