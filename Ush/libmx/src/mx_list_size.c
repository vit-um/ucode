#include "libmx.h"


int mx_list_size(t_list *list) {
    int counter = 0;
    t_list *tmp = NULL;

    if (list) {
        tmp = list;
        while (tmp != NULL) {
            counter++;
            tmp = tmp->next;
        }
    }
    return counter;
}

// int mx_list_size(t_list *list) {
//     if (list == NULL)
//         return 0;

//     if (list->data == NULL)
//         return 0;

//     int count = 1;
//     while (list->next) {
//         list = list->next;
//         count++;
//     }
//     return count;
// }
