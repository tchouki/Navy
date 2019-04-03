/*
** EPITECH PROJECT, 2018
** navy
** File description:
** error.c
*/

#include "../include/navy.h"

int check_diff(char size_c, char x_c, char y_c)
{
    int size = size_c - '0';
    int x = x_c - '0';
    int y = y_c - '0';

    if (y - x  + 1 == size)
        return (0);
    return (84);
}

int check_file2(char **tab)
{
    int j = 0;
    int tmp = 0;

    for (int i = 0; tab[i]; i++) {
        for (j = 0 ;tab[i][j]; j++);
        if (j != 7)
            return (1);
        if (tab[i][2] == tab[i][5])
            tmp = check_diff(tab[i][0], tab[i][3], tab[i][6]);
        else
            tmp = check_diff(tab[i][0], tab[i][2], tab[i][5]);
        if (tmp != 0 || (tab[i][1] != ':' && tab[i][4] != ':'))
            return (1);
    }
    return (0);
}

int check_file(char *file)
{
    char **tab = NULL;
    int *nbr = malloc(sizeof(int) * 5);
    int tmp = 0;

    tab = str_to_tab(file, '\n');
    for (;tab[tmp]; tmp++);
    if (tmp != 4)
        return (1);
    for (int i = 0; tab[i]; i++)
        if (tab[i][0] - '0' > 5 || tab[i][0] - '0' < 2)
            return (1);
        else
            nbr[(tab[i][0] - '0') - 2] += 1;
    for (int i = 0; i < 4; i++)
        if (nbr[i] != 1)
            return (1);
    if (check_file2(tab))
        return (1);
    return (0);
}

int create_map(char *buffer, int pid_player_two, int x)
{
    char **tab;

    tab = create_tab(buffer);
    return (game_loop(tab, create_tab_empty(), pid_player_two, x));
}
