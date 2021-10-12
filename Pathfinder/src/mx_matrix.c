#include "pathfinder.h"

bool mx_check_unical(char **arr, int nn, char *str);

t_finder *mx_matrix(char *filename) {
    int fd, n = 0;
    char *fstr = NULL;
    char *temp, *str1, *str2, *str3;
    t_finder *path = (t_finder *)malloc(sizeof(t_finder));

    fd = open(filename,O_RDONLY);
    mx_read_line(&fstr, '\n', fd);
    path->num = mx_atoi(fstr);

/* Initialisation new matrix */
    path->islands = (char**)malloc(sizeof(char*) * path->num);
    path->matrix = (int **)malloc(sizeof(int *) * path->num);
    path->primary = (int **)malloc(sizeof(int *) * path->num);

    for (int i = 0; i < path->num; i++){
        path->matrix[i] = (int *)malloc(sizeof(int *) * path->num);
        path->primary[i] = (int *)malloc(sizeof(int *) * path->num);
        for (int j = 0; j < path->num; j++) 
                path->matrix[i][j] = i == j ? 0 : INF;
    }

/* Copy from file */
    while (mx_read_line(&fstr, '\n', fd) > 0) {
        int k, i, j;
        temp = fstr;
        str1 = mx_strndup(temp, (k = mx_get_char_index(temp, '-')));
        temp += k + 1;
        str2 = mx_strndup(temp, (k = mx_get_char_index(temp,',')));
        temp += k + 1;
        str3 = mx_strndup(temp, mx_strlen(temp));

        if (n == 0)
            path->islands[0] = mx_strdup(str1);
        else{
            if (mx_check_unical(path->islands, n, str1)) {
                ++n;
                path->islands[n] = mx_strdup(str1);
            }
        }

        if (mx_check_unical(path->islands, n, str2)) {
            ++n;
            path->islands[n] = mx_strdup(str2);
        }

        for (k = 0; k <= n; k++){
            if (mx_strcmp(path->islands[k], str1)  == 0)
                i = k;
            if (mx_strcmp(path->islands[k], str2)  == 0)
                j = k;
        }

        path->matrix[i][j] = mx_atoi(str3);
        path->matrix[j][i] = mx_atoi(str3);

        mx_strdel(&str1);
        mx_strdel(&str2);
        mx_strdel(&str3);
    }

    mx_strdel(&fstr);
    close(fd);

/* Save primary state */
   for (int k = 0; k < path->num; k++) 
        for (int i = k; i < path->num; i++) {
            path->primary[k][i] = path->matrix[k][i];
            path->primary[i][k] = path->matrix[i][k];
        }

/* Floyd algorithm */
    for (int k = 0; k < path->num; k++) 
        for (int i = 0; i < path->num; i++) 
            for (int j = i + 1; j < path->num; j++) 
                if (path->matrix[i][k] != INF &&  path->matrix[k][j] != INF 
                && path->matrix[i][k] + path->matrix[k][j] < path->matrix[i][j]) { 
                    path->matrix[i][j] = path->matrix[i][k] + path->matrix[k][j];
                    path->matrix[j][i] = path->matrix[i][k] + path->matrix[k][j];
                } 
    return path;
}    


bool mx_check_unical(char **arr, int nn, char *str) {
    for (int i = 0; i <= nn; i++)
        if(mx_strcmp(arr[i], str) == 0)
            return false;
    return true;
}
