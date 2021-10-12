#include "uls.h"

char *get_path_uls(char *path) {
    char *buf = NULL;
    ssize_t nbytes, offset, bufsiz = 200;

    if (path[0] == '/') {
        buf = mx_strnew(bufsiz);
        nbytes = readlink("/proc/self/exe", buf, bufsiz);
        if (nbytes == -1) {
            perror("readlink");
            exit(EXIT_FAILURE);
        }
    }
    else {
        offset = path[0] == '.' && path[1] !='.' ? 2 : 0;
        buf = mx_strdup(path + offset);
    }
    return buf;
}
