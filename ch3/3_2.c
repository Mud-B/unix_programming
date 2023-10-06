#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";


int main(void){
    int fd;
    if((fd = creat("file.hole", FILE_MODE)) < 0)
        printf("creat error");
    if(write(fd, buf1, 10) != 10)
        printf("write error");
    if(lseek(fd, 40, SEEK_SET) == -1)
        printf("lseek error");
    if(write(fd, buf2, 10) != 10)
        printf("write error");
}