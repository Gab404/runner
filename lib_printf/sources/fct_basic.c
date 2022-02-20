/*
** EPITECH PROJECT, 2021
** fct_basic.c
** File description:
** fct_basic
*/

#include <unistd.h>

int nb_dig_int(int n)
{
    int res = 0;

    while (n != 0) {
        n /= 10;
        res++;
    }
    return res;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int put_str(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

int my_putnbr(int n)
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
    return n;
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
