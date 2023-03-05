#include <stdio.h>
typedef void (*sighandler_t)(int);

void test(int i)
{
printf("I've recieved %d\n",i);
}
void test2(int i)
{
printf("Second try BOOM BOOM %d\n",i);
}

void function(sighandler_t x)
{
int i;
for (i=0; i <10; i++) x(300);
}

int main(int argc, char **argv)
{
function(test);
function(test2);

}
