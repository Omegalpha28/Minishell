/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** pipe functions
*/
#include "../header/minishell.h"

static char **inspect_input(char *input, char **env)
{
    if (input != NULL) {
        start_command(env);
        env = my_command(input, env);
    }
    return env;
}

char **pipe_loop(char **my_tab, char **env, char *input)
{
    env = inspect_input(input, env);
    return env;
}
