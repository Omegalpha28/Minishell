/*
** EPITECH PROJECT, 2024
** factory1
** File description:
** strcpy.test
*/

#include "../../header/minishell.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect(void);

Test(my_strcpy, copy_string, .init = redirect)
{
    char dest[10];
    const char *src = "hello";
    char *result = my_strcpy(dest, src);
    cr_assert_str_eq(result, src);
}

Test(my_strcpy, copy_empty_string, .init = redirect)
{
    char dest[10] = "existing";
    const char *src = "";
    char *result = my_strcpy(dest, src);
    cr_assert_str_eq(result, src);
}

Test(my_strcpy, copy_to_empty_string, .init = redirect)
{
    char dest[1] = "";
    const char src[] = "hello";
    char *result = my_strcpy(dest, src);
    char *none = strcpy(dest, src);
    cr_assert(result == none);
}

Test(my_strcpy, null_destination, .init = redirect)
{
    const char *src = "world";
    char *result = my_strcpy(NULL, src);
    cr_assert_null(result);
}

Test(my_strcpy, null_source, .init = redirect)
{
    char dest[1] = "";
    char *result = my_strcpy(dest, NULL);
    cr_assert(result == dest);
}
