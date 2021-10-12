#include "ush.h"

void write_to_pipe(char *str, int *fd) {
    close(fd[0]);
    write(fd[1], str, strlen(str));
    close(fd[1]);
}
