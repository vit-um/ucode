
#include "ush.h"

void free_jobs(t_ush *ush) {
    char **input = mx_strsplit(ush->str_input, ' ');
    t_pid *temp = NULL;

    if (mx_strcmp(input[0], "fg") == 0 && ush->pids != NULL) {
        mx_strdel(&ush->str_input);
        ush->curr_pid = ush->pids->num;
        ush->str_input = mx_strdup(ush->pids->str);
        temp = ush->pids;
        ush->pids = ush->pids->prev;
        mx_strdel(&temp->str);
        free(temp);
    }
    mx_del_strarr(&input);
}
