/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int a = 0;
    int tmp;
    int b = 0;
    char letter;

    while (str[a] != '\0') {
        a++;
    }
    tmp = a - 1;

    while (tmp >= b) {
        letter = str[tmp];
        str[tmp] = str[b];
        str[b] = letter;
        b++;
        tmp--;
    }
    return (str);
}
