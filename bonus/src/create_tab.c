/*
** EPITECH PROJECT, 2018
** navy
** File description:
** create_tab.c
*/

#include "../include/navy.h"

char **set_boat(char **tab, char *file, int lign, int i)
{
    if (i == 0) {
        for (int i = file[lign + 3] - '0'; i <= file[lign + 6] - '0'; i++)
            tab[i - 1][file[lign + 2] - 'A'] = file[lign];
    }
    if (i == 1) {
        for (int i = file[lign + 2] - 'A'; i <= file[lign + 5] - 'A'; i++)
            tab[file[lign + 3] - '0' - 1][i] = file[lign];
    }
    return (tab);
}

char **create_tab_empty(void)
{
    char **tab = malloc(sizeof(char*) * 8);

    for (int i = 0; i < 8; i++)
        tab[i] = malloc(sizeof(char) * 8);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            tab[i][j] = '.';
    return (tab);
}

char **create_tab(char *file)
{
    char **tab = create_tab_empty();

    for (int i = 0; i < 31; i += 8) {
        if (file[i + 2] == file[i + 5])
            tab = set_boat(tab, file, i, 0);
        else
            tab = set_boat(tab, file, i, 1);
    }
    return (tab);
}
