/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** Initialize and modify structs
*/
#include "../header/minishell.h"

env_t *init_struct(char **tab, char **env, char *input)
{
    args_t *args = malloc(sizeof(args_t));
    int i = 0;

    e = malloc(sizeof(env_t));
    for (; tab[i]; i++)
        args->arguments = tab[i];
    e->my_pid = getpid();
    e->child_pid = 0;
    e->nb_args = i - 1;
    e->program_name = tab[0];
    e->status = 0;
    e->args = args;
    e->my_tab = tab;
    e->ending = 0;
    e->input = my_strdup(input);
    e->oldpwd = my_path_zone(env, "OLDPWD");
    e->redirect = 0;
    return e;
}

int modify_struct(char **my_tab)
{
    e->my_tab = my_tab;
    e->program_name = my_tab[0];
    return 0;
}
