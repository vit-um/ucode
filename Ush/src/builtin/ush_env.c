#include "ush.h"

int ush_env(char **args, t_ush *ush) {
    t_env *env = parse_env_args(args, ush); 
    char **env_args = NULL;
    pid_t pid;

    if (env != NULL) {
        if (env->comm == NULL || mx_strcmp(env->comm, "env") == 0) {
            mx_print_strarr(env->env_var, "\n");
        }
        else if (env->comm != NULL && ush != NULL) {
            env_args = mx_strsplit(env->comm_args, ' ');
            pid = fork();
            if (pid != 0) {
                wait(NULL);                                             //parent process
            }
            else {
                execve(env_args[0], env_args, env->env_var);        //child process
                exit(0);
            }
            mx_del_strarr(&env_args);
        }
        free_env(env);
        return 0;
    }
    free_env(env);
    free(env);
    return 1;
}
