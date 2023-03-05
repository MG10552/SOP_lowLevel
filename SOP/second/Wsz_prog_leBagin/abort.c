//Demonstracja użycia wywołania systemowego abort()

#include <stdlib.h> 
#include <stdio.h>

int main (void)
{
   abort();
   //program nie powinien tu dotrzeć
   exit (EXIT_SUCCESS);
}

//Używamy funkcji abort() jeżeli chcemy zakończyć działanie programu anormalnie.
//W Linuksie funkcja abort() może wykonać dodatkowy efekt uboczny - zapisanie rdzenia (core),
//używanego przez debugery do analizy programów, które awaryjnie zakończyły działanie.
//Chociaż wszystkie pliki są zamykane, abort() nie jest zbyt ładnym działaniem.
//Funkcja ta powinna być używana tylko w ostateczności, na przykład, gdy napotka się błąd, 
//z którym nie mozna poradzić sobie programowo, na przykład poważny brak pamięci.
//
//Powyższy program może nie generować "core'a". W takim przypadku użyjemy polecenia "ulimit -c unlimited".

