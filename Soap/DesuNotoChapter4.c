//------------------------------- zadanie 1 ----------------------------------------------

#include <std.h>

int main(){
	
	FILE *file =fopen("test.txt", "rb");
	if (fseek(file,0,SEEK_END)){
	 printf("ERROR");
	 return 1;
	}
	 else{
	 long dlugosc=ftell(file);
	 if(dlugosc<0){
	 printf("ERROR");
	 return 2;
	}
	else{
	 printf("dlugosc: %d bytes\n", dlugosc);
	 fclose(file);
	 return 0;	
	}
}

//------------------------------- zadanie 2 ----------------------------------------------

#include <stdio.h>

int main(int argc, char *argv[]){
	
	FILE *file = fopen(argv[1], "rb");
	if (fseek(file,0,SEEK_END)){
	 printf("ERROR");
	 return 1;
	}
	 else{
	 long dlugosc=ftell(file);
	 if(dlugosc<0){
	 printf("ERROR");
	 return 2;
	}
	else{
	char* bufor = malloc(dlugosc); //alokacja panięciu
	fseek(file, 0, SEEK_SET);
	fread(buffer, 1, dlugosc, file);
	printf("Dane wczytane: %s ", bufor);
	free(bufor);
	fclose(file);		
	return 0;	
	}
}

//------------------------------- zadanie 3 ----------------------------------------------


#include <stdio.h>
//string, stdlib
int main(int argc, char *argv[]){

FILE *file = fopen(argv[1], "rb");
	char* lista = malloc(1); //alokacja panięciu
char* nazwaTMp[1024];	
int wczytano_n =0;
int i;
while (fscanf(file, "%s", nazwaTMp) > 0)
{
lista = realloc(lista, sizeof(char*) * wczytano_n);
lista[wczytano_n-1] = malloc(strlen(nazwaTMp));
strcpy(lista[wczytano_n-1],nazwaTMp);
}	
for i=0; i < wczytano_n; i++){ printf("Plik %s\n", lista[i])}
for i=0; i < wczytano_n; i++){ free(lista[i]);}

free(bufor);
	fclose(file);		
	return 0;	
	}

}
