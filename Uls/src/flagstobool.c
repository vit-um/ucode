#include "uls.h"

bool *flagstobool(char *flags) {
    bool *fl = (bool *)malloc(sizeof(bool) * (ALL_FLAGS + 1));
    int amtfls = mx_strlen(flags);

    for(int ii = 0; ii <= ALL_FLAGS; ii++) 
        fl[ii] = false;    

    for(int n = 0; n < amtfls; n++)
        for(int ii = 0; ii < ALL_FLAGS; ii++) 
            if (flags[n] == FLAG_LIST[ii])
                fl[ii] = true;    
    
    if (amtfls == 0)
        fl[ALL_FLAGS] = true;

    return fl;
}
