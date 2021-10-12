#include "ush.h"

static void oldpwd(t_ush *ush);
static int handle_path(char *path, int flag, t_ush *ush);
static void stay_here(t_ush *ush);

int ush_cd(char **args, t_ush *ush) {
    int stop = 0;
    int words = mx_count_arr_el(args);
    int flag = 0;

    if (words == 1 || (words == 2 && mx_strcmp(args[1], "--") == false)) {
        stay_here(ush);
    }
    else {
        for (int i = 1; i < words; i++) {
            if (mx_strcmp(args[i], "--") == 0) {
                stop = 3;
                continue;
            }
            if (stop == 0 && args[i][0] == '-') {
                if ((flag = find_flag("Ps", args[i])) > 0) {
                    continue;
                }
            }
            return handle_path(args[i], flag, ush);
        }
    }
    return 0;
}

static int handle_path(char *path, int flag, t_ush *ush) {
    int ret = 0;
    char *tmp = mx_strdup(path);
    int link = check_symlink(&tmp, flag, 1);

    if (flag == 2 && link == 1) {
        fprintf(stderr, "cd: not a directory: %s\n", path);
        ret = 1;
    }
    else if (mx_strcmp(tmp, "-") == 0) {
        if (get_env("OLDPWD") != NULL) {
            oldpwd(ush);
        }
        else {
            fprintf(stderr, "ush: cd: OLDPWD not set\n");
            ret = 1;
        }
    }
    else {
        ret = make_path(tmp, ush, flag);
    }
    mx_strdel(&tmp);
    return ret;
}

static void stay_here(t_ush *ush) {
    char *arg = get_env("HOME");

    setenv("OLDPWD", ush->pwd_l, 1);
    setenv_ush(arg, ush);
    mx_strdel(&arg);
}

static void oldpwd(t_ush *ush) {
    char *current_pwd = get_env("PWD");
    char *old_pwd = get_env("OLDPWD");
    setenv_ush(old_pwd, ush);  
    chdir(old_pwd);
    setenv("OLDPWD", current_pwd, 1);
}
