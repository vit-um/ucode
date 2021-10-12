#include "uls.h"

char *flagsvalid(int argc, char **argv) {
    int count_fl = 0;
    int count_fl2 = 0;
    int count_par;
    char *flags;
    char *flags2;
    char *abspath = get_path_uls(argv[0]);

    for (count_par = 1; count_par < argc && argv[count_par][0] == '-' 
    && argv[count_par][1] != '-'; count_par++)
        count_fl += mx_strlen(argv[count_par]) - 1;
    
    count_par--;
    flags = mx_strnew(count_fl);

    for (int i = 1, j = 0; i <= count_par; i++)
        for (int k = 1; argv[i][k] != '\0'; k++, j++)
            flags[j] = argv[i][k];
// check illegal options
    for (int i = 0; flags[i]; i++) {
        if (mx_strchr(FLAG_LIST, flags[i]) == 0) {
            mx_printerr(abspath);
            mx_printerr(": illegal option -- ");
            mx_printerr(&flags[i]);
            mx_printerr("\n");
            mx_printerr("usage: uls [-");
            mx_printerr(FLAG_LIST);
            mx_printerr("] [file ...]\n");
            mx_strdel(&flags);
            mx_strdel(&abspath);
            exit(1);
        }
    }
// delete duplicate flags
    for (int i = count_fl - 1 ; i >= 0; i--)
        for (int j = i - 1; j >= 0; j--)
            if (flags[i] == flags[j] && flags[i] != '-') {
                flags[j] = '-';
                count_fl2++;
            }

    if (count_fl2 > 0){
        flags2 = mx_strnew(count_fl - count_fl2);
        for(int i = count_fl - 1, j = i - count_fl2; i >=0; i--) {
            if (flags[i] != '-') {
                flags2[j] = flags[i];
                j--;
            }
        }
        mx_strdel(&flags);
        mx_strdel(&abspath);
        return flags2;
    }
    mx_strdel(&abspath);
    return flags;
}
