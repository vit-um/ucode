#include "ush.h"

void setenv_ush(char *arg, t_ush *ush) {
    if (mx_strlen(arg) != 1 && arg[mx_strlen(arg) - 1] == '/') {
        arg[mx_strlen(arg) - 1] = '\0';
    }
    if (mx_strcmp(arg, ush->pwd_l) != 0) {
        mx_strdel(&ush->pwd_l);
        ush->pwd_l = mx_strdup(arg);  //arg = path oldpwd
    }
    setenv("PWD", arg, 1);
}
