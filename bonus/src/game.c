/*
** EPITECH PROJECT, 2018
** navy
** File description:
** start of the two player
*/

#include "../include/navy.h"

int check_end(char **tab, char **enemy_tab)
{
    int ally_touched = 0;
    int enemy_touched = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (tab[i][j] == 'x')
                ally_touched++;
    if (ally_touched == 14) {
        clear();
        attron(COLOR_PAIR(6));
        printw("Enemy won\n");
        refresh();
        return (1);
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (tab[i][j] == 'x')
                enemy_tab++;
    if (enemy_touched == 14) {
        clear();
        attron(COLOR_PAIR(7));
        printw("I won\n");
        refresh();
        return (2);
    }
    return (0);
}

void clear_message(void)
{
    attron(COLOR_PAIR(1));
    message[0][0] = '\0';
    message[1][0] = '\0';
    for (int i = 1; i < 17; i++) {
        message[0][i] = 2;
        message[1][i] = 2;
    }
}

void print_all(char **tab, char **enemy_tab)
{
    clear();
    printw("\nmy positions:\n");
    print_map(tab);
    printw("\nenemy's positions:\n");
    print_map(enemy_tab);
    refresh();
}

int game_loop(char **tab, char **enemy_tab, int pid_enemy, int x)
{
    int end = 0;
    int wait = 0;

    if (x == 2)
        wait = 1;
    while (end == 0) {
        clear_message();
        print_all(tab, enemy_tab);
        if (end == 0 && wait == 0)
            enemy_tab = attack(tab, enemy_tab, pid_enemy, x);
        if (enemy_tab == NULL)
            return (84);
        end = check_end(tab, enemy_tab);
        clear_message();
        wait = 0;
        if (end == 0)
            tab = enemy_attack(tab, pid_enemy, x);
        end = check_end(tab, enemy_tab);
    }
    endwin();
    system("stty -raw && stty echo && stty onlcr");
    return (0);
}
