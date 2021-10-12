#include "ush.h"

static t_input *init_input();
static char *inside_cycle(t_input *input, int *flag, t_ush *ush, char *str);

char *input_process(t_ush *ush) {
    char *str = NULL;
    struct termios savetty;
    size_t bufsize = 32;
    char *buffer = NULL;
    char *temp = NULL;
    int flag = 0;
    t_input *input = init_input();

    if (!isatty(0)) {
        getline(&buffer, &bufsize, stdin);
        str = mx_strndup(buffer, mx_strlen(buffer) - 1);
        ush->exit_non_term = 1;
        mx_strdel(&buffer);
    }
    else {
        print_prompt(1, ush);
        set_non_canonic(&savetty);
        input->savetty = savetty;
        input->term_width = tgetnum("co"); //nums cols
        while (input->input_ch != '\r' && input->ctrl_c != 1 && input->term_width != 0) {
            str = inside_cycle(input, &flag, ush, str);
            if (ush->exit_status != CONTINUE) {
                break;
            }
            if (input->len > 0) {
                temp = add_history(input, &flag, ush, temp);
            }
        }
        if (ush->history->next != NULL) {
            sort_history(ush, temp);
        }
        free_step_history(input, temp);
        mx_printstr("\n");
        set_canonic(savetty);
    }
    if (ush->history->data != NULL) {
        ush->history = addelem_history(ush->history); 
    }   
    return str;
}


static t_input *init_input() {
    t_input *input = (t_input *) malloc(sizeof (t_input));

    input->len = 0;
    input->command = mx_strnew(1);//?
    input->ctrl_c = 0;
    input->coursor_position = 0;
    input->input_ch = '\0';
    input->input_ch_arr = (char *)&input->input_ch;
    return input;
}

static char *inside_cycle(t_input *input, int *flag, t_ush *ush, char *str) {
    int j = 0;
    int i = read(STDIN_FILENO, &input->input_ch, 4);

    if (i < 0) {
        exit(errno);
    }
    while (j < i) {
        input->input_ch = input->input_ch_arr[j];
        if (input->input_ch <= 127 && input->input_ch != 27) {
            str = input_ascii(input, ush);
            if (ush->exit_status != CONTINUE) 
                break;
        }
        else {
            *flag = 0;
            input_non_ascii(input, ush);
        }
        if (input->input_ch < 32)
            break;
        j++;
    }
    return str;
}
