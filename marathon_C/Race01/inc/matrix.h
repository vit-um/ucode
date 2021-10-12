#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

typedef struct display {
    int length;
    int start;
    int finish;
    wchar_t *arr;
} display;

int mx_strcmp(const char *, const char *);
void matrix_rain(WINDOW *win, int color, int speed);
void mx_output_text(WINDOW *win);
wchar_t random_unicode();
int mx_atoi(const char *str);
int mx_atoichar(const char a);
int mx_strlen(const char*);
void mx_printerr(const char *s);
