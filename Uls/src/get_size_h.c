#include "uls.h"

char *double_to_str(double n) {
    char *str = NULL;
    char *str1 = NULL;
    char *str2 = NULL;
    char *str3 = NULL;
    int temp = (n - (int)n) * 100;
    int i = mx_pow(10, get_intlen((int)n));
    n += temp % 10 > 4 ? .1 : 0;
    n += i > 10 && temp % 100 > 50 ? 1 : 0;
    str1 = mx_itoa((int)n % i);
    if (i < 100) {
        str3 = mx_itoa((int)((n - (int)n) * 10));
        str2 = mx_strjoin(",", str2);
        str = mx_strjoin(str1, str2);
        mx_strdel(&str1);
        mx_strdel(&str2);
        mx_strdel(&str3);
        return str;
    }
    else {
        return str1;
    }
}

char *get_size_h (off_t st_size, bool *fl) {
    if (fl[h]) {
        char *str = NULL;
        char *tmp = NULL;
        if (st_size < 1000) {
            return mx_itoa(st_size);
        }
        else if (st_size >= 1000 && st_size < 1000000) {
            tmp = double_to_str((double)st_size / BIBYTE);
            str = mx_strjoin(tmp, "K");
            mx_strdel(&tmp);
            return str;
        }
        else if (st_size >= 1000000 && st_size < 1000000000) {
            tmp = double_to_str((double)st_size / BIBYTE / BIBYTE);
            str = mx_strjoin(tmp, "M");
            mx_strdel(&tmp);
            return str;
        }
        else if (st_size >= 1000000000 && st_size < 1000000000000) {
            tmp = double_to_str((double)st_size / BIBYTE / BIBYTE / BIBYTE);
            str = mx_strjoin(tmp, "G");
            mx_strdel(&tmp);
            return str;
        }
    }
    return mx_itoa(st_size);
}
