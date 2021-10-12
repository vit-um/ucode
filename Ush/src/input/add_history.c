#include "ush.h"

char *add_history(t_input *input, int *flag, t_ush *ush, char *temp) {
    if (ush->history->data != NULL) {
        if (ush->history->next != NULL && *flag == 0) {
            *flag = 1;
            mx_strdel(&temp);
            temp = mx_strdup(ush->history->data);
        }
        mx_strdel(&ush->history->data);
    }
    ush->history->data = mx_strdup(input->command);
    return temp;
}
