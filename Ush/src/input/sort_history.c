#include "ush.h"

void sort_history(t_ush *ush, char *temp) {
    char *p = mx_strdup(ush->history->data);        //зберігаємо temp у змінній p

    mx_strdel(&ush->history->data);                 //звільняємо пам`ять у полі data
    ush->history->data = mx_strdup(temp);           //записуємо нове значення у поле data
    while (ush->history->next != NULL) {
        ush->history = ush->history->next;          //переміщаємо вказівник поки не дійдемо до NULL
    }
    ush->history->data = p;                         //записуємо дані зі змінної p в переміщений вузол
}
