#include "ush.h"

static char **one_if(char *str_rep);
static char *replace(const char *s, char *str_join);
static char **two_if(char *str_rep, char *logic);

char **util_strsplit_one(const char *s, char *logic) {
    char **result = NULL;
    char *str_rep = NULL;
    str_rep = util_replace_operator((char *)s);

    if (q_count_operation(str_rep) == 0) {
        result = one_if(str_rep);
    }
    else {
        result = two_if(str_rep, logic);            ///Trouble with understanding
    }
    mx_strdel(&str_rep);
    return result;
}


static char *replace(const char *s, char *str_join) {
    int leng_s = mx_strlen(s);
    int leng_str_join = mx_strlen(str_join);
    char *name = NULL;
    int i = 0;
    int j = leng_str_join;

    name = mx_strnew(leng_s - leng_str_join);
    while (s[j]) {
        name[i] = s[j];
        i++;
        j++;
    }
    name[i] = '\0';
    return name;
}

static char **one_if(char *str_rep) {
    char **result = NULL;
    result = (char**) malloc(sizeof(char*) * (2));
    result[0] = mx_strdup(str_rep);
    result[1] = NULL;
    mx_strdel(&str_rep);
    return result;
}

static char **two_if(char *str_rep, char *logic) {
    char **result = (char**) malloc(sizeof(char*) * (3));
    int len = mx_get_substr_index(str_rep, logic);
    char *temp_str = mx_strndup(str_rep, len);
    char *str_replace = mx_strndup(str_rep, len + 2);
    char *str_trim = NULL;

    result[0] = temp_str;
    str_trim = replace(str_rep, str_replace);
    result[1] = mx_strtrim(str_trim);
    result[2] = NULL;
    mx_strdel(&str_replace);
    mx_strdel(&str_trim);
    return result;
}
