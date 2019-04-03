/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}
