/*
** EPITECH PROJECT, 2021
** bomb.c
** File description:
** bomb
*/

#include <time.h>
#include "../includes/runner.h"

void bomb_collide(struct player_s *player, \
struct game_object_s ***tab_all, char **map, sfRenderWindow *window)
{
    int nb_bomb = get_nb_bomb(map);
    float ply_x = player->pos.x;
    float ply_y = player->pos.y;
    int w = player->rect.width + 10;
    int h = player->rect.height + 50;
    float obj_x;
    float obj_y;

    for (int i = 0; i < nb_bomb; i++) {
        obj_x = tab_all[3][i]->pos.x;
        obj_y = tab_all[3][i]->pos.y;
        if ((obj_x >= ply_x && obj_x <= ply_x + w) && \
        (obj_y <= ply_y + h && obj_y >= ply_y - 30)) {
            player_dead(window, tab_all);
        }
    }
}

void anim_bomb(struct game_object_s **tab_obj, char **map)
{
    int nb_monster = get_nb_bomb(map);

    for (int i = 0; i < nb_monster; i++) {
        tab_obj[i]->pos.x -= tab_obj[i]->velocity;
        tab_obj[i]->time_anim = sfClock_getElapsedTime(tab_obj[i]->clock);
        tab_obj[i]->sec = tab_obj[i]->time_anim.microseconds / 1000000.0;
        if (tab_obj[i]->sec >= 0.14) {
            tab_obj[i]->sec = 0;
            sfClock_restart(tab_obj[i]->clock);
            change_anim(tab_obj, 87, 29, i);
        }
        sfSprite_setTextureRect(tab_obj[i]->sprite, tab_obj[i]->rect);
    }
}

void display_all_bomb(struct game_object_s **tab_m, sfRenderWindow *window, \
char **map)
{
    int nb_piece = get_nb_bomb(map);

    for (int i = 0; i < nb_piece; i++) {
        sfSprite_setScale(tab_m[i]->sprite, (sfVector2f){2.5, 2.5});
        sfRenderWindow_drawSprite(window, tab_m[i]->sprite, NULL);
        sfSprite_setPosition(tab_m[i]->sprite, tab_m[i]->pos);
    }
}

void fill_bomb(struct game_object_s **tab_obj, int compt)
{
    tab_obj[compt]->sec = 0;
    tab_obj[compt]->clock = sfClock_create();
    tab_obj[compt]->velocity = rand() % 8 + 7;
}

struct game_object_s **create_bomb(char **map)
{
    int m = get_nb_bomb(map);
    int y = 470;
    int x = 1400;
    int i[2] = { 0, 0 };
    struct game_object_s **tab_obj = malloc(sizeof(struct game_object_s *) \
    * m);

    srand(time(NULL));
    for (int compt = 0; compt != m; compt++) {
        for (; map[i[1]][i[0]] != '3'; i[0]++) {
            end_of_line(i, map);
        }
        tab_obj[compt] = create_object("./assets/object/bomb.png", \
        (sfVector2f){x + (i[0] * 50), y + (i[1] * 80)}, \
        (sfIntRect){.left = 0, .top = 0, .width = 29, .height = 25});
        fill_bomb(tab_obj, compt);
        i[0]++;
    }
    return tab_obj;
}
