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
int exit_status;
enum state s;

static char **verif_echo(char *input, char **env)
{
    ssize_t characters_read = -1;
    char **tab;
    size_t stat;

    if (!isatty(STDIN_FILENO)) {
        characters_read = getline(&input, &stat, stdin);
        if (characters_read == 1)
            exit(0);
        if (input[characters_read - 1] == '\n')
            input[characters_read - 1] = '\0';
        tab = my_str_to_word_array(my_strdup(input));
        init_struct(tab, env, my_strdup(input));
    } else {
        tab = my_str_to_word_array("hello world");
        init_struct(tab, env, "hello world");
        print_arg(tab, 1);
    }
    return tab;
}

char **add_tab(char *input, char **my_tab)
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
        return my_new_tab;
    }
    return NULL;
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

int my_loop(char **my_tab, char *input, char **env)
{
    int time = 100000;

    while (e->ending != -1) {
        if (isatty(STDIN_FILENO))
            input = my_get_input();
        if (input != NULL)
            input = skip_spaces(input);
        if (input != NULL) {
            my_tab = add_tab(input, my_tab);
            env = add_pipe(input, env, my_tab);
        }
        if (!isatty(STDIN_FILENO) || (!isatty(STDIN_FILENO) && input == NULL))
            break;
        wait(&time);
        print_arg(my_tab, 1);
    }
    return 0;
}

int main(int argc, char *argv[], char *env[])
{
    char **my_tab = NULL;
    char *input = NULL;

    if (argc >= 2) {
        for (int i = 1; i < 2; i++)
            my_tab = my_str_to_word_array(argv[i]);
        init_struct(my_tab, env, my_strdup(my_tab[0]));
        print_arg(my_tab, 1);
    } else if (argc == 1) {
        my_tab = verif_echo(input, env);
        input = my_strdup(e->input);
    }
    my_loop(my_tab, input, env);
    return (exit_status);
}
