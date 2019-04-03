/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** lit
*/

#include "my.h"

char **str_to_tab(char *const str, char cara)
{
    char **tab = NULL;
    int max_length = 1;
    int line = 0;
    int b = 0;
    int a = 0;

    for (int i = 0; str != NULL && str[i]; i++)
        if (str[i] == cara)
            max_length++;
    tab = malloc(sizeof(char *) * (max_length + 1));
    for (int i = 0; str[i] != '\0'; i++, a++) {
        for (line = i; str[line] != cara && str[line] != '\0'; line++);
        tab[a] = malloc(sizeof(char) * (line - i + 1));
        for (b = 0; str[i] != cara && str[i] != '\0'; i++, b++)
            tab[a][b] = str[i];
        tab[a][b] = '\0';
        i = str[i] == '\0' ? i - 1 : i;
    }
    tab[a] = NULL;
    return (tab);
}
