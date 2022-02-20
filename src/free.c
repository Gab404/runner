/*
** EPITECH PROJECT, 2022
** free.c
** File description:
** free
*/

#include "../includes/runner.h"

void free_skin(struct player_s **skin)
{
    for (int i = 1; i < 4; i++)
        free(skin[i]);
    free(skin);
}
