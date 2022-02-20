/*
** EPITECH PROJECT, 2021
** fct_other.c
** File description:
** fct_other
*/

#include "../includes/bsprintf.h"

void put_long(long n)
{
    if (n >= 10) {
        my_putnbr(n / 10);
        my_putchar(n % 10 + '0');
    } else if (n < 10) {
        my_putchar(n + '0');
    } else {
        my_putchar('-');
        n = -n;
    }
}

void put_long_long(long long n)
{
    if (n >= 10) {
        my_putnbr(n / 10);
        my_putchar(n % 10 + '0');
    } else if (n < 10) {
        my_putchar(n + '0');
    } else {
        my_putchar('-');
        n = -n;
    }
}

void fct_for_my_printf(char s)
{
    if (s == 'p') {
        my_putchar('0');
        my_putchar('x');
    }
    return;
}
