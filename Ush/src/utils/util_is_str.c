#include "ush.h"

bool util_is_str(char *data) {
    char *temp = mx_strtrim(data);
    bool status = false;

    if (mx_strlen(temp) != 0) {
        status = true;
    }
    mx_strdel(&temp);
    return status;
}
