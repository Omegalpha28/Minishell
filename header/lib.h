/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** struct
*/
#ifndef LIB_H_
    #define LIB_H_
    #include <sys/types.h>

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
int my_strncmp(char const *s1, char const *s2, int len);
char **my_str_to_word_array(char *word);
char *my_strdup(char const *src);
size_t walen(char **warray);
char **wacpy(char **tab);

#endif