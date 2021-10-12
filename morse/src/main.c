#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./morse \"str\"\n");
        exit(1);  
    }  
    char* str = argv[1];
    char* segment = NULL;
    int scount = 0;
    int strl = mx_strlen(str);

    for (int k = 0; k < strl; k++){
        if (str[k] != ' ' && str[k] != '.' && str[k] != '-') {
            mx_printerr("usage: ./morse \"str\"\n");
            exit(1);
        }
    }

    if (!str || strl == 0) {
        mx_printerr("usage: ./morse \"str\"\n");
        exit(1);
    }

    while (*str++ != '\0') {
        scount++;
        strl--;
		if (*str == ' ') 
            break;
	}

    if (*(str + 1) == ' ') {
        while (*str++ != '\0' && scount != 5) {
            strl--;
            if (*str != ' ')   
                break;
            scount++;
        }
    }

    segment = mx_strndup(str - scount, scount);
    mx_printascii(segment);

//    printf ("segment =%s ___ scount=%i ____ strl=%i\n ", segment, scount, strl);

    while(segment && (strl > 0)) {
        mx_strdel(&segment);
        scount = 0;
        while (*str++ != '\0') {
            strl--;
		    if (*str == ' ')   
                break;
            scount++;
        }

        if (scount > 0) {
            segment = mx_strndup(str - scount, scount);
        }
        
        if (scount == 0) {
            if (*(str + 1) == ' ') {
                while (*str++ != '\0' && scount != 4) {
                    strl--;
		            if (*str != ' ')   
                        break;
                    scount++;
                }
            segment = mx_strndup(str - scount, scount);
            mx_printchar(' ');
            }
            else if (*str != ' ') {
            segment = mx_strndup(str, 1);
            }
            else {
                mx_printerr("usage: ./morse \"str\"\n");
                mx_strdel(&segment);
                exit(1);
            }  
        }
    mx_printascii(segment);
	}

    mx_strdel(&segment);
    mx_printchar('\n');
    return 0;
}
