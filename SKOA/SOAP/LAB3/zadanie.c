#include <stdio.h>
int main()
{
float a,b,c;
int wybor;
do
{
printf("Co chcesz zrobic?\n1 — dodawanie\n2 — odejmowanie\n3 — mnozenie\n4 — dzielenie\ninne — konczy\n");
scanf("%d",&wybor);
switch (wybor)
{
case 1: /*Dodawanie*/
{
printf("Podaj 1 liczbe: ");
scanf("%f",&a);
printf("Podaj 2 liczbe: ");
scanf("%f",&b);
printf("Wartosc zmiennej a:\t%.2f\n",a);
printf("Wartosc zmiennej b:\t%.2f\n",b);
printf("Wartosc sumy:\t%.2f\n",a+b);
break;
}
case 2: /*Odejmowanie*/
{
printf("Podaj 1 liczbe: ");
scanf("%f",&a);
printf("Podaj 2 liczbe: ");
scanf("%f",&b);
printf("Wartosc zmiennej a:\t%.2f\n",a);
printf("Wartosc zmiennej b:\t%.2f\n",b);
printf("Wartosc roznicy:\t%.2f\n",a-b);
break;
}
case 3: /*Mnozenie*/
{
printf("Podaj 1 liczbe: ");
scanf("%f",&a);
printf("Podaj 2 liczbe: ");
scanf("%f",&b);
printf("Wartosc zmiennej a:\t%.2f\n",a);
printf("Wartosc zmiennej b:\t%.2f\n",b);
printf("Wartosc iloczynu:\t%.2f\n",a*b);
break;
}
case 4: /*Dzielenie*/
{
printf("Podaj 1 liczbe: ");
scanf("%f",&a);
printf("Podaj 2 liczbe: ");
scanf("%f",&b);
printf("Wartosc zmiennej a:\t%.2f\n",a);
printf("Wartosc zmiennej b:\t%.2f\n",b);
printf("Wartosc ilorazu:\t%.2f\n",a/b);
break;
}
default:
break;
}
if (wybor!=1 && wybor!=2 && wybor!=3 && wybor!=4)
break;
printf("Czy chcesz powtorzyc?\n0 — konczy\n");
scanf("%d",&wybor);
}while(wybor!=0);
system("PAUSE");
return 0;
}

