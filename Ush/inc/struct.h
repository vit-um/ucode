#pragma once

//keys
#define RIGHT_ARROW 67
#define LEFT_ARROW  68
#define UP_ARROW    65
#define DOWN_ARROW  66
#define ENTER       13
#define BACKSPACE   127
#define TAB         9

//colors
#define RED         "\033[0;31;1m"
#define GREEN       "\033[0;32;1m"
#define DEFAULT     "\033[0m"

//moves
#define MV_RIGHT    "\033[C"
#define MV_LEFT     "\033[D"

//commands
#define CD          1
#define PWD         2
#define ENV         3
#define EXPORT      5
#define UNSET       6
#define EXIT        7
#define WHICH       8
#define SH_ECHO     9
#define PATH_PWD   10
#define PATH_ECHO  11

//statuses
#define CONTINUE -1
#define STOP      0

//error messages
#define MX_ENV_US "env: option requires an argument -- %c\nusage: env [-i] \
[-P utilpath] [-u name]\n           \
[name=value ...] [utility [argument ...]]\n"
#define MX_ENV_IL "env: illegal option -- %c\nusage: env [-iv] [-P utilpath] \
[-u name]\n           [name=value ...] [utility [argument ...]]\n"
#define MX_PWD_ERR "ush: pwd: -%c: invalid option\npwd: usage: pwd [-LP]\n"
#define MX_WHICH_US "which: illegal option -- \
%c\nusage: which [-as] program ...\n"

//Struct
typedef struct s_queue t_queue;
typedef struct s_input t_input;
typedef struct s_ush t_ush;
typedef struct s_redirect t_redirect;
typedef struct s_env t_env;
typedef struct s_dbl_list t_dbl_list;
typedef struct s_pid t_pid;
typedef struct s_com_sub t_com_sub;

struct s_ush {
    char *command;
    t_dbl_list *history;
    wchar_t emodji_num;
    char *ush_path;
    int exit_status;
    t_pid *pids;
    char *str_input;
    int exit_non_term;
    int return_value;
    int curr_pid;
    char *pwd_l;
    char *pwd;
};

struct s_com_sub {
    int back_first;
    int back_first_index;
    int back_end;
    int back_end_index;
    int space;
    int space_first_index;
    int space_end_index;
    char *temp_str;
    char *temp_data;
    char *cout_execute;
    char *temp_join;
    int status;
};

struct s_queue {
    char *data;
    char operator;
    struct s_queue *next;
};

struct s_input {
    int ctrl_c;
    unsigned char input_ch;
    char *input_ch_arr;
    int len;
    int term_width;
    int coursor_position;
    char *command;
    struct termios savetty;
};

struct  s_env {
    int flag;
    char *comm;
    char *comm_args;
    char **env_var;
};

struct s_dbl_list {
    t_dbl_list *next;
    t_dbl_list *prev;
    char *data;
};

struct s_pid {
    int num;
    int index;
    char *str;
    struct s_pid *next;
    struct s_pid *prev;
};
struct s_redirect {
    int fd_return[2];
    int fd_stdout[2];
    int fd_stderr[2];
    int flag;
    char *_stdout;
    char *_stderr;
};
