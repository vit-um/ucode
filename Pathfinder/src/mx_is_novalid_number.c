#include "pathfinder.h"

bool mx_is_novalid_number(char *s) {
    int i = -1;
    while (s[++i])
        if (!mx_isdigit(s[i]))
            return true;
    return false;
}
