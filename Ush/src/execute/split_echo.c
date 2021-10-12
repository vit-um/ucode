#include "ush.h"

static void insert_chars(char **str, char sym, int index) {
    char temp;
    int len = mx_strlen(*str);

    (*str) = realloc((*str), len + 2);
    for (; index < len + 1; index++) {
        temp = (*str)[index];
        (*str)[index] = sym;
        sym = temp;
    }
    (*str)[index] = '\0';
}

static char **insertin_arr(char c, char *str_input) {
    char **arr = NULL;

    arr = mx_strsplit(str_input, c);
    insert_chars(&(arr[1]), c, 0);
    insert_chars(&(arr[1]), c, mx_strlen(arr[1]));
    return arr;
}

char **split_echo(char *str_input, int check) {
    char **arr = NULL;
    char **e_f = NULL;
    int arr_el = 0;
    char *str_test = mx_strtrim(str_input);
    free(str_input);
    str_input = mx_strdup(str_test);

    if (check == 2)
        arr = insertin_arr('\'', str_input);
    else
        arr = insertin_arr('\"', str_input);

    e_f = mx_strsplit(arr[0], ' ');
    arr_el = mx_count_arr_el(e_f);

    for (int i = 1; arr[i] != NULL; i++) {
        e_f = (char **) realloc(e_f, sizeof(char *) * (arr_el + 2));
        e_f[arr_el++] = mx_strdup(arr[i]);
        e_f[arr_el] = NULL;
    }
    mx_del_strarr(&arr);
    return e_f;
}
