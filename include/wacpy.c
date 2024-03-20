/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** cpy my array
*/
#include "../header/minishell.h"

char **wacpy(char **tab)
{
    ssize_t size = walen(tab);
    char **array = malloc(sizeof(char *) * size);
    int line = 0;
    int character = 0;

    for (; line < size; line++) {
        character = 0;
        array[line] = malloc(sizeof(char) * my_strlen(tab[line]) + 1);
        while (tab[line][character] != '\n' && tab[line][character] != '\0') {
            array[line][character] = tab[line][character];
            character++;
        }
        if (array[line][character - 1] != '\0')
            array[line][character] = '\0';
    }
    array[line] = NULL;
    return array;
}
