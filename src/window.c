/*
** EPITECH PROJECT, 2021
** window.c
** File description:
** window
*/

#include "../includes/runner.h"

void window_close(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

sfRenderWindow *init_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1332, 850, 32};

    window = sfRenderWindow_create(video_mode, "My Runner", sfDefaultStyle, \
    NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}
