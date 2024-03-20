/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** my_numlen
*/
#include "../header/minishell.h"

int num_len(int n)
{
    int step = 0;

    if (n < 0) {
        step++;
        n *= -1;
    }
    if (n == 0)
        return (1);
    while (n > 1) {
        step++;
        n = n / 10;
    }
    return (step);
}
