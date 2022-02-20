/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** create_object
*/

#include "../includes/runner.h"

struct game_object_s *create_object(const char *path_to_sprite_sheet, \
sfVector2f pos, sfIntRect rect)
{
    struct game_object_s *create_object = malloc(sizeof(struct game_object_s));

    create_object->texture = sfTexture_createFromFile(path_to_sprite_sheet, \
    NULL);
    create_object->sprite = sfSprite_create();
    create_object->rect = rect;
    create_object->pos = pos;
    sfSprite_setPosition(create_object->sprite, create_object->pos);
    sfSprite_setTexture(create_object->sprite, create_object->texture, sfTrue);
    sfSprite_setTextureRect(create_object->sprite, create_object->rect);

    return create_object;
}

void all_struct_bg_2(struct game_object_s **tab_bg)
{
    tab_bg[5] = create_object("./assets/bg/balloon.png", \
    (sfVector2f) {0, 0}, (sfIntRect){.left = 0, .top = 0, .width = 1332, \
    .height = 850});
    tab_bg[6] = create_object("./assets/bg/balloon.png", \
    (sfVector2f) {1332, 0}, (sfIntRect){.left = 0, .top = 0, .width = 1332, \
    .height = 850});
    tab_bg[7] = create_object("./assets/bg/cloud.png", \
    (sfVector2f) {0, 0}, (sfIntRect){.left = 0, .top = 0, .width = 1332, \
    .height = 362});
    tab_bg[8] = create_object("./assets/bg/cloud.png", \
    (sfVector2f) {1332, 0}, (sfIntRect){.left = 0, .top = 0, .width = 1332, \
    .height = 362});
}

void all_struct_bg(struct game_object_s ***tab_all)
{
    struct game_object_s **tab_bg = malloc(sizeof(struct game_object_s *) * 9);
    tab_bg[0] = create_object("./assets/bg/bg.jpg", \
    (sfVector2f) {0, 0}, (sfIntRect){.left = 0, .top = 0, .width = 1332, \
    .height = 850});
    tab_bg[1] = create_object("./assets/bg/moutain.png", \
    (sfVector2f) {0, 450}, (sfIntRect){.left = 0, .top = 0, .width = 2432, \
    .height = 240});
    tab_bg[2] = create_object("./assets/bg/moutain.png", \
    (sfVector2f) {2432, 450}, (sfIntRect){.left = 0, .top = 0, \
    .width = 2432, .height = 240});
    tab_bg[3] = create_object("./assets/bg/grass.png", \
    (sfVector2f) {0, 0}, (sfIntRect){.left = 0, .top = 0, .width = 1332, \
    .height = 850});
    tab_bg[4] = create_object("./assets/bg/grass.png", \
    (sfVector2f) {1332, 0}, (sfIntRect){.left = 0, .top = 0, .width = 1332, \
    .height = 850});

    all_struct_bg_2(tab_bg);
    tab_all[0] = tab_bg;
}
