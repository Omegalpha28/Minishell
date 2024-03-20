/*
** EPITECH PROJECT, 2024
** factory1
** File description:
** strcat.test
*/

#include "../../header/minishell.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect(void);

Test(my_strcat, basic_concatenation)
{
    char dest[20] = "Hello, ";
    char src[] = "world!";
    char *result = my_strcat(dest, src);

    cr_assert_str_eq(result, "Hello, world!");
}

Test(my_strcat, empty_source)
{
    char dest[20] = "Hello, ";
    char src[] = "";
    char *result = my_strcat(dest, src);

    cr_assert_str_eq(result, "Hello, ");
}

Test(my_strcat, empty_destination)
{
    char dest[20] = "";
    char src[] = "world!";
    char *result = my_strcat(dest, src);

    cr_assert_str_eq(result, "world!");
}

Test(my_strcat, both_empty)
{
    char dest[20] = "";
    char src[] = "";
    char *result = my_strcat(dest, src);

    cr_assert_str_empty(result);
}

Test(my_strcat, large_destination)
{
    char *dest = (char *)malloc(100 * sizeof(char));
    my_strcpy(dest, "Hello, ");
    char src[] = "world!";
    char *result = my_strcat(dest, src);

    cr_assert_str_eq(result, "Hello, world!");

    free(dest);
}

Test(my_strcat, null_destination)
{
    char *src = "world!";
    char *result = my_strcat(NULL, src);

    cr_assert_null(result);
}

Test(my_strcat, null_source)
{
    char *dest = my_strdup("world!");
    char *result = my_strcat(dest, NULL);
    cr_assert_str_eq(dest, "world!");
    cr_assert_eq(result, dest);
    free(dest);
}
