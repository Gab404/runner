/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include "../includes/bsprintf.h"

void type_sort_3(char s, char s2, va_list list, int n)
{
    if (s == 'i' || s == 'c' || s == 'd' || s == 'l')
        disp_stdarg(s, s2, va_arg(list, int));
    if (s == 'o') {
        n = va_arg(list, int);
        put_octal(n);
    } else if (s == 'x' || s == 'X' || s == 'p') {
        n = va_arg(list, int);
        fct_for_my_printf(s);
        put_hexa(n, s);
    }
}

void type_sort_2(char s, char s2, va_list list, int n)
{
    if (s == 'u') {
        n = va_arg(list, int);
        put_unsigned(n);
    } else if (s == 's' || s == 'S')
        disp_stdarg(s, s2, va_arg(list, char*));
    else {
        type_sort_3(s, s2, list, n);
    }
}

void type_sort(char s, char s2, va_list list)
{
    int n = 0;

    if (s == '%')
        my_putchar('%');
    if ((s == 'h' && s2 == 'd') || (s == 'h' && s2 == 'i')) {
        n = va_arg(list, int);
        put_short(n);
    } else if (s == 'b') {
        n = va_arg(list, int);
        put_bin(n);
    } else {
        type_sort_2(s, s2, list, n);
    }
}

int flags_more_1char(char *s, int i)
{
    if (s[i] == 'l' && s[i + 1] == 'l' && s[i + 2] == 'd')
        i += 2;
    if ((s[i] == 'l' && s[i + 1] == 'd') || (s[i] == 'l' && s[i + 1] == 'i'))
        i++;
    else if (s[i] == 'h' && (s[i + 1] == 'd' || s[i + 1] == 'i'))
        i++;
    return i;
}

int my_printf(char *s, ...)
{
    va_list list;

    va_start(list, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '%' || (s[i] == '%' && s[i + 1] == '\n')) {
            my_putchar(s[i]);
        } else {
            i++;
            type_sort(s[i], s[i + 1], list);
            i = flags_more_1char(s, i);
        }
    }
    va_end(list);
    return 0;
}
