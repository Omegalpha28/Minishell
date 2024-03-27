/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** add_pipe
*/
#include "../header/minishell.h"

static int my_char_isprintable(char str)
{
    if (str >= '!' && str <= '~')
        return 0;
    return 1;
}

static int count_pipe(char *input)
{
    int i = 0;
    int result = 0;

    for (; input[i]; i++) {
        if (input[i] == '|' || input[i] == '>' || input[i] == '>>' ||
            input[i] == '<' || input[i] == '<<') {
            result++;
        }
    }
    return result;
}

static char *my_strndup(int begin, int end, char const *input)
{
    char *result;
    int i = 0;

    if (!(input != NULL && ((begin > end) || end == -1)
        && my_char_isprintable(input[begin]) != 0))
        return NULL;
    result = malloc(sizeof(char) * (end - begin + 1));
    if (end == -1) {
        for (begin; input[begin]; begin++) {
            result[i] = input[begin];
            i++;
        }
    } else {
        for (begin; begin != end && input[begin]; begin++) {
            result[i] = input[begin];
            i++;
        }
    }
    result[i] = '\0';
    return result;
}

static enum state my_state1(char *input, int i)
{
    if (input[i] == '>' && input[i + 1] == '>')
        return (redirect_VV);
    if (input[i] == '<' && input[i + 1] == '<')
        return (redirect_AA);
    if (input[i] == '|' && (i == 0 || i > 0 && input[i - 1] != '|'))
        return (pipes);
    if (input[i] == '>' && (i == 0 || i > 0 && input[i - 1] != '>'))
        return (redirect_V);
    if (input[i] == '<' && (i == 0 || i > 0 && input[i - 1] != '<'))
        return (redirect_A);
    return nope;
}

static enum state my_state2(char *input, int i)
{
    if (input[i] == '|' && (i == 0 || i > 0 && input[i - 1] != '|'))
        return (pipes);
    if (input[i] == '>' && (i == 0 || i > 0 && input[i - 1] != '>'))
        return (redirect_V);
    if (input[i] == '<' && (i == 0 || i > 0 && input[i - 1] != '<'))
        return (redirect_A);
    return nope;
}

static int begin_state(char *input, int i)
{
    int begin = 0;

    if ((input[i] == '>' && input[i + 1] == '>') ||
        (input[i] == '<' && input[i + 1] == '<'))
        begin += 2;
    else if ((input[i] == '|' && input[i - 1] != '|') ||
        input[i] == '>' && (i == 0 || i > 0 && input[i - 1] != '>') ||
        (input[i] == '<' && (i == 0 || i > 0 && input[i - 1] != '<')))
        begin++;
    begin += i;
    return begin;
}

static pipe_t *init_pipe(char *input, int size)
{
    pipe_t *p = malloc(sizeof(pipe_t) * size);
    int i = 0;
    int step = 0;
    int begin = 0;

    for (; input[i]; i++) {
        if (input[i] != '|' && input[i] != '>' && input[i] != '<')
            continue;
        if (input[i + 1])
            p[step].s = my_state1(input, i);
        else
            p[step].s = my_state2(input, i);
        if (p[step].s == nope)
            continue;
        p[step].input = my_strndup(begin, i, input);
        p[step].next_input = my_strndup(i, -1, input);
        begin = begin_state(input, i);
        step++;
    }
    return p;
}

char **add_pipe(char *input, char **env, char **my_tab)
{
    int size = count_pipe(input);
    pipe_t *p;
    int i = 0;

    my_put_nbr(size);
    if (size > 0) {
        p = init_pipe(input, size);
        while (i < size) {
            e->redirect = 1;
            my_comma(my_tab, env, p[i].input);
            my_putstr(p[i].input);
            my_comma(my_tab, env, p[i].next_input);
            my_putstr(p[i].next_input);
            my_putstr("ok");
            i++;
        }
    } else
        my_comma(my_tab, env, input);
    return env;
}