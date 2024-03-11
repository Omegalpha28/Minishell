/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** Verify if we kill the child processor or not
*/
#include "../header/minishell.h"
#include "../header/struct.h"

int verif_exit(void)
{
    if (my_strcmp(e->input, "exit") == 0 || my_strcmp(e->input, "EXIT") == 0) {
        e->ending = -1;
        exit(0);
    }
    return 0;
}
