#pragma once


#include <stdio.h>  //printf
#include <string.h>
#include <stdlib.h>  //exit
#include <unistd.h>  //write

#define ARRAY_SIZE(x)  (sizeof(x) / sizeof((x)[0]))

void mx_printerr(const char *s);
void mx_printchar(char c);
void mx_printstr(const char *s);
int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);
char* mx_strnew(const int size);
void mx_strdel(char **str);
char *mx_strncpy(char *dst, const char* src, int len);
char *mx_strndup(const char *str, size_t len);
void mx_printascii(char *segment);

typedef struct
{
    char* morse;
    char* ascii;
} morse_table_t;
