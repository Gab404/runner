/*
** EPITECH PROJECT, 2022
** score.c
** File description:
** score
*/

#include "../includes/runner.h"

sfSprite *set_score_img(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile\
    ("./assets/object/piece.png", NULL);
    sfIntRect rect = (sfIntRect){ .left = 0, .top = 0, .width = 150, \
    .height = 117 };

    sfSprite_setPosition(sprite, (sfVector2f){5, 30});
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setScale(sprite, (sfVector2f){0.3, 0.3});

    return sprite;
}

sfText *set_score(int score)
{
    char *score_str = int_to_str(score);
    sfText *score_txt = sfText_create();

    sfText_setString(score_txt, score_str);
    sfText_setPosition(score_txt, (sfVector2f){65, 20});
    sfText_setCharacterSize(score_txt, 45);
    sfText_setColor(score_txt, sfBlack);
    sfText_setFont(score_txt, \
    sfFont_createFromFile("./assets/american_font.ttf"));

    return score_txt;
}

void display_score(sfText *txt, int score, sfRenderWindow *window)
{
    char *score_str = int_to_str(score);
    sfSprite *sprite = set_score_img();

    sfText_setString(txt, score_str);
    sfRenderWindow_drawText(window, txt, NULL);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}
