/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** project
*/

#include "my.h"

int *get_square(char **map, int y, int x, int *temp)
{
    int len = 1;
    int keep_x = x;
    int keep_y = y;

    while (map[y + 1] != NULL && map[y + 1][x + 1] != '\0' && map[y + 1][x + 1]\
    != 'o' && check_o(map, x + 1, y + 1, len) == 1) {
        x++;
        y++;
        len++;
    }
    temp[0] = len;
    temp[1] = keep_x;
    temp[2] = keep_y;
    temp[3] = 0;
    return (temp);
}

int *get_stat_square(char **map)
{
    int *res = malloc(sizeof (int) * 4);
    int *temp = malloc(sizeof (int) * 4);
    int x = 0;
    int y = 0;

    temp[0] = 0;
    res[0] = 0;
    while (map[y][x] != '\0' || map[y + 1] != NULL) {
        if (map[y][x] == '.')
            temp = get_square(map, y, x, temp);
        if (temp[0] > res[0])
            res = get_square(map, y, x, res);
        if (map[y][x] != '\0')
            x++;
        else {
            x = 0;
            y++;
        }
    }
    free(temp);
    return (res);
}

void search_square(char *buffer, int size)
{
    char **map = my_str_to_word_array(buffer, size);
    int *stat = get_stat_square(map);
    int x = stat[1];
    int y = stat[2];

    for (int v = 0; v < stat[0]; v++) {
        for (int h = 0; h < stat[0]; h++) {
            map[y][x++] = 'x';
        }
        x = stat[1];
        y++;
    }
    for (int v = 0; map[v + 1] != NULL; v++) {
        my_putstr(map[v]);
        my_putchar('\n');
    }
    for (int a = 0; map[a] != NULL; a++)
        free(map[a]);
    free(map);
    free(stat);
}

int read_map(int fd, char *path)
{
    struct stat temp;
    char *buffer;

    if (stat(path, &temp) == -1)
        return (my_putstr_error("No such file or directory.\n", 84));
    buffer = malloc(sizeof (char) * temp.st_size + 1);
    read(fd, buffer, temp.st_size);
    search_square(buffer, temp.st_size);
    free(buffer);
    return (0);
}

int main(int ac, char **av)
{
    int fd;

    if (ac != 2)
        return (my_putstr_error("./bsq [map]\n", 84));
    if ((fd = open(av[1], O_RDONLY)) == -1)
        return (my_putstr_error("No such file or directory.\n", 84));
    return (read_map(fd, av[1]));
}
