int mx_strlen(const char *s) {
    int k = 0;

    while (s[k] != '\0')
        ++k;
    return k;
}
