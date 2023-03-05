#define MAX 512
main(int argc, char* argv[]) {
int pdesk[2];
if (pipe(pdesk) == -1){
perror("Tworzenie potoku");
exit(1);
}
if (fork() == 0){ // proces potomny
dup2(pdesk[1], 1);
execvp("ls", argv);
perror("Uruchomienie programułs");
exit(1);
}
else { // proces macierzysty
char buf[MAX];
intlb, i;
close(pdesk[1]);
wait(0);
while ((lb=read(pdesk[0], buf, MAX)) > 0){
for(i=0; i<lb; i++)
buf[i] = toupper(buf[i]);
write(1, buf,łb);
}
}
}

