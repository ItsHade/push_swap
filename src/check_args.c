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

int ft_check_dup(char **argv)
{
    int i;
    int a;

    i = 1;
    while (argv[i])
    {
        a = 1;
        while (argv[a])
        {
            if (a != i && ft_strint_cmp(argv[i], argv[a]) == 0)
                return (-1);
            a++;
        }
        i++;
    }
    return (0);
}

int ft_is_zero(char *s)
{
    int i;

    i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    while (s[i] && s[i] == '0')
        i++;
    if (s[i] != '\0')
        return (-1);
    return (0);
}

int ft_strint_cmp(char *s1, char *s2)
{
    int i;
    int a;

    i = 0;
    a = 0;
    if (s1[i] == '+')
    {
        if (s2[a] != '+')
            i++;
    }
    else
    { 
        if (s2[a] == '+')
            a++;
    }
    while (s1[i] == 0)
        i++;
    while (s2[a] == 0)
        a++;
    while (s1[i] && s2[a] && s1[i] == s2[a])
    {
        i++;
        a++;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[a]);
}

//recommencer avec ft_split : pas un nombre, ne tiens pas dans un int, pas de doublons
int ft_valid_args(char **argv)
{
    int i;
    int zero_count;

    i = 1;
    zero_count = 0;
    while (argv[i])
    {
        if (ft_is_num(argv[i]) == -1)
            return (-1);
        if (ft_is_zero(argv[i]) == 0)
            zero_count++;
        i++;
    }
    if (zero_count > 1)
        return (-1);
    if (ft_check_dup(argv) == -1)
        return (-1);
    return (0);
}