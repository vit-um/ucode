#include "header.h"

void menu(int lim)
{
    int menuId = 0;
    int currentScene = 0;
    int x = 0;
    int y = 0;
    int result = 0;

    WINDOW *win = initscr();
    curs_set(0);
    noecho();
    getmaxyx(stdscr, y, x);
    // box(win, 0, 0);
    // refresh();
    start_color();
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    wbkgd(win, COLOR_PAIR(4));

    while (true)
    {
        box(win, 0, 0);
        refresh();
        switch (currentScene)
        {
        case 0:
            drawDino(win, x);
            drawNewGame(win, x, menuId == 0);
            //drawCharacters(win, x,  menuId == 1);
            drawAbout(win, x, menuId == 1);
            drawQuit(win, x, menuId == 2);
            char a = getch();
            switch (a)
            {
            case 3:
                menuId = (menuId + 2) % 3;
                break;
            case 2:
                menuId = (menuId + 1) % 3;
                break;
            case '\n':
                currentScene = menuId + 1;
                clear();
                break;
            }
            break;
        case 1:
//            cycle();
//            endwin();
//            exit(0);
//            break;
             result = cycle(lim);
             if (result == 1 || result == -1){ //ESC case | Game over - to menu
                 currentScene = 0;
                 clear();
                 refresh();
                 break;
             }
             else if (result == 0) { //q case - out of the game
                 endwin();
                 exit(0);
                 break;
             }
             break;
        case 2:
            if (!check_screen())
                break;
            about(win, lim);
            break;
        case 3:
            exit(0);
            break;
        }
        if (!check_screen())
            break;
        refresh();
    }
    getch();
    delwin(win);
}
