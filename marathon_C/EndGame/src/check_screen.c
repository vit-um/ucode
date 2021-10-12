#include "header.h"

bool check_screen(){
    int y, x;
    bool f = 0;
    getmaxyx(stdscr, y, x);
    timeout(-1);
    while (y<65 || x<230){
        f = 1;
        mvprintw(LINES/2 - 1, (COLS - 10)/2, "'q' - exit");
        mvprintw(LINES/2, (COLS - 36)/2, "Your window resolution is too small!");
        mvprintw(LINES/2 + 1, (COLS - 20)/2, "Resize your window!");
        refresh();
        if (getch()=='q'){
            clear();
            endwin();
            exit(0);
            }
        getmaxyx(stdscr, y, x);
        clear();
    }
    if (f){
        clear();
        mvprintw(LINES/2, (COLS - 36)/2, "Press 'c' - to continue . . .");
        while(getch()!='c');
        clear();
        refresh();
        ref_pan();
    }
    return 1;
}
