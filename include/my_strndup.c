/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** my_strndup
*/
#include "../header/minishell.h"

static int my_char_isprintable(char str)
{
    if (str >= '!' && str <= '~')
        return 0;
    return 1;
}

static char *my_result(char *result, char const *input, int begin, int step)
{
    int i = 0;

    if (input[0] == ' ' || input[0] == '\t')
        for (; input[i] == ' ' || input[i] == '\t'; i++);
    for (; input[step]; step++);
    result = malloc(my_strlen(input) - step + 1);
    for (; input[begin]; begin++) {
        result[i] = input[begin];
        i++;
    }
    result[i] = '\0';
    return result;
}

static char *coding_styles(char *input, int begin, int end, int step)
{
    int i = 0;
    char *result = NULL;

    if (input[0] == ' ' || input[0] == '\t')
        for (; input[i] == ' ' || input[i] == '\t'; i++);
    for (; step < end; step++);
    result = malloc(step + 1);
    for (; begin < end; begin++) {
        result[i] = input[begin];
        i++;
    }
    result[i] = '\0';
    return result;
}

char *my_strndup(int begin, int end, char const *input)
{
    int i = 0;
    int step = begin;
    char *result = NULL;

    if (!(input != NULL && ((begin < end) || end == -1)
        && my_char_isprintable(input[begin]) == 0))
        return NULL;
    if (end > -1)
        result = coding_styles(input, begin, end, step);
    else if (end == -1)
        result = my_result(result, input, begin, step);
    return result;
}
