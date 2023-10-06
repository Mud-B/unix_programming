#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
    if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("can't seek\n");
    else
        printf("seek OK\n");
    exit(0);
}