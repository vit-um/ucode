#include "ush.h"

static void dollar_check(int len, char **input);
static void insert_str(char **input, int j, char *var);
static char *dollar_change(int len, char **input);

char **check_expansion(char *str_input, int ret_val) {
    char **input_words = mx_strsplit(str_input, ' ');
    int check = check_echo(input_words);  // = 0;

    if (check != 0) {
        mx_del_strarr(&input_words);
        input_words = split_echo(str_input, check);
    }
    for (int i = 0; input_words[i]; i++) {
        if (mx_get_substr_index(input_words[i], "$?") >= 0) {
            mx_strdel(&input_words[i]);
            input_words[i] = mx_itoa(ret_val);
        }
        if (input_words[i][0] == '~') {
            tilde_check(&input_words[i]);
        }
        else if (input_words[i][0] == '$') {
            dollar_check(mx_strlen(input_words[i]), &input_words[i]);
        }
    }
    return input_words;
}

static void dollar_check(int len, char **input) {
    char *var = NULL;
    extern char **environ;
    int flag = 0;

    var = dollar_change(len, input);
    for (int j = 0; environ[j]; j++) {
        if (strstr(environ[j], var) != NULL && environ[j][0] == var[0]) {
            flag = 1;
            insert_str(input, j, var);
            break;
        }
    }
    mx_strdel(&var);
    if (flag == 0) {
        mx_strdel(input);
        (*input) = mx_strdup("");
    }
}

static char *dollar_change(int len, char **input) {
    char *variable = NULL;

    if ((*input)[1] == '{' && (*input)[len - 1] == '}') {
        variable = mx_strnew(len - 1);
        for (int y = 2, x = 0; y < len - 1; y++, x++) {
            variable[x] = (*input)[y];
        }
        variable[len - 3] = '=';
        variable[len - 2] = '\0';
    }
    else {
        variable = mx_strnew(len + 1);
        for (int y = 1, x = 0; y < len; y++, x++) {
            variable[x] = (*input)[y];
        }
        variable[len - 1] = '=';
        variable[len] = '\0';
    }
    return variable;
}

static void insert_str(char **input, int j, char *var) {
    int x = 0;
    extern char **environ;

    mx_strdel(input);
    (*input) = mx_strnew(mx_strlen(environ[j]) - mx_strlen(var) + 1);
    for (int y = mx_strlen(var); y <= mx_strlen(environ[j]); y++) {
        (*input)[x++] = environ[j][y];
    }
    (*input)[x] = '\0';
}

