/*
** EPITECH PROJECT, 2021
** help.c
** File description:
** help
*/

#include "../includes/runner.h"
#include "../lib_printf/includes/bsprintf.h"

int help(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_printf("Finite runner created with CSFML.\n\n");
        my_printf("USAGE\n  ");
        my_printf("./my_runner [map.txt]\n\n");
        my_printf("OPTIONS\n");
        my_printf(" -h      print the usage and quit.\n\n");
        my_printf("USER INTERACTIONS\n");
        my_printf(" SPACE_KEY      jump.\n");
        my_printf(" MOUSE_CLICK    click ont the buttons.\n");
        my_printf(" ESCAPE_KEY     come back in menu / pause in game.\n");
        return 1;
    }
    return 0;
}

void display_pause_menu(sfRenderWindow *window, \
struct game_object_s ***tab_all, struct player_s *player)
{
    display_background(window, tab_all[0]);
    display_player(player, window);
}

struct game_object_s *set_cursor(int x)
{
    struct game_object_s *cursor = create_object("./assets/btn/cursor.png", \
    (sfVector2f){152 * x, 500}, (sfIntRect){.left = 0, .top = 0, \
    .width = 356, .height = 204});

    sfSprite_setScale(cursor->sprite, (sfVector2f){0.1, 0.1});
    return cursor;
}

void leave_active(int type_btn, sfRenderWindow *window)
{
    if (type_btn == 3)
        sfRenderWindow_close(window);
}

void init_player_skin(struct player_s *player, \
struct player_s **skin)
{
    player->texture = sfTexture_createFromFile\
    ("./assets/player/player_blue.png", NULL);
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    skin[0] = player;
}
