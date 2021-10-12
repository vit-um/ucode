#include "uls.h"

t_objinfo *getdirobj(char *dirname, bool *fl) {
    DIR *dirn;
    int amt = 0;
    struct stat st;
    struct dirent *dent = NULL;
    struct passwd *pwd = NULL;
    struct group *gr = NULL;
    t_objinfo *objsdata;
    char *pathdir = NULL; 
    int k = mx_strlen(dirname) + 2;

    dirn = opendir(dirname);
    while ((dent = readdir(dirn))) {
        amt++;
    }
    closedir(dirn);

    dirn = opendir(dirname);
   
    objsdata = (t_objinfo *)malloc(sizeof(t_objinfo) * (amt + 1));

    for(int i = 0; i < amt; i++) {
        dent = readdir(dirn);
        pathdir = mx_strnew(k + mx_strlen(dent->d_name)); 
        pathdir = mx_strcat(pathdir, dirname);
        pathdir = mx_strcat(pathdir, "/");
        pathdir = mx_strcat(pathdir, dent->d_name);
        lstat(pathdir, &st);
        objsdata[i].object = mx_strdup(dent->d_name);
        objsdata[i].type = st.st_mode;
        objsdata[i].d_ino = st.st_ino;
        objsdata[i].blsize = st.st_blocks / 2;
        objsdata[i].size = st.st_size;
        if (S_ISCHR(st.st_mode))
            objsdata[i].hsize = get_rdev(st.st_rdev);
        else
            objsdata[i].hsize = get_size_h(st.st_size, fl);
        objsdata[i].time = get_time(st, fl);
        objsdata[i].time_sec = st.st_mtim;
        objsdata[i].perms = get_permissions(st);
        objsdata[i].links = st.st_nlink;
        if ((pwd = getpwuid(st.st_uid)))
            objsdata[i].user = mx_strdup(pwd->pw_name);
        else
            objsdata[i].user = NULL;
        if ((gr = getgrgid(st.st_gid)))      
            objsdata[i].group = mx_strdup(gr->gr_name);
        else
            objsdata[i].group = NULL;
        mx_strdel(&pathdir);
    }
    objsdata[amt].object = NULL;
    closedir(dirn);

    if (fl[U])
        return objsdata;    

    if (fl[S]) {
        if (fl[r])
            sortobjs(objsdata, amt, sizeof(t_objinfo), compare_size_rev);
        else 
            sortobjs(objsdata, amt, sizeof(t_objinfo), compare_size);
        return objsdata;    
    }

    if (fl[t]) {
        if (fl[r])
            sortobjs(objsdata, amt, sizeof(t_objinfo), compare_time_rev);
        else 
            sortobjs(objsdata, amt, sizeof(t_objinfo), compare_time);
        return objsdata;    
    }

    if (fl[r])
        sortobjs(objsdata, amt, sizeof(t_objinfo), compare_ascii_rev);
    else 
        sortobjs(objsdata, amt, sizeof(t_objinfo), compare_ascii);

    return objsdata;
}
