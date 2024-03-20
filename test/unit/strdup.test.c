/*
** EPITECH PROJECT, 2024
** factory1
** File description:
** strdup.test
*/

#include "../../header/minishell.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect(void);

Test(my_strdup, copy_string, .init = redirect)
{
    const char *src = "hello";
    char *result = my_strdup(src);
    cr_assert_str_eq(result, src);
    free(result);
}

Test(my_strdup, copy_empty_string, .init = redirect)
{
    const char *src = "";
    char *result = my_strdup(src);
    cr_assert_str_eq(result, src);
    free(result);
}

Test(my_strdup, null_string, .init = redirect)
{
    char *result = my_strdup(NULL);
    cr_assert_null(result);
}

Test(my_strdup, long_string, .init = redirect)
{
    const char *src = "ThisIsALongString";
    char *result = my_strdup(src);
    cr_assert_str_eq(result, src);
    free(result);
}
