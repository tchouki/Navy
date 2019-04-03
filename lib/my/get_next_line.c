/*
** EPITECH PROJECT, 2018
** project lib
** File description:
** get_next_line
*/

#include "my.h"
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *restart_str(char *str, int i)
{
    int j = 0;
    int i_cpy = i;
    char *end = NULL;

    if (i > 0 && str[i - 1] == '\0')
        return (NULL);
    for (; str[i_cpy] != '\0'; i_cpy++);
    if ((end = malloc(sizeof(char) * ((i_cpy - i) + 2))) == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++, j++)
        end[j] = str[i];
    end[j] = '\0';
    free(str);
    return (end);
}

char *my_realloc(char *str, char *buffer, int r_e)
{
    int i = 0;
    char *newstr = NULL;

    buffer[r_e] = '\0';
    if (str != NULL)
        for (;str[i] != '\0'; i++);
    if ((newstr = malloc(i + 50 + 1)) == NULL)
        return (NULL);
    if (str != NULL)
        for (int j = 0; str[j] != '\0'; j++)
            newstr[j] = str[j];
    for (int j = 0; buffer[j] != '\0'; j++, i++)
        newstr[i] = buffer[j];
    newstr[i] = '\0';
    free(str);
    return (newstr);
}

char *gnl_read(int fd, char *buffer, char *str)
{
    int r_e = 0;

    for (int i = 0; buffer != NULL && buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            return (str);
    }
    r_e = read(fd, buffer, 50);
    if (r_e == 0)
        return (str);
    if (r_e == -1)
        return (NULL);
    buffer[r_e] = '\0';
    str = my_realloc(str, buffer, r_e);
    if (r_e < 50)
        return (str);
    return (gnl_read(fd, buffer, str));
}

char *checker_str(int fd, char *buffer, char *str)
{
    if (fd < 0 || 50 == 0)
        return (NULL);
    if ((buffer = malloc(sizeof(char) * (50 + 1))) == NULL)
        return (NULL);
    buffer[0] = 0;
    str = gnl_read(fd, buffer, str);
    if (str == NULL)
        return (NULL);
    return (str);
}

char *get_next_line(int fd)
{
    static char *str = NULL;
    char *res = NULL, *buffer = NULL;
    int i = 0, a = 0;

    if ((str = checker_str(fd, buffer, str)) == NULL)
        return (NULL);
    for (a = 0; str[a] != '\n' && str[a] != '\0'; a++);
    if ((res = malloc(sizeof(char) * (a + 1))) == NULL)
        return (NULL);
    for (; str[i] != '\n' && str[i] != '\0'; i++)
        res[i] = str[i];
    res[i] = '\0';
    str = restart_str(str, i + 1);
    free(buffer);
    return (res);
}
