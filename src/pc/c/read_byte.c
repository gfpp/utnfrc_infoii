#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    /* File control definitions */
#include <unistd.h>   /* UNIX standard function definitions */
#include <signal.h>
#include "termset.h"

unsigned int flag = 1;
void handler(int );

int main(int argc, char * argv[])
{          
    int fd; /* Descriptor de archivo del puerto */
    unsigned char byte;
    size_t n;

    if(argc != 3)
    {
        printf("USO: %s <device> <baudrate>\n", argv[0]);
        return -1;
    }

    printf("Abriendo el puerto...\n");
    fd = open(argv[1], O_RDWR | O_NOCTTY | O_NDELAY);
    if(fd == -1)
    {        
        printf("ERROR: no se pudo abrir el dispositivo.\n");
        return -1;
    }        
    if(termset(fd, atoi(argv[2])) == -1)
    {        
        printf("ERROR: no se pudo configurar el TTY\n");
        return -1;
    }        

    signal(SIGINT, handler);
    tcflush(fd, TCIOFLUSH);
    while(flag)
    {        
        n = read(fd, &byte, 1);
        if(n > 0)
            printf("%03d\n", byte);
    }        

    printf("Cerrando el puerto...\n");
    close(fd);
    return 0;
}

void handler(int sig)
{
    flag = 0;
}
