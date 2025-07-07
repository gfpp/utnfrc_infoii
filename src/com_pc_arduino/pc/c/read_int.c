#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    /* File control definitions */
#include <unistd.h>   /* UNIX standard function definitions */
#include <signal.h>
#include "termset.h"

typedef union 
{
    unsigned char uc[4];
    int i;
} int_uchar_t;

unsigned int flag = 1;
void handler(int );

int main(void)
{
    int fd; /* Descriptor de archivo del puerto */
    size_t n = 0;
    int_uchar_t i_uc;

    printf("Abriendo el puerto...\n");
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
    if(fd == -1)
    {        
        printf("ERROR: no se pudo abrir el dispositivo.\n");
        return -1;
    }        
    if(termset(fd, 9600) == -1)
    {        
        printf("ERROR: no se pudo configurar el TTY\n");
        return -1;
    }        

    signal(SIGINT, handler);
    tcflush(fd, TCIOFLUSH);
    while(flag)
    {
        write(fd, "e", 1);
        tcdrain(fd);
        usleep(250000);

        n = read(fd, &(i_uc.uc[0]), 4);
        printf("Valor entero: %d\n", i_uc.i);
    }

    printf("Cerrando el puerto...\n");
    close(fd);
    return 0;
}

void handler(int sig)
{
    flag = 0;
}
