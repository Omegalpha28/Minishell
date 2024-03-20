/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** my_putstr
*/
#include "../header/minishell.h"

int my_putstr(char const *str)
{
    int step = 0;

    while (str[step] != '\0') {
        write(1, &str[step], 1);
        step++;
    }
    return (step);
}
