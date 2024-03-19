/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** my_command
*/
#include "../header/minishell.h"

static int my_home(char **env)
{
    char *path;

    path = my_path_zone(env, "HOME");
    chdir(path);
    return 0;
}

static char **slash(char *input, char **env)
{
    if (my_strncmp(input, "/", 1) == 0) {
        chdir("/");
        return (my_getpwd(env));
    }
    return env;
}

static char *create_new_line(char *env, char *my_pwd)
{
    char *new_env;
    char current_pwd[30 * 1024];
    char *result;
    char *step;

    if (my_strncmp(env, "OLDPWD", 6) == 0) {
        result = (char *)malloc(my_strlen("OLDPWD=") + my_strlen(my_pwd) + 1);
        my_strcpy(result, "OLDPWD=");
        my_strcat(result, my_pwd);
        new_env = result;
    } else if (my_strncmp(env, "PWD", 3) == 0) {
        result = getcwd(current_pwd, 30 * 1024);
        step = (char *)malloc(my_strlen("PWD=") + my_strlen(result) + 1);
        my_strcpy(step, "PWD=");
        my_strcat(step, result);
        new_env = step;
    } else
        new_env = env;
    return new_env;
}

char **my_getpwd(char **env)
{
    char **new_env = malloc(sizeof(char *) * my_arraylen(env) + 1);
    char *my_pwd = my_path_zone(env, "PWD");
    int i = 0;

    for (; env[i]; i++)
        new_env[i] = create_new_line(env[i], my_pwd);
    new_env[i] = NULL;
    return new_env;
}

char **my_cd(int i, char *input, char **env)
{
    char *my_oldpwd = my_path_zone(env, "OLDPWD");

    if (i == 1) {
        my_home(env);
        return my_getpwd(env);
    }
    for (; *input != ' '; input++);
    for (; *input == ' '; input++);
    if (my_strncmp(input, "~", 1) == 0 || my_strncmp(input, "--", 2) == 0) {
        my_home(env);
        return (my_getpwd(env));
    }
    if (my_strcmp(input, "-") == 0) {
        chdir(my_oldpwd);
        return (my_getpwd(env));
    }
    env = slash(input, env);
    if (error_diectory(input) == 0)
        chdir(input);
    return env;
}

char **my_command(char *input, char **env)
{
    char **demand = NULL;
    char **new_env = NULL;
    int i = 0;

    if (input == NULL)
        return env;
    demand = my_str_to_word_array(input);
    for (; demand[i] != NULL; i++);
    if (my_strlen(input) >= 6 && (my_strcmp(demand[0], "unsetenv") == 0 ||
        my_strcmp(demand[0], "UNSETENV") == 0 ||
        my_strcmp(demand[0], "setenv") == 0 ||
        my_strcmp(demand[0], "SETENV") == 0))
        new_env = my_setenv(env, input);
    if (my_strncmp(demand[0], "cd", 2) == 0)
        return (my_cd(i, input, env));
    if (new_env == NULL)
        return env;
    return new_env;
}
