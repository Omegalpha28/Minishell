/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** print my_strncmp
*/
#include "../header/minishell.h"

int my_strncmp(char const *s1, char const *s2, int len)
{
    int step = 0;
    int state = 0;

    for (; (s1[step] != '\0' || s2[step] != '\0') && step < len; step++){
        state = 1;
        if (s2[step] != s1[step])
            return (s2[step] - s1[step]);
    }
    if (state == 1)
        return 0;
    return (s1[step] - s2[step]);
}
