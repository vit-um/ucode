#include "ush.h"

void clear_str(void) {
    write(STDOUT_FILENO, "\033[2K", 4);
    mx_printstr("\033[G");
}
