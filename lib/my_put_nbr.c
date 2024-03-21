/*
** EPITECH PROJECT, 2024
** MINISHELL2
** File description:
** my_put_nbr
*/
#include "../header/minishell.h"

int my_put_nbr(int nb)
{
    int nombre;
    int len = num_len(nb);

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    nombre = nb % 10;
    if (nb / 10)
        my_put_nbr(nb / 10);
    my_putchar(48 + nombre);
    return (len);
}
