/*
** EPITECH PROJECT, 2024
** factory1
** File description:
** putnbr.test
*/

#include "../../header/minishell.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect(void);

Test(my_put_nbr, positive, .init = redirect)
{
    my_put_nbr(12);
    cr_assert_stdout_eq_str("12");
}

Test(my_put_nbr, negative, .init = redirect)
{
    my_put_nbr(-12);
    cr_assert_stdout_eq_str("-12");
}

Test(my_put_nbr, zero, .init = redirect) {
    my_put_nbr(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr, int_max, .init = redirect) {
    my_put_nbr(2147483647);
    cr_assert_stdout_eq_str("2147483647");
}

Test(my_put_nbr, int_min, .init = redirect) {
    my_put_nbr(-2147483648);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_put_nbr, large_positive_number, .init = redirect) {
    my_put_nbr(1234567890);
    cr_assert_stdout_eq_str("1234567890");
}

Test(my_put_nbr, large_negative_number, .init = redirect) {
    my_put_nbr(-987654321);
    cr_assert_stdout_eq_str("-987654321");
}
