/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** my_get_env
*/
#include "../header/minishell.h"

static char *concatenate_path(const char *full_path, const char *filename)
{
    char *full_path_copy = my_strdup(full_path);
    char *partieRestante = strtok(full_path_copy, "/");
    char *filename_copy = my_strdup(filename);
    char *resultat;

    while (partieRestante != NULL) {
        resultat = malloc(sizeof(char) * my_strlen(partieRestante));
        resultat = partieRestante;
        partieRestante = strtok(NULL, "/");
    }
    if (filename_copy[0] == '/')
        filename_copy++;
    if (my_strncmp(resultat, filename_copy, my_strlen(resultat)) == 0) {
        filename_copy = strtok(filename_copy, "/");
        filename_copy = strtok(NULL, "");
        return filename_copy;
    } else
        return filename_copy;
}

char *my_path_zone(char **env, const char *name)
{
    int len_path = my_strlen(name);

    for (char **e = env; *e != NULL; *e++) {
        if (my_strncmp(*e, name, len_path) == 0 && (*e)[len_path] == '=')
            return *e + len_path + 1;
    }
    return NULL;
}

static char *get_env_loop(char *path_copy, char *full_path, char *file_name)
{
    char **divided_path = my_strtok_array(path_copy, ':');
    int uno;
    int dos = my_strlen(file_name);

    for (int i = 0; divided_path[i]; i++) {
        uno = my_strlen(divided_path[i]);
        full_path = malloc(sizeof(char) * (uno + dos + 2));
        if (full_path == NULL)
            return NULL;
        my_strcpy(full_path, divided_path[i]);
        my_strcat(full_path, "/");
        my_strcat(full_path, concatenate_path(full_path, file_name));
        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }
        free(full_path);
    }
    return NULL;
}

char *get_env(char **env, char *file_name)
{
    char *path_zone = my_path_zone(env, "PATH");
    char *path_copy;
    char *full_path;

    if (path_zone == NULL)
        return NULL;
    path_copy = my_strdup(path_zone);
    return (get_env_loop(path_copy, full_path, file_name));
}
