/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** counts the number of rows in a table
*/

#include "../header/minishell.h"

size_t walen(char **warray)
{
    size_t i = 0;

    for (; warray[i]; i++);
    return i;
}
