#include "header.h"

void about(WINDOW *win, int lim) {
    int x = 0;
    int y = 0;
    int speed = 10;
    getmaxyx(stdscr, y, x);
    start_color();
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    wbkgd(win, COLOR_PAIR(4));
    char c;
   /* 
    PANEL *gover = get_pan("images/game_over.txt", 60, x / 2 - 50);
    update_panels();
    show_panel(gover);
    refresh();
*/
    timeout(speed);
    while ((c = getch()) != 27) {
            check_screen();
            box(win, 0, 0);
            drawDino(win, x);
            
            mvwprintw(win, y / 2 - 10, x / 2 - 5, "ABOUT GAME");
            mvwprintw(win, y / 2 - 8, x / 2 - 42, "\"Dino\" is not just a time killer when you are left off without any Internet access.");
            mvwprintw(win, y / 2 - 6, x / 2 - 77, "It's pretty obvious that you tend to make a bunch of ridiculous mistakes whenever you are anxious, overwhelmed with something or just emotionally unstable.");
            mvwprintw(win, y / 2 - 4, x / 2 - 84,  "That's why, we have created this game for you to stay focused and check and reduce your stress level. At first, you have to try out the game while being in a good mood.");
            mvwprintw(win, y / 2 - 2, x / 2 - 79,  "You gotta find out your average score so that you know how much cacti you have to jump over to get a significant energy boost over stressful moments in life.");
            mvwprintw(win, y / 2, x / 2 - 92,  "And there you go, if you feel like your head is about to take off to another dimension just pull up Dino on your screen, enter your average score and then check your your state of mind.");
            mvwprintw(win, y / 2 + 2, x / 2 - 80,  "If you have reached your average score or even overdid it and got the '[WIN]' message on the screen, then you're totally good, keep up with your life and tasks:)");
            mvwprintw(win, y / 2 + 4, x / 2 - 98,  "However, if you keep getting the '[GAME OVER]' message over and over again, then you gotta take up some breathing exercises, try to switch your current task with something that brings you pleasure");
            
            mvwprintw(win, y / 2 + 8, x / 2 - 4,  "CONTROLS");
            mvwprintw(win, y / 2 + 10, x / 2 - 15, "\"space\"         -     jump");
            mvwprintw(win, y / 2 + 12, x / 2 - 15, "\"esc\"           -     exit to Main menu");
            mvwprintw(win, y / 2 + 14, x / 2 - 15, "\"c\"             -     continue");
            mvwprintw(win, y / 2 + 16, x / 2 - 15, "\"q\"             -     quit");
            mvwprintw(win, y / 2 + 18, x / 2 - 15, "\"hold any key\"  -     speed up");
            
            mvwprintw(win, y / 2 + 23, x / 2 - 6, "DEVELOPED BY");
            mvwprintw(win, y / 2 + 24, x / 2 - 9, "Valerii  Petryniak");
            mvwprintw(win, y / 2 + 25, x / 2 - 9, "Tetyana  Holdanova");
            mvwprintw(win, y / 2 + 26, x / 2 - 8, "Vitalii  Umanets");
            mvwprintw(win, y / 2 + 27, x / 2 - 7, "Max  Hrynchak");
            refresh();
            timeout(speed);
    }
    clear();
    refresh();
    menu(lim);
}
