#include "uls.h"

t_path *pathsvalid(int argc, char **argv){
    int param = 1;
    struct stat stats;
    DIR *dirn;
    t_path *p = (t_path *)malloc(sizeof(t_path));
    char *abspath = get_path_uls(argv[0]);

    if (argc > 1)
        while (argv[param] && argv[param][0] == '-')
            if (argv[param++][1] == '-')
                break;

    if (argc - param == 0) {
        p->amt = 1;
        p->type = (char *)malloc(sizeof(char));
        p->type[0] = T_DIR;
        p->path = (char **)malloc(sizeof(char *));
        p->path[0] = (char *)malloc(sizeof(char) * 2);
        p->path[0][0] = '.';
        p->path[0][1] = '\0';
        mx_strdel(&abspath);
        return p;
    }
    else {
        p->amt = argc - param;
        p->path = (char **)malloc(sizeof(char *) * p->amt);
        p->type = (char *)malloc(sizeof(char) * p->amt);

        for(int i = param, j = 0; i < argc; i++, j++) {
            if (lstat(argv[i], &stats) == -1) {
                p->path[j] = mx_strdup(argv[i]);
                p->type[j] = P_ERR;
//                mx_printerr(abspath);
                mx_printerr("uls");
                mx_printerr(": cannot access '");
                mx_printerr(p->path[j]);
                perror("'");
            }
            else {
                p->path[j] = mx_strdup(argv[i]);
                switch (stats.st_mode & S_IFMT) {
                    case S_IFBLK:  
                        p->type[j] = BLK;            
                        break;
                    case S_IFCHR:
                        p->type[j] = CHR;
                        break;
                    case S_IFDIR:
                        p->type[j] = T_DIR;              
                        break;
                    case S_IFIFO:
                        p->type[j] = FIFO;            
                        break;
                    case S_IFLNK:
                        p->type[j] = LNK;                
                        break;
                    case S_IFREG:
                        p->type[j] = REG;           
                        break;
                    case S_IFSOCK: 
                        p->type[j] = SOCK;             
                        break;
                    default:
                        p->type[j] = UNKN;                
                        break;
                }
            }
            dirn = opendir(p->path[j]);
            if ((p->type[j] == T_DIR || p->type[j] == LNK) && dirn == NULL) {
                p->type[j] = P_ERR;
//                mx_printerr(abspath);
                mx_printerr("uls");
                mx_printerr(": cannot open directory '");
                mx_printerr(p->path[j]);
                perror("'");
            }
            if (dirn)
                closedir(dirn);
        }
        mx_strdel(&abspath);
        return p;
    }
}
