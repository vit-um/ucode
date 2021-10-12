#include "libmx.h"

int mx_read_line(char **lineptr, char delim, const int fd) {
    size_t len = 0;
    int eof = 0;
    char buf;
    char tmp[1024];
  
    if (read(fd, NULL, 0) < 0) {
        *lineptr = mx_realloc(*lineptr, 0);
        return -2;
    }
    
    while ((eof = read(fd, &buf, 1)) > 0) {
        if (buf == delim) {
            mx_strdel(lineptr);
            tmp[len] = '\0';
            *lineptr = mx_strdup(tmp);
            break;
        }
        else {
            tmp[len] = buf;
            len++;
 
        }
    }

    if (!lineptr)
        return -2;
    if (eof == 0)  return -1;    
   
    return len;
}
