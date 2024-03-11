/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** print my_strcpy
*/
#include "../header/minishell.h"

char *my_strcpy(char *dest, char const *str)
{
    int siu = 0;

    while (str[siu] != '\0') {
        dest[siu] = str[siu];
        siu++;
    }
    dest[siu] = '\0';
    return (dest);
}
