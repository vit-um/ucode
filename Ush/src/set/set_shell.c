#include "ush.h"

void set_shell(void) {
    char *shlv = get_env("SHLVL");
    char *shlvl = mx_itoa(mx_atoi(shlv) + 1);
    extern char **environ;        //del
    char cwd[4096];

    if (getenv("HOME") == NULL) {
        setenv("HOME", get_env("HOME"), 1);
    }
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        setenv("PWD", cwd, 1);
    }
    if (getenv("OLDPWD") == NULL) {
        setenv("OLDPWD", get_env("PWD"), 1);
    }
    if (getenv("PATH") == NULL) {
        setenv("PATH", get_env("PATH"), 1);
    }
    if (getenv("SHLVL") == NULL) {
        setenv("SHLVL", "1", 1);
    }
    else {
        setenv("SHLVL", shlvl, 1);
    }
    setenv("_", "/usr/bin/env", 1);
    mx_strdel(&shlvl);
    mx_strdel(&shlv);
}
