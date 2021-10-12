#include "matrix.h"

void mx_output_text(WINDOW *win) {
    int rows;
    int colums;
    getmaxyx(win, colums, rows);

    start_color();
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    wattron(win, COLOR_PAIR(4));
 //   wbkgd(win, COLOR_PAIR(4) | A_DIM | A_BOLD);

    if (colums > 16 && rows > 32) {
        int x = 8;
        int y = 8;

        sleep(1);
        delay_output(15);

        char text[4][74] = { "Wake up, Neo..", "The Matrix has you..", "Follow the white rabbit", "Knock, knock, Neo" };

        wclear(win);

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < mx_strlen(text[i]); j++) {
                mvwaddch(win, y, x + j, text[i][j]);
                refresh();
                delay_output(150);
            }
            if (i != 3) {
                wclear(win);
                delay_output(5);
            }
        }
    }
}
