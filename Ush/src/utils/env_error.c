#include "ush.h"

void env_error(t_env *env, char **args, int i) {
    if (file_exists(args[i]) != 1) {
        fprintf(stderr, "env: %s: No such file or directory\n", args[i]);
    } else if (file_exists(args[i]) == 1) {
        fprintf(stderr, "env: %s: Permission denied\n", args[i]);
    }
    free_env(env);
}
