#include "pathfinder.h"

bool mx_check_dup(char **arr, int iarr) {
    for (int i = iarr; i > 0; i--)
        if(mx_strcmp(arr[iarr + 1], arr[i]) == 0)
            return true;
    return false;
}
