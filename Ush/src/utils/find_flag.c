#include "ush.h"

int find_flag(char *flags, char *arg) {
    int flag = 0;

    for (int i = 0; flags[i]; i++) {
        for (int j = 1; arg[j]; j++) {
            if (arg[j] == flags[i]) {
                if (i + 1 > flag) {
                    flag = i + 1;
                }
                break;
            }
        }
    }
    return flag;
}
