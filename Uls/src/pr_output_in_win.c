#include "uls.h"

static void one_line_output(char **array, t_objsize sps, bool *fl);
static void multiple_line_output(char **array, t_objsize sps, struct winsize window);


void pr_output_in_win(char **array, t_objsize sps, bool *fl) {
    struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);

    if (sps.amt == 0) {
        return;
    }

    if (((sps.name + 2) * sps.amt -2) <= window.ws_col || isatty(1) == 0 || fl[one]) {
        one_line_output(array, sps, fl);
    }
    else {
        multiple_line_output(array, sps, window);
    }
}

static void one_line_output(char **array, t_objsize sps, bool *fl) {
    for (int i = 0; i < sps.amt; i++){
        mx_printstr(array[i]);
        if (i != sps.amt - 1 && isatty(1) && !fl[one]) 
            mx_printstr("  ");
        else
            mx_printchar('\n');
    }
}

static void multiple_line_output(char **array, t_objsize sps, struct winsize window) {
    int len_of_cell = window.ws_col / (sps.name + 2);
    int hight = sps.amt / len_of_cell;

    if (sps.amt % len_of_cell != 0) {
        hight++;
    }

    for (int ii = 0; ii < hight; ii++) {
        for (int j = ii; j < sps.amt; j += hight) {
            mx_printstr(array[j]);
            int cc = (sps.name + 2) - mx_strlen(array[j]);
            for (int hh = 0; hh < cc; hh++) {
                mx_printchar(' ');
            }
        }
        mx_printchar('\n');
    }
}
