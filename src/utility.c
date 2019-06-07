/*
** EPITECH PROJECT, 2017
** utility.c
** File description:
** utility.c
*/

#include "my.h"

int check_o(char **map, int x, int y, int len)
{
    int keep = y;

    for (int a = 0; a != len; a++) {
        if (map[y - 1][x] != 'o')
            y--;
        else
            return (0);
    }
    for (int a = 0; a != len; a++) {
        if (map[keep][x - 1] != 'o')
            x--;
        else
            return (0);
    }
    return (1);
}
