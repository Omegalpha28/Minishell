/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** my_str_pipe_array
*/

#include "../header/minishell.h"

static int my_char_isprintable(char str)
{
    int i = 0;

    if (str >= '!' && str <= '~')
        return 0;
    return 1;
}

static int back_zero(int j, char *word)
{
    char verif = word[j];

    if (my_char_isprintable(verif) == 0)
        if (word[j] == '\\' && word[j + 1] == 'n')
            return 0;
    return 1;
}

static int word_counter_strtok(char *word, char del)
{
    int line = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == del || back_zero(i, word) == 0);
            line++;
    }
    return line;
}

static int coding_style(char *word, int j)
{
    if (back_zero(j, word) == 0)
        j += 1;
    if (word[j] == ' ' || word[j] == '\t')
        for (; word[j] == ' ' || word[j] == '\t'; j++);
    return j;
}

static int compare(int j, char *word, char del)
{
    if (word[j] == ' ' || my_char_isprintable(word[j]) == 0 &&
        word[j] != del && back_zero(j, word) == 1)
        return 0;
    return 1;
}

char **my_str_pipe_array(char *word, char del)
{
    char **array;
    int line = 0;
    int character = 0;

    word = skip_spaces(word);
    array = malloc(sizeof(char *) * word_counter_strtok(word, del));
    for (int j = 0; j < my_strlen(word); j++) {
        character = 0;
        array[line] = malloc(my_strlen(word) + 1);
        for (; compare(j, word, del) == 0; j++) {
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
