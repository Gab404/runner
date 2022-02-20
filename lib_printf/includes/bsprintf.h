/*
** EPITECH PROJECT, 2021
** bsprintf.h
** File description:
** bsprintf
*/

#ifndef BSPRINTF_H_
    # define BSPRINTF_H_

void fct_for_my_printf(char s);
void put_long(long n);
void put_long_long(long long n);
int nb_dig_int(int n);
int my_strlen(char *str);
void put_str(char *str);
int my_putnbr(int n);
void put_octal(int n);
void put_hexa(int n, char s);
void put_bin(int n);
void put_unsigned(unsigned int n);
void put_short(short n);
void my_putchar(char c);
void put_octal(int n);
int my_printf(char *s, ...);
void disp_stdarg(char s, char s2, ...);

#endif /* BSPRINTF_H_ */
