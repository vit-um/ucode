#pragma once
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
#include <curses.h>
#include <panel.h>
#include <menu.h>
#include <form.h>
#include <time.h>

int cycle(int lim);
void about(WINDOW *win, int lim);
bool check_screen();
void free_panels(PANEL *panels[], int k);
void start_win();
void initcolors();
void ref_pan();
void shift_pan(PANEL *pan, int dy, int dx);
PANEL *get_pan(char *file, int pos_y, int pos_x);
void number_from_file(int src, int *num, char c);
bool is_dead(WINDOW *dino, WINDOW *obstacle);
void drawDino(WINDOW *win, int x);
void drawNewGame(WINDOW *win, int x,  bool highlighted);
void drawAbout(WINDOW *win, int x,  bool highlighted);
void drawQuit(WINDOW *win, int x,  bool highlighted);
void menu(int win);
double mx_timer(int(*f)());
void read_nums();
void hide_panels(PANEL **arr);
void parse_digits(int score);
PANEL *get_digit(int num);
int mx_atoi(const char *str);
char *mx_strnew(const int size);
