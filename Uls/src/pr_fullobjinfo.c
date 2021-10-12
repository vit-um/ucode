#include "uls.h"

void pr_fullobjinfo (t_objinfo dd, t_objsize sps, bool *fl) {
    if (fl[i]) {
        mx_printint(dd.d_ino);
        if (!fl[s])
            mx_printchar(' ');                
    }
    if (fl[s]) {
        pr_space(sps.blsize - get_intlen(dd.blsize) - (fl[i] ? 0 : 1));
        mx_printint(dd.blsize);
        mx_printchar(' ');                
    }
    mx_printstr(dd.perms);
    pr_space(sps.links - get_intlen(dd.links));
    mx_printint(dd.links);
    mx_printchar(' ');
    if (!fl[g]) {
        mx_printstr(dd.user);
        pr_space(sps.user - mx_strlen(dd.user));
    }
    mx_printstr(dd.group);
    pr_space(sps.group - mx_strlen(dd.group) - 1);
    pr_space(sps.hsize - mx_strlen(dd.hsize));
    mx_printstr(dd.hsize);
    mx_printchar(' ');
    mx_printstr(dd.time);
    mx_printchar(' ');
    pr_objname(dd,fl);
    mx_printchar('\n');
}
