/*
** EPITECH PROJECT, 2021
** manage_map.c
** File description:
** manage_map
*/

void end_of_line(int *tab_index, char **map)
{
    int i = tab_index[0];
    int j = tab_index[1];

    if (map[j][i] == '\n') {
        j++;
        i = 0;
    }
    tab_index[0] = i;
    tab_index[1] = j;

    return ;
}

int get_nb_col(char *buffer)
{
    int nb_col = 0;

    for (int i = 0; buffer[i] != '\n'; i++) {
        nb_col++;
    }

    return nb_col;
}

int get_nb_piece(char **map)
{
    int compt = 0;
    int j = 0;

    for (int i = 0; map[j][i] != 'e'; i++) {
        if (map[j][i] == '1')
            compt++;
        else if (map[j][i] == '\n') {
            j++;
            i = 0;
        }
    }
    return compt;
}

int get_nb_monster(char **map)
{
    int compt = 0;
    int j = 0;

    for (int i = 0; map[j][i] != 'e'; i++) {
        if (map[j][i] == '2')
            compt++;
        else if (map[j][i] == '\n') {
            j++;
            i = 0;
        }
    }
    return compt;
}

int get_nb_bomb(char **map)
{
    int compt = 0;
    int j = 0;

    for (int i = 0; map[j][i] != 'e'; i++) {
        if (map[j][i] == '3')
            compt++;
        else if (map[j][i] == '\n') {
            j++;
            i = 0;
        }
    }
    return compt;
}
