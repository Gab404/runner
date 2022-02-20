/*
** EPITECH PROJECT, 2022
** handle_main.c
** File description:
** handle_main
*/

#include "../includes/runner.h"

void map_already_set(char **av, struct game_object_s ***tab_all, \
struct player_s *player)
{
    sfRenderWindow *window;
    char **map;
    int var_help;

    var_help = help(av);
    if (var_help == 0 && fs_open_file(av[1]) > 0) {
        window = init_window();
        home(window, tab_all, player);
        map = get_map(av[1]);
        my_runner(map, window, tab_all, player);
    }
}

void init_struct(struct game_object_s ***tab_all, char **map)
{
    tab_all[1] = create_piece(map);
    tab_all[2] = create_monster(map);
    tab_all[3] = create_bomb(map);
}

void end_of_runner(sfRenderWindow *window, sfSound **music, \
sfSoundBuffer **buffer, struct player_s *player)
{
    change_high_score(player->score, my_getnbr2(get_high_score\
    ("./src/high_score.txt")), "./src/high_score.txt");
    music_destroy(music, buffer);
    sfRenderWindow_destroy(window);
}
