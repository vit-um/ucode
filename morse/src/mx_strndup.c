#include "header.h"

char *mx_strndup(const char *str, size_t len) {
    char *new = mx_strnew(len);
    if (new == NULL)
        return NULL;
    return mx_strncpy(new, str, len);
}
