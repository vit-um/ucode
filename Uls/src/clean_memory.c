#include "uls.h"

void clean_memory(char *flags, bool *fl, t_path *ps) {
    mx_strdel(&flags);
    for(int i = 0; i < ps->amt; i++)
        mx_strdel(&ps->path[i]);
    free(ps->path);
    free(ps->type);
    free(ps);
    free(fl);
}
