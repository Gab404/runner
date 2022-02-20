/*
** EPITECH PROJECT, 2022
** win.c
** File description:
** win
*/

#include "../includes/runner.h"

int define_pos_win(char **map)
{
    int j = 0;
    int i = 0;

    while (map[j][i] != '\n') {
        i++;
    }

    return 1400 + (i * 55);
}

void display_win(sfRenderWindow *window, \
struct game_object_s ***tab_all, struct player_s *player)
{
    sfEvent event;
    sfText *win_txt = create_text("You  Won  !", sfWhite, 60, \
    (sfVector2f){550, 500});

    while (player->win && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_background(window, tab_all[0]);
        display_player(player, window);
        sfRenderWindow_drawText(window, win_txt, NULL);
        display_score(player->score_txt, player->score, window);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event))
            window_close(window, event);
    }
}

void player_win(int *pos_x, struct player_s *ply)
{
    if (ply->pos.x >= *pos_x) {
        ply->win = true;
        ply->jump = 0;
        ply->rect.left = 160;
        ply->rect.height = 46;
        ply->pos.y = 595;
    }
    *pos_x -= 5;
}
