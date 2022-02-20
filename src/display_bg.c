/*
** EPITECH PROJECT, 2021
** display_bg.c
** File description:
** display_bg
*/

#include "../includes/runner.h"

void parallax_moutain(struct game_object_s **tab_bg)
{
    if (tab_bg[1]->pos.x == 0)
        tab_bg[2]->pos.x = 2432;
    else if (tab_bg[2]->pos.x == 0)
        tab_bg[1]->pos.x = 2432;
    tab_bg[1]->pos.x--;
    tab_bg[2]->pos.x--;
    sfSprite_setPosition(tab_bg[1]->sprite, tab_bg[1]->pos);
    sfSprite_setPosition(tab_bg[2]->sprite, tab_bg[2]->pos);

    return;
}

void parallax_balloon(struct game_object_s **tab_bg)
{
    if (tab_bg[5]->pos.x == 0)
        tab_bg[6]->pos.x = 1332;
    else if (tab_bg[6]->pos.x == 0)
        tab_bg[5]->pos.x = 1332;
    tab_bg[5]->pos.x -= 2;
    tab_bg[6]->pos.x -= 2;
    sfSprite_setPosition(tab_bg[5]->sprite, tab_bg[5]->pos);
    sfSprite_setPosition(tab_bg[6]->sprite, tab_bg[6]->pos);
}

void parallax_grass(struct game_object_s **tab_bg)
{
    if (tab_bg[3]->pos.x == -3)
        tab_bg[4]->pos.x = 1332;
    else if (tab_bg[4]->pos.x == -3)
        tab_bg[3]->pos.x = 1332;
    tab_bg[3]->pos.x -= 5;
    tab_bg[4]->pos.x -= 5;
    sfSprite_setPosition(tab_bg[3]->sprite, tab_bg[3]->pos);
    sfSprite_setPosition(tab_bg[4]->sprite, tab_bg[4]->pos);
}

void parallax_cloud(struct game_object_s **tab_bg)
{
    if (tab_bg[7]->pos.x == 0)
        tab_bg[8]->pos.x = 1332;
    else if (tab_bg[8]->pos.x == 0)
        tab_bg[7]->pos.x = 1332;
    tab_bg[7]->pos.x -= 0.5;
    tab_bg[8]->pos.x -= 0.5;
    sfSprite_setPosition(tab_bg[7]->sprite, tab_bg[7]->pos);
    sfSprite_setPosition(tab_bg[8]->sprite, tab_bg[8]->pos);
}

void display_background(sfRenderWindow *window, struct game_object_s **tab_bg)
{
    sfRenderWindow_drawSprite(window, tab_bg[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, tab_bg[7]->sprite, NULL);
    sfRenderWindow_drawSprite(window, tab_bg[8]->sprite, NULL);
    sfRenderWindow_drawSprite(window, tab_bg[1]->sprite, NULL);
    sfRenderWindow_drawSprite(window, tab_bg[2]->sprite, NULL);
    sfRenderWindow_drawSprite(window, tab_bg[3]->sprite, NULL);
    sfRenderWindow_drawSprite(window, tab_bg[4]->sprite, NULL);
    sfRenderWindow_drawSprite(window, tab_bg[5]->sprite, NULL);
    sfRenderWindow_drawSprite(window, tab_bg[6]->sprite, NULL);
    parallax_moutain(tab_bg);
    parallax_grass(tab_bg);
    parallax_balloon(tab_bg);
    parallax_cloud(tab_bg);
}
