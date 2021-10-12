#include "ush.h"

char *input_ascii(t_input *input, t_ush *ush) {
    char *str = NULL;

    if (input->input_ch != '\r' && input->input_ch != '\t' 
    && input->input_ch < 32) {
        if (input->input_ch == 4) {            //^D
            set_canonic(input->savetty);
            ush->exit_status = STOP;
        } 
        else if (input->input_ch == 3) {     //^C
            input->ctrl_c = 1;
        }
    } 
    else {
        str = get_command(input, ush);
    }
    return str;
}
