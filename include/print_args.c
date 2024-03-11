/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** Print arguments given
*/
#include "../header/minishell.h"

void print_arg(char **arg, int who)
{
    if (who == 0) {
        while (*arg) {
            my_putstr(*arg);
            my_putchar('\n');
            arg++;
        }
    } else
        my_putstr("$>");
}
