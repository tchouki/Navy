/*
** EPITECH PROJECT, 2018
** navy
** File description:
** binraies n sh*t
*/

#include "../include/navy.h"
#include <signal.h>

void signal_usr2(int sig)
{
    int i = my_strlen(message[1]);

    if (sig == SIGUSR1) {
        message[1][i] = '0';
        message[1][i + 1] = '\0';
    }
    if (sig == SIGUSR2) {
        message[1][i] = '1';
        message[1][i + 1] = '\0';
    }
}

void signal_usr(int sig)
{
    int i = my_strlen(message[0]);

    if (sig == SIGUSR1) {
        message[0][i] = '0';
        message[0][i + 1] = '\0';
    }
    if (sig == SIGUSR2) {
        message[0][i] = '1';
        message[0][i + 1] = '\0';
    }
}

void signal_catcher(int player)
{
    if (player == 1) {
        while (message[0][16] == 2) {
            signal(SIGUSR1, signal_usr);
            signal(SIGUSR2, signal_usr);
        }
    }
    else if (player == 2) {
        while (message[1][16] == 2) {
            signal(SIGUSR1, signal_usr2);
            signal(SIGUSR2, signal_usr2);
        }
    }
}

char *binaries_16length(char *binary)
{
    while (my_strlen(binary) != 16)
        binary = my_strcat("0", binary);
    return (binary);
}
