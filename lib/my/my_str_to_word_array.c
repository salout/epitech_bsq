/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>

int check_char(char a)
{
    if (a >= '0' && a <= '9')
        return (0);
    else if (a == '\0' || a == '\n')
        return (0);
    return (1);
}

int count_space(char const *str)
{
    int a = 0;

    for (int x = 0; str[x] != '\0'; x++)
        if (str[x] == '\n')
            a++;
    return (a);
}

char **my_str_to_word_array(char const *str, int size)
{
    int y = 0;
    int a = 0;
    int x = 0;
    int n = 0;

    char **temp = malloc(sizeof (char * ) * count_space(str) + 1);
    temp[y] = malloc(sizeof (char) * size + 1);

    for (; str[x] != '\0'; x++) {
        if (check_char(str[x]) == 1)
            temp[y][a++] = str[x];
        else if (str[x] == '\n' && n == 0)
            n = 1;
        else if (str[x] == '\n' && n == 1) {
            temp[y][++a] = '\0';
            temp[++y] = malloc(sizeof (char) * size + 1);
            a = 0;
        }
    }
    temp[++y] = NULL;
    return (temp);
}
