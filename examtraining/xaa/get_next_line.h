#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif
