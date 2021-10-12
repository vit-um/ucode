#include "ush.h"

void move_coursor(int num_of_moves, char *side) {
    char *str2 = "\033[";
    char *str1 = mx_itoa(num_of_moves);
    char *temp = mx_strjoin(str1,side);
    char *str = mx_strjoin(str2,temp);

    mx_strdel(&str1);
    mx_strdel(&temp);
    mx_printstr(str);
    mx_strdel(&str);
}
