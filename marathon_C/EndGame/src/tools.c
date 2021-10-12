#include "header.h"

void initcolors()
{
    start_color();
    int COLOR_BROWN = 33;
    int COLOR_DINO = 35;
    int COLOR_SAND = 36;
    int COLOR_SKY = 37;
    init_color(COLOR_DINO, 0, 0, 32536);
    init_color(COLOR_BROWN, 150, 75, 0);
    init_color(COLOR_SAND, 1000, 700, 0);
    init_color(COLOR_SKY, 0, 1000, 1000);
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_BLACK, COLOR_RED);
    init_pair(5, COLOR_BLACK, COLOR_BLUE);
    init_pair(6, COLOR_BLACK, COLOR_WHITE);
    init_pair(7, COLOR_BLACK, COLOR_BROWN);
    init_pair(8, COLOR_GREEN, COLOR_BLACK);
    init_pair(9, COLOR_YELLOW, COLOR_BLACK);
    init_pair(10, COLOR_RED, COLOR_RED);
    init_pair(11, COLOR_BLUE, COLOR_BLACK);
    init_pair(12, COLOR_WHITE, COLOR_GREEN);
    init_pair(13, COLOR_SAND, COLOR_SAND);
    init_pair(14, COLOR_RED, COLOR_WHITE);
    init_pair(15, COLOR_YELLOW, COLOR_GREEN);
    init_pair(16, COLOR_WHITE, COLOR_CYAN);
    init_pair(17, COLOR_WHITE, COLOR_BLUE);
    init_pair(18, COLOR_WHITE, COLOR_WHITE);
    init_pair(19, COLOR_WHITE, COLOR_RED);
    init_pair(20, COLOR_WHITE, COLOR_BLUE);
    init_pair(21, COLOR_GREEN, COLOR_GREEN);
    init_pair(22, COLOR_RED, COLOR_RED);
    init_pair(23, COLOR_BROWN, COLOR_BROWN);
    init_pair(24, COLOR_DINO, COLOR_DINO);
    init_pair(25, COLOR_SKY, COLOR_SKY);
}

void start_win()
{
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    curs_set(FALSE);
    initcolors();
    wbkgd(stdscr, 16);
    wrefresh(stdscr);
}

void ref_pan()
{
    update_panels();
    doupdate();
}

void shift_pan(PANEL *pan, int dy, int dx)
{
    move_panel(pan, getbegy(panel_window(pan)) + dy, getbegx(panel_window(pan)) + dx);
}

void number_from_file(int src, int *num, char c)
{
    char buf;
    *num = 0;
    for (read(src, &buf, 1); (buf != c) && (buf != '\n'); read(src, &buf, 1))
        *num = 10 * (*num) + (buf - '0');
}

PANEL *get_pan(char *image, int pos_y, int pos_x)
{
    int src = open(image, 'r'), index = 0, count = 0, height, width, k = 0;
    char buf;
    number_from_file(src, &height, ' ');
    number_from_file(src, &width, '\n');
    WINDOW *win = newwin(height, width, pos_y, pos_x);
    for (int i = 0; i < height - 1; k += count)
    {
        if (k == width)
        {
            i++;
            k = 0;
        }
        // clear();
        // mvprintw(0, 0, "invalid file: %s line: %d", image, i+2);
        // refresh();
        read(src, &buf, 1);
        number_from_file(src, &index, '-');
        number_from_file(src, &count, ',');
        wattron(win, COLOR_PAIR(index));
        for (int j = 0; j < count; j++)
            mvwprintw(win, i, j + k, &buf);
        wattroff(win, COLOR_PAIR(index));
    }
    close(src);
    return new_panel(win);
}

bool is_dead(WINDOW *dino, WINDOW *obstacle)
{
    int dinoHeight, dinoWidth, dinoY, dinoX, y, x;
    getmaxyx(dino, dinoHeight, dinoWidth);
    getbegyx(dino, dinoY, dinoX);

    getbegyx(obstacle, y, x);

    return ((dinoX + dinoWidth - 8) >= x) && ((dinoY + dinoHeight) > y);
}

void drawDino(WINDOW *win, int x)
{
    mvwprintw(win, LINES / 2 - 24, x / 2 - 40,
              " .----------------.  .----------------.  .-----------------. .----------------. ");
    mvwprintw(win, LINES / 2 - 23, x / 2 - 40,
              "| .--------------. || .--------------. || .--------------. || .--------------. |");
    mvwprintw(win, LINES / 2 - 22, x / 2 - 40,
              "| |  ________    | || |     _____    | || | ____  _____  | || |     ____     | |");
    mvwprintw(win, LINES / 2 - 21, x / 2 - 40,
              "| | |_   ___ `.  | || |    |_   _|   | || ||_   \\|_   _| | || |   .'    `.   | |");
    mvwprintw(win, LINES / 2 - 20, x / 2 - 40,
              "| |   | |   `. \\ | || |      | |     | || |  |   \\ | |   | || |  /  .--.  \\  | |");
    mvwprintw(win, LINES / 2 - 19, x / 2 - 40,
              "| |   | |    | | | || |      | |     | || |  | |\\ \\| |   | || |  | |    | |  | |");
    mvwprintw(win, LINES / 2 - 18, x / 2 - 40,
              "| |  _| |___.' / | || |     _| |_    | || | _| |_\\   |_  | || |  \\  `--'  /  | |");
    mvwprintw(win, LINES / 2 - 17, x / 2 - 40,
              "| | |________.'  | || |    |_____|   | || ||_____|\\____| | || |   `.____.'   | |");
    mvwprintw(win, LINES / 2 - 16, x / 2 - 40,
              "| |              | || |              | || |              | || |              | |");
    mvwprintw(win, LINES / 2 - 15, x / 2 - 40,
              "| '--------------' || '--------------' || '--------------' || '--------------' |");
    mvwprintw(win, LINES / 2 - 14, x / 2 - 40,
              " '----------------'  '----------------'  '----------------'  '----------------' ");
}

void drawNewGame(WINDOW *win, int x, bool highlighted)
{
    char *new_game[6] = {"     __                                                ",
                         "  /\\ \\ \\ ___ __      __   __ _   __ _  _ __ ___    ___ ",
                         " /  \\/ // _ \\\\ \\ /\\ / /  / _` | / _` || '_ ` _ \\  / _ \\",
                         "/ /\\  /|  __/ \\ V  V /  | (_| || (_| || | | | | ||  __/",
                         "\\_\\ \\/  \\___|  \\_/\\_/    \\__, | \\__,_||_| |_| |_| \\___|",
                         "                         |___/                         "};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 55; j++)
        {
            if (highlighted)
                wattron(win, COLOR_PAIR(3));
            mvwprintw(win, LINES / 2 - 10 + i, x / 2 - 28 + j, &new_game[i][j]);
            wattroff(win, COLOR_PAIR(4));
        }
    }
}

void drawAbout(WINDOW *win, int x, bool highlighted)
{
    char *about[6] = {
        "   _   _                 _   ",
        "  /_\\ | |__   ___  _   _| |_ ",
        " //_\\\\| '_ \\ / _ \\| | | | __|",
        "/  _  \\ |_) | (_) | |_| | |_ ",
        "\\_/ \\_/_.__/ \\___/ \\__,_|\\__|",
        "                             "};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 29; j++)
        {
            if (highlighted)
                wattron(win, COLOR_PAIR(3));
            mvwprintw(win, LINES / 2 + i, x / 2 - 15 + j, &about[i][j]);
            wattroff(win, COLOR_PAIR(4));
        }
    }
}

void drawQuit(WINDOW *win, int x, bool highlighted)
{
    char *quit[6] = {
        "   ____       _ _   ",
        "  /___ \\_   _(_) |_ ",
        " //  / / | | | | __|",
        "/ \\_/ /| |_| | | |_ ",
        "\\___,_\\ \\__,_|_|\\__|",
        "                    "};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (highlighted)
                wattron(win, COLOR_PAIR(3));
            mvwprintw(win, LINES / 2 + 10 + i, x / 2 - 11 + j, &quit[i][j]);
            wattroff(win, COLOR_PAIR(4));
        }
    }
}

void free_panels(PANEL *panels[], int k)
{
    WINDOW *win;
    for (int i = 0; i < k; i++)
    {
        if (panels[i] == NULL)
            continue;
        win = panel_window(panels[i]);
        del_panel(panels[i]);
        delwin(win);
        panels[i] = NULL;
    }
}

void hide_panels(PANEL **arr)
{
    for (int i = 0; i < 10; i++)
    {
        hide_panel(arr[i]);
    }
}

void parse_digits(int score)
{
    int tmp = score, i = 0, x = COLS - 20;
    static PANEL *arr[10] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    free_panels(arr, 10);

    while (tmp > 0)
    {
        arr[i] = get_digit(tmp % 10);
        move_panel(arr[i], LINES / 10, x);
        tmp /= 10;
        x -= 4;
        i++;
    }
}

PANEL *get_digit(int num)
{
    char digit = '0' + num;
    char *path = mx_strnew(23);

    strcat(path, "resources/numbers/");
    path[18] = digit;
    strcat(path + 19, ".txt");

    return get_pan(path, 0, 0);
}
