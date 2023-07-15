#include "../include/push_swap.h"

//fonction qui permet de verifier si c est compris dans un int, check si on a que des entiers, dans chaque chaine de caractere 
// int ft_is_integer(char *s)
// {
//     size_t i;

//     i = 0;
//     if (s[i] == '+' || s[i] == '-')
//         i++;
//     if (s[i] == 0)
//         return (-1);
//     while (s[i])
//     {
//         if (s[i] < '0' || s[i] > '9')
//             return (-1);
//         i++;
//     }
//     return (0);
// }

//
int ft_is_dup(char **av, char *arg, size_t a)
{
    size_t i;

    i = 1;
    while (av[i])
    {
        if (i == a)
            i++;
        if (av[i] == arg)
            return (-1);
        i++;
    }
    return (0);
}

int ft_valid_args(int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
    {
        if (ft_is_integer(av[i]) == -1)
            return (-1);
    }
    if (ft_mini_atoi(av[i]) < INT_MIN || ft_mini_atoi(av[i]) > INT_MAX)
        return (-1);
    if (ft_is_dup(av, av[i], i) == -1)
        return (-1);

    return (0);
}