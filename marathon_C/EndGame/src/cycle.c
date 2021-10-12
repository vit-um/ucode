#include "header.h"

#define maxCountObstacles 5

int cycle(int lim)
{
    int ch = 0, speed = 10, t,
        dinoX = 0,
        barY = (LINES * 3) / 4,
        // sec,
        count = 0;
    // clock_t start, stop;
    int screenWidth, screenHeight;
    getmaxyx(stdscr, screenHeight, screenWidth);

    int isUp = 0;
    int jumpDirection = 0;

    PANEL *dino = get_pan("resources/characters/dino.txt", 0, (dinoX));
    move_panel(dino, barY - getmaxy(panel_window(dino)) + 1, dinoX + 1);
    WINDOW *sand = newwin(LINES - barY, COLS, barY, 0);
    PANEL *sand_pan = new_panel(sand);
    WINDOW *sky = newwin((LINES * 3) / 4, COLS, 0, 0);
    PANEL *sky_pan = new_panel(sky);
    PANEL *game_over = get_pan("resources/misc/game_over.txt", LINES / 2 - 4, COLS / 2 - 35);
    PANEL *score = get_pan("resources/misc/score.txt", LINES / 10, (COLS * 7) / 9);
    PANEL *obstacles[maxCountObstacles] = {0, 0, 0, 0, 0};
    PANEL *game_win = get_pan("resources/misc/win.txt", LINES/2 - 4, COLS/2 - 15);
    
    hide_panel(game_over);
    hide_panel(game_win);

    wbkgd(sand, COLOR_PAIR(13));
    wbkgd(sky, COLOR_PAIR(25));

    show_panel(sand_pan);
    show_panel(sky_pan);

    bool visibleTrashes[maxCountObstacles] = {0, 0, 0, 0, 0};

    for (int i = 0; i < maxCountObstacles; ++i)
    {
        obstacles[i] = get_pan("resources/misc/cactus.txt", barY - 10, 50 + i * 50);
        bottom_panel(obstacles[i]);
        hide_panel(obstacles[i]);
        visibleTrashes[i] = 0;
    }

    timeout(speed);
    int rateNumber = 0;

    // start = clock();

    while ((ch = getch()) != 'q')
    {
        bottom_panel(dino);
        bottom_panel(sky_pan);
        // stop = clock();
        // sec = (int)(stop - start) / 36000;
        parse_digits(count);

        if (ch == 27)
        { //ESC to menu
            clear();
            hide_panel(dino);
            hide_panel(score);
            hide_panel(sky_pan);
            hide_panel(sand_pan);
            // free_panels(digits, 10);
            for (int i = 0; i < maxCountObstacles; ++i)
            {
                hide_panel(obstacles[i]);
                visibleTrashes[i] = 0;
            }
            return 1;
        }

        for (int i = 0; i < maxCountObstacles; ++i)
        {
            if (!visibleTrashes[i])
                continue;
            shift_pan(obstacles[i], 0, -1);
            t = getbegx(panel_window(obstacles[i]));
            if (t <= 1)
            {
                visibleTrashes[i] = 0;
                hide_panel(obstacles[i]);
                count++;
            }
            if (is_dead(panel_window(dino), panel_window(obstacles[i])))
            {
                show_panel(game_over);
                ref_pan();
                timeout(-1);
                getch();
                hide_panel(game_over);
                hide_panel(dino);
                hide_panel(score);
                hide_panel(sand_pan);
                hide_panel(sky_pan);
                // free_panels(digits, 10);
                for (int i = 0; i < maxCountObstacles; ++i)
                {
                    hide_panel(obstacles[i]);
                    visibleTrashes[i] = 0;
                }
                endwin();
                return -1;
                break;
            }
            if (count > lim) {
                show_panel(game_win);
                ref_pan();
                timeout(-1);
                getch();
                hide_panel(game_win);
                hide_panel(dino);
                hide_panel(score);
                hide_panel(sand_pan);
                hide_panel(sky_pan);
                // free_panels(digits, 10);
                for (int i = 0; i < maxCountObstacles; ++i)
                {
                    hide_panel(obstacles[i]);
                    visibleTrashes[i] = 0;
                }
                endwin();
                return -1;
                break;
            }
        }

        if (++rateNumber > 100)
            rateNumber = 0;

        // if (rateNumber % (rand() % 5 + 1) == 0 && (rand() % 50 == 0))
        if ((rand() % 21) == 0)
        {
            for (int i = 0; i < maxCountObstacles; ++i)
            {
                if (visibleTrashes[i] == 0)
                {
                    int height, width;
                    getmaxyx(panel_window(obstacles[i]), height, width);

                    move_panel(obstacles[i], barY - 5, screenWidth - width);
                    bool canAdd = 1;

                    for (int j = 0; j < maxCountObstacles; ++j)
                    {
                        if (i != j && visibleTrashes[j])
                        {
                            if (abs(getbegx(panel_window(obstacles[j])) - getbegx(panel_window(obstacles[i]))) < 60)
                            {
                                canAdd = 0;
                                break;
                            }
                        }
                    }
                    if (canAdd)
                    {
                        show_panel(obstacles[i]);
                        bottom_panel(obstacles[i]);
                        visibleTrashes[i] = 1;
                    }
                    break;
                }
            }
        }
        top_panel(sand_pan);

        if (jumpDirection != 0)
        {
            if (isUp == -25)
            {
                jumpDirection = 1;
            }

            isUp += jumpDirection;
            shift_pan(dino, jumpDirection, 0);
            if (isUp == 0)
            {
                jumpDirection = 0;
            }
        }
        if (jumpDirection == 0 && ch == 32 /*Space key*/)
        {
            jumpDirection = -1;
        }
        ref_pan();
        if (!check_screen())
            return 0;
        timeout(speed);
    }
    return 0;
}
