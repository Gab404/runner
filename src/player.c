/*
** EPITECH PROJECT, 2021
** player.c
** File description:
** player
*/

#include "../includes/runner.h"

struct player_s *fill_player(char *filepath, sfVector2f pos)
{
    struct player_s *player = malloc(sizeof(struct player_s));

    player->texture = sfTexture_createFromFile(filepath, NULL);
    player->sprite = sfSprite_create();
    player->rect = (sfIntRect){ .left = 160, .top = 0, .width = 50, \
    .height = 46 };
    player->pos = pos;
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setScale(player->sprite, (sfVector2f) { 2.5, 2.5 });
    player->seconds = 0;
    player->jump = false;
    player->compt_jump = 0;
    player->win = false;
    player->lose = false;
    player->score = 0;
    player->score_txt = set_score(player->score);
    return player;
}

int anim_player_run(struct player_s *player, float compt)
{
    if (player->seconds <= 8) {
        player->seconds += 0.4;
        compt++;
        if (compt == 5) {
            player->rect.top += 44;
            compt = 0;
        }
    } else {
        compt = 0;
        player->rect.top = 0;
        player->seconds = 0;
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
    return compt;
}

int anim_player_jump(struct player_s *player, float compt)
{
    if (player->compt_jump < 15)
        player->rect.top = 100;
    else
        player->rect.top = 153;
    sfSprite_setTextureRect(player->sprite, player->rect);
    return compt;
}

void display_player(struct player_s *player, sfRenderWindow *window)
{
    static float compt = 0;

    if (player->jump)
        compt = anim_player_jump(player, compt);
    else
        compt = anim_player_run(player, compt);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
}
