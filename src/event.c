/*
** EPITECH PROJECT, 2021
** event.c
** File description:
** event
*/

#include "../includes/runner.h"

int manage_click(sfMouseButtonEvent mouse, struct game_object_s **tab_btn, \
int nb_elem, int *size)
{
    int x = mouse.x;
    int y = mouse.y;

    for (int i = 0; i < nb_elem; i++) {
        if ((x >= tab_btn[i]->pos.x && x <= tab_btn[i]->pos.x + size[0]) \
        && (y >= tab_btn[i]->pos.y && y <= tab_btn[i]->pos.y + size[1])) {
            return i + 1;
        }
    }
    return 0;
}

int detect_click(sfEvent event, struct game_object_s **tab_btn, \
int nb_elem, int *size)
{
    sfMouseButtonEvent mouse;
    int res = 0;

    if (event.type == sfEvtMouseButtonPressed) {
        mouse = event.mouseButton;
        res = manage_click(mouse, tab_btn, nb_elem, size);
    }

    return res;
}

bool detect_pause_desactive(sfEvent event, bool pause)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        pause = false;
    return pause;
}

void pause_active(sfRenderWindow *window)
{
    sfEvent event;
    bool pause = true;

    while (pause && sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            window_close(window, event);
            pause = detect_pause_desactive(event, pause);
        }
    }
}

void pause_game(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        pause_active(window);
    }
}
