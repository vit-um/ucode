#include "pathfinder.h"

void mx_del_data(t_list *head);
bool mx_unical_island (t_list *list, char *str);


void mx_validation(int argc, char *argv) {
    int fd, k, i, iarr;
    int num, br, isl;
    char *fstr, *temp, *str1, *str2, *str3;
    long long int sum = 0;

    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(INVLD_CLARG);
    }
 
    if ((fd = open(argv,O_RDONLY)) < 0){
        mx_printerr("error: file ");
        mx_printerr(argv);
        mx_printerr(" does not exist\n");
        close(fd);
        exit(FILE_NEXIST);
    }

    fstr = NULL; //mx_strnew(0);
    if (mx_read_line(&fstr, '\n', fd) == -1) {
        mx_strdel(&fstr);
        close(fd);
        mx_printerr("error: file ");
        mx_printerr(argv);
        mx_printerr(" is empty\n");
        exit(FILE_EMPTY);
    }

    if ((num = mx_atoi(fstr)) <= 0 || mx_is_novalid_number(fstr)) {
        mx_strdel(&fstr);
        close(fd);
        mx_printerr("error: line 1 is not valid\n");
        exit(INVLD_LINE1);
    }
  
    br = 0;
    t_list *islands = NULL;
    while (mx_read_line(&fstr, '\n', fd) > 0) {
        temp = fstr;
        br++;
        str1 = mx_strndup(temp, (k = mx_get_char_index(temp, '-')));
        temp += k + 1;
        str2 = mx_strndup(temp, (k = mx_get_char_index(temp,',')));
        temp = NULL;
        if (mx_unical_island(islands, str1))
            mx_push_back(&islands, mx_strdup(str1));
    
        if (mx_unical_island(islands, str2)) 
            mx_push_back(&islands, mx_strdup(str2));

        mx_strdel(&str1);
        mx_strdel(&str2);
    }
    isl = mx_list_size(islands);
    mx_del_data(islands);
    mx_clear_list(&islands);
    mx_strdel(&fstr);
    close(fd);

    fd = open(argv,O_RDONLY);
    mx_read_line(&fstr, '\n', fd); 
    
    char *arr[br * 2];
    iarr = 0;
    i = 0;
    while (mx_read_line(&fstr, '\n', fd) > 0) {
        temp = fstr;
        str1 = mx_strndup(temp, (k = mx_get_char_index(temp, '-')));
        temp += k + 1;
        str2 = mx_strndup(temp, (k = mx_get_char_index(temp,',')));
        temp += k + 1;
        str3 = mx_strndup(temp, mx_strlen(temp));
        i++;
        if (mx_strlen(str1) < 1 || mx_strlen(str2) < 1 || mx_strlen(str3) < 1 ||
        mx_strcmp(str1,str2) == 0 ||
        mx_is_novalid_number(str3) ||
        mx_is_novalid_alpha(str1) || mx_is_novalid_alpha(str2) || 
        (mx_strlen(temp) > 0 && mx_strlen(str1) == 0)) {
            mx_strdel(&str1);
            mx_strdel(&str2);
            mx_strdel(&str3);
            mx_strdel(&fstr);
            for (int j = iarr - 1; j >= 0; --j)
                mx_strdel(&arr[j]);
            close(fd);
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            exit(INVLD_LINEX);
        }

        sum += mx_atoi(str3);

        arr[iarr] = mx_strjoin(str2,str1);
        iarr++;
        arr[iarr] = mx_strjoin(str1,str2);
        iarr++;

        if (mx_check_dup(arr, iarr - 2)) {
            mx_strdel(&str1);
            mx_strdel(&str2);
            mx_strdel(&str3);
            mx_strdel(&fstr);
            mx_printerr("error: duplicate bridges\n");
            exit(DUP_BRDGS);
        }

        mx_strdel(&str1);
        mx_strdel(&str2);
        mx_strdel(&str3);
    }

    for (int j = iarr - 1; j >= 0; --j)
        mx_strdel(&arr[j]);

    mx_strdel(&fstr);
    close(fd);

    if (isl != num) {
        mx_printerr("error: invalid number of islands\n");
        exit(INVLD_NUM_ISLDS);
    }

    if (sum > 2147483647) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(BRDGSL_BIG);
    }
}

void mx_del_data(t_list *head) {
    if (head != NULL) {
        t_list *current = head;
        while (current != NULL) {
            free(current->data);
            current = current->next;
        }
    }
}

bool mx_unical_island (t_list *list, char *str) {
    if (list) {
        t_list *tmp = list; 
        char *strtemp = str;
        while (tmp){
            if (mx_strcmp(tmp->data, strtemp) == 0)
                return false;
            tmp = tmp->next;
        }
        return true;
    }
    return true;
}
