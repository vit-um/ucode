#include "ush.h"

void print_prompt(int flag, t_ush *ush) {
    if (flag == 1) {
        srandom(time(NULL));
        ush->emodji_num = random() % 79 + 128512;
    }
    mx_print_unicode(ush->emodji_num);
    mx_printstr(GREEN "u$h" RED "> " DEFAULT);
}
