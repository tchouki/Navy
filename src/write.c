/*
** EPITECH PROJECT, 2018
** navy
** File description:
** write
*/

#include "../include/navy.h"
#include <signal.h>

void display_line(char **tab, int x)
{
    for (int i = 0; i < 8; i++) {
        write(1, &tab[x - 1][i], 1);
        if (i != 7)
            write(1, " ", 1);
    }
}

void print_map(char **tab)
{
    write(1, " |A B C D E F G H\n-+---------------\n", 36);
    for (int i = 1; i <= 8; i++) {
        my_putchar(48 + i);
        write(1, "|", 1);
        display_line(tab, i);
        write(1, "\n", 1);
    }
}

void writing(int bool, int pid)
{
    write(1, "my_pid: ", 8);
    my_put_nbr(pid);
    if (bool)
        write(1, "\nwaiting for enemy connection...\n", 33);
    if (!bool)
        write(1, "\nsuccessfully connected\n", 24);
}
