/*
** EPITECH PROJECT, 2022
** music.c
** File description:
** music
*/

#include "../includes/runner.h"

sfSound *set_music(sfSoundBuffer *buffer, float volume)
{
    sfSound *music = sfSound_create();

    sfSound_setBuffer(music, buffer);
    sfSound_setVolume(music, volume);

    return music;
}

sfSound **set_my_music(sfSoundBuffer **buffer)
{
    sfSound **music = malloc(sizeof(sfSound *) * 2);

    buffer[0] = sfSoundBuffer_createFromFile("./assets/music/piece.wav");
    buffer[1] = sfSoundBuffer_createFromFile("./assets/music/jump.wav");

    music[0] = set_music(buffer[0], 50);
    music[1] = set_music(buffer[1], 20);

    return music;
}

void music_destroy(sfSound **music, sfSoundBuffer **buffer)
{
    for (int i = 0; i < 2; i++) {
        sfSound_destroy(music[i]);
        sfSoundBuffer_destroy(buffer[i]);
    }
    free(music);
    free(buffer);
}

sfMusic *set_music_back(void)
{
    sfMusic *music = sfMusic_createFromFile("./assets/music/background.ogg");
    sfMusic_setVolume(music, 50);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);

    return music;
}
