/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** my_char_is_alphanum
*/

#include "../header/minishell.h"

int my_char_is_alphanum(char const *input, char const *demand)
{
    exit_status = 1;
    for (int i = 0; input[i]; i++) {
        if (!((input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= '0' && input[i] <= '9'))) {
            write(2, my_strdup(demand), my_strlen(my_strdup(demand)));
            write(2, ": Variable name must ", 21);
            write(2, "contain alphanumeric characters.\n", 33);
            return -1;
        }
    }
    return 0;
}
