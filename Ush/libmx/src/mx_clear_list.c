#include "libmx.h"

// void mx_clear_list(t_list **list) {
//     t_list *buff = *list;
//     t_list *del;

//     while(buff->next) {
//         del = buff;
//         buff = buff->next;
//         free(del);
//     }
//     free(buff);
//     *list = NULL;
// }



void mx_clear_list(t_list **list) {
    if (list) {
        t_list *tmp = *list;
        while ((*list)->next) {
            (*list) = (*list)->next;
            free(tmp);
            tmp = *list;
            }
        free (tmp);
        *list = NULL;
    }
}
