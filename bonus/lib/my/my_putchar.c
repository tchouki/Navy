/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** my_putchar
*/

#include "my.h"

int my_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return (-1);
    return (0);
}
