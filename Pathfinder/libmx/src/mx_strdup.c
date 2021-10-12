#include "libmx.h"

char* mx_strdup(const char *str) {
    int len = mx_strlen(str);
    if (len > 0) {
        char* strnew = mx_strnew(len);
        return  mx_strcpy(strnew, str);
    }
    else if (len == 0)
        return  mx_strnew(len);
    else return NULL;
}
