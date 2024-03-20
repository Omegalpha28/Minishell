/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-ossan.msoili
** File description:
** putchar.test
*/

#include "../../header/minishell.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect(void);

Test(my_putchar, writing_letter, .init = redirect)
{
    my_putchar('B');
    cr_assert_stdout_eq_str("B");
}

Test(my_putchar, writing_number, .init = redirect)
{
    my_putchar('7');
    cr_assert_stdout_eq_str("7");
}

Test(my_putchar, writing_multi_letter, .init = redirect)
{
    my_putchar('h');
    my_putchar('e');
    my_putchar('l');
    my_putchar('l');
    my_putchar('o');
    cr_assert_stdout_eq_str("hello");
}

Test(my_putchar, writing_backlash_n, .init = redirect)
{
    my_putchar('\n');
    cr_assert_stdout_eq_str("\n");
}

Test(my_putchar, writing_backlash_t, .init = redirect)
{
    my_putchar('\t');
    cr_assert_stdout_eq_str("\t");
}

Test(my_putchar, writing_space, .init = redirect)
{
    my_putchar(' ');
    cr_assert_stdout_eq_str(" ");
}