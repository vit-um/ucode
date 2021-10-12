#include "ush.h"

static void change_export(char *arg, int len_n, char *name, char *value);

int ush_export(char **args) {
    char *name = NULL;
    char *value = NULL;
    int name_len = 0;
    int value_len = 0;

    for (int i = 1; args[i]; i++) {
        if ((name_len = mx_get_char_index(args[i], '=')) != -1) {
            value_len = mx_strlen(args[i]) - name_len - 1;
            name = mx_strnew(name_len);
            value = mx_strnew(value_len);
            change_export(args[i], name_len, name, value);
            setenv(name, value, 1);
            mx_strdel(&name);
            mx_strdel(&value);
        }
    }
    return 0;
}

static void change_export(char *arg, int len_n, char *name, char *value) {
    int i = 0;

    for (i = 0; arg[i] != '='; i++) {
        name[i] = arg[i];                               ///послідовно переписуємо ім'я змінної середовища
    }
    for (i = 0; arg[len_n + i + 1] != '\0'; i++) {
        value[i] = arg[len_n + i + 1];                  ///послідовно перезаписуємо нове значення змінної середовища
    }
}
