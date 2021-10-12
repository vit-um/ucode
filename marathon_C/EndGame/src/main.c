#include "header.h"

int main(int argc, char* argv[]) {
    int win = 1000000; 
    if (argc == 2) {
        win = mx_atoi(argv[1]);
    }
    start_win();
	check_screen();
    menu(win);
    endwin();
    return 0;
}
