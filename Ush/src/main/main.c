#include "ush.h"

static void executing(t_ush *ush) {
    t_queue **queue = NULL;

    if (ush->command != NULL && strlen(ush->command) > 0) {
        queue = parsing(ush->command);                      //mainly sorting the order of certain commands execution
        ush->return_value = execute_queue(queue, ush);      //executing commands
        free_queue(queue);                                  //freeing mem after commands execution
    }
    mx_strdel(&ush->command);
}

int main(int argc, char **argv){
    if (argc > 1) {
        fprintf(stderr, "ush: can't open input file: %s\n", argv[1]);
        exit(127); // command not found
    }
    if (tgetent(NULL, "xterm-256color") < 0) {
        fprintf(stderr, "ush: Could not access the termcap data base.\n");
        exit(errno);
    }

    int ret;
    t_ush *ush = NULL;

    ush = create_ush(argv);
    set_shell();

    while (true) {
        ush->command = input_process(ush);
        executing(ush);
        if (ush->exit_status != CONTINUE || ush->exit_non_term == 1) {
            break;
        }
    }
    ret = ush->return_value;
    free_ush(ush);
    return ret; 
}
