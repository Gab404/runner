/*
** EPITECH PROJECT, 2022
** handle_skin.c
** File description:
** handle_skin
*/

#include "../includes/runner.h"

char *change_skin_2(struct player_s *player, int skin)
{
    char *filepath;

    if (skin == 3) {
        filepath = "./assets/player/player_purple.png";
        player->texture = sfTexture_createFromFile(filepath, NULL);
    } else if (skin == 4) {
        filepath = "./assets/player/player_orange.png";
        player->texture = sfTexture_createFromFile(filepath, NULL);
    }

    return filepath;
}

void change_skin(int skin, struct player_s *player)
{
    char *filepath;

    if (skin == 1) {
        filepath = "./assets/player/player_blue.png";
        player->texture = sfTexture_createFromFile(filepath, NULL);
    } else if (skin == 2) {
        filepath = "./assets/player/player_red.png";
        player->texture = sfTexture_createFromFile(filepath, NULL);
    } else
        filepath = change_skin_2(player, skin);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
}

struct player_s **create_skin(void)
{
    struct player_s **skin = malloc(sizeof(struct player_s *) * 4);

    skin[1] = fill_player("./assets/player/player_red.png", (sfVector2f)\
    {250, 595});
    skin[2] = fill_player("./assets/player/player_purple.png", (sfVector2f)\
    {400, 595});
    skin[3] = fill_player("./assets/player/player_orange.png", (sfVector2f)\
    {550, 595});

    for (int i = 1; i < 4; i++)
        sfSprite_setScale(skin[i]->sprite, (sfVector2f){2.5, 2.5});

    return skin;
}

int display_skin(struct player_s **skin, sfRenderWindow *window, \
int start_display, struct player_s *player)
{
    if (start_display == 1) {
        for (int i = 1; i < 4; i++) {
            display_player(skin[i], window);
        }
    } else {
        if (player->rect.top == 0)
            start_display = 1;
    }
    return start_display;
}

bool handle_event_skin(sfRenderWindow *window, struct player_s **skin, \
int *res_click)
{
    sfEvent event;
    bool go_back = false;

    while (sfRenderWindow_pollEvent(window, &event)) {
        go_back = handle_close_menu(go_back, event);
        *res_click = detect_click_player(*res_click, event, skin, 4);
        window_close(window, event);
    }
    return go_back;
}
