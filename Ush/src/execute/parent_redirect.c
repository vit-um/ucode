#include "ush.h"

void parent_redirect(t_redirect *redirect, int *ret) {
    if (redirect->flag == 1) {
        read_from_pipe(redirect->_stdout, 1000, redirect->fd_stdout);
    }
    read_from_pipe(redirect->_stderr, 1000, redirect->fd_stderr);
    if (mx_strlen(redirect->_stderr) != 0) {
        *ret = 1;
        mx_printstr(redirect->_stderr);
    }
}
