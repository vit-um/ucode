#include "uls.h"

void correct_flags(char *flags, bool *fl) {
    // if first `A` del `a` else del `A`
    if (mx_strchr(flags,'A') && mx_strchr(flags,'a')) {
        if (mx_strlen(mx_strchr(flags,'A')) > mx_strlen(mx_strchr(flags,'a'))) {
            fl[a] = false;
        }
        else {
            fl[A] = false;
        }
    }
    // if first `1` del `l` else del `1`
    if (mx_strchr(flags,'1') && mx_strchr(flags,'l')) {
        if (mx_strlen(mx_strchr(flags,'1')) > mx_strlen(mx_strchr(flags,'l'))) {
            fl[l] = false;
        }
        else {
            fl[one] = false;
        }
    }
    // flag `f` on `-aU` off `-ls`
    if (mx_strchr(flags,'f')) {
        if (fl[l] && (mx_strlen(mx_strchr(flags,'l')) > mx_strlen(mx_strchr(flags,'f')))) 
            fl[l] = false;  
        if (fl[s] && (mx_strlen(mx_strchr(flags,'s')) > mx_strlen(mx_strchr(flags,'f')))) 
            fl[s] = false;  
        fl[a] = true;
        fl[U] = true;
    }
    // set flag `l` if choose flag `g`
    if (mx_strchr(flags,'g')) 
        fl[l] = true;
}
