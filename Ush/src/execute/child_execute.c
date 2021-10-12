#include "ush.h"

static void child_not_builtin(int *ret_val, char **input, char *command_p);

void child_execute(int *ret, char **input, t_redirect *red, t_ush *ush) {
    char *command_p = command_in_path(input[0], getenv("PATH"));
    int command = is_builtin(command_p);
    child_redirect(red);
    if (command == PWD || command == PATH_PWD) {
        *ret = ush_pwd(input, ush);
    }
    else if (command == ENV) {
        *ret = ush_env(input, ush);
    }
    else if (command == WHICH) {
        *ret = ush_which(input);
    }
    else if (command == SH_ECHO || command == PATH_ECHO) {
        *ret = ush_echo(input);
    }
    else if (command == 0 || command == 4) {
        if (mx_strcmp(command_p, "ush") == 0 || mx_strcmp(command_p, "./ush") == 0) {
            mx_strdel(&input[0]);
            input[0] = mx_strdup(ush->ush_path);
        }
        child_not_builtin(ret, input, command_p);
    }
    child_free(command_p, red->fd_return, *ret);
    exit(0);
}

static void child_not_builtin(int *ret_val, char **input, char *command_p) {
    DIR *dp = NULL;
    extern char **environ;

    if ((dp = opendir(command_p)) != NULL) {
        fprintf(stderr, "ush: %s: is a directory\n", input[0]);
        *ret_val = 1;
        closedir(dp);
    }
    else if (file_exists(command_p)) {
        int exec = execve(command_p, input, environ);
        if (exec == -1 && errno == EACCES) {
            fprintf(stderr, "ush: Permission denied:%s\n", input[0]);
            *ret_val = 1;
        }
    }
    else {
        fprintf(stderr, "ush: command not found: %s\n", input[0]);
        *ret_val = 1;
    }
}
