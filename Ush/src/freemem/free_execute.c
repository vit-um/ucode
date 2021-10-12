#include "ush.h"

void free_execute(t_redirect *redirect, char **input) {
    if (redirect != NULL) {
        mx_strdel(&redirect->_stderr);
        mx_strdel(&redirect->_stdout);
        free(redirect);
    }
    mx_del_strarr(&input);
}
