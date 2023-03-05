//----------------------------------------ZAD_1-------------------------------------------------------

#include <stdio.h>

int main(){
	printf("Hello world\n");
	return 0;
}

//----------------------------------------ZAD_2-------------------------------------------------------

#include <stdio.h>

int main(){
	int liczba, wynik;
	printf("Podaj liczbę: ");
	scanf("%d", &liczba);
	
	wynik = liczba*liczba;
	printf("Kwadrat liczby %d to %d\n", liczba, wynik);
	return 0;
}

//----------------------------------------ZAD_3-------------------------------------------------------

#include <stdio.h>
int main(){
 int x,y,wynik;
 char znak[2];
 printf("Podaj liczbe 1\n");
 scanf("%d",&x);
 printf("Podaj znak\n");
 scanf("%1s",znak);
 printf("Podaj 2 liczbe\n");
 scanf("%d",&y);
  
switch(znak[0]){
  case '+': wynik=x+y;break;
  case '-': wynik=x-y;break;
  case '*': wynik=x*y;break;
  case '/': if(y==0){
		printf("error\n");
	}else{
		wynik=x/y;
	}
	break;
  default:printf("error");
}
printf("wynik %d:",wynik);
}

//----------------------------------------ZAD_4-------------------------------------------------------

#include <stdio.h>

int main()
{
	int liczba, i;
	char tekst[10];
	
	scanf("%d", &liczba);
	scanf("%9s", tekst);
	
	for(i=0; i<liczba; i++)
		printf("%s\n", tekst);
		
	return 0;

}

//----------------------------------------ZAD_5-------------------------------------------------------

#include <stdio.h>

int gcd (int a, int b){
	if (b==0){
		return a;
	}else return gcd(b,a%b);
}

int main()
{
	int a,b;
	scanf("%d %d", &a , &b);
	printf("%d\n", gcd(a,b));
	
	return 0;

}

//----------------------------------------ZAD_6-------------------------------------------------------

#include <stdio.h>

int fib (int a){
	if (a==0){return 0;}
	else if (a==1) {return 1;}
	else return fib(a-1)+fib(a-2);
}

int main()
{
	int a;
	scanf("%d", &a);
	printf("%d\n", fib(a));
	
	return 0;

}

//----------------------------------------ZAD_7-------------------------------------------------------

#include <stdio.h>

int fib (int a){
	if (a==0){return 0;}
	else if (a==1) {return 1;}
	else return fib(a-1)+fib(a-2);
}

int main()
{
	int a;
	scanf("%d", &a);
	printf("%d\n", fib(a));
	
	return 0;

}

//----------------------------------------ZAD_8-------------------------------------------------------

#include <stdio.h>

int main()
{
	int i, n;
	printf("Podaj rozmiar tablicy: ");
	scanf("%d",&n);
	
	int tab[n];
	
	printf("Podaj znak: \n");
	
	for (i=0; i<n; i++) {
		scanf("%d", &tab[i]);
	}
	
	for (i=n-1; i>=0; i--) {
		printf("%d ", tab[i]);
	}
	
	
	return 0;

}

//----------------------------------------ZAD_9-------------------------------------------------------

#include <stdio.h>

void bubblesort(int *tab,int dlugosc){
	
	int i,j,temp;
	
	for(i=0; i< dlugosc-1; i++){
		for(j=0; j<dlugosc-1; j++){
			if(tab[j] > tab[j+1]){
				temp=tab[j];
				tab[j]=tab[j+1];
				tab[j+1]=temp;
			}
		}
	}
}

int main()
{
	int tab[10] = {4,5,20,7,3,15,2,0,8,50};
	int i;
	
	for(i=0; i<10; i++){
		printf("%d,",tab[i]);
	}
	printf("\npo sortowaniu:");
	bubblesort(tab,10);
	
	for(i=0; i<10; i++){
		printf("%d,",tab[i]);
	}
	printf("\n");
	return 0;

}
