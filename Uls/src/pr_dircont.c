#include "uls.h"

void pr_dir_contents(t_objinfo *dd , bool *fl) {
    int i = 0;
    int j = 0;
    static t_objsize spaces;
    spaces.links = 0;
    spaces.size = 0;
    spaces.blsize = 0;
    spaces.user = 0;
    spaces.group = 0;
    spaces.name = 0;
    spaces.amt = 0;
    char **arr = NULL;
    
    while (dd[i].object) {
        if (fl[A]) {
            if(!(fl[A] && (mx_strcmp(dd[i].object, ".") == 0  || mx_strcmp(dd[i].object, "..") == 0))) 
                spaces = calc_spaces(dd[i], spaces);
        }
        else {
            if (fl[a] || dd[i].object[0] != '.')  
                spaces = calc_spaces(dd[i], spaces); 
        }
        i++;
    }

    i = 0;
    if (!fl[l]) 
        arr = (char **)malloc(sizeof(char *) * (spaces.amt + 1));

    while (dd[i].object) {
        if (fl[A]) {
            if (!(fl[A] && (mx_strcmp(dd[i].object, ".") == 0  
            || mx_strcmp(dd[i].object, "..") == 0))) {  
                if (fl[l])
                    pr_fullobjinfo(dd[i], spaces, fl);
                else 
                    arr[j++] = mx_strdup(dd[i].object);     
            }
        }
        else {
            if (fl[a] || dd[i].object[0] != '.') {
                if (fl[l]) 
                    pr_fullobjinfo (dd[i], spaces, fl);
                else
                    arr[j++] = mx_strdup(dd[i].object);
            }
        }
        i++;
    }

    if (!fl[l]) 
        pr_output_in_win(arr, spaces, fl);

  /*free memory*/
    clean_dirdata(dd);
    if (arr) {
        for(int i = 0; i < spaces.amt; i++)
            mx_strdel(&arr[i]);
        free(arr);
    }
}
