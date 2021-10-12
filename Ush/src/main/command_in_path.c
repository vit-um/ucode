#include "ush.h"

static char *check_in_path(char *command, char **path);

char *command_in_path(char *command, char *str_path) {
    char **path = NULL;
    char *command_p = NULL;
    int i = 0;

    if (str_path != NULL) {
        path = mx_strsplit(str_path, ':');
        if (strstr(str_path, "PATH=") != NULL) {
            for (; i < mx_strlen(path[0]) - 5; i++) {
                path[0][i] = path[0][i + 5];            ///позбуваємось частинки 'PATH=' шляхом покрокового перезаписування
            }
            path[0][i] = '\0';
        }
        if (mx_strcmp(command, "/") != 0 && mx_get_char_index(command, '/') == -1) {
            command_p = check_in_path(command, path);
        }

        mx_del_strarr(&path);
    }
    if (command_p == NULL) {
        command_p = mx_strdup(command);
    }
    return command_p;
}

static char *check_in_path(char *command, char **path) {
    char *command_p = NULL;

    for (int i = 0; path[i]; i++) {
        command_p = mx_strnew(mx_strlen(command) + mx_strlen(path[i]) + 1);
        mx_strcpy(command_p, path[i]);
        command_p = mx_strcat(command_p, "/");
        command_p = mx_strcat(command_p, command);
        if (file_exists(command_p)) {
            break;
        }
        mx_strdel(&command_p);
    }
    return command_p;
}
