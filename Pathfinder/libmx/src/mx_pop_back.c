#include "libmx.h"

void mx_pop_back(t_list **list) {
    t_list *temp = NULL;

    if (list == NULL || *list == NULL)
        return;

    if ((*list)->next == NULL) {
        free(*list);
        *list = NULL;
    }
    else {
        temp = *list;
        while (temp && temp->next->next != NULL)
            temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }
}


// void mx_pop_back(t_list **list) {
//     if (!(*list)) return;
//     t_list *tmp = *list;
//     if (tmp->next == NULL) {  // if there is only one item in the list, remove it
//         free(tmp);
//         *list = NULL;
//     }
//     else {

//         while (tmp -> next && tmp -> next -> next) {
//             tmp = tmp -> next;
//         }
//         free(tmp -> next);
//         tmp -> next = NULL;
//     }
// }
