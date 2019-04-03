/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *str, char const *comp)
{
    int i = 0;

    for (; str[i] || comp[i]; i++)
        if (str[i] != comp[i])
            return (0);
    if (str[i] != comp[i])
        return (0);
    return (1);
}

int my_strncmp(char *s1, char *s2, int size)
{
    int i = 0;

    for (;s1[i] == s2[i]; i++)
        if ((s1[i] == '\0' && s2[i] == '\0') || i == size - 1)
            return (0);
    if (s1[i] > s2[i])
        return (1);
    if (s1[i] < s2[i])
        return (-1);
    return (0);
}
