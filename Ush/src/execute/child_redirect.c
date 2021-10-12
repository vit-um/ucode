#include "ush.h"

void child_redirect(t_redirect *redirect) {
    signal(SIGTSTP, SIG_DFL);
    if (redirect->flag == 1) {
        if (dup2(redirect->fd_stdout[1], 1) == -1) {
            perror("dup2");
        }
        close(redirect->fd_stdout[0]);
    }
    if (dup2(redirect->fd_stderr[1], 2) == -1) {
        perror("dup2");
    }
    close(redirect->fd_stderr[1]);
}
