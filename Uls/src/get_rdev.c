#include "uls.h"

char *get_rdev(dev_t st_rdev) {
    char *str1 = mx_itoa(((st_rdev >> 8) & 0xfff) | ((unsigned int) (st_rdev >> 32) & ~0xfff));
    char *str2 = mx_itoa((st_rdev & 0xff) | ((unsigned int) (st_rdev >> 12) & ~0xff));
    char *tmp = mx_strjoin(str1, ", ");
    char *str = mx_strjoin(tmp, str2);
    mx_strdel(&str1);
    mx_strdel(&str2);
    mx_strdel(&tmp);
    return str;
}
