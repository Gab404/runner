/*
** EPITECH PROJECT, 2022
** handle_home.c
** File description:
** handle_home
*/

#include "../includes/runner.h"

int handle_event_home(int res_click, sfRenderWindow *window, \
struct game_object_s **tab_btn)
{
    sfEvent event;
    int size[2] = {150, 256};

    while (sfRenderWindow_pollEvent(window, &event)) {
        window_close(window, event);
        res_click = detect_click(event, tab_btn, 3, size);
    }
    return res_click;
}

struct game_object_s **all_struct_btn(void)
{
    struct game_object_s **tab_btn = malloc(sizeof(struct game_object_s *) \
    * 3);
    tab_btn[0] = create_object("./assets/btn/play_btn.png", \
    (sfVector2f) {325, 690}, (sfIntRect){.left = 0, .top = 0, .width = 256, \
    .height = 256});
    tab_btn[1] = create_object("./assets/btn/skin_btn.png", \
    (sfVector2f) {575, 690}, (sfIntRect){.left = 0, .top = 0, .width = 256, \
    .height = 256});
    tab_btn[2] = create_object("./assets/btn/leave_btn.png", \
    (sfVector2f) {825, 690}, (sfIntRect){.left = 0, .top = 0, .width = 256, \
    .height = 256});

    for (int i = 0; i < 3; i++) {
        sfSprite_setScale(tab_btn[i]->sprite, (sfVector2f){0.6, 0.6});
    }
    return tab_btn;
}

sfText *set_text_menu(void)
{
    sfText *menu_txt = sfText_create();
    char *menu_str = \
    "Play                              Skin                             Leave";

    sfText_setString(menu_txt, menu_str);
    sfText_setPosition(menu_txt, (sfVector2f) {370, 630});
    sfText_setCharacterSize(menu_txt, 45);
    sfText_setColor(menu_txt, sfWhite);
    sfText_setFont(menu_txt, \
    sfFont_createFromFile("./assets/american_font.ttf"));

    return menu_txt;
}

void display_text(sfRenderWindow *window, sfText **all_txt)
{
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(window, all_txt[i], NULL);
}

void display_btn(struct game_object_s **tab_btn, sfRenderWindow *window)
{
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(window, tab_btn[i]->sprite, NULL);
}
