#include "ush.h"

void insert_char(t_input *input, char sym, int index) {
    char temp;
    int len = mx_strlen(input->command);

    input->command = realloc(input->command, len + 2);
    for (; index < len + 1; index++) {
        temp = input->command[index];
        input->command[index] = sym;
        sym = temp;
    }
    input->command[index] = '\0';
}
