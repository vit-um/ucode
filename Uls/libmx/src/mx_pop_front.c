#include "libmx.h"

void mx_pop_front(t_list **list) {
    t_list *temp = NULL;

    if (list == NULL || *list == NULL)
        return;
    if ((*list)->next == NULL) {
        free(*list);
        *list = NULL;
    } else {
        temp = (*list)->next;
        free(*list);
        *list = temp;
    }
}


// void mx_pop_front(t_list **list) {
//     if (!(*list)) return;

//     t_list *tmp = *list;
//     if (tmp->next == NULL) {  // if there is only one item in the list, remove it
//         free(tmp);
//         *list = NULL;
//     }
//     else {
//         t_list *tmp = (*list)->next;
//         free(*list);
//         *list = tmp;
//     }
// }
