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
        write(1, ": hit\n", 6);
        usleep(500);
        kill_binary("0000000000000001", pid_enemy);
        usleep(500);
    } else {
        tab[pos_x][pos_y] = 'o';
        write(1, ": missed\n", 9);
        usleep(500);
        kill_binary("0000000000000000", pid_enemy);
        usleep(500);
    }
    return (tab);
}

char **enemy_attack(char **tab, int pid_enemy, int x)
{
    int pos_x;
    int pos_y;

    write(1, "\nwaiting for enemy's attack...\n", 31);
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
    return (tab);
}

char **check_hit_done_player1(char **enemy_tab, char *pos, int x)
{
    int result;

    if (x == 1) {
        signal_catcher(1);
        result = convert_base(my_revstr(message[0]));
        my_putchar(pos[0] + 16);
        my_putchar(pos[1]);
        if (result == 0) {
            enemy_tab[pos[1] - '1'][pos[0] - '1'] = 'o';
            write(1, ": missed\n", 9);
        }
        if (result == 1) {
            if (enemy_tab[pos[1] - '1'][pos[0] - '1'] == 'x')
                write(1, ": missed\n", 9);
            else
                write(1, ": hit\n", 6);
            enemy_tab[pos[1] - '1'][pos[0] - '1'] = 'x';
        }
    }
    return (enemy_tab);
}

char **check_hit_done_player2(char **enemy_tab, char *pos, int x)
{
    int result;

    if (x == 2) {
        signal_catcher(2);
        result = convert_base(my_revstr(message[1]));
        my_putchar(pos[0] + 16);
        my_putchar(pos[1]);
        if (result == 0) {
            enemy_tab[pos[1] - '1'][pos[0] - '1'] = 'o';
            write(1, ": missed\n", 9);
        }
        if (result == 1) {
            if (enemy_tab[pos[1] - '1'][pos[0] - '1'] == 'x')
                write(1, ": missed\n", 9);
            else
                write(1, ": hit\n", 6);
            enemy_tab[pos[1] - '1'][pos[0] - '1'] = 'x';
        }
    }
    return (enemy_tab);
}

char **attack(char **tab, char **enemy_tab, int pid_player_two, int x)
{
    char *pos;
    char *pos_bin;

    write(1, "\nattack: ", 9);
    pos = get_next_line(0);
    if (pos[0] == '\0')
        return (NULL);
    if (pos[0] < 'A' || pos[0] > 'H' || pos[1] < '1' || pos[1] > '8') {
        write(1, "wrong position", 14);
        return (attack(tab, enemy_tab, pid_player_two, x));
    }
    pos[0] -= 16;
    pos_bin = convert_binary(my_getnbr(pos));
    pos_bin = binaries_16length(pos_bin);
    kill_binary(pos_bin, pid_player_two);
    usleep(500);
    enemy_tab = check_hit_done_player1(enemy_tab, pos, x);
    enemy_tab = check_hit_done_player2(enemy_tab, pos, x);
    return (enemy_tab);
}
