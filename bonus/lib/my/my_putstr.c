/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** putstrr
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char *str)
{
    int i = 0;
    while (str[i]) {
        my_putchar(str[i++]);
    }
    return (0);
}
