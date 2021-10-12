#include "uls.h"

void pr_total(const char *dirname, bool *fl) {
    DIR *dirn = NULL;
    long total = 0;
    struct stat stst;
    struct dirent *dirt;
    char *pathdir = NULL; 

    dirn = opendir(dirname);
    int k = mx_strlen(dirname) + 2;

    while ((dirt = readdir(dirn))) {
        pathdir = mx_strnew(k + mx_strlen(dirt->d_name)); 
        pathdir = mx_strcat(pathdir, dirname);
        pathdir = mx_strcat(pathdir, "/");
        pathdir = mx_strcat(pathdir, dirt->d_name);
        lstat(pathdir, &stst);
        if (fl[A]) { 
            if(!(fl[A] && (mx_strcmp(dirt->d_name, ".") == 0  
            || mx_strcmp(dirt->d_name, "..") == 0))) 
                total += stst.st_blocks;
        }
        else {
            if(fl[a] || dirt->d_name[0] != '.') 
                total += stst.st_blocks;
        }
        mx_strdel(&pathdir);
    }
    closedir(dirn);

    mx_printstr("total ");
    mx_printint((int) total / 2);
    mx_printchar('\n');
}
