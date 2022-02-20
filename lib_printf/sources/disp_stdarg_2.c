/*
** EPITECH PROJECT, 2021
** disp_darg_2.c
** File description:
** disp_darg_2
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../includes/bsprintf.h"

void put_octal(int n)
{
    if (n >= 0 && n < 8) {
        n += 48;
        my_putchar(n);
    } else if (n < 0) {
        my_putchar('-');
        put_octal(n * (-1));
    } else {
        put_octal(n / 8);
        put_octal(n % 8);
    }
}

void put_hexa(int n, char s)
{
    char tab_dig[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char tab_dig_maj[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int tab_result[15];
    int i = 0;

    for ( ; n > 0; i++) {
        tab_result[i] = n % 16;
        n = n / 16;
    }
    i--;
    while (i >= 0) {
        if (s == 'x')
            my_putchar(tab_dig[tab_result[i]]);
        else {
            my_putchar(tab_dig_maj[tab_result[i]]);
        }
        i--;
    }
}

void put_unsigned(unsigned int n)
{
    if (n >= 0 && n < 10) {
        n += 48;
        my_putchar(n);
    } else if (n < 0) {
        my_putchar('-');
        put_unsigned(n * (-1));
    } else {
        put_unsigned(n / 10);
        put_unsigned(n % 10);
    }
}

void put_short(short n)
{
    if (n >= 0 && n < 10) {
        n += 48;
        my_putchar(n);
    } else if (n < 0) {
        my_putchar('-');
        put_short(n * (-1));
    } else {
        put_short(n / 10);
        put_short(n % 10);
    }
}

void put_bin(int n)
{
    char tab_dig[2] = {'0', '1'};
    int tab_result[64];
    int i = 0;

    for ( ; n > 0; i++) {
        tab_result[i] = n % 2;
        n = n / 2;
    }
    i--;
    while (i >= 0) {
        my_putchar(tab_dig[tab_result[i]]);
        i--;
    }
}
