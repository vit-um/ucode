#include "matrix.h"

int main(int argc, char *argv[]) {
    int speed = 10;
    int color = 4;

    if (argc > 1)
    {
        if (argc != 3)
        {
            mx_printerr("usage: ./matrix_rain [color] [speed]");
        }
        else
        {
            color = mx_atoi(argv[1]);
            speed = mx_atoi(argv[2]);
        }
    }

    setlocale(LC_ALL, "ja_JP.UTF-8");
    if (!initscr()) {
        mx_printerr("Error initialising ncurses.\n");
        exit(1);
    }

    WINDOW * win = initscr();
    curs_set(0);

    mx_output_text(win);

    matrix_rain(win, color, speed);

    delwin(win);
    endwin();
    return 0;
}
