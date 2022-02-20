/*
** EPITECH PROJECT, 2022
** int_to_str.c
** File description:
** int_to_str
*/

#include <stdlib.h>

int my_strlen_3(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int nb_dig_int_2(int nb)
{
    int i = 0;

    while (nb > 0) {
        nb = nb / 10;
        i++;
    }
    return i;
}

char *my_revstr(char *str)
{
    int len = my_strlen_3(str) - 1;
    int i = 0;
    char tmp;
    int end = len + 1;

    while (i < len) {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        i++;
        len--;
    }
    str[end] = '\0';
    return (str);
}

char *int_to_str(int nb)
{
    int len = nb_dig_int_2(nb);
    char *str = malloc(sizeof(char) * len);
    int i = 0;

    if (nb == 0)
        return "0";
    for ( ; i <= len; i++) {
        str[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    str++;

    return str;
}
