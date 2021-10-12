#include "ush.h"

static void right_arrow (t_input *input);
static void left_arrow (t_input *input);
static void up_arrow(t_input *input, t_ush *ush);
static void down_arrow(t_input *input, t_ush *ush);

void input_non_ascii(t_input *input, t_ush *ush) {
    if (input->input_ch == 27) {
        if (input->input_ch_arr[2] == RIGHT_ARROW) {
            right_arrow(input);
        } else if (input->input_ch_arr[2] == LEFT_ARROW) {
            left_arrow(input);
        } else if (input->input_ch_arr[2] == UP_ARROW ) {
            up_arrow(input, ush);
        } else if (input->input_ch_arr[2] == DOWN_ARROW) {
            down_arrow(input, ush);
        }
    }
}

static void right_arrow (t_input *input) {
    if (input->coursor_position < input->len) {
        mx_printstr(MV_RIGHT);
        input->coursor_position++;
    }
}

static void left_arrow (t_input *input) {
    if (input->coursor_position > 0) {
        mx_printstr(MV_LEFT);
        input->coursor_position--;
    }
}

static void up_arrow(t_input *input, t_ush *ush) {
    if (ush->history->prev != NULL && strlen(ush->history->prev->data) > 0) {
        ush->history = ush->history->prev;
        mx_strdel(&input->command);
        clear_str();
        print_prompt(0, ush);
        if (ush->history->data != NULL) {
            input->command = mx_strdup(ush->history->data);
            mx_printstr(input->command);
        }
        input->coursor_position = mx_strlen(input->command);
        input->len = mx_strlen(input->command);
    }
}

static void down_arrow(t_input *input, t_ush *ush) {
    if (ush->history->next != NULL) {
        ush->history = ush->history->next;
        mx_strdel(&input->command);
        clear_str();
        print_prompt(0, ush);
        if (ush->history->data != NULL) {
            input->command = mx_strdup(ush->history->data);
            mx_printstr(input->command);
        }
        input->coursor_position = mx_strlen(input->command);
        input->len = mx_strlen(input->command);
    }
}
