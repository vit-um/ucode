#include "ush.h"

void delete_char(t_input *input, int index) {
    int len =  mx_strlen(input->command);

    input->command = realloc(input->command, len);
    for (; index < len - 1; index++) {
        input->command[index] = input->command[index + 1];
    }
    input->command[index] = '\0';
}
