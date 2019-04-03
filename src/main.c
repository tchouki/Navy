/*
** EPITECH PROJECT, 2018
** navy
** File description:
** main.c
*/

#include "../include/navy.h"

int print_help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./navy [first_player_pid] navy_positions\n", 42);
    write(1, "DESCRIPTION\n", 12);
    write(1, "\tfirst_player_pid: only for the 2nd player.", 43);
    write(1, " pid of the first player.\n", 26);
    write(1, "\tnavy_positions: file representing the positions", 48);
    write(1, " of the ships.\n", 15);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 1 || argc > 3)
        return (84);
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        return (print_help());
    if (argc == 2)
        return (player_one(my_strdup(argv[1])));
    if (argc == 3)
        return (player_two(my_getnbr(argv[1]), my_strdup(argv[2])));
    return (0);
}
