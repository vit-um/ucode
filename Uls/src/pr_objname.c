#include "uls.h"

static inline void colorDir(mode_t sb) {
    if ((sb & S_IWOTH) == S_IWOTH
        && (sb & S_ISVTX) == S_ISVTX)
        mx_printstr(DIR_T); 
    else if ((sb & S_IWOTH) == S_IWOTH
            && (sb & S_IXOTH) == S_IXOTH)
        mx_printstr(DIR_X);
    else
        mx_printstr(BLU);
}

static inline void colorFile(mode_t sb) {
    if ((sb & S_ISUID) == S_ISUID)
        mx_printstr(BLK_F_RED_B);
    else if ((sb & S_ISGID) == S_ISGID)
        mx_printstr(BLK_F_CYAN_B);
    else if ((sb & S_IXUSR) == S_IXUSR)
        mx_printstr(RED);
    else
        mx_printstr(RESET);
}

static inline void colorLink(mode_t sb) {
    mx_printstr(S_ISFIFO(sb) ? YEL :
                S_ISCHR(sb) ? CHR_C :
                S_ISBLK(sb) ? BLOCK :
                S_ISSOCK(sb) ? GRN : MAG);
}

void pr_objname(t_objinfo dd, bool *fl) {
    if (fl[G]) {
        if (S_ISFIFO(dd.type))
            mx_printstr(YEL);
        else if (S_ISCHR(dd.type))
            mx_printstr(CHR_C);
        else if (S_ISBLK(dd.type))
            mx_printstr(BLOCK);
        else if (S_ISSOCK(dd.type))
            mx_printstr(GRN);
        else if (S_ISLNK(dd.type))
            colorLink(dd.type);
        else if (S_ISDIR(dd.type))
            colorDir(dd.type);
        else if (S_ISREG(dd.type))
            colorFile(dd.type);
        mx_printstr(dd.object);
        mx_printstr(RESET);
    } else
        mx_printstr(dd.object);
}
