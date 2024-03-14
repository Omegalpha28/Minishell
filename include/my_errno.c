/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** my_errno
*/
#include "../header/minishell.h"

int error_diectory(char *path)
{
    DIR *is_exist = opendir(path);

    if (is_exist || my_strncmp(e->my_tab[0], "setenv", 6) == 0||
        my_strncmp(e->my_tab[0], "unsetenv", 8) == 0)
        return 0;
    else {
        if (open(path, O_RDONLY) == -1) {
            write(2, path, my_strlen(path));
            write(2, ": No such file or directory.\n", 30);
        } else {
            write(2, path, my_strlen(path));
            write(2, ": Not a directory.\n", 20);
        }
        return -1;
    }
}

int error_command(int num_input)
{
    char *input = malloc(sizeof(char) * my_strlen(e->input) + 40);
    int exit_status;

    my_strcat(input, "bash: ");
    my_strcat(input, e->input);
    if (my_strncmp(e->my_tab[0], "setenv", 6) == 0 ||
        my_strncmp(e->my_tab[0], "unsetenv", 8) == 0)
        return 0;
    if (WIFEXITED(status)) {
        exit_status = WEXITSTATUS(status);
        if (exit_status == 14 && my_strcmp(e->my_tab[0], "cd") != 0) {
            write(2, e->input, my_strlen(e->input));
            write(2, ": Command not found.\n", 22);
        }
    }
    free(input);
    return 0;
}
