/*
** EPITECH PROJECT, 2021
** jump.c
** File description:
** jump
*/

#include "../includes/runner.h"

void jump(struct player_s *player)
{
    if (player->jump && player->compt_jump < 20) {
        player->pos.y -= 10;
        player->compt_jump++;
    } else if (player->jump && player->compt_jump < 40) {
        player->pos.y += 10;
        player->compt_jump++;
    } else {
        if (player->jump) {
            player->rect.left -= 50;
            player->rect.top = 0;
            player->rect.height -= 6;
        }
        player->jump = false;
        player->compt_jump = 0;
    }
    sfSprite_setPosition(player->sprite, player->pos);
}

void detect_jump(struct player_s *player, sfEvent event, \
sfSound **music)
{
    sfKeyEvent key_event;

    if (event.type == sfEvtKeyPressed) {
        key_event = event.key;
        if (key_event.code == sfKeySpace) {
            player->jump = true;
            sfSound_play(music[1]);
            player->rect.left += 50;
            player->rect.top += 50;
            player->rect.height += 6;
        }
    }
}

void handle_jump(sfRenderWindow *window, \
struct player_s *player, sfSound **music)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        window_close(window, event);
        if (player->jump == false)
            detect_jump(player, event, music);
        if (player->compt_jump == 0)
            jump(player);
        pause_game(event, window);
    }
}
