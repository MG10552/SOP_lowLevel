#include <fcntl.h>
main(){
mkfifo("kolFIFO", 0600);
open("kolFIFO", O_RDONLY);
}

