#include "libmx.h"

// Other option
// char *mx_strjoin(char const *s1, char const *s2) {
//     if (s1 && s2) {
//         char *str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));

//         return str ? mx_strcat(mx_strcat(str, s1), s2) : NULL;
//     }
//     return (s1 || s2) ? (s1 ? mx_strdup(s1) : mx_strdup(s2)) : NULL;
// }

// My old function
char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 && s2){
            char* tmp = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
            tmp =  mx_strcpy(tmp,s1);
            return tmp ? mx_strcat(tmp,s2) : NULL;
    }
    else if (s1 == NULL && s2 != NULL)
            return mx_strdup(s2);
    else if (s2 == NULL && s1 != NULL)
            return mx_strdup(s1);
    else
        return NULL;
}
