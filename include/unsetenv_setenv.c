/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** unsetenv and setenv
*/
#include "../header/minishell.h"

int my_arraylen(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return i;
}

static char *char_to_int(int num)
{
    char *result = (char *)malloc(2);

    result[0] = '0' + num;
    result[1] = '\0';
    return result;
}

static int verif_setenv(char **env, char **demand)
{
    int step = 0;
    int size = my_arraylen(demand);

    if (size == 1) {
        print_arg(env, 0);
        return 69;
    }
    if (size > 3) {
        strerror(E2BIG);
        return 69;
    }
    while (step < 10) {
        if (my_strncmp(demand[1], char_to_int(step), 1) == 0) {
            strerror(EINVAL);
            return 69;
        }
        step++;
    }
    return 0;
}

static char **malloc_new_env( int step, char **new_env, char **demand)
{
    char *name;
    char *value;

    if (my_arraylen(demand) == 3) {
        value = demand[2];
        name = malloc(sizeof(char) * my_strlen(value) + my_strlen(demand[1]));
        my_strcpy(name, demand[1]);
        my_strcat(name, "=");
        my_strcat(name, value);
        new_env[step] = malloc(sizeof(char) * my_strlen(name));
    } else {
        name = malloc(sizeof(char) * my_strlen(demand[1]) + 1);
        my_strcpy(name, demand[1]);
        my_strcat(name, "=");
        new_env[step] = malloc(sizeof(char) * my_strlen(demand[1]) + 1);
    }
    new_env[step] = name;
    new_env[step + 1] = NULL;
    return new_env;
}

static char **set_env(char **env, char **demand)
{
    char **new_env = malloc(sizeof(char *) * my_arraylen(env) + 1);
    int step = 0;

    if (verif_setenv(env, demand) == 69)
        return env;
    for (; env[step]; step++) {
        new_env[step] = malloc(sizeof(char *) * my_strlen(env[step]));
        new_env[step] = env[step];
    }
    return malloc_new_env(step, new_env, demand);
}

static char **unset_env(char **env, char **demand)
{
    char **new_env = malloc(sizeof(char *) * my_arraylen(env));
    int where = 0;

    for (int step = 0; env[step]; step++) {
        if (my_strncmp(demand[1], env[step], my_strlen(demand[1])) != 0) {
            new_env[where] = malloc(sizeof(char *) * my_strlen(env[step]));
            new_env[where] = env[step];
            where++;
        }
    }
    new_env[where] = NULL;
    return new_env;
}

char **my_setenv(char **env, char *input)
{
    char **demand;
    int size = 0;

    if (input == NULL)
        return env;
    demand = my_str_to_word_array(input);
    for (; demand[size]; size++);
    if (size == 1 && (my_strcmp(demand[0], "unsetenv") == 0 ||
        my_strcmp(demand[0], "UNSETENV") == 0)) {
        free(demand);
        return env;
    }
    if (my_strcmp(demand[0], "unsetenv") == 0 ||
        my_strcmp(demand[0], "UNSETENV") == 0)
        return unset_env(env, demand);
    if (my_strcmp(demand[0], "setenv") == 0 ||
        my_strcmp(demand[0], "SETENV") == 0)
        return set_env(env, demand);
    return env;
}
