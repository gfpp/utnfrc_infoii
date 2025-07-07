#ifndef TERMSET_H
#define TERMSET_H

#include <termios.h>
#include <fcntl.h>


/* termset function
 * Parameters:
 *  fd: file descriptor -device- (ex: /dev/ttyUSB0)
 *  baudrate: communication speed (ex: 9600, 115200)
 */
int termset(int fd, int baudrate);

#endif
