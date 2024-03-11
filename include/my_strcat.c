/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** print strcat
*/
#include "../header/minishell.h"

char *my_strcat(char *dest, char const *src)
{
    int long2 = 0;
    int step = 0;

    while (dest[long2])
        long2++;
    while (src[step] != '\0') {
        dest[long2 + step] = src[step];
        step++;
    }
    dest[long2 + step] = '\0';
    return (dest);
}
