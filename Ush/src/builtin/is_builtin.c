#include "ush.h"

static int is_built(char *command) {
    if (strcmp("cd", command) == 0)
        return CD;
    if (strcmp("pwd", command) == 0)
        return PWD;
    if (strcmp("echo", command) == 0)
        return SH_ECHO;
    return 0;
}

int is_builtin(char *command) {
    int num = 0;
    char builtins[][20] = {"/usr/bin/cd", "/bin/pwd", "/usr/bin/env",
                            "ush", "export", "unset", "exit",
                            "/usr/bin/which", "/bin/echo",  
                            "/usr/bin/pwd", "/usr/bin/echo", "\0"};

    for (int i = 0; command[i]; i++) {
        command[i] = (char)mx_tolower(command[i]);
    }

    if ((num = is_built(command)) == 0) {
        for (int i = 0; i < 12; i++) {
            if (mx_strcmp(builtins[i], command) == 0) {
                num = i + 1;
            }
        }
    }
    return num;
}
