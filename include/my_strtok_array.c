/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** My strtok_array
*/
#include "../header/minishell.h"

static int my_char_isprintable(char str)
{
    if (str >= '!' && str <= '~')
        return 0;
    return 1;
}

static int word_counter_strtok(char *word, char del)
{
    int line = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == del)
            line++;
    }
    return line;
}

static int coding_style(char *word, int j)
{
    if (word[j] == ' ')
        for (; word[j + 1] == ' '; j++);
    return j;
}

static int compare(int j, char *word, char del)
{
    if (word[j] == ' ' || my_char_isprintable(word[j]) == 0 && word[j] != del)
        return 0;
    return 1;
}

char **my_strtok_array(char *word, char del)
{
    char **array;
    int line = 0;
    int character = 0;

    word = skip_spaces(word);
    if (word == NULL)
        return NULL; // Gestion de l'erreur si skip_spaces renvoie NULL.

    array = malloc(sizeof(char *) * (word_counter_strtok(word, del) + 2));  // +2 pour le dernier mot + NULL
    if (array == NULL)
        return NULL; // Gestion de l'échec de malloc.

    for (int j = 0; j < my_strlen(word) && word[j] != '\0'; j++) {
        character = 0;
        array[line] = malloc(my_strlen(word)); // Peut-être ajuster la taille ici en fonction du mot.
        if (array[line] == NULL)
            return NULL; // Gestion de l'échec de malloc.

        for (; j < my_strlen(word) && compare(j, word, del) == 0; j++) {
            array[line][character] = word[j];
            character++;
        }
        j = coding_style(word, j);

        array[line][character] = '\0'; // Assurez-vous que la chaîne est terminée par '\0'.
        line++;
    }
    array[line] = NULL; // Terminer l'array avec NULL.
    return array;
}
