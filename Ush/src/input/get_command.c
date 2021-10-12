#include "ush.h"

static void case_backspace(t_input *input, t_ush *ush);
static void one_line_input(t_input *input, t_ush *ush);
static void case_default(t_input *input, t_ush *ush);

char *get_command(t_input *input, t_ush *ush) {
    char *str = NULL;

    switch (input->input_ch) {
        case BACKSPACE:
            if (input->coursor_position > 0)
                case_backspace(input, ush);
            break;
        case ENTER:
            str = mx_strtrim(input->command);
            break;
        case TAB:
            break;
        default:
            case_default(input, ush);
            break;
    }
    return str;
}

static void case_backspace(t_input *input, t_ush *ush) {
    input->coursor_position--;
    input->len--;
    clear_str();
    if (input->term_width > input->len + 8) {
        print_prompt(0, ush);
    }
    delete_char(input, input->coursor_position);
    if (input->term_width > input->len + 8) {
        mx_printstr(input->command);
        if (input->coursor_position != input->len) {
            move_coursor(input->len - input->coursor_position, "D");
        }
    }
}


static void one_line_input(t_input *input, t_ush *ush) {
    if (input->coursor_position != input->len) {
        insert_char(input, input->input_ch, input->coursor_position);
    } 
    else if (input->command != NULL) {
        input->command = realloc(input->command, input->len + 2);
        input->command[input->len] = (char) input->input_ch;
        input->command[input->len + 1] = '\0'; 
    } 
    else {
        input->command = mx_strnew(1000);//?
        input->command[input->len] = (char) input->input_ch;
    }
    input->len++;
    input->coursor_position++;
    if (input->coursor_position != input->len) {
        clear_str();
        print_prompt(0, ush);
        mx_printstr(input->command);
        move_coursor(input->len - input->coursor_position, "D");
    } 
    else 
        mx_printchar((char) input->input_ch);
}


static void case_default(t_input *input, t_ush *ush) {
    if (input->len + 8 > input->term_width) {
        mx_printerr("\nush: input string is too long");
        input->term_width = 0;
    } else {
        one_line_input(input, ush);
    }
}
