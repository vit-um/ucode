#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (*list) {
        t_list *tmp = *list;
        while (tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = mx_create_node(data);
    }
    else {
        *list = mx_create_node(data);
        (*list)->next = NULL;
    }
}
