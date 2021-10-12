#include "ush.h"

t_dbl_list *addelem_history(t_dbl_list *history) {
    t_dbl_list *temp, *p;

    temp = (t_dbl_list *) malloc(sizeof (t_dbl_list));
    p = history->next; // сохранение указателя на следующий узел
    history->next = temp; // предыдущий узел указывает на создаваемый
    temp->next = p; // созданный узел указывает на следующий узел
    temp->prev = history; // созданный узел указывает на предыдущий узел
    temp->data = NULL;
    if (p != NULL) {
        p->prev = temp;
    }
    return temp;
}

void free_step_history(t_input *input, char *temp) {
    mx_strdel(&temp);
    if (input != NULL) {
        mx_strdel(&input->command);
        free(input);
    }
}
