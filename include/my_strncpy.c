/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** print strncpy
*/
#include "../header/minishell.h"

char *my_strncpy(char *dest, char const *str, int n)
{
    int step = 0;
    char result;

    while (step < n && str[step] != '\0') {
        dest[step] = str[step];
        step++;
    }
    if (step < n)
        dest[step] = '\0';
    return (dest);
}
