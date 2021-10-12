#include "ush.h"

static void case_or(t_queue **queue, int i);
static void case_and_status_1(t_queue **queue, int i);

int execute_queue(t_queue **queue, t_ush *ush) {
    int status = 0;

    for (int i = 0; queue[i] != NULL; i++) {
        while (queue[i] != NULL) {
            mx_com_sub(&queue[i]->data, ush);       
            if (util_is_str(queue[i]->data) == true) {
                status = execute_command(ush, queue[i]->data, 0, NULL);
            }
            if (ush->exit_status != CONTINUE) {
                q_pop_front(&queue[i]);
                return status;
            }
            if (status == 0 && queue[i]->operator == '&') {
                q_pop_front(&queue[i]);
                continue;
            }
            else if (status == 1 && queue[i]->operator == '&') {
                case_and_status_1(queue, i);
                continue;
            }
            else if (status == 0 && queue[i]->operator == '|') {
                case_or(queue, i);
                continue;
            }
            else {
                q_pop_front(&queue[i]);
            }
        }
    }
    return status;
}

static void case_or(t_queue **queue, int i) {
    q_pop_front(&queue[i]);
    while (queue[i] != NULL && queue[i]->operator == '|') {
        q_pop_front(&queue[i]);
    }
    if (queue[i] != NULL) {
        q_pop_front(&queue[i]);
    }
}

static void case_and_status_1(t_queue **queue, int i) {
    q_pop_front(&queue[i]);
    while (queue[i] != NULL && (queue[i]->operator == '&' || queue[i]->operator == '0')) {
        q_pop_front(&queue[i]);
    }
}
