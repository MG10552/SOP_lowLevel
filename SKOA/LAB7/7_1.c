#define MAX 512
main(int argc, char* argv[]) {
int pdesk[2];
if (pipe(pdesk) == -1){
perror("Tworzenie potoku");
exit(1);
}
switch(fork()){
case -1: // blad w tworzeniu procesu
perror("Tworzenie procesu");
exit(1);
case 0: // proces potomny
dup2(pdesk[1], 1);
execvp("ls", argv);
perror("Uruchomienie programułs");
exit(1);
default: { // proces macierzysty
char buf[MAX];
int lb, i;
close(pdesk[1]);
while ((lb=read(pdesk[0], buf, MAX)) > 0){
for(i=0; i<lb; i++)
buf[i] = toupper(buf[i]);
if (write(1, buf,łb) == -1){
perror ("Zapis na standardowe wyjscie");
exit(1);
}
}
if (lb == -1){
perror("Odczyt z potoku");
exit(1);
}
}
}
}

