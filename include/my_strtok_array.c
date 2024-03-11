/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** My strtok_array
*/
#include "../header/minishell.h"

static int my_char_isprintable(char str)
{
    int i = 0;

    if (str >= '!' && str <= '~')
        return 0;
    return 1;
}

static int word_counter_strtok(char *word, char del)
{
    int line = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == del);
            line++;
    }
    return line;
}

char **my_strtok_array(char *word, char del)
{
    char **array;
    int line = 0;
    int character = 0;

    word = skip_spaces(word);
    array = malloc(sizeof(char *) * word_counter_strtok(word, del));
    for (int j = 0; j < my_strlen(word); j++) {
        character = 0;
        array[line] = malloc(my_strlen(word) + 1);
        for (; my_char_isprintable(word[j]) == 0 && word[j] != del; j++) {
            array[line][character] = word[j];
            character++;
        }
        for (; word[j + 1] == ' '; j++);
        if (array[line][character - 1] != '\0')
            array[line][character] = '\0';
        line++;
    }
    array[line] = NULL;
    return array;
}
