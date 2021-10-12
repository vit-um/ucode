#include "ush.h"

char *get_env(char *var) {
    if (strcmp(var, "PWD") == 0) {
        return getcwd(NULL,0);
    } else if (strcmp(var, "HOME") == 0) {
        if (getenv("HOME") == NULL) {
            struct passwd *pw = getpwuid(getuid());
            return mx_strdup(pw->pw_dir);
        }
        return mx_strdup(getenv("HOME"));
    } else if (strcmp(var, "SHLVL") == 0) {
        if (getenv("SHLVL") == NULL) {
            return mx_strdup("1");
        }
        return mx_strdup(getenv("SHLVL"));
    } else if (strcmp(var, "OLDPWD") == 0) {
        if (getenv("OLDPWD") == NULL) {
            return NULL;
        }
        return getenv("OLDPWD");
    } else if (strcmp(var, "PATH") == 0) {
        if (getenv("PATH") == NULL) {
            return "/bin:/usr/bin:/usr/ucb:/usr/local/bin";
        }
        return getenv("PATH");
    }
    return NULL;
}
