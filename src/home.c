/*
** EPITECH PROJECT, 2022
** home.c
** File description:
** home
*/

#include "../includes/runner.h"

sfText *set_text_name(void)
{
    sfText *name_txt = sfText_create();
    char *name_str = "My Runner";

    sfText_setString(name_txt, name_str);
    sfText_setPosition(name_txt, (sfVector2f) {450, 100});
    sfText_setCharacterSize(name_txt, 140);
    sfText_setColor(name_txt, sfBlack);
    sfText_setFont(name_txt, \
    sfFont_createFromFile("./assets/wrestlemania.ttf"));

    return name_txt;
}

sfText *get_high_score_txt(char *filepath)
{
    char *high_score_str = get_high_score(filepath);
    sfText *high_score = create_text(high_score_str, sfWhite, 40, \
    (sfVector2f){1230, 23});

    return high_score;
}

sfText **set_all_text_home(void)
{
    sfText **all_txt = malloc(sizeof(sfText *) * 4);

    all_txt[0] = set_text_name();
    all_txt[1] = set_text_menu();
    all_txt[2] = get_high_score_txt("./src/high_score.txt");
    all_txt[3] = create_text("High Score: ", sfWhite, 45, \
    (sfVector2f){1050, 20});

    return all_txt;
}

void display_all_home(sfRenderWindow *window, \
struct game_object_s ***tab_all, struct player_s *player, \
struct game_object_s **tab_btn)
{
    display_background(window, tab_all[0]);
    display_player(player, window);
    display_btn(tab_btn, window);
}

void home(sfRenderWindow *window, struct game_object_s ***tab_all, \
struct player_s *player)
{
    struct game_object_s **tab_btn = all_struct_btn();
    int res_click = 0;
    int skin = 1;
    sfText **all_txt = set_all_text_home();

    all_struct_bg(tab_all);
    while (res_click != 1 && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_all_home(window, tab_all, player, tab_btn);
        display_text(window, all_txt);
        sfRenderWindow_display(window);
        if (res_click == 2) {
            skin = skin_menu(skin, window, player, tab_all);
            change_skin(skin, player);
            res_click = 0;
        }
        res_click = handle_event_home(res_click, window, tab_btn);
        leave_active(res_click, window);
    }
    free(tab_btn);
}
