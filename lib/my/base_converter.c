/*
** EPITECH PROJECT, 2018
** project lib
** File description:
** base converter
*/

#include "my.h"

int convert_base(char *str)
{
    int i = my_strlen(str) - 1;
    int base = 1;
    int end = 0;

    for (; i >= 0; i--) {
        if (str[i] == '1')
            end += base;
        base *= 2;
    }
    return (end);
}

char *convert_binary(int value)
{
    int i = 0;
    int j = 0;
    int value_tmp = value;
    char *res = NULL;

    for (; value_tmp != 0; i++)
        value_tmp = value_tmp / 2;
    res = malloc((sizeof(char) * i) + 1);
    while (value != 0) {
        res[j] = (value % 2) + 48;
        value = value / 2;
        j++;
    }
    res[j] = '\0';
    my_revstr(res);
    return (res);
}
