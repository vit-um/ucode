#include "ush.h"

static int get_flag_index(const char *str, const char *sub);
static char *push_back_queue(char *logic, char *temp, t_queue **arr_queue);
static void insert_queue(char *arr, t_queue **arr_queue);

t_queue **parsing(char *command) {
    char **arr = mx_strsplit(command, ';');
    int size = mx_count_arr_el(arr);
    t_queue **queue = (t_queue **)malloc(sizeof(t_queue *) * (size + 1));

    for (int i = 0; arr[i]; i++) {
        queue[i] = NULL;
        insert_queue(arr[i], &queue[i]);
    }
    mx_del_strarr(&arr);
    queue[size] = NULL;
    return queue;
}

static int get_flag_index(const char *str, const char *sub) {
    int len_str = 0;
    int len_sub = 0;

    if (!str || !sub) {
        return -2;
    }
    len_str = mx_strlen(str);
    len_sub = mx_strlen(sub);
    for (int i = 0; i <= len_str - len_sub; i++) {
        if (!mx_strncmp(&str[i], sub, len_sub)) {
            return i;
        }
    }

    return INT_MAX;
}

static char *push_back_queue(char *logic, char *temp, t_queue **arr_queue) {
    char **arr_str = NULL;

    arr_str = util_strsplit_one(temp, logic);
    q_push_back(arr_queue, arr_str[0], logic[0]);
    mx_strdel(&temp);
    temp = mx_strdup(arr_str[1]);
    mx_del_strarr(&arr_str);
    return temp;
}

static void insert_queue(char *arr, t_queue **arr_queue) {
    int count = q_count_operation(arr);
    int and = 0;
    int or = 0;
    char *temp = mx_strdup(arr);

    for (int j = 0; j <= count; j++) {
        and = get_flag_index(temp, "&&");
        or = get_flag_index(temp, "||");
        if (and >= 0 && and < or) {
            temp = push_back_queue("&&", temp, arr_queue);
        } else if (or >= 0 && or < and ) {
            temp = push_back_queue("||", temp, arr_queue);
        } else if (and == INT_MAX && or == INT_MAX) {
            if (temp == NULL) {
                temp = mx_strdup(arr);
            }
            q_push_back(arr_queue, temp, '0');
        }
    }
    mx_strdel(&temp);
}
