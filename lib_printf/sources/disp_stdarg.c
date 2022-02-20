/*
** EPITECH PROJECT, 2021
** disp_stdarg.c
** File description:
** disp_stdarg
*/

#include <stdarg.h>
#include "../includes/bsprintf.h"

void none_printable_2(char *str, int i)
{
    if (str[i] < 32) {
        my_putnbr(0);
        my_putnbr(0);
    } else if (str[i] >= 10) {
        my_putnbr(0);
    }
}

void none_printable(va_list list)
{
    char *str = va_arg(list, char*);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            none_printable_2(str, i);
            my_putnbr(str[i]);
        } else {
            my_putchar(str[i]);
        }
    }
}

void disp_stdarg_2(char s, char s2, va_list list)
{
    long long n = 0;

    if (s == 'l' && (s2 == 'd' || s2 == 'i')) {
        n = va_arg(list, long);
        put_long(n);
    } else if (s == 'l' && s2 == 'l') {
        n = va_arg(list, long long);
        put_long_long(n);
    } else {
        n = va_arg(list, int);
        if (n < 0) {
            my_putchar('-');
            n *= -1;
        }
        my_putnbr(n);
    }
}

void disp_stdarg(char s, char s2, ...)
{
    va_list list;
    char *str;
    int i = 0;

    va_start(list, s2);
    if (s == 'S') {
        none_printable(list);
    } else if (s == 's') {
        str = va_arg(list, char*);
        put_str(str);
    }
    if (s == 'i' || s == 'd' || s == 'l') {
        disp_stdarg_2(s, s2, list);
    } else if (s == 'c') {
        my_putchar(va_arg(list, int));
    }
    va_end(list);
}
