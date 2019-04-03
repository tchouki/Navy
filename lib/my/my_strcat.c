/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *const str1, char *const str2)
{
    char *str = 0;
    int i = 0;
    int j = 0;

    if (str1 == NULL || str2 == NULL)
        return (NULL);
    for (; str1[i]; i++);
    for (; str2[j]; j++);
    str = malloc(sizeof(char) * (i + j + 1));
    for (i = 0; str1[i]; i++)
        str[i] = str1[i];
    for (j = 0; str2[j]; i++, j++)
        str[i] = str2[j];
    str[i] = '\0';
    return (str);
}

char *my_strcat_btw(char *const str1, char *const str2, char cara)
{
    char *str = 0;
    int i = 0;
    int j = 0;

    if (str1 == NULL || str2 == NULL || cara == 0)
        return (NULL);
    for (; str1[i]; i++);
    for (; str2[j]; j++);
    str = malloc(sizeof(char) * (i + j + 2));
    for (i = 0; str1[i]; i++)
        str[i] = str1[i];
    str[i++] = cara;
    for (j = 0; str2[j]; i++, j++)
        str[i] = str2[j];
    str[i] = '\0';
    return (str);
}
