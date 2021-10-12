#include "uls.h"

void clean_dirdata(t_objinfo *dd) {
    int i = 0;
    while (dd[i].object){
        mx_strdel(&dd[i].object);
        if (dd[i].perms) 
            mx_strdel(&dd[i].perms);
        if (dd[i].time)
            mx_strdel(&dd[i].time);
        if (dd[i].group)
            mx_strdel(&dd[i].group);
        if (dd[i].user)
            mx_strdel(&dd[i].user);
        if (dd[i].hsize)
            mx_strdel(&dd[i].hsize);
        i++;
    }    
    free(dd);
}
