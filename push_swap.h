#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
//
#include <stdio.h>

typedef struct
{
   int *nb;
   struct s_list *next;
} pile;

int ft_valid_args(int ac, char **av);

int ft_is_integer(char *av);

long ft_atoi(char *s);

int ft_is_dup(char **av, char *arg, size_t a);

void ft_putstr(char *str, int err);

int ft_strlen(char *s);

#endif