/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int nb)
{
    for (int i = 0; i < nb && src[i] != '\0'; i++) {
        dest[i] = src[i];
        dest[i + 1] = '\0';
    }
    dest[nb] = '\0';
    return (dest);
}
