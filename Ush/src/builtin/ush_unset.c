#include "ush.h"

int ush_unset(char **args) {
    for (int i = 1; args[i]; i++) {
        unsetenv(args[i]);
    }
    return 0;
}
