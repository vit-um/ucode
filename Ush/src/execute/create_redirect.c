#include "ush.h"

t_redirect *create_redirect(int flag_redir) {
    t_redirect *redirect = (t_redirect *)malloc(sizeof(t_redirect));
    redirect->_stderr = mx_strnew(1000);
    redirect->_stdout = mx_strnew(1000);
    redirect->flag = flag_redir;
    pipe(redirect->fd_return);
    pipe(redirect->fd_stdout);
    pipe(redirect->fd_stderr);
    return redirect;
}
