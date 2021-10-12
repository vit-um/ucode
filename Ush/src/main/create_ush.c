#include "ush.h"

static char *find_ush_path(char **commands); 
static t_dbl_list* lst_create();


t_ush* create_ush(char **argv) {
    t_ush *ush = (t_ush *)malloc(sizeof(t_ush));

    ush->command = NULL;
    ush->history = NULL;
    ush->emodji_num = 128512;
    ush->exit_status = CONTINUE;
    ush->exit_non_term = 0;
    ush->pids = NULL;
    ush->str_input = NULL;
    ush->ush_path = find_ush_path(argv);
    ush->history = lst_create();
    ush->pwd_l = get_env("PWD");
    return ush;
}

static char *find_ush_path(char **commands) {
    char *pwd = get_env("PWD");
    char *ush_path = NULL;

    if (mx_strstr(commands[0], "./")) {
        ush_path = mx_replace_substr(commands[0], ".", pwd);
    } else {
        ush_path = mx_strdup(commands[0]);
    }
    mx_strdel(&pwd);
    return ush_path;
}

static t_dbl_list* lst_create() {
    t_dbl_list *lst = (t_dbl_list*) malloc(sizeof (t_dbl_list));

    lst->data = NULL;
    lst->next = NULL;
    lst->prev = NULL;
    return lst;
}
