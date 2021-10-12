#include "uls.h"

int pr_mainblock(t_path *ps, bool *fl) {
    uint8_t cfs = 0;
    uint8_t cds = 0;
    static t_objsize spaces;
    char *arr[ps->amt];

    if (ps->amt > 1) {
        for(int i = 0; i < ps->amt; i++) 
            if (ps->type[i] == REG) {
                arr[cfs] = ps->path[i];
                cfs++;
            }

        if (cfs) {
            if (fl[l]) {    
                t_objinfo *dd = get_files_info(arr, cfs, fl);
                for(int i = 0; i < cfs; i++)
                    spaces = calc_spaces(dd[i],spaces);
                for(int i = 0; i < cfs; i++)
                    pr_fullobjinfo (dd[i], spaces, fl);
                clean_dirdata(dd);
                if (cfs < ps->amt)
                    mx_printchar('\n'); 
            }
            else {
                for(int i = 0; i < ps->amt; i++) 
                    if (ps->type[i] == REG) {
                        cfs--;
                        mx_printstr(ps->path[i]);
                        if (cfs) {
                            if (isatty(1) && !fl[one])
                                mx_printstr("  ");
                            else
                                mx_printchar('\n');
                        }
                        else {
                            mx_printstr("\n");
                            if (i != ps->amt - 1)
                                mx_printstr("\n");
                        }
                    }   
            }         
        }

        for(int i = 0; i < ps->amt; i++){
            if (ps->type[i] == P_ERR)
                errno = EXIT_FAILURE;
            if (ps->type[i] == T_DIR || ps->type[i] == LNK)
                cds++;
        }
        for(int i = 0; i < ps->amt; i++){
            if (ps->type[i] == T_DIR || ps->type[i] == LNK) {
                cds--;
                mx_printstr(ps->path[i]);
                mx_printstr(":\n");
                if (fl[l])
                    pr_total(ps->path[i], fl);
                pr_dir_contents(getdirobj(ps->path[i], fl), fl);
                if (cds) 
                    mx_printchar('\n');
            }
        }
    }
// print ls with flag l and curent dir only
    if (ps->amt == 1 && ps->type[0] == T_DIR) {
        if (fl[l])
            pr_total(ps->path[0], fl);
    pr_dir_contents(getdirobj(ps->path[0], fl), fl);
    }
// print ls with files 
    if (ps->amt == 1 && ps->type[0] != T_DIR && ps->type[0] != P_ERR) {
        if (fl[l]) {
            t_objinfo *dd = get_files_info(ps->path, 1, fl);
            spaces = calc_spaces(dd[0],spaces);
            pr_fullobjinfo (dd[0], spaces, fl);
            clean_dirdata(dd);
        }
        else {
            mx_printstr(ps->path[0]);
            mx_printchar('\n');
        }
    }
    return errno; 
}
