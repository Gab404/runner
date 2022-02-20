/*
** EPITECH PROJECT, 2021
** collide.c
** File description:
** collide
*/

#include <stdio.h>
#include "../includes/runner.h"

int detect_next_line(char **map, int *a, int b)
{
    if (map[b][*a] == '\n') {
        b++;
        *a = 0;
    }

    return b;
}

void remove_elem_map(char **map, int i, char c)
{
    int compt = 0;
    int b = 0;

    for (int a = 0; map[b][a] != 'e'; a++) {
        if (map[b][a] == c && compt == i) {
            map[b][a] = ' ';
            return ;
        } else if (map[b][a] == c)
            compt++;
        b = detect_next_line(map, &a, b);
    }
}

void remove_elem_tab(int i, int nb_piece, struct game_object_s **tab_obj)
{
    for (int j = i; j < nb_piece - 1; j++)
        tab_obj[j] = tab_obj[j + 1];

    tab_obj[nb_piece - 1] = create_object("./assets/object/bomb.png", \
    (sfVector2f){0, -50}, \
    (sfIntRect){.left = 0, .top = 0, .width = 29, .height = 25});
    tab_obj[nb_piece - 1]->sec = 0;
    tab_obj[nb_piece - 1]->clock = sfClock_create();
}

void player_dead(sfRenderWindow *window, struct game_object_s ***tab_all)
{
    sfEvent event;
    sfText *lose_txt = create_text("You  lose  !", sfWhite, 60, \
    (sfVector2f){550, 500});

    while (sfRenderWindow_isOpen(window)) {
        display_background(window, tab_all[0]);
        sfRenderWindow_drawText(window, lose_txt, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event))
            window_close(window, event);
    }
}
