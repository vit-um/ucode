#include "libmx.h"

char *mx_strcat(char *s1, const char *s2){
	int n = mx_strlen(s2), k = mx_strlen(s1), i = 0;
	for (; i < n; i++) {
		s1[k + i] = s2[i];
	}
	s1[k + i] = '\0';
	return s1;
}
