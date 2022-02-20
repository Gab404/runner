/*
** EPITECH PROJECT, 2022
** skin.c
** File description:
** skin
*/

#include "../includes/runner.h"

bool handle_close_menu(bool go_back, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        go_back = true;

    return go_back;
}

int manage_click_player(int res_click, sfMouseButtonEvent mouse, \
struct player_s **skin, int nb_elem)
{
    int x = mouse.x;
    int y = mouse.y;

    for (int i = 0; i < nb_elem; i++) {
        if ((x >= skin[i]->pos.x && x <= skin[i]->pos.x + 100) \
        && (y >= skin[i]->pos.y && y <= skin[i]->pos.y + 100))
            return i + 1;
    }

    return res_click;
}

void display_all_elem(sfRenderWindow *window, \
struct game_object_s ***tab_all, sfText **text, struct player_s *player)
{
    display_background(window, tab_all[0]);
    display_text_skin(text, 5, window);
    display_player(player, window);
}

int detect_click_player(int res_click, sfEvent event, \
struct player_s **skin, int nb_elem)
{
    sfMouseButtonEvent mouse;

    if (event.type == sfEvtMouseButtonPressed) {
        mouse = event.mouseButton;
        res_click = manage_click_player(res_click, mouse, skin, nb_elem);
    }

    return res_click;
}

int skin_menu(int res_click, sfRenderWindow *window, \
struct player_s *player, struct game_object_s ***tab_all)
{
    int start_display = 0;
    bool go_back = false;
    struct player_s **skin = create_skin();
    sfText **text = set_text();
    struct game_object_s *cursor = set_cursor(res_click);

    init_player_skin(player, skin);
    while (go_back == false && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_all_elem(window, tab_all, text, player);
        start_display = display_skin(skin, window, start_display, player);
        sfSprite_setPosition(cursor->sprite, (sfVector2f){152 * res_click, \
        500});
        sfRenderWindow_drawSprite(window, cursor->sprite, NULL);
        go_back = handle_event_skin(window, skin, &res_click);
        sfRenderWindow_display(window);
    }
    free_skin(skin);
    return res_click;
}
