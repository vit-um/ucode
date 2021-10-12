#include "pathfinder.h"

static void del_int_arr(int **arr, t_finder *path);


void mx_clean(t_finder *path) {
    for (int i = 0; i < path->num; ++i)
        mx_strdel(&path->islands[i]);
    free(path->islands);
    del_int_arr(path->matrix, path);
    del_int_arr(path->primary, path);
    free(path);
}

static void del_int_arr(int **arr, t_finder *path) {
    if (arr) {
        for (int i = 0; i < path->num; i++)
            free(arr[i]);
        free(arr);
    }
}
