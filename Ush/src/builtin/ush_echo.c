#include "ush.h"

int ush_echo(char **args) {
    int flag = 0;
    char *str = parse_echo(args, &flag);  

    if (str != NULL) {
        mx_printstr(str);
    }
    if (flag == 0) {
        mx_printchar('\n');
    } else if (flag == -1) {
        return 1;
    }
    mx_strdel(&str);
    return 0;
}
