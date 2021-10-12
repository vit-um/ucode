#include "pathfinder.h"

bool mx_is_novalid_alpha(char *s) {
    int i = -1;
    while (s[++i])
        if (!mx_isalpha(s[i]))
            return true;
    return false;
}
