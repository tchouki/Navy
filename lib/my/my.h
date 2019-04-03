/*
** EPITECH PROJECT, 2018
** project lib
** File description:
** my.h
*/

#ifndef MATCHSTICK_MY_H
#define MATCHSTICK_MY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	my_getnbr(char *const str);
void my_put_nbr(int nb);
char *get_next_line(int fd);
int my_putchar(char c);
char *my_strcat(char *const str1, char *const str2);
char *my_strcat_btw(char *const str1, char *const str2, char cara);
int my_strcmp(char const *str, char const *comp);
char *my_strdup(const char *str);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int nb);
char **str_to_tab(char *const str, char cara);
char **my_tabdup(char **tab);
int my_strncmp(char *s1, char *s2, int size);
char *my_strndup(const char *str, int size);
char **my_strconcat(char *str, char cara);
char **my_tabndup(char **tab, int start);
int my_putstr(char *str);
char *my_revstr(char *str);
int convert_base(char *str);
char *convert_binary(int value);

#endif
