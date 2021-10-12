#ifndef USH_H
#define USH_H

#define _DEFAULT_SOURCE  //for work in Ubuntu man GETCWD(3)

#include "libmx.h"
#include <limits.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <termcap.h>
#include <time.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "struct.h"

//Main functions
t_ush* create_ush(char **argv);
char *get_env(char *var);
char *command_in_path(char *command, char *str_path);

//Set functions
void set_shell(void);
void set_canonic(struct termios savetty);
void set_non_canonic(struct termios *savetty);

//Print function
void print_prompt(int flag, t_ush *ush);
void print_n();
void print_na();


//Input functions
char *input_ascii(t_input *input, t_ush *ush);
char *input_process(t_ush *ush);
void input_non_ascii(t_input *input, t_ush *ush);
char *get_command(t_input *input, t_ush *ush);
char *add_history(t_input *input, int *flag, t_ush *ush, char *temp);
void sort_history(t_ush *ush, char *temp);
t_dbl_list *addelem_history(t_dbl_list *history);
void free_step_history(t_input *input, char *temp);

//Coursor functions
void clear_str(void);
void insert_char(t_input *input, char sym, int index);
void delete_char(t_input *input, int index);
void move_coursor(int num_of_moves, char *side);

//Parsing and queue linked list functions
t_queue **parsing(char *command);
t_queue *create_queue(char *data, char operation);
void q_push_back(t_queue **queue, char *data, char operation);
void q_pop_front(t_queue **queue);
int q_count_operation(const char *arr);

//Executing functions
int execute_queue(t_queue **queue, t_ush *ush);
int execute_command(t_ush *ush, char *str_input, int flag_redir, char **str_red);
char **check_expansion(char *str_input, int ret_val);
void tilde_check(char **input);
int check_echo(char **n);
char **split_echo(char *str_input, int check);

void write_to_pipe(char *str, int *fd);
void read_from_pipe(char *str, int len, int *fd);
t_redirect *create_redirect(int flag_redir);
void child_redirect(t_redirect *redirect);
void parent_redirect(t_redirect *redirect, int *ret);
void child_execute(int *ret, char **input, t_redirect *red, t_ush *ush);

//Builtin functions
int is_builtin(char *command);
int ush_exit(char **args, int *exit_status);
int ush_cd(char **args, t_ush *ush);
int ush_export(char **args);
int ush_unset(char **args);
int ush_pwd(char **args, t_ush *ush);
int ush_env(char **args, t_ush *ush);
int ush_echo(char **args);
int ush_which(char **input);

//Com sub
void mx_com_sub(char **data, t_ush *ush);
int mx_com_sub_space(char **data, t_com_sub *c, t_ush *ush, int i);
int mx_com_sub_back(char **data, t_com_sub *c, t_ush *ush, int i);
void mx_com_sub_free(t_com_sub *com_sub);
t_com_sub* mx_create_com_sub();

//freemem functions
void free_ush(t_ush *ush);
void free_queue(t_queue **queue);
void free_execute(t_redirect *redirect, char **input);
void free_jobs(t_ush *ush);
void child_free(char *command_p, int *fd, int ret_val);
void free_env(t_env *env);

//utils
char **util_strsplit_one(const char *s, char *logic);
char *util_replace_operator(char *s);
char *util_strcpy(char *dst, const char *src, int first, int end);
char *util_strdup(const char *data, int first, int end);
bool util_is_str(char *data);

int find_flag(char *flags, char *arg);              //cd 
void setenv_ush(char *arg, t_ush *ush);             //cd 
int check_symlink(char **arg, int flag, int link);  //cd 
int make_path(char *path, t_ush *ush, int flag);    //cd 
int file_exists(char *path);                        //cd

t_env *parse_env_args(char **args, t_ush *ush);     //env
void env_error(t_env *env, char **args, int i);     //env
int execute_env_flags(t_env *env, char **args, 
                        int i, int *env_index);     //env
char *parse_echo(char **args, int *flag_n);         //echo  

#endif
