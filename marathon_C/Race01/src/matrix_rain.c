#include "matrix.h"

void matrix_rain(WINDOW *win, int color, int speed) {
    int rows;
    int columns;
    getmaxyx(win, columns, rows);

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(8, COLOR_YELLOW, COLOR_BLACK);
    curs_set(false);
    noecho();

    setlocale(LC_ALL, "ja_JP.UTF-8");

    display *matrix = (display *)malloc(sizeof(display) * rows);

    for (int i = 0; i < rows; i++) {
        matrix[i].arr = (wchar_t *)malloc(sizeof(wchar_t) * columns);

        for (int j = 0; j < columns; j++) {
            matrix[i].arr[j] = random_unicode();
        }

        matrix[i].length = rand() % columns;
        matrix[i].start = -matrix[i].length - matrix[i].length;
        matrix[i].finish = -matrix[i].length;
    }

    wbkgd(win, COLOR_PAIR(color));
    wclear(win);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i].arr[j] = random_unicode();

    while (true) {
        wtimeout(win, 60 / speed * 10);
        char a = getch();
        switch (a) {
        case '-':
            if (speed > 10)
                speed -= 10;
            break;
        case '+':
            if (speed < 100)
                speed += 10;
            break;
        case 'q':
            clear();
            refresh();
            for (int i = 0; i < rows; i++)
                free(matrix[i].arr);
            free(matrix);
            matrix = NULL;
            delwin(win);
            endwin();
            exit(0);
        }
        if (a >= '0' && a <= '8')
            color = mx_atoichar(a);

        wclear(win);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (j >= matrix[i].start && j <= matrix[i].finish) {
                    if (j == matrix[i].finish) {
                        attroff(COLOR_PAIR(color));
                        attron(COLOR_PAIR(2));
                    }

                    mvprintw(j, i * 2, "%lc", matrix[i].arr[j]);

                    if (j == matrix[i].finish) {
                        attroff(COLOR_PAIR(2));
                        attron(COLOR_PAIR(color));
                    }
                    if (j == matrix[i].start) {
                        matrix[i].arr[j] = random_unicode();
                    }
                    if (j == matrix[i].finish) {
                        matrix[i].arr[j] = random_unicode();
                    }
                }
            }

            matrix[i].start++;
            matrix[i].finish++;

            if (matrix[i].start > columns) {
                matrix[i].length = rand() % columns;
                matrix[i].start = -matrix[i].length - matrix[i].length;
                matrix[i].finish = -matrix[i].length;
            }
        }
        refresh();
    }
    clear();
    refresh();

    for (int i = 0; i < rows; i++) {
        free(matrix[i].arr);
    }
    free(matrix);
    matrix = NULL;
}
