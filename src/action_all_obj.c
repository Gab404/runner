/*
** EPITECH PROJECT, 2022
** action_all_obj.c
** File description:
** action_all_obj
*/

#include "../includes/runner.h"

void display_all(sfRenderWindow *window, \
struct game_object_s ***tab_all, struct player_s *player, char **map)
{
    display_background(window, tab_all[0]);
    display_all_piece(tab_all[1], window, map);
    display_all_monster(tab_all[2], window, map);
    display_all_bomb(tab_all[3], window, map);
    display_player(player, window);
    display_score(player->score_txt, player->score, window);
}

void collide_all(sfRenderWindow *window, \
struct game_object_s ***tab_all, struct player_s *player, char **map)
{
    monster_collide(player, tab_all, map, window);
    bomb_collide(player, tab_all, map, window);
}

void anim_all(struct game_object_s ***tab_all, char **map)
{
    anim_monster(tab_all[2], map);
    anim_bomb(tab_all[3], map);
    anim_piece(tab_all[1], map);
}

void change_anim(struct game_object_s **tab_obj, int limit, int shift, int i)
{
    if (tab_obj[i]->rect.left < limit) {
        tab_obj[i]->rect.left += shift;
    } else {
        tab_obj[i]->rect.left = 0;
    }
}

void change_anim_inverse(struct game_object_s **tab_obj, int i)
{
    if (tab_obj[i]->rect.left >= 2) {
        tab_obj[i]->rect.left -= 23;
    } else {
        tab_obj[i]->rect.left = 231;
    }
}
