#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    int i = 0;
    int begin = 0;
    int size = mx_count_words(s, c);
    char *tmp = mx_strtrim_char(s, c);
    char **result = (char**) malloc(sizeof(char*) * (size + 1));

    if (tmp)
        for (int k = 0; k < size; k++) {
            while (tmp[i] && tmp[i] == c) 
                i++;
            begin = i;  
            while (tmp[i] && tmp[i] != c) 
                i++;   
            result[k] = mx_strndup(&tmp[begin], i - begin);
        }
    result[size] = NULL;
    mx_strdel(&tmp);
    return result;
}



// static inline int get_length(const char *s, char c) {
//     int len = 0;

//     for (; s[len] && s[len] != c; ++len);
//     return len;
// }

// char **mx_strsplit(const char *s, char c) {
//     int words = mx_count_words(s, c);
//     char **result = s ? (char **)malloc(sizeof(char *) * (words + 1)) : NULL;

//     if (s && result) {
//         int j = 0;
//         int len;

//         for (int i = 0; s[j]; ++j) {
//             if (s[j] != c) {
//                 len = get_length(s + j, c);
//                 result[i++] = mx_strndup(s + j, len);
//                 j += len;
//             }
//         }
//         result[words] = NULL;
//     }
//     return result;
// }
