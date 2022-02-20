/*
** EPITECH PROJECT, 2022
** text_skin_menu.c
** File description:
** text_skin_menu
*/

#include "../includes/runner.h"

sfText *create_text(char *str, sfColor color, int scale, sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, scale);
    sfText_setColor(text, color);
    sfText_setFont(text, sfFont_createFromFile("./assets/american_font.ttf"));

    return text;
}

sfText **set_text(void)
{
    sfText **tab_text = malloc(sizeof(sfText *) * 5);

    tab_text[0] = create_text("Skin", sfBlack, 90, (sfVector2f){600, 200});
    tab_text[1] = create_text("Blue", sfWhite, 25, (sfVector2f){160, 550});
    tab_text[2] = create_text("Red", sfWhite, 25, (sfVector2f){310, 550});
    tab_text[3] = create_text("Purple", sfWhite, 25, (sfVector2f){450, 550});
    tab_text[4] = create_text("Gold", sfWhite, 25, (sfVector2f){610, 550});

    return tab_text;
}

void display_text_skin(sfText **text, int nb_text, sfRenderWindow *window)
{
    for (int i = 0; i < nb_text; i++)
        sfRenderWindow_drawText(window, text[i], NULL);
}
