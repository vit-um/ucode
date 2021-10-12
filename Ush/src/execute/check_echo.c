#include "ush.h"

int check_echo(char **n) {
    int flag_one = 0;
    int flag_two = 0;

    if (mx_strcmp(n[0], "echo") == 0 || mx_strcmp(n[0], "/bin/echo") == 0 
                                ||  mx_strcmp(n[0], "/usr/bin/echo")) {
        for (int i = 0; i < mx_count_arr_el(n); i++) {
            if (n[i][0] == '-')
                continue;
            else if (n[i][0] == '$')
                return 0;
            else if (n[i][0] == '\'' || n[i][mx_strlen(n[i]) - 1] == '\'')
                flag_one++;
            else if (n[i][0] == '\"' || n[i][mx_strlen(n[i]) - 1] == '\"')
                flag_two++;
        }
    }
    if (flag_one == 2 && flag_two == 0)
        return 2;
    else if (flag_one == 0 && flag_two == 2)
        return -2;
    return 0;
}
