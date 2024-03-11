/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** play_command
*/
#include "../header/minishell.h"

static int path_empty(char *path, char *full_path, char **env)
{
    if (path == NULL) {
        if (full_path == NULL)
            exit(errno);
        if (access(full_path, X_OK) == 0) {
            execve(full_path, e->my_tab, env);
            exit(errno);
        }
    }
    return 0;
}

int start_command(char **env)
{
    char *path = get_env(env, e->program_name);
    char *full_path = e->program_name;
    int p = fork();

    if (p < 0)
        return 0;
    else if (p == 0) {
        path_empty(path, full_path, env);
        execve(path, e->my_tab, env);
        exit(errno);
    } else {
        waitpid(-1, &status, 0);
        error_command(0);
    }
    return 0;
}
