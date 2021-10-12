#include "uls.h"

int compare_ascii_rev(const void *a, const void *b) {
    int len1 = mx_strlen(((t_objinfo *)a)->object);
    int len2 = mx_strlen(((t_objinfo *)b)->object);

    char *str1 = mx_strnew(len1);
    char *str2 = mx_strnew(len2);

    for(int i = 0; i < len1; i++) 
        str1[i] = mx_tolower(((t_objinfo *)a)->object[i]);            
    for(int i = 0; i < len2; i++) 
        str2[i] = mx_tolower(((t_objinfo *)b)->object[i]);            

    len1 = mx_strcmp(str2, str1);

    mx_strdel(&str1);
    mx_strdel(&str2);
    return len1;
}
