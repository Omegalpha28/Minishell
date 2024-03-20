/*
** EPITECH PROJECT, 2024
** factory1
** File description:
** strcmp.test
*/

#include "../../header/minishell.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect(void);

Test(my_strcmp, identical_strings, .init = redirect)
{
    const char *s1 = "hello";
    const char *s2 = "hello";
    int result = my_strcmp(s1, s2);
    cr_assert_eq(result, 0);
}

Test(my_strcmp, different_strings, .init = redirect)
{
    const char *s1 = "hello";
    const char *s2 = "world";
    int result = my_strcmp(s1, s2);
    cr_assert_neq(result, 0);
}

Test(my_strcmp, s1_shorter_than_s2, .init = redirect)
{
    const char *s1 = "hi";
    const char *s2 = "hello";
    int result = my_strcmp(s1, s2);
    cr_assert_neq(result, 0);
}

Test(my_strcmp, s1_longer_than_s2, .init = redirect)
{
    const char *s1 = "hello";
    const char *s2 = "hi";
    int result = my_strcmp(s1, s2);
    cr_assert_neq(result, 0);
}

Test(my_strcmp, s1_empty, .init = redirect)
{
    const char *s1 = "";
    const char *s2 = "world";
    int result = my_strcmp(s1, s2);
    cr_assert_neq(result, 0);
}

Test(my_strcmp, s2_empty, .init = redirect)
{
    const char *s1 = "hello";
    const char *s2 = "";
    int result = my_strcmp(s1, s2);
    cr_assert_neq(result, 0);
}

Test(my_strcmp, both_empty, .init = redirect)
{
    const char *s1 = "";
    const char *s2 = "";
    int result = my_strcmp(s1, s2);
    cr_assert_eq(result, 0);
}
