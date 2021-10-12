#include "ush.h"

void free_queue(t_queue **queue) {
    int i = 0;
    while (queue[i]) {
        queue = &queue[i];
        if (queue) {
            t_queue *tmp = *queue;
            while ((*queue)->next) {
                (*queue) = (*queue)->next;
                mx_strdel(&tmp->data);
                free(tmp);
                tmp = *queue;
            }
            mx_strdel(&tmp->data);   
            free(tmp);
            *queue = NULL;
        }
        i++;
    }
    free(queue);
}
