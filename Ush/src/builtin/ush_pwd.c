#include "ush.h"

static void cd_err(char c, int *flag) {
    if (c != '\0') {
        fprintf(stderr, MX_PWD_ERR, c);
    }
    else {
        fprintf(stderr, "pwd: too many arguments\n");
    }
    *flag = 3;
}

static void parse_pwd(char **args, int *flag) {
    for (int i = 1, stop = 0; args[i]; i++) {
        if (mx_strcmp(args[i], "--") == 0) {
            stop = 3;
        }
        if (stop == 0 && args[i][0] == '-') {
            for (int j = 1; j < mx_strlen(args[i]); j++) {
                if (args[i][j] != 'L' && args[i][j] != 'P') {
                    cd_err(args[i][j], flag);
                    break;
                }
            }
            if (*flag == 3) {
                break;
            }
            if ((*flag = find_flag("LP", args[i])) > 0) {
                continue;
            }
        }
        else {
            cd_err('\0', flag);
        }
    }
}

int ush_pwd(char **args, t_ush *ush) {
    int flag = 0;
    char *position = NULL;
    int is_link = 0;

    parse_pwd(args, &flag);
    if (flag != 2) {
        position = mx_strdup(ush->pwd_l);
    }
    else {
        position = get_env("PWD");
        is_link = check_symlink(&position, flag, 2);
    }
    if (flag != 3) {
        mx_printstr(position);
        mx_printchar('\n');
    }
    else {
        mx_strdel(&position);
        return 1;
    }
    mx_strdel(&position);
    return 0;
}
