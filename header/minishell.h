/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** struct
*/
#ifndef MINISHELL_H_
    #define MINISHELL_H_
    #define BUFFER_SIZE 100000
    #include "struct.h"
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <dirent.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <errno.h>
    #include <signal.h>
    #include <fcntl.h>

char my_putchar(char a);
char *skip_spaces(char *word);
int my_putstr(char const *str);
int num_len(int n);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char const *str, int n);
char *my_strcpy(char *dest, char const *str);
char *my_strcat(char *dest, char const *src);
void print_arg(char **arg, int who);
int my_strncmp(char const *s1, char const *s2, int len);
char **my_strtok_array(char *word, char delimiter);
char **my_str_to_word_array(char *word);
char *get_env(char **env, char *filename);
char *my_strdup(char const *src);
int verif_exit(void);
int modify_struct(char **my_tab);
env_t *init_struct(char **tab, char **env, int who, char *input);
char **my_cd(int i, char *input, char **env);
char **my_command(char *input, char **env);
char **my_setenv(char **env, char *input);
int start_command(char **env);
char *my_path_zone(char **env, const char *name);
int my_arraylen(char **tab);
char **my_getpwd(char **env);
char *skipstr(char *word, char delimiter);
int error_diectory(char *path);
int error_command(int num_input);
char **my_comma(char **my_tab, char **env, char *input);
#endif
