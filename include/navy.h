/*
** EPITECH PROJECT, 2018
** navy
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../lib/my/my.h"

char message[2][17];

//attack.c
char **check_hit(char **tab, int pos_x, int pos_y, int pid_enemy);
char **enemy_attack(char **tab, int pid_enemy, int x);
char **check_hit_done_player1(char **enemy_tab, char *pos, int x);
char **check_hit_done_player2(char **enemy_tab, char *pos, int x);
char **attack(char **tab, char **enemy_tab, int pid_player_two, int x);

//binaries.c
void signal_usr2(int sig);
void signal_usr(int sig);
void signal_catcher(int player);
char *binaries_16length(char *binary);

//create_tab.c
char **set_boat(char **tab, char *file, int lign, int i);
char **create_tab_empty(void);
char **create_tab(char *file);

//file_and_map.c
int check_diff(char size_c, char x_c, char y_c);
int check_file2(char **tab);
int check_file(char *file);
int create_map(char *, int pid_player_two, int x);

//game.c
int check_end(char **tab, char **enemy_tab);
int clear_message(void);
void print_all(char **tab, char **enemy_tab);
int game_loop(char **tab, char **enemy_tab, int pid_enemy, int x);

//main.c
int print_help(void);
int main(int argc, char **argv);

//player_entry.c
char *check_error(char *name_map);
void kill_binary(char *binary, int pid);
int player_one(char *name_map);
int player_two(int plyr_one_pid, char *name_map);

//write.c
void display_line(char **tab, int x);
void print_map(char **tab);
void writing(int bool, int pid);

#endif
