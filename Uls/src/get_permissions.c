#include "uls.h"

char *get_permissions(struct stat st) {
    char *str = mx_strnew(10);
    
    str[0] = (S_ISBLK(st.st_mode) ? 'b' :
              S_ISCHR(st.st_mode) ? 'c' :
              S_ISDIR(st.st_mode) ? 'd' :
              S_ISSOCK(st.st_mode) ? 's' :
              S_ISFIFO(st.st_mode) ? 'p' :
              S_ISLNK(st.st_mode) ? 'l' : '-');
    str[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
    str[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
    str[3] = ((st.st_mode & S_IXUSR) ?
             ((st.st_mode & S_ISUID) ? 's' : 'x') :
             ((st.st_mode & S_ISUID) ? 'S' : '-'));
    str[4] = ((st.st_mode& S_IRGRP) ? 'r' : '-');
    str[5] = ((st.st_mode & S_IWGRP) ? 'w' : '-');
    str[6] = ((st.st_mode & S_IXGRP) ?
             ((st.st_mode & S_ISGID) ? 's' : 'x') :
             ((st.st_mode & S_ISGID) ? 'S' : '-'));
    str[7] = ((st.st_mode& S_IROTH) ? 'r' : '-');
    str[8] = ((st.st_mode & S_IWOTH) ? 'w' : '-');
    str[9] = ((st.st_mode & S_IXOTH) ?
             ((st.st_mode & S_ISVTX) ? 't' : 'x') :
             ((st.st_mode & S_ISVTX) ? 'T' : '-'));
    str[10] = '\0';
    return str;
}
