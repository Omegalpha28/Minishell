/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** print char
*/
#include "../header/minishell.h"

char my_putchar(char a)
{
    write(1, &a, 1);
}
