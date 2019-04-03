/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** my_getnbr
*/

#include "my.h"

int	my_getnbr(char *const str)
{
    int negative = 0;
    int end = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') {
            negative += str[i] == '-' ? 1 : 0;
            continue;
        }
        end += str[i] - '0';
        end *= 10;
    }
    end /= 10;
    if (negative % 2)
        return (end * -1);
    return (end);
}
