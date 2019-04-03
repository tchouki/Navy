/*
** EPITECH PROJECT, 2018
** navy
** File description:
** write
*/

#include "../include/navy.h"
#include <signal.h>

void writing(int x, int pid)
{
	attron(COLOR_PAIR(5));
    clear();
    printw("my_pid: ");
    printw("%d", pid);
    if (x)
        printw("\nwaiting for enemy connection...\n");
    if (!x)
        printw("\nsuccessfully connected\n");
    refresh();
}
