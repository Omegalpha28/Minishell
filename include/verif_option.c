/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** pipe functions
*/
#include "../header/minishell.h"

char **inspect_input(char *input, char **env, char **my_tab)
{
    if (input != NULL) {
        start_command(env);
        env = my_command(input, env);
    }
    my_get_all_line(my_tab, env);
    return env;
}

static int verif_semicolon(char *input)
{
    for (int i = 0; input[i]; i++) {
        if (input[i] == ';')
            return 0;
        if (input[i] == '\\' && input[i + 1] == 'n')
            return 0;
    }
    return 1;
}

static char *coding_style(char *resultat)
{
    if (resultat != NULL)
        resultat = skip_spaces(resultat);
    return resultat;
}

static char **comma_loop(char *input, char **env, char **my_tab)
{
    char *input_copy = my_strdup(input);
    char *resultat;
    char **tab = my_str_pipe_array(input_copy, ';');
    int i = 0;

    while (tab[i] != NULL) {
        resultat = malloc(sizeof(char) * my_strlen(tab[i]));
        resultat = tab[i];
        resultat = coding_style(resultat);
        e->input = resultat;
        modify_struct(my_str_to_word_array(resultat));
        env = add_pipe(resultat, env, tab);
        i++;
    }
    return env;
}

char **my_comma(char **my_tab, char **env, char *input)
{
    int have_semicolon = verif_semicolon(input);

    if (have_semicolon == 1) {
        modify_struct(my_tab);
        env = add_pipe(input, env, my_tab);
        return env;
    } else
        return (comma_loop(input, env, my_tab));
}
