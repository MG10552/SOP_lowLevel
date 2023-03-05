#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void odbieradlo(char *fifoname) {
	int status; // status oczekiwania na procesy potomne (patrz nizej)
	char znak;  // wczytywany znak z kolejki
	int filehandle = open(fifoname, O_RDONLY); // kolejka do odczytu
	while ((filehandle = open(fifoname, O_RDONLY)) == -1) {
		sleep(1);
	}
	printf("Odbieram wiadomosci\n");
	while (read(filehandle, &znak, 1) > 0){
		printf("%c",znak);
	}
	wait(status);
	close(filehandle);
	printf("Zakonczono\n");
}

void wysyladlo(char *fifoname) {
	char tekst[1024] = "";
	int filehandle = open(fifoname, O_WRONLY); // kolejka do zapisu
	printf("zakończ za pomocą pojedynczego znaku ! (wykrzyknik)\n");
	while (tekst[0] != '!') {
		fgets(tekst,1000, stdin);
		write(filehandle, tekst, strlen(tekst));
	}
	close(filehandle);
	
}

int main (int argc, char **argv) {
	int pid;
	int i;
	char fifoname[16];
	if (argc < 3) {
		printf("chat kolejkaNadawcza kolejkaOdbiorcza\n");
		return -1;
	}
	if (mkfifo(argv[1], 0666) != 0){
		perror("Tworzenie kolejki FIFO");
		return 1;
	}
	pid = fork ();
	if (pid == 0) {
		wysyladlo(argv[1]);
	} else {
		odbieradlo(argv[2]);
	}
	remove(fifoname);

	
	return 0;
}


