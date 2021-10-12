#include "ush.h"

t_dbl_list *del_elem(t_dbl_list *lst);

void free_ush(t_ush *ush) {
    if (ush != NULL) {
        while (ush->history->next != NULL) {
            ush->history = ush->history->next;
        }
        while (ush->history != NULL) {
            ush->history = del_elem(ush->history);
        }
        if (ush->pids != NULL) {
            t_pid *temp = NULL;
            while (ush->pids->prev != NULL) {
                temp = ush->pids;
                ush->pids = ush->pids->prev;
                mx_strdel(&temp->str);
                free(temp);
            }
            mx_strdel(&ush->pids->str);
            free(ush->pids);
        }
        mx_strdel(&ush->ush_path);
        mx_strdel(&ush->pwd_l);
        free(ush);
    }
}

t_dbl_list *del_elem(t_dbl_list *lst) {
    t_dbl_list *prev = lst->prev; 
    t_dbl_list *next = lst->next; 
    if (prev != NULL) {
        prev->next = lst->next;
    }
    if (next != NULL) {
        next->prev = lst->prev;
    }
    mx_strdel(&lst->data);
    free(lst); 
    return(prev);
}
