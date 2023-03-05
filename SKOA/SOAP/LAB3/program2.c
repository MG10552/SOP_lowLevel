#include <stdlib.h>
#include <stdio.h>

int main() 
{
    printf("Wprowadz dowolna wartość liczbową: \n");
    int a;
    scanf("%d",&a);
    printf("Wartość zmiennej a: %d", a);

/* ------------------------------------------------------- */
    getchar();
    printf("\nNacisnij ENTER aby kontynuować ...");
    getchar();

    return 0;
}
    