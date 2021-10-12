#include "pathfinder.h"

static void shortest_route(t_finder *path, t_out *run);
static void print_route(t_finder *path, t_out *run);
static void print_distance(t_finder *path, t_out *run);


void mx_print_path(t_finder *path) {
    t_out *run = (t_out *)malloc(sizeof(t_out));

    run->route = (int *)malloc(sizeof(int) * (path->num + 1));
    for (int i = 0; i < path->num; i++) {
        for (int j = i + 1; j < path->num; j++) {
            run->length = 1;
            run->route[0] = j;
            run->route[1] = i;
            shortest_route(path, run);
        }
    }
    free(run->route);
    free(run);
}

static void shortest_route(t_finder *path, t_out *run) {
    int i = run->route[run->length];
    int j = run->route[0];

    for (int k = 0; k < path->num; k++) {
        if (k > 0 && run->route[run->length] == run->route[0])
            break;
        if (k != run->route[run->length] 
        && (path->primary[i][k] == path->matrix[i][j] - path->matrix[k][j]))  {
        run->length++;
        run->route[run->length] = k;
        shortest_route(path, run);
        run->length--;
        }
    }
    if (run->route[run->length] != run->route[0])
        return;
    print_route(path, run);
    print_distance(path, run);
}

static void print_route(t_finder *path, t_out *run) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(path->islands[run->route[1]]);
    mx_printstr(" -> ");
    mx_printstr(path->islands[run->route[0]]);
    mx_printstr("\n");
    mx_printstr("Route: ");
        for (int i = 1; i < run->length + 1;) {
            mx_printstr(path->islands[run->route[i]]);
            if (++i < run->length + 1)
                mx_printstr(" -> ");
        }
    mx_printstr("\n");
}

static void print_distance(t_finder *path, t_out *run) {
    int sum = 0;

    mx_printstr("Distance: ");
    for (int i = 1; i < run->length; i++) {
        mx_printint(path->primary[run->route[i]][run->route[i + 1]]);
        sum += path->primary[run->route[i]][run->route[i + 1]];
        if (i < run->length - 1)
            mx_printstr(" + ");
        else if (i > 1) {
            mx_printstr(" = ");
            mx_printint(sum);
        }
    }
    mx_printstr("\n");
    mx_printstr("========================================\n");
}
