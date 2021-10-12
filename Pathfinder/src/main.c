#include "pathfinder.h"

int main(int argc, char *argv[]) {
    t_finder *path = NULL;
    mx_validation(argc, argv[1]);
    path = mx_matrix(argv[1]);
    mx_print_path(path);
    mx_clean(path);
    return 0;
}
