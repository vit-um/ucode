#include "ush.h"

int ush_exit(char **args, int *exit_status) {
    int ret = 0, words = mx_count_arr_el(args);

    if (words == 1) {
        *exit_status = STOP;
    }
    else if (mx_atoi(args[1]) == INT_MIN && words == 2) {
        fprintf(stderr, "ush: exit: %s: numeric argument required\n", args[1]);
        ret = 1;
    }
    else if (words == 2) {
        *exit_status = mx_atoi(args[1]);
        ret = *exit_status;
    }
    else {
        fprintf(stderr, "ush: exit: too many arguments\n");
        ret = 1;
    }
    return ret;
}
