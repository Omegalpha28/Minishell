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

    if (is_exist)
        return 0;
    else {
        write(2, e->my_tab[0], my_strlen(e->my_tab[0]));
        write(2, ": No such file or directory.\n", 30);
        return -1;
    }
}

int error_command(int num_input)
{
    char *input = malloc(sizeof(char) * my_strlen(e->input) + 40);
    int exit_status;

    my_strcat(input, "bash: ");
    my_strcat(input, e->input);
    if (WIFEXITED(status)) {
        exit_status = WEXITSTATUS(status);
        if (exit_status == 14 && my_strcmp(e->my_tab[0], "cd") != 0) {
            write(2, e->input, my_strlen(e->input));
            write(2, ": Command not found.\n", 20);
        }
    }
    free(input);
    return 0;
}
