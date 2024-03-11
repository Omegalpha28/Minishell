/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** It's my main file
*/
#include "header/minishell.h"
#include "header/struct.h"

env_t *e;
int status;
char *my_command_echo;

static int free_all(char **my_tab, char *input, char **env)
{
    int size = my_arraylen(my_tab);

    free(input);
    for (; my_tab[size]; size++)
        free(my_tab[size]);
    for (size = 0; env[size]; size++)
        free(env[size]);
    return 0;
}

char *my_get_input(void)
{
    char *input = NULL;
    size_t input_size = 0;
    ssize_t characters_read = -1;

    if (isatty(STDIN_FILENO))
        characters_read = getline(&input, &input_size, stdin);
    if (characters_read > -1) {
        if (input[characters_read - 1] == '\n')
            input[characters_read - 1] = '\0';
        return input;
    } else
        return NULL;
}

static char **add_tab(char *input, char **my_tab)
{
    char **my_new_tab;

    if (input == NULL)
        return my_tab;
    my_new_tab = malloc(sizeof(char *) * (my_strlen(input)));
    if (my_new_tab == NULL)
        exit(EXIT_FAILURE);
    if (input != NULL) {
        e->input = my_strdup(input);
        my_new_tab = my_str_to_word_array(input);
        verif_exit();
        modify_struct(my_new_tab);
        return my_new_tab;
    }
    return NULL;
}

int my_loop(char **my_tab, char *input, char **env, int argc)
{
    int status = 100000;

    while (e->ending != -1) {
        input = my_get_input();
        if (input != NULL) {
            input = skip_spaces(input);
            my_tab = add_tab(input, my_tab);
            env = pipe_loop(my_tab, env, input);
        }
        if (!isatty(STDIN_FILENO) && input == NULL)
            break;
        wait(&status);
        print_arg(my_tab, 1);
    }
    return 0;
}

static char **verif_echo(char *input)
{
    ssize_t characters_read = -1;
    char **tab;
    size_t stat;

    if (!isatty(STDIN_FILENO)) {
        characters_read = getline(&input, &stat, stdin);
        tab = my_str_to_word_array(input);
    } else {
        tab = my_str_to_word_array("hello world");
        print_arg(tab, 1);
    }
    return tab;
}

int main(int argc, char *argv[], char **env)
{
    char **my_tab = NULL;
    char *input = NULL;
    int exit;

    if (argc >= 2) {
        for (int i = 1; i < 2; i++)
            my_tab = my_str_to_word_array(argv[i]);
    } else if (argc == 1)
        my_tab = verif_echo(input);
    init_struct(my_tab, env);
    my_loop(my_tab, input, env, argc);
    exit = status;
    return (exit);
}
