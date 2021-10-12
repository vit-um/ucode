#include "uls.h"

int main(int argc, char **argv) {
    char *flags;
    bool *fl;
    t_path *ps; 
    errno = 0;
 
    flags = flagsvalid(argc, argv);         // copy and compress flags to string
    fl = flagstobool(flags);                // copy flags to bool
    if (!fl[ALL_FLAGS])
        correct_flags(flags, fl);           // check what flags are first: a & A, l & 1
    ps = pathsvalid(argc, argv);            // copy paths to structure
    errno = pr_mainblock(ps, fl);           // print results ls  
    clean_memory(flags, fl, ps);            // clean memory
    return errno; 
}
