/*
** EPITECH PROJECT, 2018
** navy
** File description:
** start of the two player
*/

#include "../include/navy.h"
#include <signal.h>

char *check_error(char *name_map)
{
    int fd = open(name_map, O_RDONLY);
    char *buf = malloc(sizeof(char) * 33);
    int ret;

    if (fd == -1)
        return (NULL);
    ret = read(fd, buf, 32);
    buf[32] = '\0';
    // if (check_file(buf) != 0 || ret == -1)
    //     return (NULL);
    close(fd);
    return (buf);
}

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
        usleep(1000);
    }
}

int player_one(char *name_map)
{
    int pid = getpid();
    char *binary = NULL;
    int pid_plyer_two = 0;
    char *buffer;

    if ((buffer = check_error(name_map)) == NULL)
        return (84);
    message[0][0] = '\0';
    for (int i = 1; i < 17; i++)
        message[0][i] = 2;
    writing(1, pid);
    signal_catcher(1);
    pid_plyer_two = convert_base(my_revstr(message[0]));
    binary = convert_binary(pid);
    binary = binaries_16length(binary);
    usleep(1000);
    kill_binary(binary, pid_plyer_two);
    write(1, "\nenemy connected\n", 17);
    return (create_map(buffer, pid_plyer_two, 1));
}

int player_two(int plyr_one_pid, char *name_map)
{
    int pid = getpid();
    char *binary = NULL;
    char *buffer = NULL;

    if ((buffer = check_error(name_map)) == NULL)
        return (84);
    message[1][0] = '\0';
    for (int i = 1; i < 17; i++)
        message[1][i] = 2;
    writing(0, pid);
    binary = convert_binary(pid);
    binary = binaries_16length(binary);
    usleep(1000);
    kill_binary(binary, plyr_one_pid);
    signal_catcher(2);
    if (convert_base(my_revstr(message[1])) == plyr_one_pid)
        return (create_map(buffer, plyr_one_pid, 2));
    else
        return (84);
    return (0);
}
