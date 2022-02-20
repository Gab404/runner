/*
** EPITECH PROJECT, 2021
** high_score.c
** File description:
** high_score
*/

#include <unistd.h>
#include "../includes/runner.h"

int my_getnbr2(char const *str)
{
    int neg = 1;
    int value_0 = 48;
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' || str[i] == '+') {
            neg = neg * -1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10;
            result += (str[i] - value_0);
        } else {
            return neg * result;
        }
    }
    return neg * result;
}

int my_strlen_2(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        res++;
    }
    return res;
}

char *get_high_score(char *filepath)
{
    ssize_t bytes = 0;
    int fd = fs_open_file(filepath);
    char *buffer_bytes = malloc(sizeof(char) * 100);
    char *buffer;

    bytes = read(fd, buffer_bytes, 100);
    close(fd);
    buffer = malloc(sizeof(char) * bytes - 1);
    fd = fs_open_file(filepath);
    read(fd, buffer, bytes);
    buffer[bytes] = '\0';
    close(fd);
    free(buffer_bytes);
    return buffer;
}

void change_high_score(int score, int high_score, char *filepath)
{
    int fd = fs_open_file(filepath);
    char *score_txt = int_to_str(score);
    int len = my_strlen_2(score_txt);

    if (high_score < score) {
        write(fd, score_txt, len);
    }
    close(fd);
}
