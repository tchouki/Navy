/*
** EPITECH PROJECT, 2018
** navy
** File description:
** error.c
*/

#include "../include/navy.h"

void display_line(char **tab, int x)
{
    for (int i = 0; i < 8; i++) {
        attron(COLOR_PAIR(1));
        if (tab[x - 1][i] == 'x')
            attron(COLOR_PAIR(3));
        if (tab[x - 1][i] == 'o')
            attron(COLOR_PAIR(4));
        if (tab[x - 1][i] >= '2' && tab[x - 1][i] <= '5')
            attron(COLOR_PAIR(2));
        printw("%c%c", tab[x - 1][i], tab[x - 1][i]);
    }
}

void print_map(char **tab)
{
    attron(COLOR_PAIR(5));
    printw(" |A B C D E F G H\n-+---------------\n");
    for (int i = 1; i <= 8; i++) {
        attron(COLOR_PAIR(5));
        printw("%c", 48 + i);
        printw("|");
        display_line(tab, i);
        printw("\n");
    }
}

int check_diff(char size_c, char x_c, char y_c)
{
    int size = size_c - '0';
    int x = x_c - '0';
    int y = y_c - '0';

    if (y - x == size)
        return (1);
    return (0);
}

int check_file(char *file)
{
    int stop = 0;

    for (int i = 0; i < 31; i += 8) {
        if (file[i + 1] != ':' && file[i + 4] != ':' && file[i + 7] != ':' &&
            (file[i] < '2' || file[i] > '5'))
            return (84);
        if (file[i + 2] < 'A' && file[i + 2] > 'H' && file[i + 5] < 'A' &&
            file[i + 5] > 'H')
            return (84);
        if (file[i + 3] < '1' && file[i + 3] > '8' && file[i + 6] < '1' &&
            file[i + 6] > '8')
            return (84);
    }
    for (int i = 0; i < 31 && stop == 0; i += 8) {
        if (file[i + 2] == file[i + 5] && stop == 0)
            stop = check_diff(file[i], file[i + 3], file[i + 6]);
        if (file[i + 3] == file[i + 6] && stop == 0)
            stop = check_diff(file[i], file[i + 2], file[i + 5]);
    }
    return (stop);
}

int create_map(char *filepath, int pid_player_two, int x)
{
    int fd = open(filepath, O_RDONLY);
    char *buf = malloc(sizeof(char) * 31);
    int ret;
    char **tab;

    if (fd == -1)
        return (84);
    ret = read(fd, buf, 31);
    if (check_file(buf) != 0 || ret <= 0)
        return (84);
    tab = create_tab(buf);
    clear();
    refresh();
    game_loop(tab, create_tab_empty(), pid_player_two, x);
    return (0);
}
