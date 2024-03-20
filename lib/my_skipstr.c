/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** my_skipstr
*/
#include "../header/minishell.h"

char *skipstr(char *word, char delimiter)
{
    while (*word != delimiter && *word != '\0')
        word++;
    if (*word == '\n')
        word++;
    return word;
}
