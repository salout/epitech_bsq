/*
** EPITECH PROJECT, 2017
** my_putstr_error.c
** File description:
** my_putstr_error.c
*/

int my_strlen(char const *);
#include <unistd.h>

int my_putstr_error(char *str, int error)
{
    write(2, str, my_strlen(str));
    return (error);
}
