/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-ossan.msoili
** File description:
** redirect
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect(void)
{
    cr_redirect_stderr();
    cr_redirect_stdin();
    cr_redirect_stdout();
}