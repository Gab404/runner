/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** map
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../includes/runner.h"

int fs_open_file(char *filepath)
{
    int res_open;

    res_open = open(filepath, O_RDWR);
    if (res_open < 0) {
        write(2, "Map doesn't exist\n", 18);
    }
    return res_open;
}

void my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    if (src[i] == '\0') {
        dest[i] = '\0';
    }
}

char **get_map(char *filepath)
{
    char **map = malloc(sizeof(char *) * 3);
    char *line = NULL;
    FILE *file;
    size_t len = 0;
    int i = 0;

    file = fopen(filepath, "r");
    if (file != NULL) {
        while (getline(&line, &len, file) != -1) {
            map[i] = malloc(sizeof(char) * len);
            my_strcpy(map[i], line);
            i++;
        }
    }
    free(line);
    fclose(file);

    return map;
}
