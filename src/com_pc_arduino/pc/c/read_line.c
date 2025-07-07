#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "termset.h"

unsigned int flag = 1;
void handler(int );

int main(int argc, char * argv[])
{  
    int fd;
    FILE *fptr;
    ssize_t n_read;
    size_t len = 0;
    char * line;

    if(argc != 3)
    {
        printf("USO: %s <device> <baudrate>\n", argv[0]);
        return -1;
    }

    fptr = fopen(argv[1], "r");
    if(fptr == NULL)
    {
        printf("ERROR: opening %s file\n", argv[1]);
        return -1;
    }
    fd = fileno(fptr);

    if(termset(fd, atoi(argv[2])) == -1)
    {
        printf("ERROR: setting tty\n");
        return -1;
    }

    signal(SIGINT, handler);
    while(flag)
    {
        n_read = getline(&line, &len, fptr);
        if(n_read != -1)
            printf("Line: %s", line);
    }

    fclose(fptr);
    return 0;
}

void handler(int sig)
{
    flag = 0;
}
