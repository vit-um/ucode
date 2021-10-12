#include "uls.h"

char *get_time(struct stat st, bool *fl) {
    time_t sec = time(NULL);
    time_t time = 0;
    char *sub;
    char *tmp;
    char *tmp2;

    time =  fl[c] ? st.st_ctime :
            fl[u] ? st.st_atime : st.st_mtime;
    
    if (((sec - (time)) > 15778368)) {
        sub = mx_substr(ctime(&(time)), 4, 10);
        tmp = mx_strjoin(sub, "  ");
        free(sub);
        tmp2 = mx_substr(ctime(&(time)), 20, 24);
        sub = mx_strjoin(tmp, tmp2);
        free(tmp2);
        free(tmp);
        return sub;
    }
    else {
        sub = mx_substr(ctime(&(time)), 4, fl[T] ? 24 : 16);
        return sub;
    }
    return NULL;
}
