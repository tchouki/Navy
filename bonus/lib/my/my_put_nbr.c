/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** my_put_nbr.c
*/

#include "my.h"

void my_put_nbr(int nb)
{
    char modulo = 0;

    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    modulo = (nb % 10) + '0';
    nb /= 10;
    if (nb != 0)
        my_put_nbr(nb);
    write(1, &modulo, 1);
}
