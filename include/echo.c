/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** echo
*/
#include "../header/minishell.h"

int my_get_all_line(char **my_tab, char **env)
{
    ssize_t characters_read = -1;
    char *input = NULL;
    size_t stat;

    if (!isatty(STDIN_FILENO)) {
        characters_read = getline(&input, &stat, stdin);
        if (characters_read <= 1)
            return 0;
        if (input[characters_read - 1] == '\n')
            input[characters_read - 1] = '\0';
        if (input != NULL)
            input = skip_spaces(input);
        if (input != NULL && my_strncmp(input, e->input,
            my_strlen(e->input)) != 0) {
            my_tab = add_tab(input, my_tab);
            env = my_comma(my_tab, env, input);
        }
    }
    return 0;
}
