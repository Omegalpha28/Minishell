/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** struct
*/
#ifndef STRUCT_H_
    #define STRUCT_H_
    #define _X_OPEN_SOURCE 700
    #include <sys/types.h>

typedef struct args_s {
    char *arguments;
    struct args_s *next;
}args_t;

typedef struct env_s {
    pid_t my_pid;
    pid_t child_pid;
    int nb_args;
    int fork;
    int status;
    char *program_name;
    char **my_tab;
    args_t *args;
    int ending;
    char *input;
    char *oldpwd;
}env_t;

extern env_t *e;
extern int status;
extern char *my_command_echo;
extern int exit_status;

#endif
