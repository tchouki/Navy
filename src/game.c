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
            tab[i][j] == 'x' ? ally_touched++ : 0;
    if (ally_touched == 14) {
        print_all(tab, enemy_tab);
        write(1, "\nEnemy won\n", 11);
        return (2);
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            enemy_tab[i][j] == 'x' ? enemy_touched++ : 0;
    if (enemy_touched == 14) {
        print_all(tab, enemy_tab);
        write(1, "\nI won\n", 7);
        return (1);
    }
    return (0);
}

int clear_message(void)
{
    message[0][0] = '\0';
    message[1][0] = '\0';
    for (int i = 1; i < 17; i++) {
        message[0][i] = 2;
        message[1][i] = 2;
    }
    return (0);
}

void print_all(char **tab, char **enemy_tab)
{
    write(1, "\nmy positions:\n", 15);
    print_map(tab);
    write(1, "\nenemy's positions:\n", 20);
    print_map(enemy_tab);
}

int game_loop(char **tab, char **enemy_tab, int pid_enemy, int x)
{
    int end = 0;
    int wait = x - 1;

    while (end == 0) {
        clear_message();
        print_all(tab, enemy_tab);
        if (end == 0 && wait == 0)
            enemy_tab = attack(tab, enemy_tab, pid_enemy, x);
        if (enemy_tab == NULL)
            return (84);
        if (end == 0)
            end = check_end(tab, enemy_tab);
        wait = clear_message();
        if (end == 0)
            tab = enemy_attack(tab, pid_enemy, x);
        if (end == 0)
            end = check_end(tab, enemy_tab);
    }
    return (end - 1);
}
