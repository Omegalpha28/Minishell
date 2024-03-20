/*
** EPITECH PROJECT, 2024
** factory
** File description:
** my_str_to_word_array.test
*/

#include "../../header/minishell.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect(void);

Test(my_str_to_word_array, single_word)
{
    char str[] = "Hello";
    char **wa = my_str_to_word_array(str);

    cr_assert_str_eq(wa[0], "Hello");
}

Test(my_str_to_word_array, multiple_words)
{
    char str[] = "Hello this is a test";
    char **wa = my_str_to_word_array(str);

    cr_assert_str_eq(wa[0], "Hello");
    cr_assert_str_eq(wa[1], "this");
    cr_assert_str_eq(wa[2], "is");
    cr_assert_str_eq(wa[3], "a");
    cr_assert_str_eq(wa[4], "test");
}

Test(my_str_to_word_array, leading_spaces)
{
    char str[] = "   Spaces before";
    char **wa = my_str_to_word_array(str);

    cr_assert_str_eq(wa[0], "Spaces");
    cr_assert_str_eq(wa[1], "before");
}

Test(my_str_to_word_array, trailing_spaces)
{
    char str[] = "Spaces after  ";
    char **wa = my_str_to_word_array(str);

    cr_assert_str_eq(wa[0], "Spaces");
    cr_assert_str_eq(wa[1], "after");
}

Test(my_str_to_word_array, multiple_spaces_between_words)
{
    char str[] = "Hello   this   is   a   test";
    char **wa = my_str_to_word_array(str);

    cr_assert_str_eq(wa[0], "Hello");
    cr_assert_str_eq(wa[1], "this");
    cr_assert_str_eq(wa[2], "is");
    cr_assert_str_eq(wa[3], "a");
    cr_assert_str_eq(wa[4], "test");
}

Test(my_str_to_word_array, multiple_spaces_between_words_leading_spaces)
{
    char str[] = "   Hello   this   is   a   test";
    char **wa = my_str_to_word_array(str);

    cr_assert_str_eq(wa[0], "Hello");
    cr_assert_str_eq(wa[1], "this");
    cr_assert_str_eq(wa[2], "is");
    cr_assert_str_eq(wa[3], "a");
    cr_assert_str_eq(wa[4], "test");
}

Test(my_str_to_word_array, multiple_spaces_between_words_trailing_spaces)
{
    char str[] = "Hello   this   is   a   test    ";
    char **wa = my_str_to_word_array(str);

    cr_assert_str_eq(wa[0], "Hello");
    cr_assert_str_eq(wa[1], "this");
    cr_assert_str_eq(wa[2], "is");
    cr_assert_str_eq(wa[3], "a");
    cr_assert_str_eq(wa[4], "test");
}

Test(my_str_to_word_array, trailing_and_leading_spaces)
{
    char str[] = "    Spaces between  ";
    char **wa = my_str_to_word_array(str);

    cr_assert_str_eq(wa[0], "Spaces");
    cr_assert_str_eq(wa[1], "between");
}

Test(my_str_to_word_array, null_string)
{
    char **wa = my_str_to_word_array(NULL);

    cr_assert(wa == NULL);
}