/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** add_pipe
*/
#include "../header/minishell.h"

static int count_pipe(char *input)
{
    int i = 0;
    int result = 0;

    for (; input[i] != '\0'; i++) {
        if (input[i] == '|' || input[i] == '>' || input[i] == '>>' ||
            input[i] == '<' || input[i] == '<<') {
            result++;
        }
    }
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

static int ending_state(char *input, int i, int end)
{
    if (input[i] == '|' || input[i] == '<' || input[i] == '>')
        for (; input[i] == '|' || input[i] == '<' || input[i] == '>'; i++);
    for (; input[i]; i++) {
        if (input[i] == '|' || input[i] == '<' || input[i] == '>')
            break;
        end++;
    }
    return end;
}

static int end_state(char *input, int i)
{
    int end = 0;
    int begin = i;

    if (input[i] == ' ' || input[i] == '\t')
        for (; input[i] == ' ' || input[i] == '\t'; i++);
    if (input[i + 1])
        end = ending_state(input, i, end);
    end += begin;
    return end;
}

static char *no_spaces(char *input)
{
    int size = my_strlen(input);

    if (input[size - 1] == ' ' || input[size - 1] == '\t') {
        for (; input[size - 1] == ' ' || input[size - 1] == '\t'; size--)
            input[size - 1] = '\0';
    }
    return input;
}

char *skip_spaces_t(char *word)
{
    if (*word == ' ' || *word == '\t' || *word == '|' || *word == '<' ||
        *word == '>') {
        while (*word == ' ' || *word == '\t' || *word == '|' || *word == '<' ||
        *word == '>')
            word++;
    }
    return word;
}

static pipe_t *init_pipe(char *input, int size, int begin, int end)
{
    pipe_t *p = malloc(sizeof(pipe_t) * size);
    int i = 0;
    int step = 0;

    for (; input[i]; i++) {
        if (input[i] != '|' && input[i] != '>' && input[i] != '<')
            continue;
        if (input[i + 1])
            p[step].s = my_state1(input, i);
        else
            p[step].s = my_state2(input, i);
        p[step].input = no_spaces(skip_spaces_t(my_strndup(begin, i, input)));
        end = end_state(input, i) + 1;
        p[step].next_input =
            no_spaces(skip_spaces_t(my_strndup(i, end, input)));
        begin = i;
        step++;
    }
    return p;
}

char **add_pipe(char *input, char **env, char **my_tab)
{
    int size = count_pipe(input);
    pipe_t *p;
    int i = 0;
    char **tab = NULL;

    if (size > 0) {
        p = init_pipe(input, size, 0, 0);
        while (i < size) {
            e->redirect = 1;
            tab = my_str_to_word_array(p[i].input);
            modify_struct(tab);
            inspect_input(p[i].input, env, tab);
            tab = my_str_to_word_array(p[i].next_input);
            modify_struct(tab);
            inspect_input(p[i].next_input, env, tab);
            i++;
        }
    } else
        inspect_input(input, env, my_tab);
    return env;
}
