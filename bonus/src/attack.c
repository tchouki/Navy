/*
** EPITECH PROJECT, 2018
** navy
** File description:
** attack.c
*/

#include "../include/navy.h"

char **check_hit(char **tab, int pos_x, int pos_y, int pid_enemy)
{
    my_putchar(pos_y + 'A');
    my_putchar(pos_x + '1');
    if ((tab[pos_x][pos_y] >= '2' && tab[pos_x][pos_y] <= '5') ||
        tab[pos_x][pos_y] == 'x') {
        tab[pos_x][pos_y] = 'x';
        usleep(100);
        kill_binary("0000000000000001", pid_enemy);
        usleep(100);
    } else {
        tab[pos_x][pos_y] = 'o';
        attron(COLOR_PAIR(5));
        printw(": missed\n");
        usleep(100);
        kill_binary("0000000000000000", pid_enemy);
        usleep(100);
    }
    return (tab);
}

char **enemy_attack(char **tab, int pid_enemy, int x)
{
    int pos_x;
    int pos_y;

    clear();
    attron(COLOR_PAIR(5));
    printw("\nwaiting for enemy's attack...\n");
    if (x == 1) {
        signal_catcher(1);
        pos_x = convert_base(my_revstr(message[0]));
        pos_y = pos_x / 10;
        pos_x = pos_x - (pos_y * 10);
    }
    else {
        signal_catcher(2);
        pos_x = convert_base(my_revstr(message[1]));
        pos_y = pos_x / 10;
        pos_x = pos_x - (pos_y * 10);
    }
    tab = check_hit(tab, pos_x - 1, pos_y - 1, pid_enemy);
    refresh();
    return (tab);
}

char **check_hit_done_player1(char **enemy_tab, char *pos, int x)
{
    int result;

    attron(COLOR_PAIR(5));
    if (x == 1) {
        signal_catcher(1);
        result = convert_base(my_revstr(message[0]));
        my_putchar(pos[0] + 16);
        my_putchar(pos[1]);
        if (result == 0) {
            enemy_tab[pos[1] - '1'][pos[0] - '1'] = 'o';
            printw(": missed\n");
        }
        if (result == 1) {
            if (enemy_tab[pos[1] - '1'][pos[0] - '1'] == 'x')
                printw(": missed\n");
            else {
                attron(COLOR_PAIR(6));
                printw(": hit\n");
            }
            enemy_tab[pos[1] - '1'][pos[0] - '1'] = 'x';
        }
    }
    refresh();
    return (enemy_tab);
}

char **check_hit_done_player2(char **enemy_tab, char *pos, int x)
{
    int result;

    attron(COLOR_PAIR(5));
    if (x == 2) {
        signal_catcher(2);
        result = convert_base(my_revstr(message[1]));
        my_putchar(pos[0] + 16);
        my_putchar(pos[1]);
        if (result == 0) {
            enemy_tab[pos[1] - '1'][pos[0] - '1'] = 'o';
            printw(": missed\n");
        }
        if (result == 1) {
            if (enemy_tab[pos[1] - '1'][pos[0] - '1'] == 'x')
                printw(": missed\n");
            else {
                attron(COLOR_PAIR(6));
                printw(": hit\n");
            }
            enemy_tab[pos[1] - '1'][pos[0] - '1'] = 'x';
        }
    }
    refresh();
    return (enemy_tab);
}

char **attack(char **tab, char **enemy_tab, int pid_player_two, int x)
{
    char *pos = malloc(sizeof(char) * 3);
    char *pos_bin;

    attron(COLOR_PAIR(5));
    printw("\nattack: ");
    getstr(pos);
    if (pos[0] == '\0')
        return (NULL);
    if (pos[0] < 'A' || pos[0] > 'H' || pos[1] < '1' || pos[1] > '8') {
        printw("%s -> wrong position", pos);
        refresh();

        return (attack(tab, enemy_tab, pid_player_two, x));
    }
    pos[0] -= 16;
    pos_bin = convert_binary(my_getnbr(pos));
    pos_bin = binaries_16length(pos_bin);
    kill_binary(pos_bin, pid_player_two);
    usleep(100);
    enemy_tab = check_hit_done_player1(enemy_tab, pos, x);
    enemy_tab = check_hit_done_player2(enemy_tab, pos, x);
    refresh();
    return (enemy_tab);
}
