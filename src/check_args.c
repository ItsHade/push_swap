#include "../include/push_swap.h"

//fonction qui permet de verifier si c est compris dans un int, check si on a que des entiers, dans chaque chaine de caractere 
int ft_is_num(char *s)
{
    int i;

    i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (s[i] == 0)
        return (-1);
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (-1);
        i++;
    }
    return (0);
}

// int ft_check_dup(char **argv)
// {
//     int i;
//     int a;

//     i = 1;
//     while (argv[i])
//     {
//         a = 1;
//         while (argv[a])
//         {
//             if (a != i && ft_strint_cmp(argv[i], argv[a]) == 0)
//                 return (-1);
//             a++;
//         }
//         i++;
//     }
//     return (0);
// }


int ft_check_splitted(char **strs, t_pile **pile_a)
{
    int a;
    long int nb;
    t_pile *new;

    a = 0;
    while (strs[a][0] != 0)
    {
        ft_putstr(strs[a], 1);
        ft_putchar('\n', 1);
        if (ft_is_num(strs[a]) == -1)
            return (-1);
        nb = ft_atol(strs[a]);
        if (nb < INT_MIN || nb > INT_MAX)
            return (-1);
        new = ft_lstnew(nb);
        ft_lstadd_back(pile_a, new);
        a++;
    }
}

int ft_valid_args(char **argv, t_pile **pile_a)
{
    int i;
    char **strs;

    i = 1;
    while (argv[i])
    {
        strs = ft_split(argv[i], ' ');
        if (ft_check_splitted(strs, pile_a) == -1)
            return (ft_freesplit(strs), -1);
        ft_freesplit(strs);
        i++;
    }
    return (0);
}