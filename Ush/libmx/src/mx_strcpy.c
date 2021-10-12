char *mx_strcpy(char *dst, const char *src) {
    char *orig = dst;
    while ((*dst++ = *src++) != '\0')
		;
	return orig;
}
