/*
** EPITECH PROJECT, 2018
** navy
** File description:
** main.c
*/

#include "../include/navy.h"

int print_help(WINDOW *win)
{
	int c = 0;

	attron(COLOR_PAIR(5));
	clear();
	printw("USAGE\n");
	printw("\t./navy [first_player_pid] navy_positions\n");
	printw("DESCRIPTION\n");
	printw("\tfirst_player_pid: only for the 2nd player.");
	printw(" pid of the first player.\n");
	printw("\tnavy_positions: file representing the positions");
	printw(" of the ships.\n");
	attron(COLOR_PAIR(6));
	printw("\n\nPRESS SPACE TO EXIT\n");
	refresh();
	while (c != ' ')
		c = wgetch(win);
	endwin();
	system("stty -raw && stty echo && stty onlcr");
	return (0);
}

void init_all_color(void)
{
	start_color();

    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_RED, COLOR_RED);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_RED, COLOR_BLACK);
    init_pair(7, COLOR_GREEN, COLOR_BLACK);
}

int main(int argc, char **argv)
{
	WINDOW *win;

	initscr();
	clear();
	noecho();
	cbreak();
	win = newwin(10, 30, (24 - 10) / 2, (80 - 30) / 2);
	keypad(win, TRUE);
	refresh();
	curs_set(0);
	init_all_color();
	if (argc == 1) {
		endwin();
		system("stty -raw && stty echo && stty onlcr");
		return (84);
	}
	if (argv[1][0] == '-' && argv[1][1] == 'h')
		return (print_help(win));
	if (argc == 2)
	    return (player_one(my_strdup(argv[1])));
	if (argc == 3 || (argc == 4 && argv[4][0] == '-' || argv[4][1] == 'i'))
	    return (player_two(my_getnbr(argv[1]), my_strdup(argv[2])));
	endwin();
	system("stty -raw && stty echo && stty onlcr");
	return (0);
}
