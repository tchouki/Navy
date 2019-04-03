/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** my_strconcat
*/

#include "my.h"

char **my_strconcat(char *str, char cara)
{
    int size_tab = 1;
    char **tab = NULL;
    int size_line = 0;
    int k = 0;
    int j = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == cara)
            size_tab++;
    tab = malloc(sizeof(char *) * (size_tab + 1));
    for (int i = 0; i < my_strlen(str); i++) {
        for (k = i, size_line = 0; str[k] != cara && str[k]; k++)
            size_line++;
        tab[j] = malloc(sizeof(char) * size_line + 1);
        for (k = 0; str[i] != cara && str[i]; i++, k++)
            tab[j][k] = str[i];
        tab[j++][k] = '\0';
    }
    tab[size_tab] = NULL;
    return (tab);
}
