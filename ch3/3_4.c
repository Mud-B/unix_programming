#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char* argv[]){
    int accmode, val;
    if(argc != 2){
        printf("usage: a.out <descriptor#>\n");
        exit(-1);
    }
        
    if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0){
        printf("fcntl error for fd %d\n", atoi(argv[1]));
        exit(-2);
    }

    accmode = val & O_ACCMODE;
    if      (accmode == O_RDONLY) printf("read only");
    else if (accmode == O_WRONLY) printf("write only");
    else if (accmode == O_RDWR) printf("read write");
    else printf("unkown access mode");

//     if(val & O_APPEND)      printf(", append");
//     if(val & O_NONBLOCK)    printf(", nonblocking");
// #if !defined(_POSIX_SOURCE) && define(O_SYNC)
//     if(val & O_SYNC)
// #endif
    putchar('\n');
    exit(0);
}