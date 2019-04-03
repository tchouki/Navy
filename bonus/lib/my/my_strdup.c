/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(const char *str)
{
    char *end = 0;
    int i = 0;

    for (; str[i]; i++);
    end = malloc(sizeof(char) * (i + 1));
    for (i = 0; str[i]; i++)
        end[i] = str[i];
    end[i] = '\0';
    return (end);
}

char *my_strndup(const char *str, int size)
{
    char *end = 0;
    int i = 0;
    int j = 0;

    for (; str[i]; i++);
    end = malloc(sizeof(char) * (i + 1 - size));
    for (i = size; str[i]; i++, j++)
        end[j] = str[i];
    end[j] = '\0';
    return (end);
}

char **my_tabdup(char **tab)
{
    int i = 0;
    char **dup = NULL;

    for (; tab[i]; i++);
    dup = malloc(sizeof(char *) * (i + 1));
    for (i = 0; tab[i]; i++) {
        dup[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1));
        for (int j = 0; tab[i][j]; j++) {
            dup[i][j] = tab[i][j];
            dup[i][j + 1] = '\0';
        }
    }
    dup[i] = NULL;
    return (dup);
}

char **my_tabndup(char **tab, int start)
{
    int i = 0;
    char **dup = NULL;

    for (; tab[i]; i++);
    dup = malloc(sizeof(char *) * (i + 1 - start));
    for (i = start - 1; tab[i]; i++) {
        dup[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1));
        for (int j = 0; tab[i][j]; j++) {
            dup[i][j] = tab[i][j];
            dup[i][j + 1] = '\0';
        }
    }
    dup[i] = NULL;
    return (dup);
}
