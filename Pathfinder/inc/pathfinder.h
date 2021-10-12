#pragma once
#include <stdio.h>
#include <fcntl.h>

#include "libmx.h"

#define INF 2147483647

//Error numbers
enum {
    INVLD_CLARG = 1,
    FILE_NEXIST,
    FILE_EMPTY,
    INVLD_LINE1,
    INVLD_LINEX,
    INVLD_NUM_ISLDS,
    DUP_BRDGS,
    BRDGSL_BIG
};

typedef struct s_finder {
    int num;
    char **islands;
    int **matrix;
    int **primary;
}              t_finder;


typedef struct s_out {
    int length;
    int *route;
}              t_out;

void mx_validation(int argc, char *argv);
bool mx_is_novalid_number(char *s);
bool mx_is_novalid_alpha(char *s);
bool mx_check_dup(char **arr, int iarr);
t_finder *mx_matrix(char *filename);
void mx_clean(t_finder *path);
void mx_print_path(t_finder *path);
