#include "ush.h"

void q_pop_front(t_queue **queue) {
    t_queue *temp = NULL;

    if (queue == NULL || *queue == NULL) {
        return;
    }
    if ((*queue)->next == NULL) {
        free((*queue)->data);
        free(*queue);
        *queue = NULL;
    } else {
        temp = (*queue)->next;
        free((*queue)->data);
        free(*queue);
        *queue = temp;
    }
}
