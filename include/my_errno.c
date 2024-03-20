/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** my_errno
*/
#include "../header/minishell.h"

static char *skip_spaces_after(char *input)
{
    char *result = malloc(sizeof(char) * my_strlen(input) + 1);
    int i = 0;

    for (; input[i] != '\0' && input[i] != ' '; i++)
        result[i] = input[i];
    if (result[i - 1] != '\0')
        result[i] = '\0';
    return result;
}

static int verif_cd(char *path)
{
    char *result;

    if (my_strncmp(e->my_tab[0], "cd", 2) == 0) {
        result = skip_spaces_after(path);
        chdir(result);
        return 1;
    }
    return 0;
}

int error_diectory(char *path)
{
    DIR *is_exist = opendir(path);

    if (verif_cd(path) == 1)
        return -1;
    if (is_exist || my_strncmp(e->my_tab[0], "setenv", 6) == 0 ||
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

int error_command(void)
{
    char *input = malloc(sizeof(char) * my_strlen(e->input) + 100);

    if (my_strncmp(e->my_tab[0], "setenv", 6) == 0 ||
        my_strncmp(e->my_tab[0], "unsetenv", 8) == 0)
        return 0;
    if (WIFEXITED(status)) {
        exit_status = WEXITSTATUS(status);
        if (exit_status == 14 && my_strcmp(e->my_tab[0], "cd") != 0) {
            exit_status = 1;
            my_strcat(input, "bash: ");
            my_strcat(input, e->input);
            write(2, e->input, my_strlen(e->input) - 1);
            write(2, ": Command not found.\n", 22);
        }
        exit_status = 0;
    }
    free(input);
    return 0;
}
