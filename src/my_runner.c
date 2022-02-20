/*
** EPITECH PROJECT, 2021
** my_runner.c
** File description:
** my_runner
*/

#include "../includes/runner.h"

void runing(sfRenderWindow *window, struct player_s *player, \
struct game_object_s ***tab_all, char **map)
{
    jump(player);
    collide_all(window, tab_all, player, map);
    anim_all(tab_all, map);
    display_all(window, tab_all, player, map);
}

void my_runner(char **map, sfRenderWindow *window, \
struct game_object_s ***tab_all, struct player_s *player)
{
    sfSoundBuffer **buffer = malloc(sizeof(sfSoundBuffer *) * 2);
    sfSound **music = set_my_music(buffer);
    int pos_win = define_pos_win(map);

    init_struct(tab_all, map);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        handle_jump(window, player, music);
        runing(window, player, tab_all, map);
        piece_collide(player, tab_all[1], map, music);
        player_win(&pos_win, player);
        display_win(window, tab_all, player);
        sfRenderWindow_display(window);
    }
    end_of_runner(window, music, buffer, player);
    free(map);
}

int main(int ac, char **av)
{
    sfRenderWindow *window;
    struct game_object_s ***tab_all = malloc(sizeof\
    (struct game_object_s **) * 4);
    struct player_s *player = fill_player("./assets/player/player_blue.png", \
    (sfVector2f){100, 595});
    sfMusic *music = set_music_back();
    char **map;

    if (ac == 2) {
        map_already_set(av, tab_all, player);
    } else {
        window = init_window();
        home(window, tab_all, player);
        map = get_map(difficulty_menu(window, player, tab_all));
        my_runner(map, window, tab_all, player);
    }
    sfMusic_destroy(music);
    return 0;
}
