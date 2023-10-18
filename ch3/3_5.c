#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
// #include <unistd.h>


void set_fl(int fd, int flags){
    int val;
    if((val = fcntl(fd, F_GETFL, 0)) < 0){
        printf("fcntl F_GETFL error\n");
        exit(-1);
    }

    val |= flags;

    if((val = fcntl(fd, F_SETFL, val)) < 0){
        printf("fcntl F_SETFL error\n");
        exit(-2);
    }
    printf("set fd to %d success.\n", fcntl(fd, F_GETFL, 0));
}

int main(int argc, char* argv[]){
    set_fl(atoi(argv[1]), O_APPEND);
    // set_fl(atoi(argv[1]), O_NONBLOCK);
    // set_fl(atoi(argv[1]), O_SYNC);
    // set_fl(atoi(argv[1]), O_ASYNC);
    exit(0);
}