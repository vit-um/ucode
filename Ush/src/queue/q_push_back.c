#include "ush.h"

void q_push_back(t_queue **queue, char *data, char operation) {
    if (*queue) {
        t_queue *tmp = *queue;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = create_queue(data, operation);
    } else {
        *queue  = create_queue(data, operation);
    }
}
