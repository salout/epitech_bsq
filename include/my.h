/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef _MY_H_
#define _MY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void my_putchar(char);
int my_putstr(char const *);
int my_strlen(char const *);
int my_putstr_error(char *, int);
char **my_str_to_word_array(char const *, int);
int check_o(char **, int, int, int);
void get_first_dot(char **, int *, int *);

#endif
