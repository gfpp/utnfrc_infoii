#include <stdio.h>
#include "termset.h"

struct termios tty_config;
/*
 struct termios
  {
    tcflag_t c_iflag;       // input mode flags
    tcflag_t c_oflag;       // output mode flags
    tcflag_t c_cflag;       // control mode flags
    tcflag_t c_lflag;       // local mode flags
  };
*/

int termset(int fd, int baudrate)
{
    switch(baudrate)
    {
        case 115200: baudrate = B115200;
                     break;
        case 57600:  baudrate = B57600;
                     break;
        case 38400:  baudrate = B38400;
                     break;
        case 19200:  baudrate = B19200;
                     break;
        case 9600:   baudrate = B9600;
                     break;
        default:     baudrate = B115200;
                     break;
    }

    fcntl(fd, F_SETFL, 0);
    if(tcgetattr(fd, &tty_config) != 0)
    {
        printf("ERROR: tcgetattr\n");
        return -1;
    }

    cfsetospeed(&tty_config, baudrate);
    cfsetispeed(&tty_config, baudrate);

    /* TTY control modes */
    tty_config.c_cflag = (tty_config.c_cflag & ~CSIZE) | CS8; /* 8 */
    tty_config.c_cflag &= ~(PARENB | PARODD);                 /* N */
    tty_config.c_cflag &= ~CSTOPB;                            /* 1 */

    tty_config.c_cflag |= (
        CLOCAL |                /* ignore modem status lines */
        CREAD                   /* enable receptions */
    );

    tty_config.c_cflag &= ~CRTSCTS;     /* disable flow control */

    /* TTY input modes */
    tty_config.c_iflag &= ~(    /* Disable next flags: */
        IGNBRK |                /* break condition */
        BRKINT |                /* break interrupt */
        ICRNL  |                /* CR to new line!!! */
        INLCR  |                /* new line to CR */
        PARMRK |                /* parity mark */
        INPCK  |                /* parity checking */
        ISTRIP |                /* strip byte (7 bits) */
        IGNCR  |                /* ignore CR */
        IXON   |                /* start/stop output control */
        IXOFF  |                /* start/stop input control */
        IXANY                   /* any character to restart */
    );

    /* TTY output modes */
    tty_config.c_oflag &= ~(    /* Disable next flags: */
        OCRNL  |                /* CR to new line */
        ONLCR  |                /* new line to CR */
        ONLRET |                /* new line is CR */
        ONOCR  |                /* no CR in column zero */
        OFILL  |                /* replace delay with characters */
        OPOST                   /* implementation defined characters */
    );

    /* No line processing:
     * echo off, echo newline off, canonical mode off,
     * extended input processing off, signal chars off */
    tty_config.c_lflag &= ~(    /* Disable next flags: */
        ECHO   |                /* echo character */
        ECHONL |                /* echo new line */
        ICANON |                /* canonical mode */
        IEXTEN |                /* special characters */
        ISIG                    /* signal characters */
    );


    /* One input byte is enough to return from read()
     * Inter-character timer off */
    tty_config.c_cc[VMIN]  = 1;
    tty_config.c_cc[VTIME] = 0;

    /*
     * TCSANOW: Make the change immediately.
     * TCSADRAIN: Make the change after waiting until all queued output has been written. 
     * TCSAFLUSH: This is like TCSADRAIN, but also discards any queued input.
     */
    if(tcsetattr(fd, TCSAFLUSH, &tty_config) != 0)
    {
        printf("ERROR: tcsetattr\n");
        return -1;
    }

    return 0;
}
