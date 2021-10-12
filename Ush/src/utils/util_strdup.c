#include "ush.h"

char *util_strdup(const char *data, int first, int end) {
    char *new = NULL;

    if (!data) {
        return NULL;
    }
    new = mx_strnew(end - first);
    return util_strcpy(new, data, first, end);
}
