/*
** EPITECH PROJECT, 2022
** difficulty_menu.c
** File description:
** difficulty_menu
*/

#include "../includes/runner.h"

struct game_object_s **set_all_skull(void)
{
    float x = 0.15;
    struct game_object_s **skull = malloc(sizeof(struct game_object_s *) * 3);

    skull[0] = create_object("./assets/btn/skull.png", \
    (sfVector2f){420, 410}, (sfIntRect){.left = 0, .top = 0, .width = 436, \
    .height = 436});
    skull[1] = create_object("./assets/btn/skull.png", \
    (sfVector2f){600, 385}, (sfIntRect){.left = 0, .top = 0, .width = 436, \
    .height = 436});
    skull[2] = create_object("./assets/btn/skull.png", \
    (sfVector2f){800, 365}, (sfIntRect){.left = 0, .top = 0, .width = 436, \
    .height = 436});
    for (int i = 0; i < 3; i++, x += 0.05)
        sfSprite_setScale(skull[i]->sprite, (sfVector2f){x, x});

    return skull;
}

void display_all_diff(struct game_object_s **skull, sfRenderWindow *window, \
struct game_object_s ***tab_all, struct player_s *player)
{
    display_background(window, tab_all[0]);
    display_player(player, window);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(window, skull[i]->sprite, NULL);
}

sfText **set_text_diff(void)
{
    sfText **tab_text = malloc(sizeof(sfText *) * 4);

    tab_text[0] = create_text("Difficulty", sfBlack, 90, \
    (sfVector2f){500, 100});
    tab_text[1] = create_text("Easy", sfWhite, 25, (sfVector2f){430, 500});
    tab_text[2] = create_text("Normal", sfWhite, 25, (sfVector2f){610, 500});
    tab_text[3] = create_text("Hard", sfWhite, 25, (sfVector2f){830, 500});

    return tab_text;
}

char *get_map_diff(int res_click)
{
    char *easy = "./assets/map/map_easy.txt";
    char *normal = "./assets/map/map_normal.txt";
    char *hard = "./assets/map/map_hard.txt";

    if (res_click == 1)
        return easy;
    else if (res_click == 2)
        return normal;
    else
        return hard;
}

char *difficulty_menu(sfRenderWindow *window, \
struct player_s *player, struct game_object_s ***tab_all)
{
    sfEvent event;
    struct game_object_s **skull = set_all_skull();
    sfText **text = set_text_diff();
    int res_click = 0;
    int size[2] = {109, 109};

    while (res_click == 0 && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_all_diff(skull, window, tab_all, player);
        display_text_skin(text, 4, window);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            window_close(window, event);
            res_click = detect_click(event, skull, 3, size);
        }
    }
    return get_map_diff(res_click);
}
