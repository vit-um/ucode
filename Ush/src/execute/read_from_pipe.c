#include "ush.h"

void read_from_pipe(char *str, int len, int *fd) {
    close(fd[1]);
    read(fd[0], str, len);
    close(fd[0]);
}

