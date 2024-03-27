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
    #include "lib.h"
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

void print_arg(char **arg, int who);
char **my_strtok_array(char *word, char delimiter);
char *get_env(char **env, char *filename);
int verif_exit(void);
int modify_struct(char **my_tab);
env_t *init_struct(char **tab, char **env, char *input);
char **my_cd(int i, char *input, char **env);
char **my_command(char *input, char **env);
char **my_setenv(char **env, char *input);
int start_command(char **env);
char *my_path_zone(char **env, const char *name);
int my_arraylen(char **tab);
char **my_getpwd(char **env);
char *skipstr(char *word, char delimiter);
int error_diectory(char *path);
int error_command(void);
char **my_comma(char **my_tab, char **env, char *input);
char **my_str_pipe_array(char *word, char del);
int my_get_all_line(char **my_tab, char **env);
char **add_tab(char *input, char **my_tab);
int my_char_is_alphanum(char const *input, char const *demand);
size_t walen(char **warray);
char **wacpy(char **tab);
int my_strncmp(char const *s1, char const *s2, int len);
char *my_strncpy(char *dest, char const *str, int n);
char **add_pipe(char *input, char **env, char **my_tab);
char *my_strndup(int begin, int end, char const *input);
char **inspect_input(char *input, char **env, char **my_tab);

#endif
