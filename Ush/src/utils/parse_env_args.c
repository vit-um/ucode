#include "ush.h"

static t_env *create_env(void) {
    t_env *env = (t_env *) malloc(sizeof (t_env));
    int i = 0;
    extern char **environ;
    int size = mx_count_arr_el(environ) + 1;

    env->flag = 0;
    env->comm = NULL;
    env->comm_args = NULL;
    env->env_var = (char **) malloc(size * sizeof (char *));
    for (int j = 0; j < size -1; j++) {
        env->env_var[i++] = mx_strdup(environ[j]);
    }
    env->env_var[i] = NULL;
    return env;
}


static int check_flag_if(char **args, int i, t_env *env) {
    if (find_flag("Piu", args[i]) == 0) {
        fprintf(stderr, MX_ENV_IL, args[i][1]);
        free_env(env);
        return -1;
    }
    else if (find_flag("Piu", args[i]) < 3 && env->flag == 0 && args[i + 1] == NULL) {
        fprintf(stderr, MX_ENV_US, args[i][1]);
        free_env(env);
        return -1;//break
    }
    else if (find_flag("Piu", args[i]) > env->flag) {
        env->flag = find_flag("Piu", args[i]);
    }
    return 0;
}


static int check_flag(char **args, int i, t_env *env) {//
    if (mx_strcmp(args[i], "--") == 0) {
        env->flag = 4;
        return 0;
    }
    else if (args[i][0] == '-' && env->flag != 4) {
        return check_flag_if(args, i, env);
    }
    return 1;
}

static void create_command(t_env *env, char *arg, t_ush *ush) {
    int y = 0;
    char *temp = NULL;

    for (; env->env_var[y]!= NULL; y++) {
        temp = mx_strdup(env->env_var[y]);
        if (strstr(temp, "PATH=") != NULL) {
            mx_strdel(&temp);
            break;
        }
        mx_strdel(&temp);
    }
    if (mx_strcmp(arg, "ush") == 0 || mx_strcmp(arg, "./ush") == 0) {
        env->comm = mx_strdup(ush->ush_path);
    }
    if (env->env_var[y] == NULL) {
        env->comm = command_in_path(arg, get_env("PATH"));
    }
    else {
        env->comm = command_in_path(arg, env->env_var[y]);
    }
}


t_env *parse_env_args(char **args, t_ush *ush) {
    t_env *env = create_env();
    int env_index = 0;

    for (int i = 1; args[i]; i++) {
        if (check_flag(args, i, env) == -1) {
            break;
        }
        else if (check_flag(args, i, env) == 0) {
            continue;
        }
        create_command(env, args[i], ush);
        if (execute_env_flags(env, args, i, &env_index) == -1) {
            break;
        }
        if (env != NULL) {
            mx_strdel(&env->comm);
        }
    }
    if (env == NULL) {
        return NULL;
    }
    return env;
}
