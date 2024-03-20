/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** my_str_to_word_array
*/
#include "../header/minishell.h"

static int my_char_isprintable(char str)
{
    int i = 0;

    if (str >= '!' && str <= '~')
        return 0;
    return 1;
}

static int word_counter(char *word)
{
    int line = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == ' ')
            line++;
    }
    return line;
}

char *skip_spaces(char *word)
{
    char *result = malloc(sizeof(char) * my_strlen(word));

    if (*word == ' ' || *word == '\t') {
        while (*word == ' ' || *word == '\t')
            word++;
    }
    return word;
}

static int coding_style(char *word, int j)
{
    if (word[j] == ' ' || word[j] == '\t')
        for (; (!(word[j + 1] != ' ' && word[j + 1] != '\t')); j++);
    return j;
}

static int compare(int j, char *word)
{
    if (my_char_isprintable(word[j]) == 0 && word[j] != ' ' && word[j] != '\t')
        return 0;
    return 1;
}

char **my_str_to_word_array(char *word)
{
    char **array;
    int line = 0;
    int character = 0;

    skip_spaces(word);
    array = malloc(sizeof(char *) * word_counter(word) + 1);
    for (int j = 0; j < my_strlen(word); j++) {
        character = 0;
        array[line] = malloc(sizeof(char) * my_strlen(word) + 1);
        for (; compare(j, word) == 0; j++) {
            array[line][character] = word[j];
            character++;
        }
        j = coding_style(word, j);
        if (array[line][character - 1] != '\0')
            array[line][character] = '\0';
        line++;
    }
    array[line] = NULL;
    return array;
}
