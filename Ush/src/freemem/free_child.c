#include "ush.h"

void child_free(char *command_p, int *fd, int ret_val) {
    char *ret = NULL;

    ret = mx_itoa(ret_val);
    write_to_pipe(ret, fd);
    mx_strdel(&ret);
    mx_strdel(&command_p);
}
