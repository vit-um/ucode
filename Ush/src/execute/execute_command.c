#include "ush.h"

static void fill_jobs(pid_t pid, t_ush *ush);
static int parent_execute(char **input, t_ush *ush, pid_t pid);
static void check_for_redir(int *ret, int *fd, t_redirect *red, t_ush *ush);

int execute_command(t_ush *ush, char *str_input, int flag_redir, char **str_red) {
    pid_t pid;
    int ret = 0;
    char **input = check_expansion(str_input, ush->return_value);
    t_redirect *redirect = create_redirect(flag_redir);
    ush->str_input = str_input;
    pid = fork();
    if (pid != 0) {
        ret = parent_execute(input, ush, pid);
        check_for_redir(&ret, redirect->fd_return, redirect, ush);
    }
    else {
        child_execute(&ret, input, redirect, ush);
    }
    if (redirect->_stdout != NULL && flag_redir == 1) {
        if (redirect->_stdout[mx_strlen(redirect->_stdout) - 1] == '\n') {
            redirect->_stdout[mx_strlen(redirect->_stdout) - 1] = '\0';
        }
        *str_red = mx_strdup(redirect->_stdout);
    }
    free_execute(redirect, input);
    return ret;
}

static int parent_execute(char **input, t_ush *ush, pid_t pid) {
    char *command_p = command_in_path(input[0], get_env("PATH"));
    int command = is_builtin(command_p);
    int ret_val = 0;
    ush->curr_pid = pid;

    if (command == CD) {
        ret_val = ush_cd(input, ush);
    }
    else if (command == EXPORT) {
        ret_val = ush_export(input);
    }
    else if (command == UNSET) {
        ret_val = ush_unset(input);
    }
    else if (command == EXIT) {
        ret_val = ush_exit(input, &ush->exit_status);
    }
    mx_strdel(&command_p);
    return ret_val;
}

static void check_for_redir(int *ret, int *fd, t_redirect *red, t_ush *ush) {
    char *ret_str = mx_strnew(1);
    int status = 0;
    free_jobs(ush);
    waitpid(ush->curr_pid, &status, WUNTRACED);
    if(!WIFSTOPPED(status)) {
        read_from_pipe(ret_str, 1, fd);
        parent_redirect(red, ret);
    }
    if(WIFSTOPPED(status)) {
        *ret = 146;
        printf("\nush: suspended  %s\n", ush->str_input);
        fill_jobs(ush->curr_pid, ush);
    }
    else if (mx_atoi(ret_str) == 1 || *ret == 1) {
        *ret = 1;
    }
    mx_strdel(&ret_str);
}

static void fill_jobs(pid_t pid, t_ush *ush) {
    t_pid *temp = NULL;
    if (ush->pids != NULL) {
        temp = ush->pids;
        ush->pids = ush->pids->next;
    }
    ush->pids = (t_pid *) malloc(sizeof (t_pid));
    ush->pids->num = pid;
    ush->pids->index++;
    ush->pids->str = mx_strdup(ush->str_input);
    ush->pids->prev = temp;
    ush->pids->next = NULL;
}
