/*
** EPITECH PROJECT, 2021
** piece.c
** File description:
** piece
*/

#include "../includes/runner.h"

void piece_collide(struct player_s *player, \
struct game_object_s **tab_obj, char **map, sfSound **music)
{
    int nb_piece = get_nb_piece(map);
    float ply_x = player->pos.x;
    float ply_y = player->pos.y;
    int w = player->rect.width + 20;
    int h = player->rect.height + 20;
    float obj_x;
    float obj_y;

    for (int i = 0; i < nb_piece; i++) {
        obj_x = tab_obj[i]->pos.x;
        obj_y = tab_obj[i]->pos.y;
        if ((obj_x >= ply_x && obj_x <= ply_x + w) && \
        (obj_y <= ply_y + h && obj_y >= ply_y - 10)) {
            remove_elem_map(map, i, '1');
            remove_elem_tab(i, nb_piece, tab_obj);
            player->score++;
            sfSound_play(music[0]);
        }
    }
}

void display_all_piece(struct game_object_s **tab_obj, \
sfRenderWindow *window, char **map)
{
    int nb_piece = get_nb_piece(map);

    for (int i = 0; i < nb_piece; i++) {
        sfSprite_setScale(tab_obj[i]->sprite, (sfVector2f){0.3, 0.3});
        sfRenderWindow_drawSprite(window, tab_obj[i]->sprite, NULL);
        sfSprite_setPosition(tab_obj[i]->sprite, tab_obj[i]->pos);
    }
}

void anim_piece(struct game_object_s **tab_obj, char **map)
{
    int nb_piece = get_nb_piece(map);

    for (int i = 0; i < nb_piece; i++) {
        tab_obj[i]->pos.x -= 5;
        tab_obj[i]->time_anim = sfClock_getElapsedTime(tab_obj[i]->clock);
        tab_obj[i]->sec = tab_obj[i]->time_anim.microseconds / 1000000.0;
        if (tab_obj[i]->sec >= 0.1) {
            tab_obj[i]->sec = 0;
            sfClock_restart(tab_obj[i]->clock);
            change_anim(tab_obj, 750, 150, i);
        }
        sfSprite_setTextureRect(tab_obj[i]->sprite, tab_obj[i]->rect);
    }
}

struct game_object_s **create_piece(char **map)
{
    int p = get_nb_piece(map);
    int y = 470;
    int x = 1400;
    int i[2] = {0, 0};
    struct game_object_s **tab_obj = malloc(sizeof(struct game_object_s *) \
    * p);

    for (int compt = 0; compt != p; compt++) {
        for (; map[i[1]][i[0]] != '1'; i[0]++)
            end_of_line(i, map);
        tab_obj[compt] = create_object("./assets/object/piece.png", \
        (sfVector2f){x + (i[0] * 50), y + (i[1] * 80)}, \
        (sfIntRect){.left = 0, .top = 0, .width = 150, .height = 117});
        tab_obj[compt]->sec = 0;
        tab_obj[compt]->clock = sfClock_create();
        i[0]++;
    }
    return tab_obj;
}
