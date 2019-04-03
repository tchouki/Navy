/*
** EPITECH PROJECT, 2018
** navy
** File description:
** start of the two player
*/

#include "../include/navy.h"
#include <signal.h>

void kill_binary(char *binary, int pid)
{
    int i = my_strlen(binary) - 1;
    int tmp = 0;

    for (; i >= 0; i--) {
        tmp = binary[i] - '0';
        if (tmp == 0)
            kill(pid, SIGUSR1);
        if (tmp == 1)
            kill(pid, SIGUSR2);
        usleep(100);
    }
}

int player_one(char *name_map)
{
    int pid = getpid();
    char *binary = NULL;
    int pid_plyer_two = 0;

    message[0][0] = '\0';
    for (int i = 1; i < 17; i++)
        message[0][i] = 2;
    writing(1, pid);
    signal_catcher(1);
    pid_plyer_two = convert_base(my_revstr(message[0]));
    binary = convert_binary(pid);
    binary = binaries_16length(binary);
    usleep(100);
    kill_binary(binary, pid_plyer_two);
    create_map(name_map, pid_plyer_two, 1);
    return (0);
}

int player_two(int plyr_one_pid, char *name_map)
{
    int pid = getpid();
    char *binary = NULL;

    message[1][0] = '\0';
    for (int i = 1; i < 17; i++)
        message[1][i] = 2;
    writing(0, pid);
    refresh();
    binary = convert_binary(pid);
    binary = binaries_16length(binary);
    usleep(100);
    kill_binary(binary, plyr_one_pid);
    signal_catcher(2);
    refresh();
    if (convert_base(my_revstr(message[1])) == plyr_one_pid)
        create_map(name_map, plyr_one_pid, 2);
    else
        return (84);
    return (0);
}
